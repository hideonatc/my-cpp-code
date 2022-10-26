#include<iostream>
#include<cctype>
using namespace std;
void scanner(int idx, string text);
int digitScan(int idx, string text);
int main(){
	string s="",a;
	while(!cin.eof()){
		getline(cin,a);
		s+=a+" ";
	}
	scanner(0,s);
}
int digitScan(int idx, string text){
	string val = "";
	val += text[idx];
	while(idx+1<text.length()&&isdigit(text[idx+1])){
		val += text[++idx];
	}
	cout<<"NUM "<<val<<endl;
	return idx;
}
void scanner(int idx, string text){
	if(idx==text.length()) return;
	if(text[idx]==' '){
		scanner(idx+1, text);
		return;
	}
	else if(isdigit(text[idx])){
		idx = digitScan(idx, text);
		scanner(idx+1, text);
		return;
	}
	else if(text[idx]=='+'){
		cout<<"PLUS"<<endl;
		scanner(idx+1, text);
		return;
	}
	else if(text[idx]=='-'){
		cout<<"MINUS"<<endl;
		scanner(idx+1, text);
		return;
	}
	else if(text[idx]=='*'){
		cout<<"MUL"<<endl;
		scanner(idx+1, text);
		return;
	}
	else if(text[idx]=='/'){
		cout<<"DIV"<<endl;
		scanner(idx+1, text);
		return;
	}
	else if(text[idx]=='('){
		cout<<"LPR"<<endl;
		scanner(idx+1, text);
		return;
	}
	else if(text[idx]==')'){
		cout<<"RPR"<<endl;
		scanner(idx+1, text);
		return;
	}
	return;
}