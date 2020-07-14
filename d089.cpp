#include<iostream>
using namespace std;
int price[16];
double m(int d,int a){
	double sum=0;
	for(int i=a;i>a-d;i--)
		sum+=price[i];
	return sum/d;
}
char solve(int a){
	double m5=m(5,a),m10=m(10,a);
	//cout<<m5<<" "<<m10<<endl;
	if(m5>m(5,a-1)&&m10>m(10,a-1)&&price[a]<1.2*m10&&price[a]>m5&&m5>m10)
		return 'B';
	if(price[a]>1.2*m10||(price[a]<m5&&m5<m10)||m10<m(10,a-1))
		return 'S';
	return 'N';
}
int main(){
	for(int i=1;i<=15;i++)
		cin>>price[i];
	for(int i=11;i<=15;i++)
		cout<<price[i]<<solve(i)<<" ";
	cout<<endl;
}