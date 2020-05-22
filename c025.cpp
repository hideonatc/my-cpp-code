#include<iostream>
using namespace std;
int main(){
	string a,s;
	cin>>a>>s;
	int len=a.length();
	int score=0,com=0,max_com=0,spir=0;
	int k=0;
	while(k<len){
		if(a[k]==s[k]&&a[k]!='-'){
			com++;
			score+=100*com;
			spir++;
			if(com>max_com)max_com=com;
		}
		else if(a[k]!=s[k]&&a[k]!='-'){
			if(com>max_com)max_com=com;
			com=0;
			spir-=3;
			if(spir<0)spir=0;
		}
		k++;
	}
	printf("%d %d %d",score,max_com,spir);
}
