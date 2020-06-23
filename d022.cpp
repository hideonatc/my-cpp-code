#include<iostream>
using namespace std;
bool yr(int y){
	if(y%4==0)
		if(y%100!=0||y%400==0)
			return 1;
	return 0;
}
int m_d(int y,int m){
	if(m==5||m==7||m==10||m==12)
		return 30;
	else if(m==1||m==2||m==4||m==6||m==8||m==9||m==11)
		return 31;
	else 
		return 28+yr(y);
}
int main(){
	int n;
	cin>>n;
	int y=n*100-99;
	int m=2;
	int ans=0;
	int w=(y+((y-1)/4)-((y-1)/100)+((y-1)/400))%7;
	//cout<<"w="<<w<<endl;
	w=(w+12)%7;
	if(w==5)ans++;
	while(y<=n*100){
		w=(w+m_d(y,m))%7;		
		//printf("%d %d 13 is %d\n",y,m,w);
		if(w==5)
			ans++;
		if(m+1==13){
			y++;
			m=1;
		}
		else
			m++;
	}
	printf("共有%d次黑色星期五\n",ans);
}