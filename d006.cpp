#include<iostream>
#include<cmath>
using namespace std;
string at="acute triangle";
string rt="right triangle";
string ot="obtuse triangle";
string no="無法形成三角形";
void judge(int a,int b,int c){
	if(a>=b+c)cout<<no;
	else if(pow(a,2)==pow(b,2)+pow(c,2)) cout<<rt;
	else if(pow(a,2)>pow(b,2)+pow(c,2)) cout<<ot;
	else cout<<at;
}
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int x,y,z;
	x=max(a,max(b,c));
	if(x==a){
		y=b;
		z=c;
	}
	else if(x==b){
		y=a;
		z=c;
	}
	else {
		y=b;
		z=a;
	}
	judge(x,y,z);
}
