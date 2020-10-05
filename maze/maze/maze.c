#include <stdio.h>
#include <stdlib.h>


#define numRow 10
#define numCol 10
#define MAX_ROW 12
#define MAX_COL 12
#define MAX_STACK_SIZE 100 
#define TRUE 1               
#define FALSE 0                
#define EXIT_ROW MAX_ROW-1
#define EXIT_COL MAX_COL-1


typedef struct {
	short int row;
	short int col;
	short int dir;
}element;

typedef struct {
	short int vert;
	short int horiz;
}offsets;

offsets move[8] = {
{ -1, 0 },
{ -1, 1 },
{ 0, 1 },
{ 1, 1 },
{ 1, 0 },
{ 1, -1 },
{ 0, -1 },
{ -1, -1 }
};


element stack[MAX_STACK_SIZE];
int maze[MAX_ROW][MAX_COL];   
int mark[MAX_ROW][MAX_COL];   
void setup_maze();
void path();
element add(int *top, element position);
element delete(int* top);



int main(void) {

	setup_maze();
	path();

	return 0;
}

element add(int *top, element position) 
{
	(*top)++;
	stack[*top].row = position.row;
	stack[*top].col = position.col;
	stack[*top].dir = position.dir;
}


element delete(int* top)  
{
	element result;
	if (*top<0) {
		printf("Stack is Empty.\n");
	}
	else {
		result = stack[*top];
		(*top)--;
	}
	return result;
}

void path() { 
	int i, row, col, next_row, next_col, dir, found = FALSE;
	int top;
	element position;
	mark[1][1] = 1;
	top = 0;
	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].dir = 1;

	while (top>-1 && !found) {
		position = delete(&top);
		row = position.row;
		col = position.col;
		dir = position.dir;
		while (dir < 8 && !found) {
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;
			if (next_row == EXIT_ROW-1 && next_col == EXIT_COL-1 || next_row == EXIT_ROW-1 && next_col == EXIT_COL || next_row == EXIT_ROW && next_col == EXIT_COL-1)
				found = TRUE;
			else if (!maze[next_row][next_col] && !mark[next_row][next_col]) {
				mark[next_row][next_col] = 1;
				position.row = row;
				position.col = col;
				position.dir = ++dir;
				add(&top, position);
				row = next_row;
				col = next_col;
				dir = 0;
			}
			else ++dir;
		}
	}
	if (found) {
		printf("The path is : \n");
		printf("row col\n");
		for (i = 0; i <= top; i++)
			printf("%2d%5d\n", stack[i].row, stack[i].col);
		printf("%2d%5d\n", row, col);
	}
	else printf("The maze dose not have a path\n");
}


void setup_maze() { //maze setting 함수
	int i, j;
	short int maze0[numRow][numCol] = {
	{ 0,0,1,0,1,1,1,0,1,0 },
	{ 1,0,0,1,1,1,0,1,0,1 },
	{ 1,0,0,0,1,0,1,0,1,1 },
	{ 0,0,0,0,1,0,1,0,0,0 },
	{ 0,1,0,0,0,0,1,0,1,0 },
	{ 1,0,1,0,0,1,1,0,1,0 },
	{ 1,1,0,0,0,1,0,0,1,0 },
	{ 1,0,1,0,0,0,1,0,0,0 },
	{ 0,1,0,1,0,0,0,1,1,0 },
	{ 1,0,0,1,1,0,0,0,0,0 }
	};


	for (i = 0; i<numRow; i++) { //maze[][]에 maze0[][] 값 넣기
		for (j = 0; j < numCol; j++) {
			maze[i + 1][j + 1] = maze0[i][j];
		}

	}

	for (i = 0; i < MAX_ROW; i++)
		for (j = 0; j < MAX_COL; j++) {
			if (i == 0 || j == 0 || i == MAX_ROW - 1 || j == MAX_COL - 1)
				maze[i][j] = 1; // 미로를 1로 테두리침
		}




}
