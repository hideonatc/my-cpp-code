#include<iostream>
#include<cstring>
using namespace std;
char pic[999][999];
void draw(int n){
	int x=n+48;
	char c=char(x);
	while(!isdigit(c)){
		x-=10;
		c=char(x);
	}
	for(int i=499-2*n+2;i<=499+2*n-2;i++)pic[499+2*n-2][i]=c;
	for(int i=499-2*n+2;i<=499+2*n-2;i++)pic[i][499-2*n+2]=c;
	for(int i=499-2*n+2;i<=499+2*n-2;i++)pic[i][499+2*n-2]=c;
	for(int i=499-2*n+2;i<=499+2*n-2;i++)pic[499-2*n+2][i]=c;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<999;i++)memset(pic[i],'_',999);
	for(int i=1;i<=n;i++){
		draw(i);
	}
	for(int i=499-2*n+2;i<=499+2*n-2;i++){
		for(int j=499-2*n+2;j<=499+2*n-2;j++){
			cout<<pic[i][j];
		}
		cout<<endl;
	}
}
