#include<iostream>
#include<stack>
using namespace std;
stack<int> tower[4];
stack<int> b_tower[4];
void move(int t,int f,int c){
	int r=6-f-c;
	if(t==1){
		tower[f].pop();
		tower[c].push(1);
		printf("Ring 1 from %d to %d\n",f,c);
	}
	else{
		move(t-1,f,r);
		if(tower[f].top()==t&&tower[r].top()==1){
			tower[f].pop();
			tower[c].push(t);
			printf("Ring %d from %d to %d\n",t,f,c);
			move(t-1,r,c);
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=n;i>0;i--)
		tower[1].push(i);
	move(n,1,3);
}