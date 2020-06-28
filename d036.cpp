#include<iostream>
using namespace std;
int main(){
	int mn=1e9,mx=-9999999;
	float ans=0;
	for(int i=1;i<=5;i++){
		int c;
		cin>>c;
		if(c>mx)
			mx=c;
		if(c<mn)
			mn=c;
		ans+=c;
	}
	printf("%.2f\n",(ans-mn-mx)/3+0.005);
}