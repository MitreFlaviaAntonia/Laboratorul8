#include <stdio.h>
#include <stdlib.h>

struct node
{
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;


void print_the_list()
{
    struct node *ptr = head;

    while(ptr != NULL)
    {
        printf(" %d ->",ptr->data);
        ptr = ptr->next;
    }
    printf(" NULL");

}

void *cross_the_list(int index)
{
    struct node *ptr = head;
    int i;
    for( i=0 ; i <= index - 1 ; i++ )
    {
    ptr = ptr->next;
    }
    return ptr;

}

void Insert_After(struct node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
       printf("The given previous node can't be NULL!");
       return;
    }

    struct node* new_node =(struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}


void insert_link(int data)
{
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    link->next = head;
    head = link;
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
    int n;
    int i;
    int v[100];
    int val;
    int *index;
    struct node *smth;
    printf("How many components has the list?\n");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("The next value in the list is: ");
        scanf("%d",&v[i]);
        insert_link(v[i]);
    }
    printf("The new value in the list is: ");
    scanf("%d",&val);
    printf("The index of the new value in the list is: ");
    scanf("%d",&index);
    smth=cross_the_list(index);
    Insert_After(smth->next,val);
    print_the_list();
    free_list(head);
    return 0;
}
