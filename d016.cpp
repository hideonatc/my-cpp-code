#include<iostream>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	if(x>0&&y>0)printf("(%d,%d)�b�Ĥ@�H��",x,y);
	else if(x<0&&y>0)printf("(%d,%d)�b�ĤG�H��",x,y);
	else if(x<0&&y<0)printf("(%d,%d)�b�ĤT�H��",x,y);
	else if(x>0&&y<0)printf("(%d,%d)�b�ĥ|�H��",x,y);
	else if(x==0&&y!=0)printf("(%d,%d)�bY�b",x,y);
	else if(x!=0&&y==0)printf("(%d,%d)�bX�b",x,y);
	else printf("(%d,%d)�b���I",x,y);
}
