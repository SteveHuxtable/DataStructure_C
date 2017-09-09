// the structure of SeqStack
// Date: 2017-09-09

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int DataType;

struct SeqStack{
    int MAXNUM;
	int t;      // store the position of top element
	DataType *s;
};

typedef struct SeqStack * PSeqStack;

// if the stack is empty, the pastack->t = -1
PSeqStack createEmptyStack_Seq(int m);

int isEmptyStack_Seq(PSeqStack pastack);

void push_Seq(PSeqStack pastack, DataType x);

DataType pop_Seq(PSeqStack pastack);

DataType gettoppos_Seq(PSeqStack pastack);

int main(void){

	printf("Please input the depth of the stack : ");
	int depth;
	scanf("%d", &depth);
    // test the functions
	PSeqStack pastack = createEmptyStack_Seq(depth);

	push_Seq(pastack, 15);

	isEmptyStack_Seq(pastack);

	//DataType pop_value = pop_Seq(pastack);

    DataType pop_value = gettoppos_Seq(pastack);

	printf("%d is the top value of the stack ! \n", pop_value);

	pop_value = pop_Seq(pastack);

	pop_value = gettoppos_Seq(pastack);

	isEmptyStack_Seq(pastack);
}

// createEmptyStack
PSeqStack createEmptyStack_Seq(int m){
    PSeqStack pastack = (PSeqStack)malloc(sizeof(struct SeqStack));
	
	if(pastack != NULL){
		pastack->s = (DataType *)malloc(sizeof(DataType) * m);
		if(pastack->s){
		    pastack->MAXNUM = m;
			pastack->t = -1;
			printf("Create the stack successfully !\n");
			return pastack;
		}
		else free(pastack);
	}

	printf("Out of space !! \n");

	return NULL;
}

int isEmptyStack_Seq(PSeqStack pastack){
    if(pastack->t == -1){
        printf("the stack is empty !\n");
	    return 1;	
	}
	if(pastack->t >= 0){
	    printf("the stack is not empty !\n");
		return 0;
	}
	else{
		printf("the stack is not right !\n");
		exit(-1);
	}
}

void push_Seq(PSeqStack pastack, DataType x){
    // at first, we have to check the stack
	if(pastack->t < pastack->MAXNUM - 1){
	    printf("You can push an element into the stack!\n");
		pastack->s[++pastack->t] = x;
		printf("The element %d was pushed into the stack! \n", pastack->s[pastack->t]);
	}
    
    else{
	    printf("Overflow!\n");
	}	
}

DataType pop_Seq(PSeqStack pastack){
    if(!isEmptyStack_Seq(pastack)){
	    return pastack->s[pastack->t--];
	}
	else{
	    printf("the stack is an empty stack ! \n");   
	    exit(-1);
	}
}

DataType gettoppos_Seq(PSeqStack pastack){
    if(isEmptyStack_Seq(pastack)){
	    exit(-1);
	}
	else{
	    return pastack->s[pastack->t];
	}
}
