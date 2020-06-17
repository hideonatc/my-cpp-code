#include<iostream>
using namespace std;
int map[13][13]={0};
bool used_x[13]={0};
bool used_y[13]={0};
int ans[13];
bool fire(int x,int y,int a){
	if(used_x[x])
		return false;
	if(used_y[y])
		return false;
	for(int i=x+1,j=y+1;i<=a&&j<=a;i++,j++)
		if(map[i][j])
			return false;
	for(int i=x-1,j=y-1;i>=0&&j>=0;i--,j--)
		if(map[i][j])
			return false;
	for(int i=x-1,j=y+1;i>=0&&j<=a;i--,j++)
		if(map[i][j])
			return false;
	for(int i=x+1,j=y-1;i<=a&&j>=0;i++,j--)
		if(map[i][j])
			return false;
	used_x[x]=true;
	used_y[y]=true;
	return true;
}
void bt(int a,int n){
	if(n==a+1){
		for(int i=1;i<=a;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	else{
		bool f=false;
		for(int i=1;i<=a;i++){
			if(fire(n,i,a)){
				f=true;
				map[n][i]=1;
				ans[n]=i;
				//printf("map[%d][%d]=true,call bt(%d,%d)\n",n,i,a,n+1);
				bt(a,n+1);
				used_x[n]=0;
				used_y[i]=0;
				map[n][i]=0;
			}
		}
		if(!f){
			return;
		}
	}
}
int main(){
	int n;
	cin>>n;
	bt(n,1);
}