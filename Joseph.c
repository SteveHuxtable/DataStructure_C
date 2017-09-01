#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// the structure of a Joseph_Node

#define Datatype int

typedef struct Joseph_Node{
    int Per_Num;
   	struct Joseph_Node *next;
}Joseph_Node, *Joseph_PNode;

typedef struct Joseph_Node *Joseph_llist;

// create a Joseph_llist - should be a circle list
Joseph_llist crea_Jollist();

// initialize the Joseph_llist;
void init_Jollist(Joseph_llist llist, int num);

// to tranverse the Joseph_llist
void tranv_Jollist(Joseph_llist llist, int num);

// kill people one by one, and then output the array that be killed
void kill_Onebyone(Joseph_llist llist, int kill_Num);

// main function
int main(){
	int num, kill_Num;
    printf("Please input the number of people : ");
	scanf("%d", &num);

	printf("Please input the number of the count that kill people : ");
	scanf("%d", &kill_Num);

	Joseph_llist llist;
	llist = crea_Jollist(llist);
	init_Jollist(llist, num);
	tranv_Jollist(llist, num);
    kill_Onebyone(llist, kill_Num);

	return 0;
}

Joseph_llist crea_Jollist(){
	Joseph_PNode fir_guy;
	fir_guy = (Joseph_PNode)malloc(sizeof(Joseph_Node));
    if(fir_guy == NULL){
	    printf("Out of space !! \n");
		exit(-1);
	}
	fir_guy -> next = NULL;
	return fir_guy;
}

void init_Jollist(Joseph_PNode llist, int num){
    Joseph_PNode p = llist;
	Joseph_PNode pre_p;
    
    if(p == NULL){
	    printf("Can not get a valid Joseph_llist !! \n");
		exit(-1);
	}	
    else{
	    printf("Get a valid Joseph_llist !! \n");
		printf("Let's initialize it !! \n");
	}

	int i = 0;

    for(i = 0; i < num; ++i){
		p -> Per_Num = i + 1;
	    printf("[Initing...]No.%d is in the Joseph_llist !! \n", p -> Per_Num);
	    Joseph_PNode pnew = (Joseph_PNode)malloc(sizeof(Joseph_Node));
		p -> next = pnew;
		pre_p = p;
		p = pnew;
	}

	pre_p -> next = llist;
	free(p);
}

void tranv_Jollist(Joseph_llist llist, int num){
    int i = 0;

	Joseph_PNode p = llist;

	while(i < num){
	    printf("[TRANV] The No.%d is in the Joseph_llist !! \n", p -> Per_Num);

		p = p -> next;

		++i;
	}

	p = p -> next;

	//printf("[TRANV] The No.1 element in the array is : %d \n", p -> Per_Num);
}

// write the true kill_Onebyone functino !!
void kill_Onebyone(Joseph_PNode llist, int kill_Num){
    int count;
	
	Joseph_PNode knife = llist;

	// the PNode that pre-knife
	Joseph_PNode pre_knife, free_knife;
    
	while(knife -> next != knife){
        count = 1;
	    while(count != kill_Num){
			pre_knife = knife;
		    knife = knife -> next;
			++count;
		}	    
		// kill someone -delete the PNode
		printf("[killing...] The No.%d people has been killed !! \n", knife -> Per_Num);
		free_knife = knife;
        knife = knife -> next;
		pre_knife -> next = knife;
        free(free_knife);
	}
}

