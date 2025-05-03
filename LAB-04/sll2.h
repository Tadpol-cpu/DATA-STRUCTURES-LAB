#ifndef SLL2_H
#define SLL2_H
#include<cstdio>
#include<cstdlib>
//class to implement list adt with below operations using sll
class sll{
   private :
   struct node{
    int data;
    struct node *next;
   }*head;
   //GET FUNCTION PROTOTYPE + DEFINITION
   struct node* gethead(){
    return head;
   }
   public :
   //CONSTRUCTOR
   sll(){head = NULL;}
   //DATA MEMBERS PROTOTYPES
   void insert_ascending(int num);
   void mergelists(sll& sll1,sll& sll2);
   void display();
   
};
//DATA MEMBERS DEFINITION FOR THE LIST ADT OPERATIONS 
//DEFINITION FOR INSERTING IN ASCENDING ORDER 
void sll :: insert_ascending(int value){
    struct node*newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    if(head == NULL || head->data>=value){
        newnode->next = head;
        head = newnode; 
    }else{
        struct node *current = head;
        while(current->next && current->next->data<value){
            current = current->next;
        }
        newnode->next = current->next;
        current->next=newnode; 
    }
}
//DEFINITION FOR MERGING TWO LISTS 
void sll :: mergelists(sll& sll1,sll& sll2){
   struct node *head1 = sll1.gethead();
   struct node *head2 = sll2.gethead();
   head = NULL;
   struct node ** lastptr = &head;
   while(head1 && head2){
    if(head1->data <= head2->data){
        *lastptr = head1;
        head1 = head1->next;
    }else{
        *lastptr = head2;
        head2 = head2->next;
    }
    lastptr = &((*lastptr)->next);
   }
   *lastptr = (head1)?head1 : head2;
//DEFINITION FOR DISPLAYING THE LISTS 
}
void sll :: display(){
    if(head == NULL){
        printf("IT IS AN EMPTY LIST \n");
    }else{
        struct node *temp = head;
        while(temp->next != NULL){
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
    }
}

#endif
