#include<iostream>
#include<cmath>
using namespace std;
int raw_data[50][2];
void data_sort(int t){
	for(int i=1;i<=t;i++){
		int mn=1e5,pos=i;
		for(int j=i;j<=t;j++){
			if(mn>raw_data[j][0]){
				pos=j;
				mn=raw_data[j][0];
			}
		}
		swap(raw_data[i][0],raw_data[pos][0]);
		swap(raw_data[i][1],raw_data[pos][1]);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>raw_data[i][0];
	for(int i=1;i<=n;i++)
		cin>>raw_data[i][1];
	data_sort(n);
	for(int i=1;i<=n;i++){
		raw_data[i][0]=raw_data[i][1];
		raw_data[i][1]=i;
	}
	data_sort(n);
	double d=0;
	for(int i=1;i<=n;i++)
		d+=(i-raw_data[i][1])*(i-raw_data[i][1]);
	double k=(double)n*((double)n*(double)n-1);
	double ans=1-((6*d)/k);
	char sym=(ans>=0?'+':'-');
	printf("%c%.3f\n",sym,abs(ans));
}