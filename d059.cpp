#include<iostream>
#include<queue>
using namespace std;
bool isprime(int n){
	if(n==2)
		return 1;
	if(n<2)
		return 0;
	for(int i=2;i<=n/2;i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main(){
	int s,e;
	bool first=1;
	cin>>s>>e;
	queue<bool> q;
	for(int i=s;i<s+4;i++)
		q.push(isprime(i));
	int ans=0;
	for(int i=s+4;i<=e;i++){
		bool f=isprime(i);
		if(f&&q.front()){
			ans++;
			if(first){
				first=0;
				printf("(%d,%d)",i-4,i);
			}
			else
				printf(",(%d,%d)",i-4,i);
		}
		q.pop();
		q.push(f);
	}
	printf("\n共%d組\n",ans);
}