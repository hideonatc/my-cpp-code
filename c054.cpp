#include<iostream>
using namespace std;
int vec_tab[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
int main(){
	int ip,x=50,y=50,v=0;
	while(cin>>ip){
		if(ip==0){
			printf("(%d,%d)\n",x,y);
			break;
		}
		if(ip<0){
			if(ip==-1)
				v=(v+3)%4;
			else if(ip==-2)
				v=(v+1)%4;
			else if(ip==-3)
				v=(v+2)%4;
		}
		else{
			x+=vec_tab[v][0]*ip;
			y+=vec_tab[v][1]*ip;
			if(x<0)x=0;
			if(x>100)x=100;
			if(y<0)y=0;
			if(y>100)y=100;
		}
		//printf("(%d,%d)\n",x,y);
	}
}