#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int arr[102][1002];
	int v[102],w[102];
	int M,N;
	cin>>N>>M;
	for(int i=0;i<=M;i++)arr[0][i]=0;
	for(int i=0;i<=N;i++)arr[i][0]=0;
	for(int i=1;i<=N;i++)cin>>w[i]>>v[i];
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(w[i]<=j){
				arr[i][j]=max(arr[i-1][j],arr[i-1][j-w[i]]+v[i]);
			}
			else arr[i][j]=arr[i-1][j];
		}
	}
	cout<<arr[N][M];
}