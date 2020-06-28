#include<iostream>
#include<cmath>
#define PI 3.14159265358979323846264
using namespace std;
struct dot{
	double x;
	double y;
	double v;
	double ang;
}data[9999];
int main(){
	int k=1;
	int r;
	cin>>r;
	while(cin>>data[k].x>>data[k].y>>data[k].v>>data[k].ang){
		if(cin.fail())
			break;
		k++;
	}
	for(int i=1;i<=k-1;i++){
		for(int j=i+1;j<=k-1;j++){
			if(data[i].v==data[j].v&&data[i].ang==data[j].ang){
				printf("LET (i=%d, j=%d) = INF\n",i,j);
				continue;
			}
			double a,b,c,d;
			a = data[i].v*cos(data[i].ang*PI/180)-data[j].v*cos(data[j].ang*PI/180);
			b = data[i].x-data[j].x;
			c = data[i].v*sin(data[i].ang*PI/180)-data[j].v*sin(data[j].ang*PI/180);
			//cout<<"c="<<c<<endl;
			d = data[i].y-data[j].y;
			double let=(sqrt((a*a+c*c)*(r*r)-(a*d-b*c)*(a*d-b*c))-(a*b+c*d))/(a*a+c*c);
			printf("LET (i=%d, j=%d) = %.4lf\n",i,j,let);
		}
	}
}