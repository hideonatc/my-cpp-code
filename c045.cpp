#include<iostream>
using namespace std;
int main(){
	int num[5];
	for(int i=0;i<5;i++)
		cin>>num[i];
	int a=num[0]+num[1];
	int b=num[3]+num[4];
	int c=num[0]+num[2]+num[4];
	int d=num[3]+num[2]+num[1];
	cout<<min(min(a,b),min(c,d))<<endl;
}