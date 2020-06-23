#include<iostream>
#include<vector>
using namespace std;
vector<int> I,I_bk;
vector<int> F;
int mn=10;
int c;
bool has_ans=false;
void p(int n){
	if(n==1){
		for(int i=1;i<=c;i++){
			I[i]=(I[i]?0:1);
		}
	}
	else if(n==2){
		for(int i=1;i<=c;i++){
			if(i%2){
				I[i]=(I[i]?0:1);
			}
		}
	}
	else if(n==3){
		for(int i=1;i<=c;i++){
			if(!i%2){
				I[i]=(I[i]?0:1);
			}
		}
	}
	else if(n==4){
		for(int i=0;3*i+1<=c;i++){
			I[3*i+1]=(I[3*i+1]?0:1);
		}
	}
}
int main(){
	bool sol[16][4]={{0,0,0,0},{0,0,0,1},{1,0,0,0},{0,1,0,0},{0,0,1,0},{1,0,0,1},{0,1,0,1},{0,0,1,1},{1,1,0,0},{1,0,1,0},{0,1,1,0},{1,1,0,1},{1,0,1,1},{0,1,1,1},{1,1,1,0},{1,1,1,1}};
	I.push_back(0);
	F.push_back(0);
	char in;
	cin>>in;
	cin>>in;
	cin>>c;
	cin>>in;
	cin>>in;
	char b;
	for(int i=1;i<=c;i++){
		cin>>b;
		I.push_back(int(b-'0'));
	}
	cin>>in;
	cin>>in;
	for(int i=1;i<=c;i++){
		cin>>b;
		F.push_back(int(b-'0'));
	}
	I_bk=I;
	int ans;
	for(int i=0;i<16;i++){
		I=I_bk;
		for(int j=0;j<4;j++){
			if(sol[i][j]){
				//printf("sol[%d][%d]=true\n",i,j);
				p(j+1);
				//printf("p(%d)\n",j+1);
				/*for(int i=1;i<=c;i++)
					cout<<I[i];
				cout<<endl;*/
			}
		}
		if(I==F){
			has_ans=true;
			ans=i;
			break;
		}
	}
	I=I_bk;
	if(!has_ans)
		cout<<"無解"<<endl;
	else{
		if(sol[ans][3]){
			cout<<"P4:";
			p(4);
			for(int i=1;i<=c;i++)
				cout<<I[i];
			cout<<endl;
		}
		if(sol[ans][0]){
			cout<<"P1:";
			p(1);
			for(int i=1;i<=c;i++)
				cout<<I[i];
			cout<<endl;
		}
		if(sol[ans][1]){
			cout<<"P2:";
			p(2);
			for(int i=1;i<=c;i++)
				cout<<I[i];
			cout<<endl;
		}
		if(sol[ans][2]){
			cout<<"P3:";
			p(3);
			for(int i=1;i<=c;i++)
				cout<<I[i];
			cout<<endl;
		}
	}
}