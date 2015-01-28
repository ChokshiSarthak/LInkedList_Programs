#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{

     struct Node *child;
     struct Node *next;
     char *key;
}Node;


void PrintList(Node *head)
{

     Node *tmp = head;
     while(tmp!= NULL)
     {
          printf("%s",tmp->key);
          printf("->");
          tmp = tmp->next;
     }

     printf("\n");

}
      
Node *CreateListUtil( char *arr[], int len)
{
     Node *head = NULL;
     Node *p;
     int i;
     for(i=0; i < len; i++)
     {
          if(head == NULL)
          {             
               head = (Node *) malloc(sizeof (struct Node));
               p = head;
          }
          else
          {
               p->next = (Node *) malloc(sizeof(struct Node));
               p = p->next;
          }
          p->key = arr[i];
          p->next = NULL;
          p->child = NULL;
     }      
  
return head;
}
Node *CreateList(void)
{
    char *arr1[4] = {"N1","N2","N3","N4"};
    char *arr2[3] = {"N11","N12","N13"};
    char *arr3[2] = {"N121","N122"};
    
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    int len3 = sizeof(arr3)/sizeof(arr3[0]);
     Node *head1 = CreateListUtil(arr1, len1);
     Node *head2 = CreateListUtil(arr2, len2);
     Node *head3 = CreateListUtil(arr3, len3);
     head1->child = head2;
     head2->next->child = head3;      
     printf("\n");  
     printf("child of linked list 1: is %s\n", head1->child->key);
     printf("child from linkedlist 2: is %s\n",head2->next->child->key);
     return head1;
}

Node* FlattenList(Node  *head)
{
       printf("function called for %s\n",(*head)->key);
//     printf("%s\n",__FUNCTION__);
     Node *p;     
     for(p = *head; p; p = p->next)
     {
          if(p->child)
          {
               Node *tail = FlattenList(&(p->child));
               tail->next = p->next;
               p->next = p->child;
               p->child = NULL;
          }
          if(p->next == NULL)
               return p;
    }
}


int main()
{
     Node *head = CreateList();
     FlattenList(&head);
     PrintList(head);
     return 0;
}
