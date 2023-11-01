#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>

struct node{
	char *name;
	int age;
	int scoreM;
	int scoreF;
}typedef node;

int compare(const void *cp1, const void *cp2){
	return strcmp(((node *)cp1)->name, ((node *)cp2)->name);
}

void print_node(const void *, VISIT, int);

int main(){
	int num_st;
	int i = 0;
	void *root = NULL;
	node *nodeptr;
	node *nodetable;
	char* nametable;
	char* nameptr;
	node **ret;

	printf("학생의 수를 입력 : ");
	scanf("%d", &num_st);
	
	
	nodetable = (node *)malloc(sizeof(node) * num_st);
	nametable = (char *)malloc(sizeof(char) * 20 * num_st);

	nodeptr = nodetable;
	nameptr = nametable;

	while(scanf("%s%d%d%d", nameptr, &(nodeptr->age), &(nodeptr->scoreM), &(nodeptr->scoreF)) != EOF && i++ < num_st){
		nodeptr->name = nameptr;

		ret = (struct node **)tsearch((void *)nodeptr, (void **)&root, compare);
		printf("\"%s\"님이", (*ret)->name);
		if (*ret == nodeptr)
			printf("트리에 추가되었습니다.\n");
		else
			printf("트리에 이미 존재합니다.\n");
		nameptr += strlen(nameptr) + 1;
		nodeptr++;
	}
	twalk((void *)root, print_node);
}
void print_node(const void *nodeptr, VISIT order, int level){
	if (order == preorder || order == leaf)
		printf("이름 = %-10s, 나이 = %d, 중간성적 = %d, 기말성적 = %d\n", (*(node **)nodeptr)->name, (*(node **)nodeptr)->age, (*(node **)nodeptr)->scoreM, (*(node **)nodeptr)->scoreF);
}
