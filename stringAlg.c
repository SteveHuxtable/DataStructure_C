/*
 *
 * 
 * string alg 
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a string
struct SeqString{

	int MAXNUM;
	int n;
	char *c;
};

typedef struct SeqString * PSeqString;

// create a empty string
PSeqString creat_String(){
	PSeqString p_str = (PSeqString) malloc (sizeof(struct SeqString));

    if(p_str != NULL){
		// why m ???	
	    // p_str -> c = (char *) malloc (sizeof(char) * m);
		printf("Create a sequential string !! \n");
		return p_str;
	}

	else
		free(p_str);
	printf("Out of space !! \n");
	return NULL;

}

// find the location of str_m in seq_str
void simple_find_substr(char * sub_str, char * main_str){

    char * sub_p = sub_str;
	char * main_p = main_str;

	printf("sub_str : %s  \nmain_str : %s \n", sub_p, main_p);
	printf("length of sub_str is : %ld \n", strlen(sub_str));
	printf("length of main_str is : %ld \n", strlen(main_str));

	int len_sub = strlen(sub_str);
	int len_main = strlen(main_str);

	if(len_sub > len_main){
	    printf("The substr should be shorter than mainstr !! \n");
		exit(-1);
	}

	// the simple way to find substring's location
	for(int start = 0; start + len_sub <= len_main; ++ start){

		int tmp_start = start;

	    for(int count = 0; sub_p[count] == main_p[tmp_start]; ++count, ++tmp_start){
		    if(count == len_sub - 1){
			    printf("The sub_str in at location [%d] \n", start);
				return;
			}    
		}	
	}

	printf("Can not find sub_str in the main_str \n");
}

// the alg to calculate next
void makeNext(char * sub_str, int * next){
    int i = 0, k = -1;
	
	next[0] = -1;
	
	while(i < strlen(sub_str)){

	    while(k >= 0 && sub_str[i] != sub_str[k])
			k = next[k];

	    ++i;
	    ++k;
	    
		next[i] = k;	
	}
}




// Knuth pattern-match
void Knuth_pmatch(char * sub_str, char * main_str){
	char * sub_p = sub_str;
    char * main_p = main_str;

}

int main(){
    int m;

    int * next;

	PSeqString seq_str;
	seq_str = creat_String();

	// define a string
	char * str_m = "VWXYZ";
	printf("The main string is : %s \n", str_m);
	printf("The length of str_m is : %ld \n", strlen(str_m));

	// initiate seq_str, give a string to seq_str -> c
	seq_str -> c = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("The seq_str is : %s \n", seq_str -> c);
	printf("The length of seq_str is : %ld \n", strlen(seq_str -> c));

	// find the location of str_m in seq_str
	simple_find_substr(str_m, seq_str -> c);

	return 0;

}
