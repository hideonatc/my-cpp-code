#include<iostream>
#include<cstdlib>
using namespace std;
struct Card{
	int num;
	char suit;
};
struct Deck{
	int idx = 0;
	Card d[20];
}D;
struct ll{
	Card card;
	ll* next = NULL;
};
struct ll *head = NULL;
void push(Card c){
	D.d[D.idx++] = c;
	return;
}
Card pop(void){
	Card re = D.d[--D.idx];
	return re;
}
void insert(void){
	Card c = pop();
	struct ll* nc = (struct ll*)malloc(sizeof(struct ll));
	nc->card.num = c.num;
	nc->card.suit = c.suit;
	nc->next = NULL;
	if(head == NULL){
		head = nc;
		return;
	}
	struct ll* now = head;
	while(now->next != NULL)
		now = now->next;
	now->next = nc;
	return;
}
void delete_card(Card c){
	//printf("delete %c%d\n",c.suit,c.num);
	struct ll* chk = head;
	struct ll* bf;
	while(chk != NULL){
		if(chk->card.num==c.num&&chk->card.suit==c.suit){
			if(chk == head){
				head = chk->next;
				return;
			}
			bf->next = chk->next;
			return;
		}
		bf = chk;
		chk = chk->next;
	}
	return;
}
int deal(string str){
	int r = 0;
	for(int i=1;i<str.length();i++)
		r = r*10+int(str[i]-'0');
	return r;
}
/*void ppp(void){
	struct ll* tmp = head;
	while(tmp != NULL){
		printf("%c%d ",tmp->card.suit,tmp->card.num);
		tmp = tmp->next;
	}
	printf("\n");
	return;
}*/
void check_pair(void){
	struct ll* chk1 = head;
	struct ll* chk2;
	bool del;
	while(chk1 != NULL){
		del = 0;
		chk2 = chk1->next;
		while(chk2 != NULL){
			//printf("now checking %c%d %c%d\n",chk1->card.suit,chk1->card.num,chk2->card.suit,chk2->card.num);
			if(chk1->card.num == chk2->card.num){
				del = 1;
				Card c1=chk1->card,c2=chk2->card;
				delete_card(c1);
				//ppp();
				delete_card(c2);
				//ppp();
				break;
			}
			chk2 = chk2->next;
		}
		if(del)
			chk1 = head;
		else
			chk1 = chk1->next;
	}
	return;
}
bool smaller(Card a,Card b){
	//printf("checking %c%d and %c%d\n", a.suit, a.num, b.suit, b.num);
	if(a.num != b.num) return a.num<b.num;
	return a.suit<b.suit;
}
void print_hand(void){
	struct ll* chk;
	while(head != NULL){
		chk = head;
		//printf("head=%c%d\n",head->card.suit,head->card.num);
		Card mn;
		mn.num = 99;
		mn.suit = 'a';
		while(chk != NULL){
			if(smaller(chk->card,mn))
				mn = chk->card;
			chk = chk->next;
		}
		printf("%c%d\n",mn.suit, mn.num);
		delete_card(mn);
	}
	return;
}
int main(){
	string ip;
	Card ncard;
	for(int i=0;i<13;i++){
		cin>>ip;
		ncard.suit = ip[0];
		ncard.num = deal(ip);
		push(ncard);
	}
	for(int i=0;i<13;i++)
		insert();
	check_pair();
	print_hand();
}
