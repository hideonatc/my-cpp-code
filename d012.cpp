#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	struct dot{
		char name;
		float x;
		float y;
		int b;
	}m[99999];
	for(int i=0;i<n;i++){
		cin>>m[i].name>>m[i].x>>m[i].y;
	}
	for(int i=0;i<n;i++){
		m[i].b=0;
			for(int j=0;j<n;j++){
		if(m[i].x>m[j].x&&m[i].y>m[j].y)m[i].b++;
		}
		printf("%c %d\n",m[i].name,m[i].b);
	}
}
