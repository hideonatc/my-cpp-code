#include<iostream>
using namespace std;
int gint(){
	int x;
	cin>>x;
	return x;
}
int main(){
	int n=gint();
	int min=99999,max=-1;
	while(n--){
		int nu=gint();
		if(nu<min)min=nu;
		if(nu>max)max=nu;
	}
	cout<<max-min;
}
