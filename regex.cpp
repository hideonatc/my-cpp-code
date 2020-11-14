#include<iostream>
#include<regex>
using namespace std;
int main(){
	string s="A1B2C10";
	smatch m;
	regex e ("[A-Z]");
	cout<<regex_search(s,m,e);
}