#include<iostream>
#include<stack>
using namespace std;
stack<int> s[4];
int ans=0;
int n,bn;
void mv(int d,int f,int t){
	int r=6-f-t;
	if(d==1){
		s[f].pop();
		s[t].push(1);
		ans++;
		printf("ring 1 : %c => %c\n",char(f-1+int('A')),char(t-1+int('A')));
	}
	else{
		mv(d-1,f,r);
		if(s[f].top()==d&&s[r].top()==1){
			s[f].pop();
			s[t].push(d);
			printf("ring %d : %c => %c\n",d,char(f-1+int('A')),char(t-1+int('A')));
			ans++;
		}
	}
}
void solve(){
	mv(n-1,1,2);
	s[1].pop();
	s[3].push(n);
	printf("ring %d : A => C\n",n);
	ans++;
	for(int i=n-1;i>=1;i--){
		if(i%2==0)
			mv(i-1,2,3);
		else
			mv(i-1,3,2);
	}
}
int main(){
	cin>>n;
	bn=n;
	for(int i=n;i>=1;i--)
		s[1].push(i);
	solve();
	printf("共需%d個步驟\n",ans);
}