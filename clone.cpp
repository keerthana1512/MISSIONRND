#include<stdio.h>
#include<stdlib.h>

struct rnode{
	int data;
	struct rnode *next;
	struct rnode *random;
};


struct rnode * createNode(int num) {
	struct rnode *newNode = (struct rnode *)malloc(sizeof(struct rnode));
	newNode->data = num;
	newNode->next = NULL;
	newNode->random = NULL;
	return newNode;
}


struct rnode * clone(struct rnode * head)
{
	struct rnode *start = head;
	while (head != NULL)
	{
		struct rnode *temp = createNode(head->data);
		temp->next = head->next;
		head->next = temp;
		head = head->next->next;
	}
	head = start;
	while (head != NULL)
	{
		if (head->random != NULL)
			head->next->random = head->random->next;
		head = head->next->next;
	}
	struct rnode *tmp = start->next;
	while (tmp->next != NULL)
	{
		tmp->next = tmp->next->next;
		tmp = tmp->next;
	}
	return start->next;
}


void testclone()
{
	struct rnode *temp1 = createNode(1);
	struct rnode *temp2 = createNode(2);
	struct rnode *temp3 = createNode(3);
	struct rnode *temp4 = createNode(4);
	struct rnode *temp5 = createNode(5);
	struct rnode *temp6 = createNode(6);

	temp1->next = temp2;
	temp2->next = temp3;
	temp3->next = temp4;
	temp4->next = temp5;
	temp5->next = temp6;
	temp6->next = NULL;
	temp1->random = temp3;
	temp2->random = temp5;
	temp3->random = NULL;
	temp4->random = temp5;
	temp5->random = NULL;
	temp6->random = temp4;

	struct rnode *head = clone(temp1);
	struct rnode *temp = head;
	while (temp != NULL)
	{
		printf("%d-", temp->data);
		temp = temp->next;
	}
	printf("\n");
	printf("Random:\n");
	while (head != NULL)
	{
		if (head->random != NULL)
			printf("%d-%d\n", head->data, head->random->data);
		head = head->next;
	}
}


int main()
{
	testclone();
	return 0;
}