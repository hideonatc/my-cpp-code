#include<iostream>
#include<set>
#include<map>
using namespace std;
map<string,map<string,int > > m;
string place[1002];
map<string ,map<int,string> >animal;
int p_idx=0;
string ani,pla;
bool chk(string str,int arg){
	int a_idx=1;
	while(animal[pla][a_idx]!="")
		a_idx=a_idx+1;
	if(arg==0&&p_idx==0){
		place[++p_idx]=str;
		return 0;
	}
	if(arg==1&&a_idx==1){
		animal[pla][a_idx]=str;
		return 0;
	}
	if(arg==0){
		for(int i=1;i<=p_idx;i++)
			if(str==place[i])
				return 1;
		place[++p_idx]=str;
	}
	if(arg==1){
		for(int i=1;i<a_idx;i++)
			if(str==animal[pla][i])
				return 1;
		animal[pla][a_idx]=str;
	}
	return 0;
}
int main(){
	int n;
	cin>>n;
	int num;
	for(int i=1;i<=n;i++){
		cin>>ani>>num>>pla;
		bool a=chk(ani,1),b=chk(pla,0);
		if(a&&b){
			m[pla][ani]+=num;
		}
		else
			m[pla][ani]=num;
	}
	for(int i=1;i<=p_idx;i++){
		cout<<place[i]<<':';
		bool f=1;
		for(int j=1;animal[place[i]][j]!="";j++){
			if(f){
				cout<<animal[place[i]][j]<<" "<<m[place[i]][animal[place[i]][j]];
				f=0;
			}
			else
				cout<<','<<animal[place[i]][j]<<" "<<m[place[i]][animal[place[i]][j]];
		}
		cout<<endl;
	}
}