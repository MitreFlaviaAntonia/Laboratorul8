#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void print_the_list(struct Node*head)
{
    struct node *ptr = head;

    while(ptr != NULL)
    {
        printf(" %d ->",ptr->data);
        ptr = ptr->next;
    }
    printf(" NULL");

}

void Sorted_Insert(struct node** head_ref, struct node* new_node)
{
    struct node* current;

    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next!=NULL && current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void Normal_Insert(struct node** head_ref, struct node* new_node)
{
    struct node* current;

    if (*head_ref == NULL )
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next!=NULL && current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

struct node *insert_link(int data)
{
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    link->next = NULL;
    return link;
}

void free_list(struct node* head)
{
   struct node* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}
int main()
{
    struct node *head = NULL;
    int n;
    int i;
    int v[100];
    int val;
    printf("How many components has the list?\n");
    scanf("%d",&n);
    i=0;
    printf("\nThe next value in the list is: ");
    scanf("%d",&v[i]);
    struct node *new_node = insert_link(v[i]);
    Normal_Insert(&head, new_node);
    for(i=1;i<=n-1;i++)
    {
        printf("\nThe next value in the list is: ");
        scanf("%d",&v[i]);
        new_node = insert_link(v[i]);
        Normal_Insert(&head, new_node);
    }
    print_the_list(head);

    printf("\nThe new value in the list is: ");
    scanf("%d",&val);
    new_node = insert_link(val);
    Sorted_Insert(&head,new_node);
    printf("The list after the insertion sort:\n");
    print_the_list(head);
    free_list(head);
    return 0;
}
