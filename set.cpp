#include<set>
#include<iostream>
using namespace std;
int main(){
	set<int> s;
	s.insert(1);
	s.insert(5);
	s.insert(3);
	s.erase(1);
	for(set<int>::iterator it = s.begin(); it != s.end();it++){
		cout<<*it<<" ";		
	}
}
