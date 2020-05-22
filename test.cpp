#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int r(char c){
	if(c=='I')return 1;
	else if(c=='V')return 5;
	else if(c=='X')return 10;
	else if(c=='L')return 50;
	else if(c=='C')return 100;
	else if(c=='D')return 500;
	else return 1000;
}
int main(){
	string input;
	int last,s=0;
	cin>>input;
	int l = input.length();
	last = r(input[l-1]);
	s+=last;
	for(int i = l-2;i>=0;i--){
		if(last <= r(input[i])){
			s+=r(input[i]);
			last = r(input[i]);
		}
		else if(last > r(input[i])){
			s-=r(input[i]);
			last = r(input[i]);
		}
		cout<<s<<endl;
	}
	cout<<s;
}
