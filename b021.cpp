#include<iostream>
#include<map>
using namespace std;
map< int,int,greater<int> > score[501];
int main(){
	int n;
	cin>>n;
	for(int j=1;j<=n;j++){
		int s=0,m,k;
		cin>>k;
		for(int i=1;i<=5;i++){
			int t;
			cin>>t;
			s+=t;
			if(i==3)
				m=t;
		}
		score[s][m]=k;
	}
	for(int i=500;i>=0;i--){
		if(!score[i].empty()){
			for(map<int,int>::iterator it=score[i].begin();it!=score[i].end();it++)
				cout<<it->second<<endl;
		}
		else
			continue;
	}
}