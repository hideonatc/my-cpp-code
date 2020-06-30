#include<iostream>
using namespace std;
string t="LEOCBFQSTNARGHJUWXDVIKMPYZ/";
int main(){
	int c[1001]={0};
	int b[250][3];
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int idx=0;
		for(int i=0;i<s.length();i++){
			for(int j=0;j<t.length();j++){
				if(s[i]==t[j]){
					b[i][0]=j/9+1;
					b[i][1]=((j%9)/3)+1;
					b[i][2]=(j%9)%3+1;
					//printf("(%d,%d,%d)\n",j/9+1,((j%9)/3)+1,(j%9)%3+1);
				}
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<s.length();j++)
				c[idx++]=b[j][i];
		}
		idx-=1;
		for(int i=0;i<=idx;i+=3){
			int k=(c[i]-1)*9+(c[i+1]-1)*3+(c[i+2]-1);
			//printf("(%d,%d,%d)\n",c[i],c[i+1],c[i+2]);
			cout<<t[k];
		}
		cout<<endl;
	}
}