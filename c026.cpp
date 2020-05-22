#include<iostream>
using namespace std;
int main(){
	int n,p;
	cin>>n>>p;
	int k=(n/100)*10;
	if(k<=p){
		n-=k;
		p-=k;
		p+=n/100;
	}
	else {
		n-=(p/10)*10;
		p-=(p/10)*10;
		p+=n/100;
	}
	cout<<n<<" "<<p; 
} 
