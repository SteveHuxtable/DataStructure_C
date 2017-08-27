/*
 * Link list
 * 2017 - 08 - 28
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DataType int

// LinkList struct
struct Node;
typedef struct Node * PNode;
struct Node{
    DataType info;  // data field
	PNode link;     // pointer field
};
typedef struct Node * LinkList;


// create a new LinkList
LinkList createNullList_link(void){

    LinkList llist = (LinkList)malloc(sizeof(struct Node));
	
	if(llist != NULL) 
		llist -> link = NULL;
	else
		printf("Out of space !! \n");

	return llist;
}

// to judge if the llist empty
int isNullList_link(LinkList llist){
     return(llist -> link == NULL);
}

// to get the site of the first element x
PNode locate_link(LinkList llist, DataType x){
    
	PNode p; 
    
	if(llist -> link == NULL){
	    printf(" The llist is null !! \n");
		return 0;
	}
    
    p = llist -> link;
    while(p != NULL && p -> info != x)
		p = p -> link;
    
	if(p -> info == x)
        return p;
    else{
	    printf(" You cannot find the element \n");
		return NULL;
	}
}

// insert Datatype x after PNode p
int insertPost_link(LinkList llist, PNode p, DataType x){
    PNode q = (PNode)malloc(sizeof(struct Node));
    
	if(q == NULL){
		printf("Out of space !!");
		return 0;
	}
	else{
	    if(p -> link == NULL){
            p -> link = q;
			q -> info = x;
			q -> link = NULL;
		}
		else{
			q -> link = p -> link;
			p -> link = q;
			q -> info = x;
		}
        return 1;
	}
}

// get the precursor of p
PNode locatePre_link(LinkList llist, PNode p){
    PNode p1;

	if(llist == NULL && llist -> link == NULL)
		return NULL;
	
    p1 = llist -> link;

    while(p1 != NULL && p1 -> link != p){
	     p1 = p1 -> link;
	}

	if(p1 == NULL){
		printf("cannot find the node p \n");
		return NULL;
	}
	else{
        printf(" find the node !! \n");
	    return p1;
	}
}

// delete the first element x
int deleteV_link(LinkList llist, DataType x){
    PNode p, q;
    p = llist;
	
	if(p == NULL)
		return 0;
    
	while(p -> link != NULL && p -> link -> info != x)
			p = p -> link;

	if(p -> link == NULL){
	    printf(" Not exist! \n");
		return 0;
	}
    else{
	    q = p -> link;
		p -> link = q -> link;
		free(q);
		return 1;
	}

}


// main function to test the above functions
int main(int argc, char ** argv){

	//show the input 
	printf("argc = %d \n", argc);
	printf("argc[0] = %s \n", argv[0]);
	printf("argc[1] = %s \n", argv[1]);
	printf("argc[2] = %s \n", argv[2]);
	getchar();
	
	// initialize the linklist
    LinkList llist = createNullList_link();

    if(isNullList_link(llist))
		printf(" the llist is empty !! \n");
	else
		printf(" th llist is not empty !! \n");

	// input the date into the linklist
    if(argc < 2)
		printf(" You should input the date after the './LinkList' !!! \n");
    else{
		PNode p, q;
		p = llist;
	    for(int i = 1; i < argc; p = p -> link, i++){
		   PNode q =(PNode)malloc(sizeof(struct Node));  // create the space for q
		   if(q == NULL){
		       printf("Out of space \n");
               return 0;
		   }
		   q -> info = atoi(argv[i]);
		   p -> link = q;              // give q's address to p
           printf(" You have input %d into the linklist !! \n", atoi(argv[i])); 
		   getchar();
		} 
	}	

    if(isNullList_link(llist))
		printf(" the llist is empty !! \n");
	else
		printf(" th llist is not empty !! \n");


    PNode site = locate_link(llist, 10);

    getchar();

	return 0;
}
