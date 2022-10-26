#include<iostream>
using namespace std;
string ans = "", temp = "";
bool err = 0, flagLB = 0;
int idx = 0, tidx = 0;
void program(string text);
void stmts(string text);
void stmt(string text);
void primary(string text);
void primary_tail(string text);
void error(void);
string scanner(string text);
int main(){
	string s="",a;
	while(!cin.eof()){
		getline(cin,a);
		s+=a;
	}
	program(s);
	if(err||flagLB)
		cout<<"invalid input"<<endl;
	else
		cout<<ans;
}
void program(string text){
	stmts(text);
	return;
}
void stmts(string text){
	if(scanner(text)=="id"){
		stmt(text);
		stmts(text);
	}
	else if(scanner(text)=="STRLIT"){
		stmt(text);
		stmts(text);
	}
	else if(scanner(text)=="end"){}
	else error();
	return;
}
void stmt(string text){
	if(idx!=0&&text[idx-1]=='('&&text[idx]==')'){
		tidx = ++idx;
		flagLB = 0;
		ans += "RBR )\n";
		return;
	}
	else if(scanner(text)=="id"){
		primary(text);
	}
	else if(scanner(text)=="STRLIT"){
		tidx = idx;
		ans += "STRLIT " + temp + "\n"; 
	}
	else if(scanner(text)=="end"){}
	else error();
	return;
}
void primary(string text){
	if(scanner(text)=="id"){
		tidx = idx;
		ans += "ID "+ temp + "\n";
		primary_tail(text);
	}
	else if(scanner(text)=="end"){}
	else error();
	return;
}
void primary_tail(string text){
	if(scanner(text)=="dot"){
		tidx = idx;
		if(scanner(text)=="id"){
			tidx = idx;
			ans += "DOT .\nID " + temp + "\n";
			primary_tail(text);
		}
		else error();
	}
	else if(scanner(text)=="LBR"){
		flagLB = 1;
		tidx = idx;
		ans+="LBR (\n";
		stmt(text);
		if(scanner(text)=="RBR"){
			flagLB = 0;
			tidx = idx;
			ans += "RBR )\n";
			primary_tail(text);
		}
	}
	else if(scanner(text)=="end") return;
	else if(flagLB&&scanner(text)=="RBR"){
		flagLB = 0;
		tidx = idx;
		ans += "RBR )\n";
		primary_tail(text);
	}
	return;
}
void error(void){
	err = 1;
	return;
}
string scanner(string text){
	idx = tidx;
	while(idx!=text.length()&&text[idx]==' '){
		idx++;
		tidx++;
	}
	if(idx==text.length()){
		return "end";
	}
	else if(text[idx]=='_'||isalpha(text[idx])){
		temp = "";
		temp += text[idx++];
		while(text[idx]=='_'||isalpha(text[idx])||isdigit(text[idx])){
			temp += text[idx++];
		}
		return "id";
	}
	else if(text[idx]=='"'){
		temp = "";
		if(idx+1==text.length()){
				error();
				return "error";
		}
		temp += text[idx++];
		while(text[idx]!='"'){
			temp += text[idx];
			idx++;
			if(idx==text.length()){
				error();
				return "error";
			}
		}
		temp += text[idx++];
		return "STRLIT";
	}
	else if(text[idx]=='.'){
		idx++;
		return "dot";
	}
	else if(text[idx]=='('){
		idx++;
		return "LBR";
	}
	else if(text[idx]==')'){
		idx++;
		return "RBR";
	}
	else{
		error();
		return "error";
	}
}