#include<iostream>
#include<cmath>
#define pi 3.14159265358979323846264
using namespace std;
int main(){
	double l,a1,a2;
	cin>>l>>a1>>a2;
	double d=sin(a1*pi/180)*sin(a2*pi/180)/sin((a1+a2)*pi/180);
	printf("%.2f\n",d*l);
}
/*
17.6 40 70
31.4 15.9 26.5
*/