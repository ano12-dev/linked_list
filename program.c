#include<stdio.h>
#include<stdlib.h>
void add(int);
void display();
void add_beg(int);
struct node {
	int value;
	struct node *next;
}*first_node;

int main()
{
	first_node = NULL;
	add(30);
	add_beg(20);
	display();
	return 0;
}
void add(int data)
{
	struct node *new_node,*p;
	new_node = (struct node*) malloc(sizeof(struct node));
	new_node->value = data;
	new_node->next = NULL;
	if(first_node == NULL)
		first_node = new_node;
	else {
		p = first_node;
		while(p->next != NULL)
			p = p->next;
		p->next = new_node;
	}
}
void display()
{
	struct node *tmp;
	tmp = first_node;
	if(first_node == NULL) {
		printf(" No data to display\n");
		return ;
	}
	while(tmp != NULL) {
		printf("%d\n",tmp->value);
		tmp = tmp->next;
	}
}
void add_beg(int data)
{
	struct node *new_node;
	new_node = (struct node *) malloc(sizeof(struct node));
	new_node->value = data;
	new_node->next = first_node;
	first_node = new_node;
}
