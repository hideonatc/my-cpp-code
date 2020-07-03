#include<iostream>
#include<map>
using namespace std;
int main(){
	map<int ,string> m;
	int a,b,c;
	cin>>a>>b>>c;
	m[a]="甲";
	m[b]="乙";
	m[c]="丙";
	map<int ,string>::iterator it=m.begin();
	int n=it->first;
	it++;
	n+=it->first;
	if(n>a+b+c-n)
		cout<<it->second<<endl;
	else{
		it++;
		cout<<it->second<<endl;
	}
}