#include<iostream>
using namespace std;
int main(){
	string in;
	cin>>in;
	int idx=1,sum=0,nm;
	while(in.length()>idx*3){
		if(idx%2)
			nm=int(in[idx*3-1]-'0')+int(in[idx*3-2]-'0')*10+int(in[idx*3-3]-'0')*100;
		else
			nm=int(in[idx*3-1]-'0')*100+int(in[idx*3-2]-'0')*10+int(in[idx*3-3]-'0');
		idx++;
		sum+=nm;
	}
	int l=in.length()%3;
	if(l==1)
		nm=int(in[idx*3-3]-'0');
	else if(l==2){
		if(idx%2)
			nm=int(in[idx*3-2]-'0')+int(in[idx*3-3]-'0')*10;
		else
			nm=int(in[idx*3-2]-'0')*10+int(in[idx*3-3]-'0');
	}
	else{
		if(idx%2)
			nm=int(in[idx*3-1]-'0')+int(in[idx*3-2]-'0')*10+int(in[idx*3-3]-'0')*100;
		else
			nm=int(in[idx*3-1]-'0')*100+int(in[idx*3-2]-'0')*10+int(in[idx*3-3]-'0');
	}
	sum+=nm;
	cout<<sum%997<<endl;
}