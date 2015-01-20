#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
     struct Node *next;
     const char *key;
     struct Node *child;

}Node;

Node *CreateList(Node *head,const char *array[], int len)
{

     int i;
     for(i=0; i < len; i++)
     {

          if(head == NULL)
         {
              head = (Node*)malloc(sizeof (Node));
              head->next = NULL;
              head->key = array[i];
         }
         else
         {
              Node *tmp = head;
              while(tmp->next != NULL)
                   tmp = tmp->next;
              tmp->next = (Node*) malloc(sizeof(Node));
              tmp->next->next = NULL;
              tmp->next->key = array[i];
         } 
      }

     return head;
  
}

void PrintList(Node *head)
{

     if(head == NULL)
          printf("%s\n","List is empty");
     else
     {
          Node *tmp = head;
          while(tmp != NULL)
          {
               printf("%s",tmp->key);
               printf("%s","->");
               tmp = tmp->next;
          }
     }
     printf("\n");
}



int main()
{

     Node *head1 = NULL;
     Node *head2 = NULL;
     const char *array1[5] = {"N1","N2","N3","N4","N5"};
     const char *array2[2] = {"N11","N12"};
     head1 = CreateList(head1,array1,5);
     head2 = CreateList(head2,array2,2);
 
     PrintList(head1);
     PrintList(head2);
     head1->child = head2;
     head2->child = NULL;
     if(head1->child)
          printf("%s\n",head1->child->key);
     return 0;
}


