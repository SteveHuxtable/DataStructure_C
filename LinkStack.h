#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

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

PLinkStack createEmptyStack_link(void);

int isEmptyStack_link(PLinkStack plstack);

void push_link(PLinkStack plstack, DataType x);

DataType pop_link(PLinkStack plstack);

DataType top_link(PLinkStack plstack);

#endif
