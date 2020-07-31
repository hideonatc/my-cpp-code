#include<iostream>
using namespace std;
int getint(){
	int x;
	cin>>x;
	return x;
}
int main(){
	int a,b;
	while(cin>>a>>b){
		if(cin.fail())
			break;
		int n=max(a,b);
		int wrong=0,ans=0;
		for(int i=1;i<=30;i++){
			int m=getint();
			if(!m)
				continue;
			if(m==n&&wrong<3)
				ans=1;
			else
				wrong++;
		}
		if(ans)
			cout<<'Y'<<endl;
		else
			cout<<'N'<<endl;
	}
}