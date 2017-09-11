// functions for a stack using linklist
// 20170909

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int DataType;

// basic struct
struct Node;
typedef struct Node * PNode;
struct Node{
    DataType info;
    PNode link;	
};

// top node
struct LinkStack{
    PNode top;
};

typedef struct LinkStack * PLinkStack;


PLinkStack createEmptyStack_link(void){
    PLinkStack plstack;
	plstack = (PLinkStack)malloc(sizeof(struct LinkStack));
	if(plstack != NULL)
		plstack->top = NULL;
	else{
	    printf("Out of space !!!\n");
		exit(-1);
	}

	return plstack;
}

int isEmptyStack_link(PLinkStack plstack){
	return (plstack->top == NULL);
}

void push_link(PLinkStack plstack, DataType x){
    PNode pushNode = (PNode)malloc(sizeof(struct Node)); 

	if(pushNode != NULL){
	    pushNode->info = x;
		pushNode->link = plstack->top;
		plstack->top = pushNode;
	}
	else{
	    printf("Out of space ! \n");
		exit(-1);
	}
}

DataType pop_link(PLinkStack plstack){
    if(plstack->top == NULL){
	    printf("The stack is empty !! \n");
		exit(-1);
	}    
	
	PNode tmpNode;
	
	tmpNode = plstack->top;

    plstack->top = plstack->top->link;

	DataType tmp = tmpNode->info;
	
	free(tmpNode);

	return tmp;
}

DataType top_link(PLinkStack plstack){
    if(plstack->top != NULL){
	    return plstack->top->info;
	}

	else{
	    printf("There is no top node ! \n");
		exit(-1);
	}
}
