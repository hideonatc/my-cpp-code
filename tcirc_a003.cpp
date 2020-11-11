#include<iostream>
using namespace std;
int main(){
	string s;
	while(cin>>s){
		for(int i=0;i<s.length()-1;i++)
			cout<<max(int(s[i]),int(s[i+1]))-min(int(s[i]),int(s[i+1]));
		cout<<endl;
	}
}