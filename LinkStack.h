#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef int DataType;

// basic struct
struct Node;
typedef struct Node * PNode;
struct Node{
    DataType info;
    PNode link;	
};

// top node
struct LinkStack{
    PNode top;
};

typedef struct LinkStack * PLinkStack;

extern PLinkStack createEmptyStack_link(void);
extern int isEmptyStack_link(PLinkStack plstack);
extern void push_link(PLinkStack plstack, DataType x);
extern DataType pop_link(PLinkStack plstack);
extern DataType top_link(PLinkStack plstack);

#endif
