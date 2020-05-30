#include<iostream>
#include<set>
using namespace std;
int main(){
	set<string> s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string name;
		cin>>name;
		s.insert(name);
	}
	for(set<string>::iterator it=s.begin();it!=s.end();it++){
		cout<<*it<<endl;
	}
}