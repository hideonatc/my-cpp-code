#include<iostream>
using namespace std;
int n,mxl=-1;
bool used[100]={0};
string in[100];
string ans[11][100],ans_fn[100];
int idx_ans=1,id_ans=1;
bool judge(int idx){
	if(!used[idx]&&ans_fn[id_ans-1][9]==in[idx][0]&&ans_fn[id_ans-1][10]==in[idx][1]&&ans_fn[id_ans-1][11]==in[idx][2])
		return 1;
	return 0;
}
void bt(int l){
	if(l==0){
		for(int i=1;i<=n;i++){
			used[i]=1;
			ans_fn[id_ans++]=in[i];
			bt(l+1);
			used[i]=0;
			id_ans--;
		}
		return;
	}
	if(l>=mxl){
		if(l>mxl){
			mxl=l;
			idx_ans=1;
		}
		for(int i=1;i<=l;i++)
			ans[idx_ans][i]=ans_fn[i];
		idx_ans++;
	}
	for(int i=1;i<=n;i++){
		if(judge(i)){
			used[i]=1;
			ans_fn[id_ans++]=in[i];
			bt(l+1);
			used[i]=0;
			id_ans--;
		}
	}
}
void print(){
	cout<<mxl<<endl;
	for(int i=1;i<idx_ans;i++){
		bool fir=1;
		for(int j=1;j<=mxl;j++){
			if(fir){
				fir=0;
				cout<<ans[i][j];
			}
			else
				cout<<"→"<<ans[i][j];
		}
		cout<<endl;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>in[i];
	bt(0);
	print();
}