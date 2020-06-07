//unfinished
#include<iostream>
#include<stack>
#include<ctype>
using namespace std;
int main(){
	stack<char> c;
	string s;
	cin>>s;
	bool b=false;
	int l=s.length();
	for(int i=0;i<l;){
		int n=0;
		while(isdigit(s[i])){
			n=s[i]+n*10;
			i++;
		}
		if(isdigit(s[--i])){
			if(b){
				char d=c.top();
				c.pop();
				int t=c.top();
				c.pop();
				if(d=='*')
					c.push(t*n);
				else
					c.push(t/n);
				b=false;
			}
			else
				c.push(n);
		}
		else if(s[i]=='*'||s[i]=='/'){
			b=true;
			c.push(s[i]);
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='(')
			c.push(s[i]);
		else if(s[i]==')'){
			int t=0;
			stack<char> c2;
			while(c.top()!='('){
				c2.push(c.top());
				c.pop();
			}
			c.pop();
			string s2="";
			int p=0;
			while(!c2.empty()){
				s2[p]=c2.top();
				c2.pop();
				p++;
			}
			for(int j=0;j<p;j++){
				s2[j]
			}
		}
	}
}