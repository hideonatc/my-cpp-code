#include<iostream>
using namespace std;
int main(){
	unsigned long long int x;
	cin>>x;
	unsigned long long int ex[9999]={0};
	ex[1]=0;
	ex[2]=10;
	bool flag=true;
	if(x<10){
		printf("1 %d",10-x);
		flag=false;
	}
	else if(x<24){
		printf("2 %d",24-x);
		flag=false;
	}
	int i=2;
	for(;ex[i]<=x;i++){
		ex[i+1]=ex[i]+(ex[i]-ex[i-1])*2-i*3;
		//cout<<ex[i+1]<<endl;
	}
	if(flag)printf("%d %d",i-1,ex[i]-x);
}
