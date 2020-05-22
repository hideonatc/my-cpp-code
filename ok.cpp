#include<iostream>
using namespace std;
void add(int pos[],int n,int a){
	for(int i=0;i<n;i++){
		pos[i]+=a;
	}
}
void add_t(int pos[],int x,int y,int a){
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			*pos[i]+=a;
		}
	}
}
int main(){
	int a[99][99];
	cin>>a[0][0]>>a[0][1]>>a[1][0]>>a[1][1];
	add(a[0],2,1);
	for(int i=0;i<2;i++)cout<<a[0][i]<<" ";
	add(a[1],2,5);
	for(int i=0;i<2;i++)cout<<a[1][i]<<" ";
	add_t(a,2,2,3);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<a[i][j]<<" ";
		}
	}
} 
