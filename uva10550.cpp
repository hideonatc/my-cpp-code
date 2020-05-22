#include<iostream>
using namespace std;
int main(){
	while(1){
		int pos,fir,sec,thir,ans=80;
		cin>>pos>>fir>>sec>>thir;
		if(fir==0&&sec==0&&thir==0&&pos==0)return 0;
		if(pos>=fir)ans+=pos-fir;
		else ans+=40+pos-fir;
		ans+=40;
		pos=fir;
		if(pos<=sec)ans+=sec-pos;
		else ans+=40+sec-pos;
		pos=sec;
		if(pos>=thir)ans+=pos-thir;
		else ans+=40+pos-thir;
		pos=thir;
		cout<<ans*9<<endl;
	}
} 
