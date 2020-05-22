#include<iostream>
using namespace std;
int main(){
	int a,b;
	int i=1;
	char k[99999];
	int r[99999],s,e;
	bool flag=true,end=false,ok=false;
	cin>>a>>b;
	while(1){
		if(flag){
			cout<<a/b<<'.';
			flag=false;
			a=a%b;
			continue;
		}
		if(!flag){
			a*=10;
			r[i]=a;
		}
		for(int f=1;f<i;f++){
			if(r[f]==r[i]){
				s=f;
				end=true;
				break;
			}
		}
		if(end)break;
		if(!flag)k[i]=char((a/b)+48);
		a=a%b;
		if(a==0){
			ok=true;
			break;
		}
		i++;
	}
	if(ok)i++;
	for(int j=1;j<i;j++)cout<<k[j];
	if(end){
		cout<<" (";
		for(int j=s;j<i;j++)cout<<k[j];
		cout<<"´`Àô)";
	}
}
