 /*
  C program to insert a new node at the beginning of a Singly Linked List
 */
 
#include <stdio.h>
#include <stdlib.h>
 
 
 
/* Structure of a node */
struct node {
    int data; //Data part
    struct node *next; //Address part
}*head;
 
 
 
void createList(int n);
void insertNodeAtBeginning(int data);
void displayList();



int main()
{
    int n, data;

     clrscr();
    /*
     * Creates a singly linked list of n nodes
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    /*
     * Inserts data at the beginning of the singly linked list
     */
    printf("\nEnter data to insert at beginning of the list: ");
    scanf("%d", &data);
    insertNodeAtBeginning(data);

    printf("\nData in the list \n");
    displayList();
     getch();
    return 0;
}



/*
 * Create a list of n nodes
 */
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    /*
     * If unable to allocate memory for head node
     */
    if(head == NULL)
    {
	printf("Unable to allocate memory.");
    }
    else
    {
	/*
	 * Reads data of node from the user
	 */
	printf("Enter the data of node 1: ");
	scanf("%d", &data);

	head->data = data; //Links the data field with data
	head->next = NULL; //Links the address field to NULL

	temp = head;

	/*
	 * Creates n nodes and adds to linked list
	 */
	for(i=2; i<=n; i++)
	{
	    newNode = (struct node *)malloc(sizeof(struct node));

	    /* If memory is not allocated for newNode */
	    if(newNode == NULL)
	    {
		printf("Unable to allocate memory.");
		break;
	    }
	    else
	    {
		printf("Enter the data of node %d: ", i);
		scanf("%d", &data);

		newNode->data = data; //Links the data field of newNode with data
		newNode->next = NULL; //Links the address field of newNode with NULL

		temp->next = newNode; //Links previous node i.e. temp to the newNode

		temp = temp->next;
	    }
	}

	printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}



/*
 * Creates a new node and inserts at the beginning of the linked list.
 */
void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
	printf("Unable to allocate memory.");
    }
    else
    {
	newNode->data = data; //Links the data part
	newNode->next = head; //Links the address part

	head = newNode; //Makes newNode as first node

	printf("DATA INSERTED SUCCESSFULLY\n");
    }
}



/*
 * Displays the entire list
 */
void displayList()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL
     */
    if(head == NULL)
    {
	printf("List is empty.");
    }
    else
    {
	temp = head;
	while(temp != NULL)
	{
	    printf("Data = %d\n", temp->data); //Prints the data of current node
	    temp = temp->next; //Advances the position of current node
	}
    }
}
