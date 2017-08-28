#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

// Initialize 
LinkList Init_LNode(){
	LNode *L;
	L = (LinkList)malloc(sizeof(LNode));
	if(L == NULL){
		printf("Out of space !! \n");
		exit(-1);
	}
	L->next = NULL;
	    return L;
}

// Create list
void Creat_List1(LNode *L){
	int i,n,num;
	LNode *pnew;

	printf("Please input the number of elements: n = ");
	scanf("%d", &n);
	for(i = 0; i < n; i ++){
		printf("Please input t he No.%d number", i + 1);
		scanf("%d", &num);
		pnew = (LinkList)malloc(sizeof(LNode));
		pnew -> data = num;
		pnew -> next = L -> next;  // give the L->next to pnew->next first, and then
		L -> next = pnew;          // insert pnew to the L->next
	}
}

void Creat_List2(LNode *L){
    int i, n, num;
    LNode *p, *pnew;
    p = L;
    printf("Please input the number of elements : ");
    scanf("%d", &n);

    for(i = 0; i < n; i ++){
        printf("Please input the No. %d elements : ", i + 1);
        scanf("%d", &num);
        pnew = (LinkList)malloc(sizeof(LNode));
        if(pnew == NULL){
        	printf("Out of space !! \n");
        	exit(-1);
        }
        pnew -> data = num;
        p -> next = pnew;
        p = pnew;
    }
    p -> next = NULL;

}

void Show_Linst(LNode *L){
    LNode *p;
    p = L -> next;

    while(p != NULL){
    	printf("%d ", p -> data);
    	p = p -> next;
    }

    printf("\n");
}

// insert an element into the list
// pre insert method !!!
void Insert_List1(LNode *L){
    int i, n, val;
    LNode *p, *s;
    p = L;
    i = 1;
    printf("Please input the site where you want to insert : ");
    scanf("%d", &n);
    printf("Please input the element that you want to insert : ");
    scanf("%d", &val);
    while(p && i < n){
        p = p -> next;
        ++i;
    }
    if(!p || i > n)
        printf("Can not insert !! \n");
    s = (LinkList)malloc(sizeof(LNode));
    s->data = val;
    s->next = p->next;
    p->next = s;   // pre insert!
}

// insert an element into the linklist
// post insert !!!
void Insert_List2(LinkList L){
    int i, n, val;
    LNode *s, *p;
    p = L;
    i = 1;
    printf("Please input the site where you want to insert : ");
    scanf("%d", &n);
    printf("Please input the element that you want to insert : ");
    scanf("%d", &val);
    while(p && i < n){
        p = p -> next;
        ++i;
    }
    if(!p || i > n)
        printf("Can not insert ! \n");
    s = (LinkList)malloc(sizeof(LNode));
    s->data = val;
    s->next = p->next;
    p->next = s;
}

int main(){
	LinkList llist;
	llist = Init_LNode();

	// Creat_List1(llist);
	Creat_List2(llist);

    //Insert_List1(llist);
    Insert_List2(llist);

	Show_Linst(llist);

	return 0;

}