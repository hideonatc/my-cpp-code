#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int m=1;
	int p,l=-1;
	while(m<=n){
		int x,y;
		cin>>x>>y;
		if(x*x+y*y>l){
			p=m;
			l=x*x+y*y;
		}
		m++;
	}
	printf("%d %d",p,l);
}
