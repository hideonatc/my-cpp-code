#include<iostream>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	if(x>0&&y>0)printf("(%d,%d)在第一象限",x,y);
	else if(x<0&&y>0)printf("(%d,%d)在第二象限",x,y);
	else if(x<0&&y<0)printf("(%d,%d)在第三象限",x,y);
	else if(x>0&&y<0)printf("(%d,%d)在第四象限",x,y);
	else if(x==0&&y!=0)printf("(%d,%d)在Y軸",x,y);
	else if(x!=0&&y==0)printf("(%d,%d)在X軸",x,y);
	else printf("(%d,%d)在原點",x,y);
}
