#include<iostream>
using namespace std;
int main(){
	int s[2][2];
	for(int i=0;i<2;i++){
		scanf("%d,%d",&s[i]);
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
			printf("%d\n",s[i-1][j-1]);
		}
	}
}

