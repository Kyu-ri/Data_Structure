#include <stdlib.h>
#include <stdio.h>

typedef struct node *treePointer;

typedef struct node {
	char data;
	treePointer leftChild, rightChild;
} node;

treePointer createNode(char newData) //���ο� node ����
{
	treePointer newNode = (treePointer)malloc(sizeof(node));
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	newNode->data = newData;

	return newNode;
}

void preorder(treePointer ptr) //preorder traversal
{
	if (ptr) {
		printf("%c", (*ptr).data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}


int main()
{
	char Data;
	char relation;
	char Child;

	while (1) {
		printf(">>");
		scanf_s("%c%c%c", &Data, &relation, &Child); // data �Է� �ޱ�
	
		treePointer nodeData = createNode(Data); // �Է¹��� data�� �������� ���ο� root node ����
	
		if (relation == 'F') { //���谡 F(father)�� ��

			treePointer nodeFather = createNode(Child);
			(*nodeData).leftChild = nodeFather;
			printf(">>");
			preorder(nodeData);

		}
		if (relation == 'M') { //���谡 M(mother)�� ��

			treePointer nodeMother = createNode(Child);
			(*nodeData).rightChild = nodeMother;
			printf(">>");
			preorder(nodeData);

		}

		if (relation =='?') { //���踦 ���� ��
			preorder(nodeData);
			if (Child == nodeData->leftChild) { //�Է¹��� Child���� preorder traversal�� ã�� data�� �ٷ� ���� ���̸� F�� ���
				printf(">>F");
			}
			else(Child == nodeData->rightChild) { //�Է¹��� Child���� preorder traversal�� ã�� data���� ������ tree treversal�� �����ϴ� ù��° ���̸� M�� ���
				printf(">>M");
			}

		}
		system("pause");
	}
	return 0;
}