#include<iostream>
#include<map>
using namespace std;
string name_list[11];	//name_list[number]=name
map <string,int> list;	//list[name]=number
int tab[11][11]={0},pay[11]={0};	//i owe j tab[i][j] dollars,i spend pay[i] dollars in total.
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>name_list[i];
		list[name_list[i]]=i;
	}
	string name,input;
	int price;
	cin>>name;
	while(name!="EOF"){
		cin>>input>>price;
		if(input=="ALL"){
			for(int i=1;i<=n;i++){
				if(name_list[i]!=name)
					tab[i][list[name]]+=price/n;	//everyone besides "name" owe "name" price/n dollars
				pay[i]+=price/n;	//everyone spend price/n dollars
			}
		}
		else{
			string p;
			for(int i=1;i<=int(input[0])-int('0');i++){
				cin>>p;
				tab[list[p]][list[name]]+=price/(int(input[0])-int('0')+1);
				pay[list[p]]+=price/(int(input[0])-int('0')+1);
			}
			pay[list[name]]+=price/(int(input[0])-int('0')+1);
		}
		cin>>name;
	}
	for(int i=1;i<=n;i++){
		cout<<name_list[i]<<" ";
		for(int j=1;j<=n;j++)
			if(tab[i][j]>tab[j][i])	//if i has to give j more than j has to give i, then i owe j tab[i][j]-tab[j][i] dollars
				cout<<name_list[j]<<" "<<tab[i][j]-tab[j][i]<<" ";
		cout<<pay[i]<<endl;
	}
}