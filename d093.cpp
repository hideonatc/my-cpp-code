#include<iostream>
#include<bitset>
using namespace std;
struct T{
	int b,tm;
}dt[600];
int main(){
	string s;
	int t;
	cin>>t;
	getline(cin,s);
	while(t--){
		getline(cin,s);
		int idx=1;
		bool h_ans=1;
		for(int i=0;i<s.length();){
			int num=1;
			if(s[i]!='0'&&s[i]!='1'){
				h_ans=0;
				break;
			}
			while(i<s.length()&&s[i]==s[i+1]&&num<7){
				num++;
				i++;
			}
			dt[idx].b=s[i];
			dt[idx++].tm=num;
			i++;
		}
		if(!h_ans)
			cout<<"-1"<<endl;
		else{
			for(int i=1;i<idx;i++){
				cout<<dt[i].b-48;
				std::bitset<3>y(dt[i].tm);
				cout<<y<<" ";
			}
			cout<<int((((double)(idx-1)*4)/(double)s.length())*100+0.5)<<endl;
		}
	}
}
/*
1 
00010000000111111101111111*/