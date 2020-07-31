#include<iostream>
using namespace std;
int main(){
	int pl,pa,pd,bl,ba,bd;
	while(cin>>pl>>pa>>pd>>bl>>ba>>bd){
		if(!(pl||pa||pd||bl||ba||bd))
			break;
		int round=1;
		while(pl>0&&bl>0){
			bl-=pa-bd;
			if(bl<=0){
				printf("You win in %d round(s).\n",round);
				break;
			}
			pl-=ba-pd;
			if(pl<=0){
				printf("You lose in %d round(s).\n",round);
				break;
			}
			round++;
		}
	}
}