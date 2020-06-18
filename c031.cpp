#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int> q;
	int n,p;
	cin>>n>>p;
	for(int i=1;i<=n;i++)
		q.push(i);
	int t=1,ans;
	while(!q.empty()){
		if(t==p){
			ans=q.front();
			q.pop();
			t=1;
		}
		else{
			ans=q.front();
			q.pop();
			q.push(ans);
			t++;
		}
	}
	cout<<ans<<endl;
}