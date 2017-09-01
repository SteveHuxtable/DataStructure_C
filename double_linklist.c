#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Datatype int

typedef struct dllist_Node{
    int num;
	Datatype info;
    struct dllist_Node * pre_Node;
	struct dllist_Node * post_Node;
}dllist_Node, * dllist_PNode; 

dllist_PNode crea_dllist(){
	dllist_PNode p = (dllist_PNode)malloc(sizeof(dllist_Node));
	if(p == NULL){
	    printf("Out of space ! \n");
		exit(-1);
	}
	else{
    	printf("Create a double list !! \n");
		return p;
	}
}

//init a double list and input the values of it
void init_dllist(dllist_PNode llist, int len_llist){
    int i = 0;

	dllist_PNode p = llist;

	dllist_PNode fir_Node = llist;

	for(i = 0; i < len_llist; ++i){
        if(i == 0){
		    p -> pre_Node = NULL;
		}

		p -> num = i;
		printf("Please input the value that the %dth node have : ", i + 1);
		scanf("%d", & p -> info);

	    dllist_PNode pnew = (dllist_PNode)malloc(sizeof(dllist_Node));

		p -> post_Node = pnew;
		pnew -> pre_Node = p;

		p = p -> post_Node;
	}

	p = NULL;

	printf("You have initialized a double list \n");
}

void output_dllist(dllist_PNode llist){
   
	int direct;
	dllist_PNode p_now;
	p_now = llist;
	
    do{
        printf("Please input '0' or '1' to choose the direction : ");
		
		//direct = getchar();

		scanf("%d", &direct);

		printf("The value of direct is : %d \n", direct);

        switch(direct){
            case 0:
				p_now = p_now -> pre_Node;
				break;
			case 1:
				p_now = p_now -> post_Node;
				break;
			default:
				printf("You should input '0' or '1' \n");
				break;
		}

		if(p_now != NULL){
			printf("The value of No.%d Node is : %d \n", p_now -> num + 1, p_now -> info);
		}
		else{
		    printf("You have reach the end of the list !! \n");
			exit(-1);
		}

    }while(direct == 0 || direct == 1); 
}

int main(){

    int len_llist;
	printf("Please input the length of the double list : ");
	scanf("%d", &len_llist);
    dllist_PNode dllist = crea_dllist();
	init_dllist(dllist, len_llist);

	output_dllist(dllist);

	return 0;
}


