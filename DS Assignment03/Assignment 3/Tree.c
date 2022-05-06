#include "Tree.h"

TNODE createNode(char data) {

	TNODE newNode = NULL;
	newNode = (TNODE)malloc(sizeof(NODE));
	if (newNode) {
		newNode->data = data;
		newNode->lChild = NULL;
		newNode->rChild = NULL;
		return newNode;
	}
	return NULL;
}

void insert(TREE* root, char data) {

	TNODE tempParent = NULL;
	TNODE tempEval = *root;
	TNODE newNode = NULL;

	while (tempEval != NULL) {
		tempParent = tempEval;

		if (tempEval->data == data) {
			return;
		}
		if (tempEval->data > data) {
			tempEval = tempEval->lChild;
		}
		else {
			tempEval = tempEval->rChild;
		}
	}

	newNode = createNode(data);

	if (newNode && tempParent) {

		if (newNode->data > tempParent->data) {
			tempParent->rChild = newNode;
		}
		else {
			tempParent->lChild = newNode;
		}
	}
	else {
		*root = newNode;
	}
}

TNODE search(TREE root, char searchLetter) {

	if (root == NULL) {
		return NULL;
	}
	if (searchLetter == root->data) {
		return root;
	}
	else if (searchLetter < root->data) {
		return search(root->lChild, searchLetter);
	}
	else {
		return search(root->rChild, searchLetter);
	}
}

int countNodes(TREE root) {

	int left, right;

	if (root) {

		left = countNodes(root->lChild);
		right = countNodes(root->rChild);

		return left + right + 1;
	}
	return 0;
}

int treeHeight(TREE root) {
	
	int leftHeight, rightHeight;

	if (!root) {
		return -1;
	}
	leftHeight = treeHeight(root->lChild);
	rightHeight = treeHeight(root->rChild);

	if (leftHeight > rightHeight) {
		return leftHeight + 1;
	}
	else {
		return rightHeight + 1;
	}
}

void displayTree(TREE root) {

	printf("Tree in-order: ");
	displayInorder(root);
	printf("\n");
}

void displayInorder(TREE root) {
	if (!root) {
		return;
	}
	//Inorder of B. tree. Values in acsending order by value;
	displayInorder(root->lChild);
	printf("%c", root->data);
	displayInorder(root->rChild);
}

void removeNodes(TREE root) {
	if (!root) {
		return;
	}
	removeNodes(root->lChild);
	free(root->lChild);
	removeNodes(root->rChild);
	free(root->rChild);
}