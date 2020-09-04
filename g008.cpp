//unfinished
#include<iostream>
using namespace std;
int tab[21]={0},ok=0;
void bt(int t,int n,int now){
	printf("bt(%d,%d,%d)\n",t,n,now);
	if(t==now){
		printf("%d OK\n",t);
		ok=1;
		return;
	}
	for(int i=1;i<=n;i++)
		if(tab[i]+now<=t){
			bt(t,n,tab[i]+now);
			if(ok)return;
		}
	return;
}
int main(){
	int p;
	while(cin>>p){
		if(p==0)
			break;
		int l=0,ans=1;
		for(int i=1;i<=p;i++){
			cin>>tab[i];
			l+=tab[i];
		}
		for(int i=1;i<=l;i++){
			ok=0;
			bt(i,p,0);
			if(!ok){
				ans=0;
				break;
			}
		}
		if(!ans)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
}