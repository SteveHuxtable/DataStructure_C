// 20170910 
#include <stdio.h>
#include "LinkStack.h"

// the maze using 2-dim array to store
// '1' is feasible route , '0' is unfeasible route
int maze[8][11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                   0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0,
     	   		   0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0,
	    		   0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0,
		    	   0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0,
			       0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0,
			       0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0,
			       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  };

// the functions that "LinkStack.c" define
// struct LinkStack * PLinkStack
// PLinkStack createEmptyStack_link(void);
// int isEmptyStack_link(PLinkStack plstack);
// void push_link(PLinkStack plstack, DataType x);
// DataType top_link(PLinkStack plstack);

// use two stacks to store the route 
int main(void){

    PLinkStack rowStack = createEmptyStack_link();
    PLinkStack colStack = createEmptyStack_link();

    // push (1,1) into the two stacks
    push_link(rowStack, 1);
    push_link(colStack, 1);

    // there are 4 directions that can go
	int direct;
	
	// how to judge the node is still feasible?
	// use judgeMaze[8][11] to judge,
	// when judgeMaze[m][n] == 0, (m, n) is not feasible
	// initialize the judgeMaze
	int judgeMaze[8][11];
	for(int row = 0; row < 8; ++row){
	    for(int col = 0; col < 11; ++col){
		    judgeMaze[row][col] = 4;
		}
	}
   
   	//begin from (1,1)
	while((!isEmptyStack_link(rowStack)) && (!isEmptyStack_link(colStack))){

		printf("judgeMaze[3][5] is : %d \n", judgeMaze[3][5]);

		int row = top_link(rowStack);
		int col = top_link(colStack);

		maze[row][col] = 2;

		printf("The starting point is (%d, %d), and the value is : %d \n", row, col, maze[row][col]);

		if(row == 6 && col == 9){
			// print the routh here
			printf("The route is : ");

            while((!isEmptyStack_link(rowStack)) && (!isEmptyStack_link(colStack))){
		        printf("(%d, %d) -> ", pop_link(rowStack), pop_link(colStack));	
			}

            return 0;
		}
        
	    // go left
		if(maze[row][col - 1] == 1 && judgeMaze[row][col] == 4){
			push_link(rowStack, row);
		    push_link(colStack, col - 1);
			--judgeMaze[row][col];
			printf("Try to go left \n");
			continue;
		}
		else{
			if(judgeMaze[row][col] == 4)
		        --judgeMaze[row][col];
		}
	    
		// go up
		if(maze[row - 1][col] == 1 && judgeMaze[row][col] == 3){
		    push_link(rowStack, row - 1);
			push_link(colStack, col);
			--judgeMaze[row][col];
			printf("Try to go up\n");

			continue;
		}
		else{
			if(judgeMaze[row][col] == 3)
		        --judgeMaze[row][col];
		}

		// go right
		if(maze[row][col + 1] == 1 && judgeMaze[row][col] == 2){
			push_link(rowStack, row);
		    push_link(colStack, col + 1);
			--judgeMaze[row][col];
			printf("Try to go right\n");
			continue;
		} 
		else{
			if(judgeMaze[row][col] == 2)
		        --judgeMaze[row][col];    
		}

		// go down
		if(maze[row + 1][col] == 1 && judgeMaze[row][col] == 1){
		    push_link(rowStack, row + 1);
			push_link(colStack, col);
			--judgeMaze[row][col];
			printf("Try to go down\n");
			continue;
		}
		else{
			if(judgeMaze[row][col])
		        --judgeMaze[row][col];
		}

		// no direction to go, and then traceback
		DataType tmp1, tmp2;
		printf("Trace back a step \n");
		tmp1 = pop_link(rowStack);
		tmp2 = pop_link(colStack);
	}	

    if(isEmptyStack_link(rowStack) && isEmptyStack_link(colStack)){
		printf("Can not find the route ... \n");
    }
			
	return 0;
}


