#include<iostream>
#include<map>
#include<set>
using namespace std;
map<char,int> m;
set<set<char> >ans;
set<char>ans_fn;
char s_ans[27];
bool mp[27][27]={0};
int h_ans=0;
bool vis[27]={0};
int t_idx=1,s_idx=1;
/*void print_ans(){
	cout<<"in set ans:"<<endl;
	for(set<set<char> >::iterator it=ans.begin();it!=ans.end();it++){
		for(set<char>::iterator ite= it->begin(); ite!= it->end();ite++){
			cout<<*ite<<" ";
		}
		cout<<endl;
	}
}
void print_ans_fn(){
	cout<<"in set ans_fn:"<<endl;
	for(set<char>::iterator it= ans_fn.begin(); it!= ans_fn.end();it++)
		cout<<*it<<" ";
	cout<<endl;
}*/
void bt(int idx,char beg,char now){
	//printf("bt(%d,%c,%c)\n",idx,beg,now);
	if(idx==0){
		for(map<char,int>::iterator it=m.begin();it!=m.end();it++){
			if(!vis[it->second]){
				vis[it->second]=1;
				ans_fn.insert(it->first);
				s_ans[s_idx++]=it->first;
				bt(idx+1,it->first,it->first);
				s_idx--;
				ans_fn.erase(it->first);
				vis[it->second]=0;
			}
		}
		return;
	}
	if(idx!=1&&now==beg){
		/*print_ans();
		print_ans_fn();*/
		h_ans++;
		if(h_ans==1)
			cout<<"存在迴圈"<<endl;
		if(!ans.count(ans_fn)){
			ans.insert(ans_fn);
			for(int i=1;i<s_idx;i++)
				cout<<s_ans[i]<<" ";
			cout<<endl;
		}
		return;
	}
	else{
		for(map<char,int>::iterator it=m.begin();it!=m.end();it++){
			//printf("vis[%c]=%d  mp[%c][%c]=%d\n",it->first,vis[it->second],now,it->first,mp[m[now]][it->second]);
			if(beg==it->first&&mp[m[now]][it->second]==1){
				bt(idx+1,beg,beg);
			}
			else if(!vis[it->second]&&mp[m[now]][it->second]==1){
				vis[it->second]=1;
				ans_fn.insert(it->first);
				s_ans[s_idx++]=it->first;
				bt(idx+1,beg,it->first);
				vis[it->second]=0;
				s_idx--;
				ans_fn.erase(it->first);
			}
		}
	}
	return;
}
/*void print(){
	cout<<"* ";
	for(map<char,int>::iterator it=m.begin();it!=m.end();it++)
		cout<<it->first<<" ";
	cout<<endl;
	for(map<char,int>::iterator it=m.begin();it!=m.end();it++){
		cout<<it->first<<" ";
		for(int i=1;i<=m.size();i++)
			cout<<mp[it->second][i]<<" ";
		cout<<endl;
	}
}*/
int main(){
	char in_a,in_b;
	/*int t;
	cin>>t;*/
	while(cin>>in_a){
		if(cin.fail())
			break;
		cin>>in_b;
		if(!m.count(in_a))
			m[in_a]=t_idx++;
		if(!m.count(in_b))
			m[in_b]=t_idx++;
		mp[m[in_a]][m[in_b]]=1;
	}
	//print();
	bt(0,'0','0');
	if(!h_ans)
		cout<<"不存在迴圈"<<endl;
}