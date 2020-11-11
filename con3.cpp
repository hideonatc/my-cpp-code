#include<iostream>
using namespace std;
int odd=0,even=0,mx=-1,mn=999,o=0,e=0;
void fun(int k){
	if(k%2) {odd+=k;o++;}
	else {even+=k;e++;}
	if(k>mx) mx=k;
	if(k<mn) mn=k;
}
int main(){
	int n;
	cin>>n;
	int in;
	for(int i=1;i<=n;i++){
		cin>>in;
		fun(in);
	}
	printf("奇數平均值:%.2f\n偶數平均值:%.2f\n最大值:%d\n最小值:%d\n",double(odd)/o,double(even)/e,mx,mn);
}