#include<stdio.h>
#include<stdlib.h>
void add(int);
void display();
void add_beg(int);
int search(int);
void insert(int, int);
void update(int, int);
void delete(int);
void reverse();
struct node {
	int value;
	struct node *next;
}*first_node;

int main()
{
	first_node = NULL;
      	add(30);
	add_beg(20);
	add(44);
	add_beg(334);
	insert(2,300);
	display();
	update(20,200);
	printf(" After Update\n");
	display();
	printf(" Delete\n");
	delete(334);
	printf(" After delete\n");
	display();
	printf(" After reverse\n");
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
int search(int no)
{
	int pos = 1;
	struct node *tmp;
	tmp = first_node;
	while(tmp != NULL) {
		if(tmp->value == no)
			return pos;
		tmp = tmp->next;
		pos++;
	}
	return -1;

}
void insert(int pos, int data)
{
	int tot = 0;
	struct node *tmp, *new_node;
	tmp = first_node;
	while(tmp != NULL) {
		tot++;
		tmp = tmp->next;
	}
	if(pos > tot) {
		printf(" Can not insert \n");
		return ;
	}
	tot = 1;
	tmp = first_node;
	while(tot < pos-1)
	{
		tmp = tmp->next;
		tot++;
	}
	new_node = (struct node*) malloc(sizeof(struct node));
	new_node->value = data;
	new_node->next = tmp->next;
	tmp->next = new_node;
}
void update(int old, int new)
{
	int pos;
	int i = 0;
	struct node *tmp;
	if((pos = search(old)) == -1) {
		printf(" Data not found\n");
		return ;
	}
	tmp = first_node;
	while(i < pos-1) {
		tmp = tmp->next;
		i++;
	}
	tmp->value = new;
}
void delete(int data)
{
	int pos;
	int i = 0;
	struct node *tmp, *tmp2;
	if((pos = search(data)) == -1) {
		printf("Data not found\n");
		return ;
	}
	else if(pos == 1)
	{
		first_node = first_node->next;
		return ;
	}
	tmp = first_node;
	tmp2 = first_node;
	while(i<pos-1) {
		tmp = tmp->next;
		i++;
	}
	i=0;
	while(i < pos-2) {
		tmp2 = tmp2->next;
		i++;
	}
	tmp2->next = tmp->next;
	free(tmp);
}
