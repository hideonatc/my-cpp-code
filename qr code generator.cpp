#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<cstring>
using namespace std;
int main(){
	int i;
	while(cin>>i){
	system("CLS");
	int arr[26][26];
	memset(arr,sizeof(arr),1);
    srand(time(NULL));
	for(int i=1;i<=25;i++){
		for(int j=1;j<=25;j++){
			arr[i][j]=rand()%2+1;
		}
	}
	for(int i=1;i<=7;i++){
		for(int j=1;j<=7;j++){
			arr[i][j]=arr[18+i][j]=arr[i][18+j]=1;
		}
	}
	for(int i=1;i<=5;i++)arr[2][i+1]=arr[20][i+1]=arr[6][i+1]=arr[24][i+1]=2;
	for(int i=1;i<=5;i++)arr[i+1][2]=arr[19+i][6]=arr[i+1][6]=arr[19+i][2]=2;
	for(int i=1;i<=5;i++)arr[2][19+i]=arr[6][i+19]=arr[i+1][20]=arr[i+1][24]=2;
	for(int i=1;i<=8;i++)arr[8][i]=arr[18][i]=arr[i+17][8]=arr[i][8]=arr[8][18+i]=arr[i][18]=2;
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			arr[16+i][16+j]=1;
		}
	}
	for(int i=1;i<=3;i++)arr[18][17+i]=arr[20][17+i]=arr[17+i][18]=arr[17+i][20]=2;
	for(int i=1;i<=25;i++){
		for(int j=1;j<=25;j++){
			if(arr[i][j]==1)cout<<"¢i";
			else cout<<"  ";
	}
	cout<<endl;
	}
}
}







