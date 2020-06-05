#include<iostream>
#include<ctime>
using namespace std;
int main(){
	//string s="Hello World!";
	clock_t start,end;
	for(int i=1;i<=5;i++){
		start=clock();
		cout<<"Hello World!";
		end=clock();
		cout<<" "<<end-start<<endl;
	}
	cout<<"-------"<<endl;
	for(int i=1;i<=5;i++){
		start=clock();
		printf("Hello World!");
		end=clock();
		printf(" %d\n",end-start);
	}
	cout<<"-------"<<endl;
	ios_base::sync_with_stdio(false);
	for(int i=1;i<=5;i++){
		start=clock();
		cout<<"Hello World!";
		end=clock();
		cout<<" "<<end-start<<endl;
	}
	cout<<"-------"<<endl;
	for(int i=1;i<=5;i++){
		start=clock();
		printf("Hello World!");
		end=clock();
		printf(" %d\n",end-start);
	}
}