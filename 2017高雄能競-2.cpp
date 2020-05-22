#include<iostream>
#include<cmath>
using namespace std;
long long int dis(long long int a,long long int b){
	return abs(a-b);
}
int main(){
	long long int bx,by,cx,cy,dx,dy;
	cin>>bx>>by>>cx>>cy>>dx>>dy;
	long long int d=99999999999;
	if(d>dis(bx,cx)+dis(by,cy))d=dis(bx,cx)+dis(by,cy);
	if(d>dis(bx,cx)+dis(by,dy))d=dis(bx,cx)+dis(by,dy);
	if(d>dis(bx,dx)+dis(by,cy))d=dis(bx,dx)+dis(by,cy);
	if(d>dis(bx,dx)+dis(by,dy))d=dis(bx,dx)+dis(by,dy);
	if(bx<max(cx,dx)&&bx>min(dx,cx))d=min(dis(by,cy),dis(by,dy));
	if(by<max(cy,dy)&&by>min(dy,cy))d=min(dis(bx,cx),dis(bx,dx));
	cout<<d;
} 
