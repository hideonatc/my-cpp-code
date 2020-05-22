#include<iostream>
using namespace std;
struct linked{
	int value;
	linked *next;
};
linked *head=new linked();
/*void addition(int v,int b){
	linked *current=
}*/
int dele(int v){
	linked *temp,*follow;
	temp=head;
	if(temp==NULL)return 0;
	if(temp->value==v){
		head=temp->next;
		delete temp;
	}
	while(temp!=NULL&&temp->value!=v){
		follow=temp;
		temp=temp->next;
	}
	if(temp==NULL)return 0;
	else if(temp->value==v){
		follow->next=temp->next;
		delete temp;
	}
}
void print(void){
	linked *temp;
	temp=head->next;
	printf("%d",head->value);
	while(temp!=NULL){
		printf("->%d",temp->value);
		temp=temp->next;
	}
}
int main() {
	int t;
	while(cin>>t){
		/*if(t==0){
			int i,j;
			cin>>i>>j;
			addition(i,j);
		}*/
		/*else*/ if(t==1){
			int i;
			cin>>i;
			dele(i);
		}
		else if(t==2){
			print();
		}
	}
}
