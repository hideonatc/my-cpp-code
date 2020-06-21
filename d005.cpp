#include<iostream>
#include<queue>
using namespace std;
void print_C(int r){
	if(r==1)
		cout<<"一";
	else if(r==2)
		cout<<"二";
	else if(r==3)
		cout<<"三";
	else if(r==4)
		cout<<"四";
	else if(r==5)
		cout<<"五";
	else if(r==6)
		cout<<"六";
	else if(r==7)
		cout<<"七";
	else if(r==8)
		cout<<"八";
	else if(r==9)
		cout<<"九";
	else if(r==10)
		cout<<"十";
}
int main(){
	int k;
	cin>>k;
	for(int r=1;r<=k;r++){
		int tree[99999]={0};
		int ans=-9999999;
		queue<char> q;
		queue<char> test;
		test.push('(');
		test.push(')');
		test.push('(');
		test.push(')');
		string in;
		int up=0,down=0;
		int idx=0;
		while(up!=down||up==0){
			cin>>in;
			for(int i=0;i<in.length();i++){
				if(q.size()>=4)
					q.pop();
				q.push(in[i]);
				if(in[i]=='('){
					up++;
					idx++;
				}
				else if(in[i]==')'){
					down++;
					idx--;
				}
				else{
					int a=int(in[i]-'0');
					while(i+1<in.length()){
						if(isdigit(in[i+1])){
							int b=int(in[i+1]-'0');
							a=a*10+b;
							i++;
						}
						else
							break;
					}
					tree[idx]=tree[idx-1]+a;
					//printf("tree[%d]=%d\n",idx,tree[idx]);
				}
				if(q==test){
					if(ans<tree[idx])
						ans=tree[idx];
					//cout<<"end"<<endl;
				}
			}
		}
		cout<<"第";
		print_C(r);
		printf("棵二元樹最長路徑長度：%d\n",ans);
	}
}