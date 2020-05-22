#include<iostream>
using namespace std;
int main(){
	float rr1,rr2,rr3;
	//int r1,r2,r3;
	cin>>rr1>>rr2>>rr3;
	//cin>>r1>>r2>>r3;
	//int r=r1+r2+r3;
	int n;
	cin>>n;
	printf("第1代:\n");
	printf("RR:%0.4f Rr:%0.4f rr:%0.4f\n",rr1,rr2,rr3);
	for(int i=1;i<=n;i++){
		float a,b,c;
		a=rr1*rr1+rr2*rr2/4+rr1*rr2;
		b=rr2*rr2/2+rr1*rr2+rr2*rr3+2*rr1*rr3;
		c=rr2*rr2/4+rr3*rr3+rr2*rr3;
		rr1=a;
		rr2=b;
		rr3=c;
		printf("第%d代:\n",i+1);
		printf("RR:%0.4f Rr:%0.4f rr:%0.4f\n",rr1,rr2,rr3);
	}
}
