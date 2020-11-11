#include<iostream>
using namespace std;
int main(){
	int l,w;
	cin>>l>>w;
	int a=min(l,w);
	while(!(l%a==0&&w%a==0))
		a--;
	printf("A=%d, D=%d\n",a,(l*w)/(a*a));
}