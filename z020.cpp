#include<iostream>
#include<set>
using namespace std;
set<int>coin;
bool tab[200000];
char solve(int a){
	for(int i=0;i<=a;i++){
		for(set<int>::iterator it=coin.begin();it!=coin.end();it++){
			if(tab[i]==0||i+*it>=199999)
				break;
			tab[i+*it]=1;
			if(i+*it==a)
				return 'Y';
		}
	}
	return 'N';
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		coin.clear();
		int k;
		for(int i=1;i<=199999;i++)
			tab[i]=0;
		tab[0]=1;
		for(int i=1;i<=n;i++){
			cin>>k;
			coin.insert(k);
		}
		for(int i=1;i<=m;i++){
			cin>>k;
			cout<<solve(k);
		}
		cout<<endl;
	}
}