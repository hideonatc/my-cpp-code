#include<iostream>
using namespace std;
int main(){
	int xn=0,yn=0,k,ans=0;
	cin>>k;
	for(int i=1;i<21&&!ans;i++){
		if(k==i){
			ans=1;
			break;
		}
		xn+=5;
	}
	for(int i=21;i<41&&!ans;i++){
		if(k==i){
			ans=1;
			break;
		}
		yn+=5;
	}
	for(int i=41;i<61&&!ans;i++){
		if(k==i){
			ans=1;
			break;
		}
		xn-=5;
	}
	for(int i=61;i<81&&!ans;i++){
		if(k==i){
			ans=1;
			break;
		}
		yn-=5;
	}
	printf("(%d,%d)\n",xn,yn);
}