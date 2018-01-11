#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

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
    (*head_ref) = new_node;
}


int GetNth(struct Node* head, int y)
{
    struct Node* current = head;
    int count = 0;
    while (current != NULL)
    {
        if (count == y)
           return (current->data);

        count++;

        current = current->next;
    }

   assert(0);
}


int main()
{
    int i,n,x,y;
    int s=0;

    struct Node* head = NULL;
    printf("Give the number of components: ");
    scanf("%d",&n);

    printf("Give the index number to search at: ");
    scanf("%d",&y);

    printf("\nEnter %d elements in the list:\n",n);
     for(i=0;i<=n-1;i++)
     {
        scanf("%d",&x);
        push(&head, x);
     }

    printf("\nThe element at index %d is: %d",y,GetNth(head, y));
}
