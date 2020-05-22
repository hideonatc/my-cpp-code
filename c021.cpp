#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int ua=a+3*b+5*c;
	int ub=3*a+2*b+4*c;
	int uc=3*(a+b+c);
	int ans=min(min(ua,ub),uc);
	if(ans==ua)printf("A %d",ans);
	else if(ans==ub)printf("B %d",ans);
	else printf("C %d",ans);
}
