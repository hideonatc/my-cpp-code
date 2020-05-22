#include<iostream>
#include<algorithm>
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;
int n=5;
int w=10;
int wg[5]={2,5,4,2,3};
int v[5]={6,3,5,4,6};
int value[6][11];
void dp(void){

}
int main(){
	int i,j;
	for(j=0;j<=w;j++){
		value[0][j]=0;
	}
	for(i=0;i<=n;i++){
		value[i][0]=0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=w;j++){
			if(j<wg[i-1]){
				value[i][j]=value[i-1][j];
			}
			else {
				value[i][j]=max(value[i-1][j],value[i-1][j-wg[i-1]]+v[i-1]);
			}
		}
	}
	cout<<value[n][w];
}
