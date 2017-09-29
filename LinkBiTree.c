#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DataType int

// define the struct of BiTreeNode and BiTree

typedef struct BiTreeNode{
    
	DataType info;

	struct BiTreeNode * lchild;
	struct BiTreeNode * rchild;

}BiTreeNode, * PBiTreeNode;

typedef struct RootNode{
    PBiTreeNode rootNode;
}RootNode, * PBiTree;
/* PBiTree point to the root_node of the BiTree */


// create a BiTree only with a root_node
PBiTree createBiTree();
/*
// destroy a BiTree using the recursion method
int destroyBiTree(PBiTree pbitree);
*/
// check if the tree is empty
int checkEmptyTree(PBiTree pbitree);

void addLchild(PBiTreeNode node);
void addRchild(PBiTreeNode node);
// delete the left leaf, right leaf
int checkLeaf(PBiTreeNode node);
void delLleaf(PBiTreeNode node);
void delRleaf(PBiTreeNode node);

// preorder traversal
DataType * preorderBiTree(PBiTree pbitree);

/*
// delete the left child of a node in a binary tree
int delLeft(PBiTree pbitree, PBiTreeNode node);
// delete the right child of a node in a binary tree
int defRight(PBiTree pbitree, PBiTreeNode  node);
// order traversal
DataType * orderBiTree(PBiTree pbitree);
// posterior traversal
DataType * posteriorBitree(PBiTree pbitree);
// merge two binary trees
PBiTree mergeBiTree(PBiTree leftBiTree, PBiTree rightBiTree);
*/
// get the info of a node
void printInfo(PBiTreeNode node);

int main(void){

    PBiTree pbitree = createBiTree();

    // simple method to construct a node
	addLchild(pbitree->rootNode);
	addRchild(pbitree->rootNode);
    addLchild(pbitree->rootNode->lchild);
    addRchild(pbitree->rootNode->lchild);
    addLchild(pbitree->rootNode->rchild);
    addRchild(pbitree->rootNode->rchild);
	addLchild(pbitree->rootNode->lchild->lchild);

	// preorder

	return 0; 
}

PBiTree createBiTree(void){
    PBiTree pbitree = (PBiTree)malloc(sizeof(struct RootNode));

    if(pbitree == NULL){
	    printf("Out of space ! \n");
		exit(-1);
	}
    else{
	    // create the root value 
		printf("Please input the info of the root : ");
		DataType tempInfo;
		scanf("%d", &tempInfo);
		// create the space for the root node
		PBiTreeNode rootNode = (PBiTreeNode)malloc(sizeof(struct BiTreeNode));
		if(rootNode == NULL){
		    printf("Out of space ! \n");
			exit(-1);
		}
		else{
		    rootNode->info = tempInfo;
			rootNode->lchild = NULL;
			rootNode->rchild = NULL;
			pbitree->rootNode = rootNode;

			printf("Create an empty binary tree successfully ! \n");

			return pbitree;
		}
	}
}

int checkEmptyTree(PBiTree pbitree){

   return (pbitree->rootNode == NULL); 

}

void addLchild(PBiTreeNode node){
    if(node->lchild != NULL){
	    printf("The node has left child already! \n");
		return;
	}
	else{
	    PBiTreeNode Lchild = (PBiTreeNode)malloc(sizeof(struct BiTreeNode));
		DataType tempValue;
		printf("Please input the value of the left child : ");
		scanf("%d", &tempValue);
		Lchild->info = tempValue;
		Lchild->lchild = NULL;
		Lchild->rchild = NULL;
		node->lchild = Lchild;
		printf("Add a left child successfully ! \n");
	}
}

void addRchild(PBiTreeNode node){
    if(node->rchild != NULL){
	    printf("The node has right child already! \n");
		return;
	}
	else{
	    PBiTreeNode Rchild = (PBiTreeNode)malloc(sizeof(struct BiTreeNode));
		DataType tempValue;
		printf("Please input the value of the right child : ");
		scanf("%d", &tempValue);
		Rchild->info = tempValue;
		Rchild->lchild = NULL;
		Rchild->rchild = NULL;
		node->rchild = Rchild;
		printf("Add a right child successfully ! \n");
	}
}

int checkLeaf(PBiTreeNode node){
    return ((node->lchild == NULL)&&(node->rchild == NULL));
}

void delLleaf(PBiTreeNode node){
    if(node->lchild == NULL){
		printf("The node has no left child !\n");
		return;
	}
	else{
	    if(checkLeaf(node->lchild)){
		    PBiTreeNode tempNode;
			tempNode = node->lchild;
			node->lchild = NULL;
			free(tempNode);
			printf("Delete the node's left child which is a leaf ! \n");
		}
		else{
		    printf("The node's left child is not a leaf, can not delete it straightly ! You can use the method that deleting a tree to do this ! \n"); 
		}
	}
}

void delRleaf(PBiTreeNode node){
    if(node->rchild == NULL){
		printf("The node has no right child !\n");
		return;
	}
	else{
	    if(checkLeaf(node->rchild)){
		    PBiTreeNode tempNode;
			tempNode = node->rchild;
			node->rchild = NULL;
			free(tempNode);
			printf("Delete the node's right child which is a leaf ! \n");
		}
		else{
		    printf("The node's right child is not a leaf, can not delete it straightly ! You can use the method that deleting a tree to do this ! \n"); 
		}
	}
}


void printInfo(PBiTreeNode node){
    printf("this node is : %d\n", node->info);    
}

DataType * preorderBiTree(PBiTree pbitree){
    if(pbitree == NULL)
	    return;
    printInfo();	
}
