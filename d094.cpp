#include<iostream>
using namespace std;
int tab[10000]={0};
int f(int a){
	if(tab[a])
		return tab[a];
	tab[a]=f(a-1)+f(a-2);
	return tab[a];
}
int main(){
	int t;
	cin>>t;
	tab[1]=1;
	tab[2]=1;
	while(t--){
		int n;
		cin>>n;
		if(n==1)
			cout<<"1"<<endl;
		else{
			int i=3;
			while(f(i)<n){
				if(f(i+1)==n){
					cout<<i+1<<endl;
					break;
				}
				else if(f(i+1)>n){
					cout<<"-1"<<endl;
					break;
				}
				i++;
			}
		}
	}
}