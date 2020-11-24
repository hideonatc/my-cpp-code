#include<iostream>
using namespace std;
int n,arr[99999],arr2[99999];
int count_insertion_sort(){
	int cnt=0;
	for(int i=1;i<n;i++){
		for(int j=i;j>0;j--){
			cnt++;
			if(arr[j]>=arr[j-1])
				break;
			swap(arr[j],arr[j-1]);
		}
	}
	return cnt;
}
int count_bubble_sort(){
	int cnt=0;
	for(int i=0;i<n;i++)
		cnt+=i;
	return cnt;
}
int count_gnome_sort(){
	int cnt=0;
	for(int i=0;i<n-1;){
		cnt++;
		if(arr2[i]>arr2[i+1]){
			swap(arr2[i],arr2[i+1]);
			i=0;
		}
		else
			i++;
		if(i==n)
			return cnt;
	}
	return cnt;
}
int main(){
	cin>>n;
	int in;
	for(int i=0;i<n;i++){
		cin>>in;
		arr[i]=arr2[i]=in;
	}
	printf("Insertion Sort: %d\n",count_insertion_sort());
	printf("Bubble Sort: %d\n",count_bubble_sort());
	printf("Stupid Sort: %d\n",count_gnome_sort());
}