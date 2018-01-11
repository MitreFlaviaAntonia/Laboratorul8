#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node
{
    int data;
    struct node* next;
};


void deleteList(struct node** head_ref)
{

   struct node* current = *head_ref;
   struct node* next;

   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }

   *head_ref = NULL;
}

void push(struct node** head_ref, int new_data)
{
    struct node* link =(struct node*) malloc(sizeof(struct node));
    link->data  = new_data;
    link->next = (*head_ref);
    (*head_ref) = link;
}

int main()
{
    int i,n,x,y;

    struct node* head = NULL;
    printf("Give the number of components: ");
    scanf("%d",&n);

    printf("\nEnter %d elements in the list: \n",n);
     for(i=0;i<=n-1;i++)
     {
        scanf("%d",&x);
        push(&head, x);
     }

    printf("\nDeleting linked list");
    deleteList(&head);

    printf("\nLinked list deleted");
}
