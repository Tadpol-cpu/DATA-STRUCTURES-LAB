//PROGRAM TO IMPLEMENT A LIST ADT USING CIRCULARLY LINKED LIST 
#include<cstdio>
#include<cstdlib>
//CLASS FOR CIRCULARLY LINKED LIST 
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
       //FUNCTION OR MEMBER FUNCTION PROTOTYPES/DECLARATIONS
       void insert_beg(int num);
       void insert_end(int num);
       void insert_pos(int pos,int num);
       void delete_beg();
       void delete_end();
       void delete_pos(int pos);
       void search(int num);
       void display();
};
//DRIVER CODE 
int main(){
   int choice,num,pos;
   cll cll1;
  do{
      printf("MENU \n");
      printf("1.INSERT AT THE BEGINNING \n");
      printf("2.INSERT AT THE END \n");
      printf("3.INSERT AT A GIVEN POSITION \n");
      printf("4.DELETE AT THE BEGINNING \n");
      printf("5.DELETE AT THE END \n");
      printf("6.DELETE AT A GIVEN POSITION \n");
      printf("7.SEARCH \n");
      printf("8.DISPLAY \n");
      printf("9.EXIT \n");
      printf("ENTER YOUR CHOICE : ");
      scanf("%d",&choice);
      switch(choice){
        case 1 :
        printf("ENTER THE NUMBER TO BE INSERTED AT THE BEGINNING : ");
        scanf("%d",&num);
        cll1.insert_beg(num);
        break;
        case 2:
        printf("ENTER THE NUMBER TO BE INSERTED AT THE END : ");
        scanf("%d",&num);
        cll1.insert_end(num);
        break;
        case 3 :
        printf("ENTER THE POSITION AND NUMBER WHERE AND WHAT TO INSERT : ");
        scanf("%d%d",&pos,&num);
        if(pos<1){
            printf("INVALID POSITION \n");
            break;
        }
        cll1.insert_pos(pos,num);
        break;
        case 4 :
        cll1.delete_beg();
        break;
        case 5 :
        cll1.delete_end();
        break;
        case 6 :
        printf("ENTER THE POSITION TO BE DELETED : ");
        scanf("%d",&pos);
        cll1.delete_pos(pos);
        break;
        case 7 :
        printf("ENTER THE NUMBER TO BE SEARCHED FOR : ");
        scanf("%d",&num);
        cll1.search(num);
        break;
        case 8 :
        cll1.display();
        break;
        case 9 :
        printf("EXITED SUCCESSFULLY :) \n");
        break;
        default :
        printf("INVALID CHOICE ENTER AGAIN :( \n");
    }

   }while(choice!=9);
   return 0;   
}
//FUNCTION DEFINITIONS FOR CLL
//DEF TO INSERT AN ELEMENT AT THE BEGINNING
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
//DEF TO INSERT AN ELEMENT TO A GIVEN POSITION 
void cll :: insert_pos(int pos,int num){
  if(head==NULL || pos == 1){
    insert_beg(num);
    return;
  }
  if(pos<1){
    printf("INVALID POSITION \n");
    return;
  }
  struct node *temp = head;
  int j = 0;
  for(int i = 1;i<pos-1 && j==0;i++){
    temp = temp->next;
    if(temp==head){
      j = 1;
    }
  }
  if(j==1){
    insert_end(num);
    return;
  }
  if(temp->next == head){
    insert_end(num);
    return;
  }
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = num;
  
  newnode->next = temp->next;
  temp->next = newnode;
  return;
}
//DEF TO DELETE AN ELEMENT AT THE BEGINNING 
void cll :: delete_beg(){
  if(head == NULL){
    printf("THE LIST IS ALREADY EMPTY \n");
    return;
  }
  if(head->next==head){
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
//DEF TO DELETE AN ELEMENT AT THE END 
void cll :: delete_end(){
  if(head == NULL){
    printf("THE LIST IS ALREADY EMPTY \n");
    return;
  }
  if(head->next==head){
    free(head);
    head=NULL;
    return;
  }
  struct node *temp = head;
  while(temp->next->next!=head){
    temp= temp->next;
  }
  struct node *ptr = temp->next;
  temp->next = head;
  free(ptr);
  return;
}
//DEF TO DELETE AN ELEMENT AT A GIVEN POSITION
void cll :: delete_pos(int pos){
  if(head == NULL){
    printf("LIST IS ALREADY EMPTY \n");
    return;
  }
  if(pos<1){
    printf("INVALID POSITION \n");
    return;
  }
  if(pos==1){
    delete_beg();
    return;
  }
  struct node*temp=head;
  struct node*prev = NULL;
  int j = 0;
  for(int i = 1;i<pos && j==0;i++){
     prev = temp;
     temp = temp->next;
     if(temp==head){
      j=1;
     }
  }
  if(j==1){
    delete_end();
    return;
  }
  if(temp->next == head){
    delete_end();
    return;
  }
  prev->next = temp->next;
  free(temp);
  return;


}
//DEF TO SEARCH FOR AN ELEMENT AND PRINT ITS FIRST OCCURANCE POSITION 
void cll :: search(int num){
   if(head == NULL){
    printf("THE LIST IS EMPTY \n");
    return;
   }
   int i=0;
   struct node *temp=head;
   while(temp->next!=head){
    
      i++;
      if(temp->data==num){
        printf("THE ELEMENT IS FOUND IN POSITION : %d \n",i);
        return;
      } 
      temp = temp->next;
    
   }
  printf("ELEMENT NOT FOUND IN LIST \n");
  return;
}
//DEF TO DISPLAY THE CLL 
void cll :: display(){
    if(head == NULL){
      printf("IT IS AN EMPTY LIST \n");
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
