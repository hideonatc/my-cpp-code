#include<iostream>
#include<map>
using namespace std;
string num_str = "3456789TJQKA2";
string shape_str = "CDHS";
map<char,int> num,shape;
string card[13];
void init(){
	for(int i=0;i<13;i++)
		num[num_str[i]]=i+1;	//將3到2映射到0到12
	for(int i=0;i<4;i++)	
		shape[shape_str[i]]=i+1;	//將花色大小映射到0到3
	for(int i=0;i<13;i++)
		cin>>card[i];
}
void mysort(){
	for(int i=0;i<13;i++){
		for(int j=i;j>0;j--){
			if(num[card[j][1]]<num[card[j-1][1]]){	//先比較數字大小
				string swap=card[j];
				card[j]=card[j-1];
				card[j-1]=swap;
			}
			else if(card[j][1]==card[j-1][1]){
				if(shape[card[j][0]]<shape[card[j-1][0]]){	//若相同再比較花色
					string swap=card[j];
					card[j]=card[j-1];
					card[j-1]=swap;
				}
			}
		}
	}
}
int main(){
	init();
	mysort();
	for(int i=0;i<13;i++)
		cout<<card[i]<<endl;
}