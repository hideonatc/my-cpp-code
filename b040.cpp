#include<iostream>
#include<set>
using namespace std;
int item[21]; //物品價錢
int ans[21];
bool used[21],out=false; //out：是否有答案
set<set <int> > u_ans; //紀錄輸出過的組合
void bt(int a,int b,int p,int t){ //回溯法 a：幾樣物品 b：要達成的價錢 p：累積價格 t：累積物品數
	cout<<"bt"<<endl;
	if(p==b){ //達成目標價錢
		set<int> s; //確認是否已有同樣物品 不同排序的答案
		for(int i=0;i<t;i++)
			s.insert(ans[i]);
		if(u_ans.find(s)!=u_ans.end()) //有
			return; 
		u_ans.insert(s); //沒有 將這組答案加入集合中
		out=true; //有至少一組答案
		for(int i=0;i<t;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
		return;
	}
	else{
		bool bl=false; //紀錄是否要回溯
		for(int i=1;i<=a;i++){
			if((p+item[i]<=b)&&(used[i]==0)){ //累積價錢+此物品價值不超過目標價錢且此物品沒被用過
				used[i]=true; //將此物品設為用過
				bl=true; //不須回溯
				ans[t]=item[i];
				bt(a,b,p+item[i],t+1); //將此物品加入答案並繼續
				used[i]=false; //回溯回來後將此物品設為沒用過
			}
		}
		if(!bl){
			return; //for迴圈結束 沒有符合答案 回溯
		}
	}
}
int main(){
	int n,m;
	int w=0;
	cin>>n>>m; //n：物品數 m：目標價錢
	for(int i=1;i<=n;i++){
		cin>>item[i];
		w+=item[i];
	}
	for(int i=1;i<=n;i++)
		used[i]=0;
	if(w>=m)
		bt(n,m,0,0); //從價錢0 物品數0開始
	if(!out) //沒有任何一組合理答案 輸出NO
		cout<<"NO"<<endl;
}
/*
20 100000000
12102014 6365927 4574888 19249272 11794313 9967753 17874324 12928450 7586884 689693 429058 16218345 8988232 15296533 15653127 868523 663110 17919643 1199116 15775930
*/