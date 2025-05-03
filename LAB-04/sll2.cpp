//TO IMPLEMENT LIST ADT WITH THE OPERATIONS BELOW USING SINGLY LINKED LIST 
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
int main(){
    sll sll1,sll2,sll3,linkedlist;
    int choice,value;
    do{
      printf("\nMENU\n");
      printf("1.INSERT ASCENDING \n");
      printf("2.INSERT INTO LIST 1 \n");
      printf("3.INSERT INTO LIST 2\n");
      printf("4.MERGE LIST1 AND LIST2 INTO LITS3\n");
      printf("5.DISPLAY LISTS\n");
      printf("6.EXIT\n");
      printf("ENTER YOUR CHOICE : ");
      scanf("%d",&choice);
      switch(choice){
        case 1 :
        printf("ENTER VALUE TO BE INSERTED IN LIST : ");
        scanf("%d",&value);
        linkedlist.insert_ascending(value);
        break;
        case 2 :
        printf("ENTER VALUE TO BE INSERTED IN LIST1 : ");
        scanf("%d",&value);
        sll1.insert_ascending(value);
        break;
        case 3 :
        printf("ENTER THE VALUE TO BE INSERTED IN LIST2 : ");
        scanf("%d",&value);
        sll2.insert_ascending(value);
        break;
        case 4 :
        sll3.mergelists(sll1,sll2);
        printf("SUCCESSFULLY MERGED INTO LIST3 \n");
        break;
        case 5 :
        int ans;
        printf("IF YOU WANT THE NORMAL LINKED LIST IN OPTION 1 TO BE DISPLAYED ENTER 1 IF YOU WANT THE MERGED LIST TO BE DISPLAYED ENTER 2 : ");
        scanf("%d",&ans);
        if(ans == 1){
            linkedlist.display();
        }else{
            sll3.display();
        }
        break;
        case 6:
        printf("SUCCESSFULLY EXITED :) \n");
        break;
        default :
        printf("INVALID CHOICE TRY AGAIN :( \n");

      }

    }while(choice!=6);

}
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
