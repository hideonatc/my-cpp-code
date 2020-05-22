#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	bool end=false;
	int i=0,j=0;
	for(i=0;7*i<=n;i++){
		for(j=0;7*i+11*j<=n;j++){
			if(7*i+11*j==n){
				printf("Yes 7:%d 11:%d",i,j);
				end=1;
				break;
			}
		}
		if(end)break;
	}
	if(!end)cout<<"No";
}
