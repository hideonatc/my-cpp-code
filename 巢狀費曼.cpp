#include<iostream>
using namespace std;
int fm(int a){
	int f[13]={0,1,1,2,3,5,8,13,21,34,55,89,144};
	if(a<13)return f[a];
	else return fm(a-1)+fm(a-2);
}
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	while(m--){
		if(n==0||n==1||n==5)break;
		if(n==2&&m>0){
			n=1;
			break;
		}
		if(n==3&&m>1){
			n=1;
			break;
		}
		n=fm(n);
	}
	printf("%d",n);
}