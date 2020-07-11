#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
struct line{
	int arr,tim;
}cs[101];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>cs[i].arr>>cs[i].tim;
	int ans=1,time=cs[1].arr,idx=1;
	q.push(idx);
	while(idx+1<=n){
		if(q.empty()){
			time=cs[++idx].arr;
			q.push(idx);
			if(q.size()>ans)
				ans=q.size();
		}
		else if(time+cs[q.front()].tim>cs[idx+1].arr){
			q.push(++idx);
			if(q.size()>ans)
				ans=q.size();
		}
		else if(time+cs[q.front()].tim==cs[idx+1].arr){
			time=cs[++idx].arr;
			q.pop();
			q.push(idx);
		}
		else{
			time=cs[q.front()].tim+time;
			q.pop();
		}
	}
	cout<<ans-1<<endl;
}