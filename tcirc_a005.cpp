#include<iostream>
using namespace std;
int main(){
	int c,w;
	cin>>c>>w;
	int ans=0;
	while(c>=12&&w>0){
		ans++;
		c-=10;
		w--;
		//printf("ans=%d c=%d w=%d\n",ans,c,w);
	}
	while(w+c>12){
		ans++;
		w-=12-c;
		c=2;
		w--;
		//printf("ans=%d c=%d w=%d\n",ans,c,w);
	}
	cout<<ans<<endl;
}