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


int GetNth(struct Node* head, int index)
{
    struct Node* current = head;
    int count = 0;
    while (current != NULL)
    {
        if (count == index)
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

    printf("\nEnter %d elements in the list:\n",n);
     for(i=0;i<=n-1;i++)
     {
        scanf("%d",&x);
        push(&head, x);
     }

    for(i=0;i<=n-1;i++)
    {
        s=s+GetNth(head, i);
    }

    printf("\nThe sum of all elements in the list is: %d",s);
}
