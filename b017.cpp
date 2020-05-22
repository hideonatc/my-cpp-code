#include<iostream>
using namespace std;
int main (){
	string a,b;
	cin>>a>>b;
	int ans[101];
	int la=a.length();
	int lb=b.length();
	//printf("%d %d\n",la,lb);
	int idx=0,k=0;
	for(int i=0;i<=la-1;i++){
		for(int j=lb-1;j>=0;j--){
			int c=(int(a[i])-48)*(int(b[j])-48)+idx;
			idx=0;
			while(c>=10){
				c-=10;
				idx++;
			}
			//printf("%d %d\n",c,idx);
			ans[k+i]=c;
			k++;
		}
	}
	if(idx>0){
		ans[k]=idx;
		k++;
	}
	int l=k;
	while(l--)cout<<ans[l-1];
}
