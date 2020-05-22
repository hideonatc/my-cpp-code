#include<iostream>
using namespace std;
struct linked{
	int value;
	linked *next;
};
linked *head=new linked();
int addition(int v,int b){
	linked *before,*n;
	before=head;
	while(before->next!=NULL&&before->value!=b){
		before=before->next;
	}
	if(before->value==b){
		linked *temp=new linked();
		n=before->next;
		before->next=temp;
		temp->value=v;
		temp->next=n;
	}
	else printf("Can't find the value before\n");
}
int deletion(int v){
	linked *temp,*follow;
	temp=head;
	if(temp->value==v){
		head=temp->next;
		delete temp;
	}
	while(follow->next!=NULL&&temp->value!=v){
		follow=temp;
		temp=temp->next;
	}
	if(temp->value==v){
		follow->next=temp->next;
		delete temp;
	}
	else printf("Can't find the value\n");
}
void print(void){
	linked *temp;
	temp=head->next;
	printf("%d",head->value);
	while(temp!=NULL){
		printf("->%d",temp->value);
		temp=temp->next;
	}
	printf("\n");
}
int main() {
	int t;
	int f;
	printf("Enter the value of head:\n");
	cin>>f;
	printf("0:add 1:delete 2:print\n");
	head->value=f;
	while(cin>>t){
		if(t==0){
			int i,j;
			cin>>i>>j;
			addition(i,j);
		}
		else if(t==1){
			int i;
			cin>>i;
			deletion(i);
		}
		else if(t==2){
			print();
		}
		printf("0:add 1:delete 2:print\n");
	}
}