#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string in;
		cin>>in;
		for(int i=0;i<in.length();i++){
			if(char(int(in[i])-n)<'A')
				cout<<char(int(in[i])-n+26);
			else
				cout<<char(int(in[i])-n);
		}
		cout<<endl;
	}
}