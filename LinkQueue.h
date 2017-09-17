#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#define DataType int
typedef struct Node{
    DataType info;
    struct Node * next;	
}Node , * PNode;

typedef struct LinkQueue{
    PNode head;
	PNode tail;
}LinkQueue, * PLinkQueue;


PLinkQueue createEmptyQueue_link(void);
int isEmptyQueue_link(PLinkQueue plqu);
void enQueue_link(PLinkQueue plqu, DataType x);
DataType deQueue_link(PLinkQueue plqu);
DataType headQueue_link(PLinkQueue plqu);


#endif
