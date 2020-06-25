#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int a2=a,c2=c;
	while(a2>=5&&c2>=2){
		a2-=5;
		c2-=2;
		b++;
	}
	printf("%d杯咖啡，%d盒巧克力，%d份蛋糕\n",a,b,c);
}