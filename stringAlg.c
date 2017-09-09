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
// to understand the KMP algri
// how to get the lenth of max equivalent prefix and suffix
// improve the alg to get next[]  20170909
void makeNext(const char * sub_str, int * next){
	int p, max_len;
	
	next[0] = 0;

	for(p = 1, max_len = 0; p < strlen(sub_str); ++p){
        while(max_len > 0 && sub_str[p] != sub_str[max_len]){
		    max_len = next[max_len - 1];
		}

        if(sub_str[p] == sub_str[max_len])
		    ++max_len;

		if(sub_str[max_len] == sub_str[p])
			next[p] = next[max_len];
		else
            next[p] = max_len;		
	}

	int i = 0;
	while(i < strlen(sub_str)){
	    printf("the No.%d of next[] is : %d \n", i, next[i]);
		++i;
	}
}

// Knuth pattern-match
void KMP_match(const char * sub_str, const char * main_str, int *next){
    int sub_len = strlen(sub_str);
    int main_len = strlen(main_str);

    makeNext(sub_str, next);

	// begin to match main_str using sub_str
    int match_len = 0, match_mainloc = 0, match_subloc = 0;   
	for(; match_mainloc < main_len; ++match_mainloc){
    // the process that doing the match
        while(match_subloc > 0 && sub_str[match_subloc] != main_str[match_mainloc]){
		    match_subloc = next[match_subloc - 1];
		}

		if(sub_str[match_subloc] == main_str[match_mainloc]){
		    ++match_subloc;
		}

		if(match_subloc == sub_len)
			printf("Pattern occurs with shift : %d \n", (match_mainloc - sub_len + 1));
	}
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

	char * test_next = "abcdabcdaazeyu";
	makeNext(test_next, next);

	return 0;

}
