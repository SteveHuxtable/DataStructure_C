// time : 20170914 
// circular queue !!!



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define DataType int

typedef struct SeqQueue{
    
	int MAXNUM;
	int head, tail;
	DataType * q;

}SeqQueue, * PSeqQueue;

// functions for SeqQueue

PSeqQueue createSeqQueue(int MAXNUM);

int isEmptySeqQueue(PSeqQueue paqu);

void enSeqQueue(PSeqQueue paqu, DataType x);

DataType deSeqQueue(PSeqQueue paqu);

DataType firstSeqQueue(PSeqQueue paqu);


// test the functions
int main(void){

    PSeqQueue paqu = createSeqQueue(10);

    isEmptySeqQueue(paqu);

	printf("is here ok?\n");

    enSeqQueue(paqu, 10);

	enSeqQueue(paqu, 20);

    isEmptySeqQueue(paqu);

    deSeqQueue(paqu);	

	isEmptySeqQueue(paqu);

	deSeqQueue(paqu);

	isEmptySeqQueue(paqu);

	return 0;
}


// let's start to write the above functions !!
PSeqQueue createSeqQueue(int MAXNUM){
    PSeqQueue paqu = (PSeqQueue) malloc (sizeof(struct SeqQueue));

	// check if the creation of paqu is OK ?  
	if(paqu == NULL){ 
		printf("The creation failed ! \n"); 
		exit(-1); 
	}
	else{
		paqu->q = (DataType *) malloc (sizeof(DataType) * MAXNUM);
		paqu->head = 0;
		paqu->tail = 0;
		paqu->MAXNUM = MAXNUM;
	    printf("Creation of paqu is successful !! \n"); 
		return paqu;
	} 
}

int isEmptySeqQueue(PSeqQueue paqu){
    if(paqu == NULL){
	    printf("paqu is NULL! \n");
	    exit(-1);
	} 

	if(paqu->head == paqu->tail){
	    printf("The queue is empty ! \n");
		return 1;
	}

	else{
	    printf("The queue is not empty \n");
        return 0;		
	}
}

void enSeqQueue(PSeqQueue paqu, DataType x){
    
    if((paqu->tail+1) % paqu->MAXNUM == paqu->head){
        printf("This is a full queue already ! \n");
    } 
    else{
        paqu->q[paqu->tail] = x;
	    paqu->tail = (paqu->tail + 1) % paqu->MAXNUM;
    }
}

DataType deSeqQueue(PSeqQueue paqu){
   if(isEmptySeqQueue(paqu)){
       printf("This is a empty queue ! \n");
	   exit(-1);
   }

   else{
       DataType tmp = paqu->q[paqu->head];
	   paqu->head = (paqu->head + 1) % paqu->MAXNUM;
	   return tmp;
   }
}

DataType firstSeqQueue(PSeqQueue paqu){
   if(isEmptySeqQueue(paqu)){
       printf("This is a empty queue ! \n");
	   exit(-1);
   } 

   else{
       return paqu->q[paqu->head];
   }
}
