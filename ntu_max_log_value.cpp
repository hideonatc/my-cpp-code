#include<iostream>
using namespace std;
int n,price[502]={0};
int m,l[502]={0};
int mem[502]={0};	//to memorize the maximum of each length, so we don't have to repeat all the calculations
int rec(int len){
	if(mem[len]!=0)	//if mem[len] has been calculated, just return the value
		return mem[len];
	int mx=-1;
	for(int i=1;i<(len/2)+1;i++){	//list all possibilities of turning the log into two pieces
		mem[i]=rec(i);	
		mem[len-i]=rec(len-i);
		if(rec(i)+rec(len-i)>mx)	//record the maximum value in all the possibilities
			mx=rec(i)+rec(len-i);
	}
	mem[len]=(len<=n)?max(mx,price[len]):mx;	//fill in the maximum value we found into the array
	return mem[len];	//if the length is smaller than n, we have to compare whether the price is bigger than the value in the array
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>price[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>l[i];
	int ans=0;
	for(int i=1;i<=m;i++)
		ans+=rec(l[i]);
	cout<<ans<<endl;
}