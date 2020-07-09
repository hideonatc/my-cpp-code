#include<iostream>
#include<cmath>
using namespace std;
double r1=0,r2=0;
int solve(int a,int b,int c){
	int k=(b*b-4*a*c);
	if(k<0)
		return 0;
	if(k==0){
		r1=-b/(2*a);
		return 1;
	}
	r1=(-b+sqrt((double)k))/(double)(2*a);
	r2=(-b-sqrt((double)k))/(double)(2*a);
	return 2;
}
void print(int arg){
	if(arg==0)
		printf("No real root\n");
	else if(arg==1)
		printf("Two same roots x=%.2f\n",r1);
	else
		printf("Two different roots x1=%.2f , x2=%.2f\n",max(r1,r2),min(r1,r2));
}
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	print(solve(a,b,c));
}