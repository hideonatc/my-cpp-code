#include<iostream>
using namespace std;
int arr[20001]={0};
int solve(int n){
	int idx=2,m=arr[2]-arr[1],count=2,max=-1;
	while(idx<n){
		if(arr[idx+1]-arr[idx]==m){
			idx++;
			count++;
			/*for(int i=idx-count+1;i<=idx;i++)cout<<arr[i]<<" ";
				cout<<endl;*/
		}
		else{
			max=(count>max)?count:max;
			count=2;
			m=arr[idx+1]-arr[idx];
			idx++;
		}
	}
	if(count==n) return n;
	return count>max?count:max;
}
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++)
			cin>>arr[j];
		printf("Case #%d: %d\n",i,solve(n));
	}
}