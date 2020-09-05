#include<iostream>
using namespace std;
int tab[41]={0};
bool check(int n,int t){
	int now=0,tail=1;
	for(int i=1;i<=n;i++){
		if(now+tab[i]>t){
			while(now+tab[i]>t){
				now-=tab[tail];
				tail++;
			}
			now+=tab[i];
		}
		else
			now+=tab[i];
		//printf("tail:%d head:%d total:%d target:%d\n",tail,i,now,t);
		if(now==t)
			return 1;
	}
	return 0;
}
int main(){
	int n;
	while(cin>>n){
		if(!n)break;
		int l=0,ans=1;
		for(int i=1;i<=n;i++){
			cin>>tab[i];
			l+=tab[i];
		}
		for(int i=1;i<=l;i++){
			if(!check(n,i)){
				ans=0;
				break;
			}
		}
		if(ans)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}