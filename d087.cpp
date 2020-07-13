#include<iostream>
using namespace std;
long long int tab[1001]={0};
long long int f(int a){
	if(tab[a]!=0)
		return tab[a];
	tab[a]=f(a-1)+f(a-2);
	return tab[a];
}
int main(){
	tab[1]=1;
	tab[2]=1;
	long long int n,idx=1,first,ans=1;
	cin>>n;
	while(f(idx)<n)
		idx++;
	if(f(idx)!=n)
		cout<<n<<endl;
	else{
		first=idx;
		while(cin>>n){
			if(cin.fail())
				break;
			if(f(++idx)!=n){
				ans=0;
				cout<<n<<endl;
				break;
			}
		}
		if(ans)
			cout<<first<<endl;
	}
}