//unfinished
#include<iostream>
using namespace std;
int dis(int a,int b,int c,int d){
	return (a-c)*(a-c)+(b-d)*(b-d);
}
int main(){
	int x1,y1,x2,y2;
	int n;
	cin>>n;
	while(n--){
		cin>>x1>>y1>>x2>>y2;
		int mx1=0,mx2=0;
		int m;
		cin>>m;
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			if(dis(x1,y1,x,y)>mx1&&dis(x2,y2,x,y)>mx2){
				if(dis(x1,y1,x,y)>dis(x2,y2,x,y)){
					mx2=dis(x2,y2,x,y);
				}
				else{
					mx1=dis(x1,y1,x,y);
				}
			}
		}
		cout<<mx1+mx2<<endl;
	}
}
/* test data
5
2 0 10 0
3
-3 3
10 0
5 3
3 4 -7 -8
7
1 -2
-2 -7
-7 -9
3 -7
-4 11
2 -7
4 7
-5 0 2 0
6
-2 4
-1 2
-5 0
2 0
0 0
2 -2
-4 3 10 -11
7
-4 3
-3 3
-3 3
3 -4
2 -3
13 0
0 10
1 0 -1 3
9
-1 3
-3 1
5 0
2 9
1 0
1 1
1 0
2 9
2 -4
*/