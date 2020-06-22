#include<iostream>
#include<vector>
using namespace std;
bool map[27][27]={0};
vector<int> v;
bool has_ans=false;
void solve(int s,int e){
	if(v.front()==v.back()){
		if(!has_ans){
			printf("存在迴圈\n");
			has_ans=true;
		}
		v.pop_back();
		for(vector<int>::iterator it=v.begin();it!=v.end();it++)
			cout<<char(*it+int('A'))<<" ";
		cout<<endl;
		v.clear();
		return;
	}
	else{
		if(e>26)
			return;
		if(s!=e&&map[s][e]){
			v.push_back(e);
			solve(e,1);
		}
		solve(s,e+1);
	}
}
int main(){
	char a,b;
	int n;
	cin>>n;
	while(n--){
		/*if(cin.fail())
			break;*/
		cin>>a>>b;
		map[int(a-'A')][int(b-'A')]=1;
	}
	printf("here");
	solve(1,1);
	if(!has_ans)
		printf("不存在迴圈\n");
}