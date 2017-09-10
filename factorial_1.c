#include <stdio.h>
#include <stdlib.h>

int factorial(int endValue){

    int factValue = endValue;

	// recursion base
	if(endValue > 1){
	    factValue *= factorial(endValue - 1);
	}

	return factValue;
}


int main(void){
    printf("Please input the factorial number : ");

	int endValue;
	scanf("%d", &endValue);

	printf("The factorial number for %d is : %d \n", endValue, factorial(endValue));

	return 0;
}
