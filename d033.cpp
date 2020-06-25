#include<iostream>
#include<stack>
using namespace std;
bool ck(char a,char b){
	if(a==')'&&b=='(')
		return 1;
	if(a==']'&&b=='[')
		return 1;
	return 0;
}
void solve(string s){
	int l=s.length();
	stack<char> st;
	for(int i=0;i<l;i++){
		if(!st.empty()&&ck(s[i],st.top())){
			st.pop();
		}
		else{
			st.push(s[i]);
		}
	}
	if(st.empty())
		cout<<"Correct"<<endl;
	else
		cout<<"Error"<<endl;
}
int main(){
	string s;
	while(cin>>s){
		if(cin.fail())
			break;
		solve(s);
	}
}