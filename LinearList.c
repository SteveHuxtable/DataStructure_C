/*
 * author = Steve Hu
 * date = 2017.8.26
 */

// LinearList in Sequential storage structure

// define a linearlist

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DataType int

struct SeqList{
	int MAXNUM; 
	int n; 
	DataType *element;
};

// define a pointer to SeqList
typedef struct SeqList * PSeqList;

PSeqList createNullList_seq(int m){
   PSeqList palist = (PSeqList)malloc(sizeof(struct SeqList));
   if(palist != NULL){
       palist -> element = (DataType *)malloc(sizeof(DataType) * m);
	   if(palist -> element){
	       palist -> MAXNUM = m;
		   palist -> n = 0;
		   printf("You have successfully create a linear list !!! \n"); 
		   return palist;
	   }
	   else free(palist);
   }
   printf("Out of space!! \n");
   return NULL;
}

// check if a list is null !
int isNullList(PSeqList palist){
    return (palist -> n == 0);
}

int locate_first(PSeqList palist, DataType x){
    int q;
	for(q = 0; q < palist -> n; q++){
	    if(palist -> element[q] == x){
			return q;
		}
	}
	return -1;
}


// insert an element before the pth element
int insertPre_seq(PSeqList palist, int p, DataType x){

    int q;

	if(palist -> n >= palist -> MAXNUM){
	    printf(" Overflow ! \n");
		return 0;
	}

	if(p < 0 || p > palist -> n){
	    printf(" Not exist ! \n");
	    return 0;	
	}

	for(q = palist -> n-1; q >= p; q--)
		palist -> element[q+1] = palist -> element[q];

	palist -> element[q] = x;

	palist -> n += 1;

	return 1;
} 

// delete the element in the positon of p
int deleteP_seq(PSeqList palist, int p){
    
	int q;

	if(p < 0 || p > palist -> n - 1){
	    printf("Not exist ! \n");
		return 0;
	}

	for(q = p; q < palist -> n - 1; q++){
		// use the q+1 element to replace q element
	    palist -> element[q] = palist -> element[q+1];   
	}
    palist -> n = palist -> n-1;	
	return 1;
}

// delete the first e element and return success or not
int deleteV_seq(PSeqList palist, DataType x){
    
	// at first, we should find the position of x
    int	site = locate_first(palist, x);
    
    deleteP_seq(palist, site); 

	return 0;
} 


// the main function to do some test

int main(int argc, char** argv){

	// at first, we should get the data from the CommandLine
    int	list_length = argc - 1;

    PSeqList palist;
    palist = createNullList_seq(20);	

	// initialize the list
	int list_len = argc - 1;
	for(int i = 0; i <= list_len; i++){
	    palist -> element[i] = atoi(argv[i]);
	    printf(" Put %s into the list successfully \t", argv[i]);
		palist -> n ++;
	}
	printf("\n All data were put into the list !!! \n");

	// test if the list is null
	if(isNullList(palist))
		printf(" This is a null list !! \n");
	else
	    printf(" This is not a null list !! \n");
    
	int site = locate_first(palist, 10);
	if(site == -1)
		printf(" You can not find the element !! \n");
	else
        printf(" The element is at the %d site !! \n", site);

	if(insertPre_seq(palist, 5, 10))
	    printf(" You have inserted successfully !!");
	else
		printf(" You cannot inserted !!");

	if(deleteV_seq(palist, 10))
		printf(" delete element successfully !! \n");
	else
        printf(" not delete element successfully !! \n");

    getchar();

	return 0;
}

