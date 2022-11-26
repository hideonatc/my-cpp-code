#include<iostream>
#include<set>
#include<map>
using namespace std;
map <char , set <char> > firstSet;
map <char , set <string> > grammar;
void split(char idx, string s){
	string tmp = "";
	for(int i=0;i<s.length();){
		if(islower(s[i])||s[i]=='$'){
			tmp += s[i];
			while(i<s.length()&&s[++i]!='|')
			grammar[idx].insert(tmp);
		}
		else if(isupper(s[i])||s[i]==';'){
			tmp += s[i++];
		}
		else if(s[i++]=='|'){
			grammar[idx].insert(tmp);
			tmp = "";
		}
	}
	if(tmp!="")
		grammar[idx].insert(tmp);
	return;
}
bool sep = false;
void getFirstSet(char c,char tar){
	bool this_sep = false;
	for(set<string>::iterator i = grammar[c].begin(); i!= grammar[c].end();i++){
		for(int j=0;j<(*i).length();j++){
			if(islower((*i)[j])||(*i)[j]=='$'){
				if(!this_sep)
					sep = false;
				firstSet[tar].insert((*i)[j]);
				break;
			}
			else if(isupper((*i)[j])){
				getFirstSet((*i)[j],tar);
				if(!sep){
					sep = false;
					break;
				}
			}
			else if((*i)[j]==';'){
				sep = true;
				this_sep = true;
				break;
			}
		}
		this_sep = sep;
		if(sep&&c==tar){
			sep = false;
			firstSet[tar].insert(';');
		}
	}
	return;
}
int main(){
	string s;
	while(cin>>s){
		if(s=="END_OF_GRAMMAR")
			break;
		char idx = s[0];
		cin>>s;
		split(idx,s);
	}
	for(map<char , set<string> >::iterator i = grammar.begin(); i != grammar.end();i++){
		getFirstSet(i->first,i->first);
	}
	for(map<char , set<char> >::iterator i = firstSet.begin(); i != firstSet.end();i++){
		cout<<i->first<<" ";
		for(set<char>::iterator j = i->second.begin(); j != i->second.end();j++)
			cout<<*j;
		cout<<endl;
	}
	cout<<"END_OF_FIRST\n";
}