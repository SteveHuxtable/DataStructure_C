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
int main(){

    LinkList llist = createNullList_link();

    if(isNullList_link(llist))
		printf(" the llist is empty !! \n");
	else
		printf(" th llist is not empty !! \n");

    PNode site = locate_link(llist, 10);

    getchar();

	return 0;
}
