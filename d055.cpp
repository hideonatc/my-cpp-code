#include<iostream>
using namespace std;
int n;
struct dot{
	double x;
	double y;
}d[11];
dot cen(int a,int b,int c){
	double dt=2*(d[a].x-d[b].x)*(d[c].y-d[b].y)-2*(d[a].y-d[b].y)*(d[c].x-d[b].x);
	double dtx=(d[c].y-d[b].y)*(d[a].x*d[a].x+d[a].y*d[a].y-d[b].x*d[b].x-d[b].y*d[b].y)-(d[a].y-d[b].y)*(d[c].x*d[c].x+d[c].y*d[c].y-d[b].x*d[b].x-d[b].y*d[b].y);
	double dty=(d[a].x-d[b].x)*(d[c].x*d[c].x+d[c].y*d[c].y-d[b].x*d[b].x-d[b].y*d[b].y)-(d[c].x-d[b].x)*(d[a].x*d[a].x+d[a].y*d[a].y-d[b].x*d[b].x-d[b].y*d[b].y);
	dot r;
	r.x=dtx/dt;
	r.y=dty/dt;
	return r;
}
int solve(int a,int b,int c){
	int in=3;
	dot ct=cen(a,b,c);
	double r=(ct.x-d[a].x)*(ct.x-d[a].x)+(ct.y-d[a].y)*(ct.y-d[a].y);
	for(int i=1;i<=n;i++){
		if(i==a||i==b||i==c)
			continue;
		double ri=(ct.x-d[i].x)*(ct.x-d[i].x)+(ct.y-d[i].y)*(ct.y-d[i].y);
		if(ri<=r+0.00000000001)
			in++;
	}
	return in;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>d[i].x>>d[i].y;
	int t=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				t++;
				ans+=solve(i,j,k);
				//printf("solve(%d,%d,%d)=%d\n",i,j,k,solve(i,j,k));
			}
		}
	}
	//printf("ans=%d t=%d\n",ans,t);
	double as=(double)ans/(double)t;
	printf("%.6f\n",as);
}