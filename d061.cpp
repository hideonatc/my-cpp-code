#include<iostream>
#include<set>
using namespace std;
string s;
int ans;
string ss[90];
int num=0;
string to_string(int b,int e){
	string st="";
	for(int i=b;i<=e;i++)
		st+=s[i];
	return st;
}
void type_a(int idx){
	int l=3;
	int k=2;
	while(idx-k>=0&&idx+k<s.length()){
		if(s[idx+k]==s[idx-k]){
			k++;
			l+=2;
		}
		else{
			k--;
			break;
		}
	}
	if(idx-k<0||idx+k>=s.length())
		k--;
	if(l>ans){
		ans=l;
		num=0;
		ss[num++]=to_string(idx-k,idx+k);
	}
	else if(l==ans){
		bool flag=1;
		for(int i=0;i<=num;i++){
			if(ss[i]==to_string(idx-k,idx+k))
				flag=0;
		}
		if(flag)
			ss[num++]=to_string(idx-k,idx+k);
	}
}
void type_b(int idx){
	int l=2;
	int k=1;
	while(idx-k>=0&&idx+k+1<s.length()){
		if(s[idx-k]==s[idx+k+1]){
			k++;
			l+=2;
		}
		else{
			k--;
			break;
		}
	}
	if(idx-k<0||idx+k+1>=s.length())
		k--;
	if(l>ans){
		ans=l;
		num=0;
		ss[num++]=to_string(idx-k,idx+k+1);
	}
	else if(l==ans){
		bool flag=1;
		for(int i=0;i<=num;i++){
			if(ss[i]==to_string(idx-k,idx+k+1))
				flag=0;
		}
		if(flag)
			ss[num++]=to_string(idx-k,idx+k+1);
	}
}
void solve(int tc){
	for(int i=0;i<s.length();i++){
		if(i>0&&i<s.length()-1&&s[i-1]==s[i+1])
			type_a(i);
		if(i<s.length()-1&&s[i]==s[i+1])
			type_b(i);
	}
	printf("第%d組測試資料的最長迴文子字串長度為:%d\n",tc,ans);
	printf("第%d組測試資料的最長迴文子字串內容為:",tc);
	if(num==0){
		set<char> _set;
		for(int i=0;i<s.length();i++){
			if(_set.count(s[i]))
				continue;
			_set.insert(s[i]);
			cout<<s[i]<<" ";
		}
	}
	else{
		for(int i=0;i<num;i++)
			cout<<ss[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>s;
		ans=1;
		solve(i);
	}
}