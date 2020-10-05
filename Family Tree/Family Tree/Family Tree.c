#include <stdlib.h>
#include <stdio.h>

typedef struct node *treePointer;

typedef struct node {
	char data;
	treePointer leftChild, rightChild;
} node;

treePointer createNode(char newData) //새로운 node 만듦
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
		scanf_s("%c%c%c", &Data, &relation, &Child); // data 입력 받기
	
		treePointer nodeData = createNode(Data); // 입력받은 data를 바탕으로 새로운 root node 만듦
	
		if (relation == 'F') { //관계가 F(father)일 때

			treePointer nodeFather = createNode(Child);
			(*nodeData).leftChild = nodeFather;
			printf(">>");
			preorder(nodeData);

		}
		if (relation == 'M') { //관계가 M(mother)일 때

			treePointer nodeMother = createNode(Child);
			(*nodeData).rightChild = nodeMother;
			printf(">>");
			preorder(nodeData);

		}

		if (relation =='?') { //관계를 물을 때
			preorder(nodeData);
			if (Child == nodeData->leftChild) { //입력받은 Child값이 preorder traversal로 찾은 data의 바로 다음 값이면 F를 출력
				printf(">>F");
			}
			else(Child == nodeData->rightChild) { //입력받은 Child값이 preorder traversal로 찾은 data에서 오른쪽 tree treversal을 시작하는 첫번째 값이면 M을 출력
				printf(">>M");
			}

		}
		system("pause");
	}
	return 0;
}