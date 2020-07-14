#include<iostream>
using namespace std;
int main(){
	int t,x,y,z;
	cin>>t;
	while(t--){
		cin>>x>>y>>z;
		int a=min(x,min(y,z)),c=max(x,max(y,z));
		int b=x+y+z-a-c;
		if(a+b<=c)
			cout<<"0"<<endl;
		else{
			cout<<"1"<<" ";
			if(a==b||b==c)
				cout<<"1";
			else
				cout<<"0";
			cout<<endl;
		}
	}
}