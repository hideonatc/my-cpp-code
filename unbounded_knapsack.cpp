#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	int N,M;
	cin>>N>>M;
	int value[1001];
	memset(value,0,sizeof(value));
	int v[101],w[101];
	for(int i=1;i<=N;i++)cin>>w[i]>>v[i];
	for(int i=0;i<N;i++){
		for(int j=w[i];j<=M;j++){
			value[j]=max(value[j],value[j-w[i]]+v[i]);
		}
	}
	cout<<value[M];
}