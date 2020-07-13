#include<iostream>
#include<map>
using namespace std;
struct gd{
	int num,pri;
};
int main(){
	string s;
	map<string,gd>m; 
	while(cin>>s){
		if(s[0]=='0')
			break;
		int price,nm;
		cin>>price>>nm;
		if(m.count(s))
			m[s].num+=nm;
		else{
			m[s].num=nm;
			m[s].pri=price;
		}
	}
	double sum=0;
	for(map<string,gd>::iterator it=m.begin();it!=m.end();it++){
		if(it->first[0]=='X')
			sum+=it->second.pri*((it->second.num-it->second.num%2)/2+(it->second.num%2));
		else if(it->first[0]=='Y')
			sum+=it->second.pri*(0.75*(it->second.num-it->second.num%2)+(it->second.num%2));
		else
			sum+=it->second.pri*it->second.num;
	}
	cout<<sum<<endl;
}