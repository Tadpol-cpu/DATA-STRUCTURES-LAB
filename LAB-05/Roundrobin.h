//IMPLEMENTATION OF A QUEUE USING CIRCULARLY LINKED LIST TO IMPLEMENT ROUNDROBIN SEQUENCING 
#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H
#include<cstdio>
#include<cstdlib>
//CLASS FOR CLL AND ROUNDROBIN IMPLEMENTATION
class cll{
    private :
       struct node{
         int data;
         struct node*next; 
       }*head;
    public:
       cll(){
         head = NULL;
       }
      struct node* gethead(){
        return head;
      };
      //MEMBER FUNCTIONS PROTOTYPE AND DECLARATION
      void delete_beg(); 
      void insert_beg(int num);
      void insert_end(int num);
      void insert(int time);
      void execute(int value);
      void display();
};
//MEMBER FUNCTION DEFINITIONS
//DEF TO INSERT AT THE BEGINNING 
void cll :: insert_beg(int num){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    if(head == NULL){
      head = newnode;
      newnode->next = head;
      return;
    }
    struct node*temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }

    newnode->next = head;
    head = newnode;
    temp->next= head;

    return;
}
//DEF TO INSERT AT THE END 
void cll :: insert_end(int num){
    if(head==NULL){
      insert_beg(num);
      return;
    }
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    struct node * temp = head;
    while(temp->next!=head){
      temp = temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    return;
}
void cll :: insert(int time){
    insert_end(time);
    return;
}
void cll :: execute(int value){
  if(head==NULL){
    return;
  }
  if(head->next == NULL){

  }
  struct node *ptr = head;
  int num = ptr->data;
  num = num-value;
  delete_beg();
  if(num>0){
    insert_end(num);
    return;
  }
  
}
//DEF TO DELETE AT THE BEGINNING
void cll :: delete_beg(){
  if(head == NULL){
    printf("ALL PROCESS COMPLETED :) \n");
    return;
  }
  if(head->next == head){
    free(head);
    head = NULL;
    return;
  }
  struct node *temp = head;
  struct node *ptr = head;
  while(temp->next!=head){
    temp = temp->next;
  }
  head = head->next;
  temp->next = head;
  free(ptr);
  return;
}
//DEF TO DISPLAY THE QUEUE 
void cll :: display(){
    if(head == NULL){
      printf("ALL PROCESS COMPLETED :) \n");
      return;
    }
    struct node *temp = head;
    while(temp->next!=head){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
    return;
}

#endif
