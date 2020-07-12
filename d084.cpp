#include<iostream>
#include<stack>
using namespace std;
char c;
int cal(int a,int b){
	if(c=='+')
		return a+b;
	else if(c=='-')
		return b-a;
	else if(c=='*')
		return a*b;
	else
		return b/a;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		bool f=0;
		stack<char> s;
		string in;
		cin>>in;
		for(int i=0;i<in.length();i++)
			if(!isdigit(in[i])&&in[i]!='('&&in[i]!=')'&&in[i]!=','&&in[i]!='+'&&in[i]!='-'&&in[i]!='*'&&in[i]!='/'){
				cout<<"-1"<<endl;
				f=1;
			}
		if(!f){
			for(int i=0;i<in.length();i++){
				if(in[i]!=')')
					s.push(in[i]);
				else{
					if(s.top()=='+'||s.top()=='-'||s.top()=='*'||s.top()=='/'){
						c=s.top();
						s.pop();
						if(s.top()!=',')
							f=1;
						else
							s.pop();
					}
					else
						f=1;
					int a=0,b=0,ten=1;
					while(s.top()!=','&&!f){
						if(isdigit(s.top())){
							a+=int(s.top()-'0')*ten;
							ten*=10;
							s.pop();
						}
						else
							f=1;
					}
					if(s.top()!=',')
						f=1;
					ten=1;
					s.pop();
					while(s.top()!='('&&!f){
						if(isdigit(s.top())){
							b+=int(s.top()-'0')*ten;
							ten*=10;
							s.pop();
						}
						else
							f=1;
					}
					if(s.top()!='(')
						f=1;
					s.pop();
					if((c!='/'||a!=0)&&!f){
						//printf("cal(%d,%d,%c)\n",a,b,c);
						int r=cal(a,b);
						if(r<0)
							f=1;
						string num="";
						if(r==0){
							num="0";
							s.push('0');
							//cout<<"push:0"<<endl;
						}
						while(r>0){
							num+=char(r%10+int('0'));
							r/=10;
						}
						if(num!="0"&&!f){
							//cout<<"push:";
							for(int k=num.length()-1;k>=0;k--){
								//cout<<num[k];
								s.push(num[k]);
							}
							//cout<<endl;
						}
					}
					else
						f=1;
				}
			}
			string ans="";
			while(!s.empty()){
				if(!isdigit(s.top())){
					f=1;
					break;
				}
				else{
					ans+=s.top();
					s.pop();
				}
			}
			if(f)
				cout<<"-1";
			else
				for(int j=ans.length()-1;j>=0;j--)
					cout<<ans[j];
			cout<<endl;
		}
	}
}
/*
4
(1000,0,/)
((2,((9,3,/),8,+),*),4,-)
(80,(15,(30,((68,(9,7,*),-),5,*),-),+),/)
(1,2,3)
*/