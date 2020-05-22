#include<iostream>
using namespace std;
int m[99][99],backup[99][99];
void rev(int n,int max){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			m[i][j]=max-m[i][j];
		}
	}
}
void find_zero(int r[],int n,int k){
	for(int i=0;i<n;i++){
		if(m[k][i]==0)r[k]++;
	}
}
int less_zero(int r[],int n){
	int min=1<<10,pos;
	for(int i=0;i<n;i++){
		if(r[i]<0)continue;
		else if(r[i]<min){
			min=r[i];
			pos=i;
		}
	}
	r[pos]=-1;
	return pos;
}
int cross_zero(int pos,int n){
	int r,l;
	for(int i=0;i<n;i++){
		if(m[pos][i]==0){
			r=backup[pos][i];
			l=i;
			break;
		}
	}
	for(int i=0;i<n;i++)
		if(m[pos][i]==0)
			m[pos][i]=1;
	for(int i=0;i<n;i++)
		if(m[i][l]==0)
			m[i][l]=1;
	return r;
}
int max_in_raw(int n){
	int ans=0;
	for(int i=0;i<n;i++){
		int max=-1;
		for(int j=0;j<n;j++){
			if(backup[i][j]>max)max=backup[i][j];
		}
		ans+=max;
	}
	return ans;
}
int max_in_column(int n){
	int ans=0;
	for(int j=0;j<n;j++){
		int max=-1;
		for(int i=0;i<n;i++){
			if(backup[i][j]>max)max=backup[i][j];
		}
		ans+=max;
	}
	return ans;
}
int main(){
	int o;
	cin>>o;
	for(int q=1;q<=o;q++){
	int zero_in_row[99]={0};
	int n,ans=0,max=-1;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>m[i][j];
			backup[i][j]=m[i][j];
			if(m[i][j]>max)max=m[i][j];
		}
	}
	rev(n,max);
	for(int i=0;i<n;i++){
		int min=1<<10;
		for(int j=0;j<n;j++){
			if(min>m[i][j])
				min=m[i][j];
		}
		for(int j=0;j<n;j++)m[i][j]-=min;
	}
	for(int j=0;j<n;j++){
		int min=1<<10;
		for(int i=0;i<n;i++){
			if(min>m[i][j])
				min=m[i][j];
		}
		for(int i=0;i<n;i++)m[i][j]-=min;
	}
	for(int i=0;i<n;i++)
		find_zero(zero_in_row,n,i);
	for(int i=0;i<n;i++){
		ans+=cross_zero(less_zero(zero_in_row,n),n);
	}
	printf("第%d組測試資料結果\n",q);
	printf("(1) 讓所有先生都最滿意的「速配程度」總分為%d分\n",max_in_raw(n));
	printf("(2) 讓所有小姐都最滿意的「速配程度」總分為%d分\n",max_in_column(n));
	printf("(3) 完滿結局最高「速配程度」總分為%d分\n",ans);
}
}
