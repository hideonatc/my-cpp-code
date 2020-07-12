#include<iostream>
using namespace std;
int main(){
	string in;
	cin>>in;
	int idx=1;
	bool first=1;
	cout<<'{';
	while(in[idx]!='}'){
		string s="";
		bool f=1;
		while(in[idx]!=','&&in[idx]!='}'){
			//cout<<idx<<endl;
			if(!isupper(in[idx]))
				f=0;
			s+=in[idx++];
		}
		if(in[idx]==',')
			idx++;
		if(f){
			if(!first)
				cout<<',';
			for(int i=s.length()-1;i>=0;i--)
				cout<<s[i];
			first=0;
		}
		else{
			if(!first)
				cout<<',';
			cout<<s;
			first=0;
		}
	}
	cout<<'}'<<endl;
}