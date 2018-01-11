#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}


int count(struct Node* head, int search_for)
{
    struct Node* current = head;
    int count = 0;
    while (current != NULL)
    {
        if (current->data == search_for)
           count++;
        current = current->next;
    }
    return count;
}


int main()
{
    int i,n,x,y;

    struct Node* head = NULL;
    printf("Give the number of components: ");
    scanf("%d",&n);

    printf("\nGive the number to search for in the list:");
    scanf("%d",&y);

    printf("\nEnter %d elements in the list:\n",n);
     for(i=0;i<=n-1;i++)
     {
        scanf("%d",&x);
        push(&head, x);
     }

    printf("\nCount of %d is %d", y, count(head, y));
    return 0;
}
