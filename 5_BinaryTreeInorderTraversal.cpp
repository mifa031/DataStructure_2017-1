#include <stdio.h>
#include <malloc.h>
#include <string.h>

char* treeInfo[] = { "L.A","R.B",
"LL.C","LR.D","RL.E","RR.F",
"LLL.G","LLR.H","LRL.I" };  // ����Ʈ�� ����

typedef struct node* treePointer;
typedef struct node {
	char* data;
	treePointer leftChild;
	treePointer rightChild;
};

void inorder(treePointer ptr);

void main() {
	treePointer node;

	treePointer root; // ��Ʈ ��� ����
	root = (treePointer)malloc(sizeof(treePointer));
	root->data = "root";
	root->leftChild = NULL;
	root->rightChild = NULL;

	int i = 0;
	while (treeInfo[i]) { // �о�� Ʈ�� ������ �˸°� ����Ʈ�� ����
		node = root;
		for (int j = 0; j < strlen(treeInfo[i]); j++) {
			if (treeInfo[i][j] == 'L') {
				if (node->leftChild == NULL) {
					node->leftChild = (treePointer)malloc(sizeof(treePointer));
					node->leftChild->leftChild = NULL;
					node->leftChild->rightChild = NULL;
					if (treeInfo[i][j + 1] == '.') {
						node->leftChild->data = &treeInfo[i][j + 2];
						j = strlen(treeInfo[i]) - 1;
					}
				}
				node = node->leftChild;
			}
			if (treeInfo[i][j] == 'R') {
				if (node->rightChild == NULL) {
					node->rightChild = (treePointer)malloc(sizeof(treePointer));
					node->rightChild->leftChild = NULL;
					node->rightChild->rightChild = NULL;
					if (treeInfo[i][j + 1] == '.') {
						node->rightChild->data = &treeInfo[i][j + 2];
						j = strlen(treeInfo[i]) - 1;
					}
				}
				node = node->rightChild;
			}
		}
		i++;
	}

	printf("\n��������ȸ ���\n");
	inorder(root); // ��Ʈ������ �����Ͽ� ������ȸ
	printf("\n\n");
}

void inorder(treePointer ptr) // ������ȸ ��� �Լ�
{
	if (ptr) {
		inorder(ptr->leftChild);
		printf("%s ", ptr->data);
		inorder(ptr->rightChild);
	}
}