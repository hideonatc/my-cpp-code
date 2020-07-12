#include<iostream>
using namespace std;
long long int tab[11]={0,4,64,400,4624,26244,228484,2022084,20268004,202208400,2006860804};
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<tab[n]<<endl;
	}
}