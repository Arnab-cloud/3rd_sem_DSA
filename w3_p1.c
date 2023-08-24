#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
}typedef node;

node* createNode(int data)
{
	node* new = (node*)malloc(sizeof(node));
	new->data = data;
	new->next = NULL;
	
	return new;
}

int isEmpty(node** head)
{	
	return !(*head);
}

void print_linkedList(node** head)
{
	printf("Linked list upto now:\n\n");
	node* temp = *head;
	while(temp)
	{
		printf("%d--> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n\n");
}

void insert_at_start(node** head, int data)
{
	if(!head)
	{
		*head = createNode(data);
		return ;
	}
	
	node* new = createNode(data);
	new->next = *head;
	*head = new;
}

void insert_at_any_pos(node** head, int data, int pos)
{
	if(pos == 1)
	{
		insert_at_start(head,data);
		return;
	}
	
	node* temp = *head;
	int i=1;
	while(temp && (i++) != pos-1)
		temp = temp->next;
	
	if(!temp)
	{
		printf("ERROR: Out of bound\n");
		return;
	}
	
	node* new = createNode(data);
	new->next = temp->next;
	temp->next = new;
}

void insert_at_end(node** head, int data)
{
	if(isEmpty(head) && ((*head) = createNode(data)))
		return;
	node* temp = *head;
	while(temp->next)
		temp = temp->next;
	node* new = createNode(data);
	temp->next = new;
}

void delete_from_start(node** head)
{
	if(isEmpty(head) && printf("ERROR: List is already empty\n"))
		return;
	node* temp = *head;
	*head = temp->next;
	free(temp);
}

void delete_from_any_pos(node** head,int pos)
{
	if(isEmpty(head) && printf("ERROR: List is already empty\n"))
		return;
	if(pos ==1)
	{
		delete_from_start(head);
		return;
	}
	node* ptr = *head, *prePtr;
	int i=1;
	while(ptr && i++ != pos)
	{
		prePtr = ptr;
		ptr = ptr->next;
	}
	
	if(!ptr)
	{
		printf("ERROR: Out of bound\n");
		return;
	}
	
	prePtr->next = ptr->next;
	
	free(ptr);	
}

void delete_from_end(node** head)
{
	if(isEmpty(head) && printf("ERROR: List is already empty\n"))
		return;
	node* ptr = *head;
	if(!(*head)->next)
	{
		free(ptr);
		*head = NULL;
		return;
	}
	node* prePtr = ptr;
	while(ptr->next && (prePtr = ptr) &&(ptr = ptr->next));
	
	free(ptr);
	prePtr->next = NULL;
}

void delete_list(node* head)
{
	if(!head)
		return;
	delete_list(head->next);
	free(head);
}


int main()
{
	int ch, data, pos, choice;
	while(1)
	{
		printf("\nMENU:\n");
		printf("1. Create a new linked list\n2. Insert at start\n3. Insert at any positon\n4. Insert at end\n5. Delete from start\n6. Delete from any position\n7. Delete from end\n8. Print the list\n9. Exit\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				node* head = NULL;
				printf("Creating a new linked list...\n");
				while(1)
				{
					printf("Enter the value to be stored: ");
					scanf("%d", &data);
					insert_at_end(&head,data);
					printf("Continue? \"Yes\" = 1 \"NO\" = 0 : ");
					scanf("%d",&choice);
					if(!choice)
						break;
				}
				break;
			case 2:
				printf("Enter the value to be inserted: ");
				scanf("%d",&data);
				insert_at_start(&head,data);
				break;
			case 3:
				printf("Enter the Position: ");
				scanf("%d", &pos);
				printf("Enter the value to be inserted: ");
				scanf("%d",&data);
				insert_at_any_pos(&head,data,pos);
				break;
			case 4:
				printf("Enter the value to be inserted: ");
				scanf("%d",&data);
				insert_at_end(&head,data);
				break;
			case 5:
				delete_from_start(&head);
				break;
			case 6:
				printf("Enter the Position: ");
				scanf("%d", &pos);
				delete_from_any_pos(&head,pos);
				break;
			case 7:
				delete_from_end(&head);
				break;
			case 8:
				print_linkedList(&head);
				break;
			case 9:
				printf("\nEXITING...\n\n");
				delete_list(head);
				exit(0);
			default:
				printf("ERROR: You entered wrong choice\n");
		}
	}
	return 0;
}
