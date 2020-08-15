#include<iostream>
using namespace std;
int ans[2]={-1,-1};
bool check(int f,int t,int p,int pn){
	if(!f&&!t)
		return 1;
	if(p-pn<500&&!t)
		return 1;
	if(p-pn<200)
		return 1;
	return 0;
}
void dp(int f,int t,int p,int pn){
	//printf("dp(%d,%d,%d,%d)\n",f,t,p,pn);
	if(check(f,t,p,pn)){
		if(pn>ans[0]*500+ans[1]*200){
			ans[0]=4-f;
			ans[1]=5-t;
			return;
		}
		else if(pn==ans[0]*500+ans[1]*200){
			if(4-f>ans[0]){
				ans[0]=4-f;
				ans[1]=5-t;
				return;
			}
			return;
		}
		return;
	}
	if(pn+500<=p&&f>0)
		dp(f-1,t,p,pn+500);
	if(pn+200<=p&&t>0)
		dp(f,t-1,p,pn+200);
	return;
}
int main(){
	int p;
	cin>>p;
	dp(4,5,p,0);
	printf("%d %d %d\n",ans[0],ans[1],p-ans[0]*500-ans[1]*200);
}