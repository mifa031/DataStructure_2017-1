#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_NODES 100

char* treeInfo[] = { "L.A","R.B",
"LL.C","LR.D","RL.E","RR.F",
"LLL.G","LLR.H","LRL.I",'\0' };

int post_seq = 1;
int first_in = TRUE;

typedef struct threadedTree *threadedPointer;
typedef struct threadedTree {
	short int leftThread;
	threadedPointer leftChild;
	char data;
	threadedPointer rightChild;
	short int rightThread;
};

threadedPointer node;
threadedPointer root;
threadedPointer node0;
threadedPointer child[MAX_NODES];

threadedPointer postsucc(threadedPointer tree);  //������ȸ �ļ��� ����
void postorder(threadedPointer tree);  //������ȸ ����
void insertLeft(threadedPointer parent, threadedPointer child);
void insertRight(threadedPointer parent, threadedPointer child);
threadedPointer insucc(threadedPointer tree); // ������ȸ �ļ��� ����
threadedPointer inPredec(threadedPointer tree); // ������ȸ ������ ����

void main() {
	root = (threadedPointer)malloc(sizeof(threadedPointer));
	node0 = (threadedPointer)malloc(sizeof(threadedPointer));

	root->data = '-';
	root->rightChild = root;
	root->rightThread = FALSE;
	root->leftChild = node0;
	root->leftThread = FALSE;

	node0->data = 'Z';
	node0->leftChild = root;
	node0->leftThread = TRUE;
	node0->rightChild = root;
	node0->rightThread = TRUE;

	int i = 0;
	int num = 0;
	while (treeInfo[i]) { // Ʈ�� ������ �˸°� Ʈ�� ����
		node = node0;
		for (int j = 0; j < strlen(treeInfo[i]); j++) {
			if (treeInfo[i][j] == 'L') {
				if (node->leftThread == TRUE) {
					child[num] = (threadedPointer)malloc(sizeof(threadedTree));
					insertLeft(node, child[num]);
					num++;
					if (treeInfo[i][j + 1] == '.') {
						node->leftChild->data = treeInfo[i][j + 2];
						j = strlen(treeInfo[i]) - 1;
					}
				}
				node = node->leftChild;
			}
			if (treeInfo[i][j] == 'R') {
				if (node->rightThread == TRUE) {
					child[num] = (threadedPointer)malloc(sizeof(threadedTree));
					insertRight(node, child[num]);
					num++;
					if (treeInfo[i][j + 1] == '.') {
						node->rightChild->data = treeInfo[i][j + 2];
						j = strlen(treeInfo[i]) - 1;
					}
				}
				node = node->rightChild;
			}
		}
		i++;
	}
	printf("\n��������ȸ ���\n");
	postorder(root);
	printf("\n\n");
}

threadedPointer postsucc(threadedPointer tree) {//������ȸ �ļ��� ���ϴ� �Լ�
	threadedPointer temp;   //3�ܰ�� ���� �ܰ躰 �ൿ �����ϰ� �Լ� ȣ��ø��� 1~3�ܰ� �ݺ�

	if (post_seq == 1) {
		temp = tree;
		if (first_in != TRUE) {
			while (!temp->rightThread)
				temp = temp->rightChild;
		}
		temp = temp->rightChild->rightChild;
		if (first_in != TRUE) {
			if (temp == root) {
				return temp;
			}
		}
		first_in = FALSE;
		while (!temp->leftThread)
			temp = temp->leftChild;
		post_seq++;
	}
	else if (post_seq == 2) {
		temp = tree->rightChild;
		if (temp->rightThread == FALSE)
			temp = tree->rightChild->rightChild;
		post_seq++;
	}
	else if (post_seq == 3) {
		temp = tree;
		if (temp->leftThread == TRUE) {
			temp = tree->leftChild;
		}
		else if (temp->leftThread == FALSE) {
			while (!temp->leftThread)
				temp = temp->leftChild;
			temp = temp->leftChild;
		}
		post_seq = 1;
	}

	return temp;
}

void postorder(threadedPointer root) {
	threadedPointer temp = root;
	for (;;) {
		temp = postsucc(temp);
		if (temp == root) {
			printf("%c ", root->leftChild->data);
			break;
		}
		else {
			printf("%c ", temp->data);
		}
	}
}

void insertRight(threadedPointer parent, threadedPointer child)
{
	threadedPointer temp;

	child->rightChild = parent->rightChild;
	child->rightThread = parent->rightThread;
	child->leftChild = parent;
	child->leftThread = TRUE;
	parent->rightChild = child;
	parent->rightThread = FALSE;
	if (!child->rightThread) {
		temp = insucc(child);
		temp->leftChild = child;
	}
}

void insertLeft(threadedPointer parent, threadedPointer child)
{
	threadedPointer temp;

	child->leftChild = parent->leftChild;
	child->leftThread = parent->leftThread;
	child->rightChild = parent;
	child->rightThread = TRUE;
	parent->leftChild = child;
	parent->leftThread = FALSE;
	if (!child->leftThread) {
		temp = inPredec(child);
		temp->rightChild = child;
	}
}

threadedPointer insucc(threadedPointer tree)
{
	threadedPointer temp;
	temp = tree->rightChild;
	if (!tree->rightThread)
		while (!temp->leftThread)
			temp = temp->leftChild;
	return temp;
}

threadedPointer inPredec(threadedPointer tree)
{
	threadedPointer temp;
	temp = tree->leftChild;
	if (!tree->leftThread)
		while (!temp->rightThread)
			temp = temp->rightChild;
	return temp;
}