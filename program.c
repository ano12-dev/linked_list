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
	int usr_input = 1;
	int _number, _pos, _old, _new, _sno, _del;
	char boo;
	first_node = NULL;
	while(usr_input != 0)
	{
		printf(" Press 1 to Add: \n");
		printf(" Press 2 to Add from beginning: \n");
		printf(" Press 3 to Display items: \n");
		printf(" Press 4 to insert in between: \n");
		printf(" Press 5 to update item: \n");
		printf(" Press 6 to search item: \n");
		printf(" Press 7 to delete item: \n");
		printf(" Press 8 to reverse the whole list: \n");
		printf(" Press 0 to exit: \n");
		printf(" Please enter your choice: ");
		scanf("%d",&usr_input);
		putchar('\n');
		switch(usr_input)
		{
			case 1:
				printf(" You have selected to add a number, please enter the number: ");
				scanf("%d",&_number);
				add(_number);
				break;
			case 2:
				printf(" You have selected to add number from beginning, please enter the number: ");
				scanf("%d",&_number);
				add_beg(_number);
				break;
			case 3:
				printf(" You have selected to display items: \n");
				display();
				break;
			case 4:
				printf(" You have selected to inster item in between: \n");
				printf(" Please enter the position you wish to enter the number in: ");
				scanf("%d",&_pos);
				putchar('\n');
				printf(" Please enter the number you wish to enter: ");
				scanf("%d",&_number);
				insert(_pos,_number);
				break;
			case 5:
				printf(" You have selected to update the item in a list: \n");
				printf(" Please enter the item you wish to update: \n");
				printf(" Here are your items: \n");
				display();
				printf(" Enter the item from the above list to update: ");
				scanf("%d",&_old);
				printf(" Enter the number to replace the selected item: ");
				scanf("%d",&_new);
				update(_old,_new);
				break;
			case 6:
				printf(" Enter the number you wish to search: \n");
				scanf("%d",&_sno);
				_pos = search(_sno);
				if(_pos != -1)
					printf(" Search number found at %d position.\n", _pos);
				else
					printf(" Search number not found.\n");
				break;
			case 7:
				printf(" You have selected to delete an item.\n");
				printf(" Here are your items. Select any one you wish to delete\n");
				display();
				printf(" Enter the item you wish to delete: ");
				scanf("%d",&_number);
				//printf(" Are you sure Y/N: ");
				//scanf("%c",&boo);
				//if(boo == 'Y' || boo == 'y')
				delete(_number);
				break;
			case 8:
				printf(" You have selected to reverse the whole list: \n");
				reverse();
				break;
			case 0:
				break;
			default:
				printf(" Please select the correct option.\n");
				break;
		}
				
	}
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
void reverse()
{
	struct node *current, *pre, *next;
	pre = first_node;
	current = first_node->next;
	pre->next = NULL;
	while(current != NULL) {
		next = current->next;
		current->next = pre;
		pre = current;
		current = next;
	}
	first_node = pre;
}
