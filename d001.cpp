#include<iostream>
#include<set>
using namespace std;
int main(){
	set <int> s;
	int ans=0;
	bool flag=1;
	for(int i=10;i<=99;i++){
		for(int j=100;j<=999;j++){
			int x[10]={i/10,i%10,j/100,(j%100)/10,j%10,i*j/10000,(i*j%10000)/1000,(i*j%1000)/100,(i*j%100)/10,i*j%10};
			s.clear();
			for(int l=0;l<10;l++){
				if(s.count(x[l])){
					flag=false;
					break;
				}
				s.insert(x[l]);
			}
			if(flag&&i*j>=10000){
				printf("%d X %d = %d\n",i,j,i*j);
				ans++;
			}
			flag=true;						
		}
	}
	printf("\n共%d種運算式",ans);
} 
