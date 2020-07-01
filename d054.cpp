#include<iostream>
using namespace std;
void print(int b,char c){
	for(int i=1;i<=b;i++)
		cout<<c;
}
int main(){
	int num[10][64];
	for(int i=0;i<10;i++)
		for(int j=0;j<64;j++){
			char input;
			cin>>input;
			num[i][j]=int(input-'0');
		}
	string in;
	cin>>in;
	int out[5],idx=0,i=0;
	while(isdigit(in[i])){
		out[idx++]=int(in[i]-'0');
		i++;
	}
	idx--;
	int b=int(in[i+1]-'0');
	int n=idx+1;
	for(int i=0;i<8;i++){
		for(int j=0;j<b;j++){
			for(int k=0;k<=idx;k++){
				for(int l=8*i;l<8*(i+1);l++){
					if(num[out[k]][l]==1)
						print(b,'*');
					else
						print(b,'_');
				}
				if(k!=idx)
					cout<<"___";
			}
			cout<<endl;
		}
	}
}