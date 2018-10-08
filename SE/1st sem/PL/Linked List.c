/*
 ============================================================================
 Name        : linked.c
 Author      : Devashish
 Version     : 1.0
 Copyright   : GNU Public Licence
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node* getNode()
{
	struct Node *temp;
	temp = (struct Node *) malloc(sizeof(temp));
	printf("\n Enter the data for the Node - ");
	scanf("%d", &temp->data);
	temp->next = NULL;
	return temp;
}

void display(struct Node *h)
{
	while(h != NULL)
	{
		printf(" %d -> ", h->data);
		h = h->next;
	}
}

struct Node * reverse (struct Node * head)
{
	struct Node *c, *t, *r;
	t = NULL;
	c = head;
	r = NULL;

	if(head->next == NULL)
		return head;
	
	while(c != NULL)
	{
		printf(" ** ");
		t = c->next;
		c->next = r;
		r = c;
		c = t;
	}

	head = r;
	return head;
} 
int main(void) {

	int i, n, ch, pos;
	struct Node *p, *t, *head=NULL;

	printf("\n Creating the Head -");

	head = getNode();

	printf("\n How many elements do you want to enter - ");
	scanf("%d", &n);

	p = head;

	for(i = 0; i < n; i++)
	{
		p->next = getNode();
		p = p->next;
	}
	do{
		printf("\n\n\n MENU - ");
		printf("\n 1. Insert at front");
		printf("\n 2. Insert in middle");
		printf("\n 3. Insert at last");
		printf("\n 4. Delete from front");
		printf("\n 5. Delete from middle");
		printf("\n 6. Delete from last");
		printf("\n 7. Reverse the list");
		printf("\n 8. Display the list");
		printf("\n 9. Exit");
		printf("\n Enter your choice - ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					printf("\n\n Inserting at front - \n");
					t = getNode();
					t->next = head;
					head = t;
					break;
			case 2:
					printf("\n\n Inserting in middle - Enter the position - ");
					scanf("%d", &pos);
					t = getNode();			
					p = head;		
					for(i = 0; i < pos-2 && p->next != NULL ; i++)
						p = p->next;
					t->next = p->next;
					p->next = t;
					break;
			case 3:
					printf("\n\n Insertion at last - \n");
					t = getNode();
					p = head;
					while(p->next != NULL)
						p = p->next;
					p->next = t;	
					break;
			case 4:
					printf("\n\n Deletion at first - \n");
					t = head;
					head = head->next;
					free(t);
					printf("\n Deleted successfully");
					break;
			case 5:
					printf("\n\n Deletion at middle - Enter the position \n");
					scanf("%d", &pos);
					p = head;
					t = head;
					for(i = 0; i < pos-1 && p->next != NULL; i++)
					{
						t = p;
						p = p->next;
					}	

					t->next = p->next;
					free(p);
					printf("\n Deleted successfully");
					break;
			case 6:
					printf("\n\n Deletion at end - \n");
					p = head;
					t = head;
					while(p->next != NULL)
					{
						t = p;
						p = p->next;
					}	
					t->next = p->next;
					free(p);
					printf("\n Deleted successfully");
					break;
			case 7:
					printf("\n\n Reversing your list - ");
					head = reverse(head);
					display(head);
					break;
			case 8:
					printf("\n\n Your List - \n");
					display(head);
					printf(" NULL ");
					break;
			case 9:
					return 0;
			default:
					printf("\n Please enter a valid option");
		}
	}while(1);

	return 0;
}
