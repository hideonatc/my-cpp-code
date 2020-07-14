#include<iostream>
using namespace std;
int used[4][12]={0},h_ans=0;
int ans[4][12],n;
int mv[9][2]={{0,0},{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
bool can_move(int x,int y,int arg){
	if(x+mv[arg][0]>0&&x+mv[arg][0]<=3&&y+mv[arg][1]>0&&y+mv[arg][1]<=n)
		if(!used[x+mv[arg][0]][y+mv[arg][1]])
			return 1;
	return 0;
}
bool rep_ans(){
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++){
			if(ans[i][j]>used[i][j])
				return 1;
			else if(ans[i][j]<used[i][j])
				return 0;
		}
	return 0;
}
void bt(int idx,int x,int y){
	if(idx==3*n){
		h_ans=1;
		if(rep_ans())
			for(int i=1;i<=3;i++)
				for(int j=1;j<=n;j++)
					ans[i][j]=used[i][j];
		return;
	}
	else{
		for(int i=1;i<=8;i++){
			if(can_move(x,y,i)){
				used[x+mv[i][0]][y+mv[i][1]]=idx+1;
				bt(idx+1,x+mv[i][0],y+mv[i][1]);
				used[x+mv[i][0]][y+mv[i][1]]=0;
			}
		}
	}
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++)
			ans[i][j]=99999;
	used[1][1]=1;
	bt(1,1,1);
	if(h_ans)
		for(int i=1;i<=3;i++)
			for(int j=1;j<=n;j++)
				cout<<ans[i][j]<<" ";
	else
		cout<<"0";
	cout<<endl;
}