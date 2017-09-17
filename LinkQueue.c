#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

PLinkQueue createEmptyQueue_link(){
     // create a Node
	 PNode tmpNode = (PNode) malloc (sizeof(struct Node));
     
	 if(tmpNode == NULL){
	     printf("Out of space ! \n");
	     exit(-1);
	 }
	 else{
	     PLinkQueue plqu = (PLinkQueue) malloc (sizeof(struct LinkQueue));
		 plqu -> head = NULL;
		 plqu -> tail = NULL;

		 printf("Create the link queue successfully ! \n");

		 return plqu;
	 }
}

int isEmptyQueue_link(PLinkQueue plqu){
    return (plqu -> head == NULL);     
}

void enQueue_link(PLinkQueue plqu, DataType x){
    PNode tmpNode = (PNode) malloc (sizeof(struct Node));  

	tmpNode -> info = x;

	tmpNode -> next = NULL;
    
    if(plqu -> head == NULL){
	    plqu -> head = tmpNode;
		plqu -> tail = tmpNode;
		printf("%d is in the queue ! \n", x);
	}
	else{
	    plqu -> tail -> next = tmpNode;
	    plqu -> tail = tmpNode;	
		
		printf("%d is in the queue ! \n", x);
	}
}

DataType headQueue_link(PLinkQueue plqu){
	if(plqu -> head == NULL){
	    printf("empty queue ! \n");
		exit(-1);
	}
	else{
		printf("The head node is : %d \n", plqu -> head -> info);
	    return plqu -> head -> info;
	}
}

DataType deQueue_link(PLinkQueue plqu){
	if(plqu -> head == NULL){
	    printf("No element in the queue ! \n");
		exit(-1);
	}

	PNode tmpNode = plqu -> head;
	
	DataType tmpValue = plqu -> head -> info;

	if(plqu -> head == plqu -> tail){
	    printf("Only one element ! \n");

		plqu -> head = NULL;
		plqu -> tail = NULL;

	}
	else{
        plqu -> head = plqu -> head -> next;
	}
	
	free(tmpNode);

	printf("The element that dequeue : %d \n", tmpValue);

	return tmpValue;
}
