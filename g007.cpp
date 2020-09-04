#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(n==0)
			break;
		int tab[42]={0},m;
		for(int i=1;i<=n;i++){
			cin>>m;
			for(int j=1;j<=m;j++){
				int in;
				cin>>in;
				tab[in]++;
			}
		}
		int min=1e9;
		for(int i=1;i<=41;i++)
			if(tab[i]<min)
				min=tab[i];
		cout<<min<<endl;
	}
}