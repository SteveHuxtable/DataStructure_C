/*
 * Joseph problem
 *
 * Date = 2017.8.27
 */

#include <stdio.h>
#include <stdlib.h>

// use linklist structure to solve the problem

#define MAXNUM 14

// define the struct to be used

struct Node;

typedef struct Node * PNode;

struct Node{
    int number;
	int killed;
    PNode next; 
};

// initialize the PNode by using the MAXNUM

int InitJoseph(PNode Jo_llist, int guest_NUM){
    
	PNode first_Node = (PNode)malloc(sizeof(struct Node));
	first_Node ->number = 1;
	first_Node -> killed = 0;
    printf(" The 1 is into the list \n");

    PNode tmp_Node;
	PNode new_Node;
    
	int i;

	for(i = 0; i < guest_NUM; i ++){

		new_Node = (PNode)malloc(sizeof(struct Node));
	
		if(i == 0)
			first_Node -> next = new_Node;

        new_Node -> number = i + 2;
		new_Node -> killed = 0;
		printf(" The %d is into the list \n", i + 2);

		new_Node = new_Node -> next;

		if(i == guest_NUM -1)
			first_Node = new_Node;
	}	

	if(i == guest_NUM){

		Jo_llist = first_Node;
        printf(" Create the llist successfully !! \n");	
		return 0;
	}
	else{
	    printf(" Unable to create the llist !! \n");
		return 1;
	}
}

// tranverse the PNode
int Joseph_trans(PNode Jo_llist){
    PNode p;
	p = Jo_llist;
	do{
        printf(" The number %d is in the linklist !! \n", p -> number);	
		p = p -> next;
	}while(p -> number != 1);
	return 0;
}

// Output the sequence of number until only 1 left
int Joseph_run(PNode Jo_llist, int guest_Num, int count_Num){
	
	PNode knife = Jo_llist;

	printf(" is this one all right? \n");

	while(guest_Num != 1){
	
	    // kill people one by one
		int count = 0;

	    while(count < count_Num){

		    if(count == count_Num - 1){
				if(knife -> killed == 0){
			        knife -> killed = 1;
			        printf(" The No.%d guest is killed \n", knife -> number);
				}	
			}
			
			printf("run for %d time", count);

			knife = knife -> next;
            
			if(knife -> killed != 1)
			    count++;
		}	

		guest_Num--;
	}

	return 0;
}


// main function

int main(){

    int guest_Num, count_Num;

	scanf("%d", &guest_Num);

	scanf("%d", &count_Num);

    PNode Jo_llist;

	InitJoseph(Jo_llist, guest_Num);

	printf(" is here all right ? \n");

	Joseph_trans(Jo_llist);

    Joseph_run(Jo_llist, guest_Num, count_Num);

	getchar();

	return 0;
}
