#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct treeNode {
	char data;
	struct treeNode* lChild;
	struct treeNode* rChild;
}NODE, *TNODE, *TREE;


TNODE createNode(char);

void insert(TREE*, char);

TNODE search(TREE, char);

int countNodes(TREE);

int treeHeight(TREE);

void displayTree(TREE);

void displayInorder(TREE);

void removeNodes(TREE);

