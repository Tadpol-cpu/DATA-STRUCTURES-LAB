//TO IMPLEMENT LIST ADT USING SINGLY LINKED LIST 
#include<cstdio>
#include<cstdlib>
//CLASS FOR SLL 
class sll{
   private :
    struct node{
        int data;
        struct node *next;
    }*head;
  public :
  //MEMBER FUNCTION DECLARATIONS OR PROTOTYPES
    sll(){head=NULL;}
    void insert_beg(int num);
    void insert_end(int num);
    void insert_pos(int pos,int num);
    void delete_beg();
    void delete_end();
    void delete_pos(int pos);
    void search(int num);
    void reverse();
    void displayreverse();
    void display();

};
int main(){
    sll sll1;
   int choice,num,pos;
   do{
    printf("MENU : \n");
    printf("1.INSERTION AT THE BEGINNING \n");
    printf("2.INSERTION AT THE END \n");
    printf("3.INSERTION AT A GIVEN POSITION \n");
    printf("4.DELETE AT THE BEGINNING \n");
    printf("5.DELETE AT THE END \n");
    printf("6.DELETE AT A GIVEN POSITION \n");
    printf("7.SEARCH FOR AN ELEMENT \n");
    printf("8.DISPLAY \n");
    printf("9.DISPLAY REVERSE \n");
    printf("10.REVERSE SLL \n");
    printf("11.EXIT \n");
    printf("ENTER YOUR CHOICE : ");
    scanf("%d",&choice);
    switch(choice){
        case 1 :
         printf("ENTER THE NUMBER TO BE INSERTED AT THE BEGINNING : ");
         scanf("%d",&num);
         sll1.insert_beg(num);
         break;
        case 2 :
         printf("ENTER THE NUMBER TO BE INSERTED AT THE END : ");
         scanf("%d",&num);
         sll1.insert_end(num);
         break;
        case 3 :
         printf("ENTER THE POSITION YOU WOULD LIKE THE NUMBER TO BE INSERTED IN : ");
         scanf("%d",&pos);
         if(pos<1){
            printf("INVALID POSITION \n");
         }else{
            printf("ENTER THE NUMBER TO BE INSERTED AT THE GIVEN POSITION : ");
            scanf("%d",&num);
            sll1.insert_pos(pos,num);
         }
         break;
        case 4 :
         sll1.delete_beg();
         break;
        case 5 :
         sll1.delete_end();
         break;
        case 6 :
         printf("ENTER THE POSITION TO BE DELETED :");
         scanf("%d",&pos);
         if(pos<1){
            printf("INVALID POSITION \n");
         }else{
            sll1.delete_pos(pos);
         }
         break;
        case 7 :
         printf("ENTER THE NUMBER TO BE SEARCHED FOR : ");
         scanf("%d",&num);
         sll1.search(num);
         break;
        case 8 :
         sll1.display();
         break;
        case 9 :
         sll1.displayreverse();
         break;
        case 10 :
         sll1.reverse();
         break;
        case 11 :
         printf("SUCCESSFULLY EXITED :) \n");
         break;
        default :
        printf("INVALID CHOICE PLEASE ENTER AGAIN :(\n");
        }
  }while(choice!=11);
   return 0;
}
//MEMBER FUNCTION DEFINITIONS 
//DEFINITION FOR INSERTION AT BEGINNING
void sll :: insert_beg(int num){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    if(head == NULL){
        head = newnode;
        newnode->next = NULL;
    }else{
        newnode->next = head;
        head = newnode;
    }
}
//DEFINITION FOR INSERTION AT THE END
void sll :: insert_end(int num){
     if(head==NULL){
        insert_beg(num);
    }else{
        struct node *temp = head;
        struct node * newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
}
//DEFINITION FOR INSERTION AT A GIVEN POSITION 
void sll :: insert_pos(int pos,int num){
    if(head == NULL || pos ==1){
        insert_beg(num);
        return;
    }
    if(pos < 1){
        printf("INVALID POSITION \n");
        return;
    }else{
        struct node *temp = head;
        for(int i = 1;temp != NULL && i <pos-1;i++){
            temp = temp->next;
        }
        if(temp == NULL){
            insert_end(num);
        }else{
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = num;
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}
//DEFINITION FOR DELETING AT THE BEGINNING
void sll :: delete_beg(){
    if(head == NULL){
        printf("THE LIST IS ALREADY EMPTY \n");
        return;
    }else{
        struct node *ptr= head;
        head = head->next;
        free(ptr);
    }
}
//DEFINITION FOR DELETING AT THE END
void sll :: delete_end(){
    if(head == NULL){
        printf("THE LIST IS EMPTY \n");
        return;
    }
    if(head->next == NULL){
        struct node * temp = head;
        head = NULL;
        free(temp);
        return;
    }
    struct node *prev = NULL;
    struct node *temp = head;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    
}
//DEFINITION FOR DELETING AT A GIVEN POSITION 
void sll :: delete_pos(int pos){
    if(head == NULL){
        printf("LIST IS ALREADY EMPTY \n");
        return;
    }
    if(pos<1){
        printf("INVALID POSITION \n");
        return;
    }
    if(pos == 1){
        delete_beg();
        return;
    }else{
        struct node *temp = head;
        struct node *prev = NULL;
        for(int i = 1;temp!=NULL && i<pos;i++){
           prev=temp;
           temp = temp->next;
        }
        if(temp==NULL){
            delete_end();
        }else{
            prev->next = temp->next;
            free(temp);
        }
    }

}
//DEFINITION FOR SEARCHING FOR A GIVEN ELEMENT AND PRINTING THE FIRST OCCURENCE POSITION OTHERWISE PRINTING NOT FOUND
void sll :: search(int num){
    struct node *temp = head;
    int i = 0;
    while(temp!=NULL){
        i++;
        if(temp->data==num){
            printf("ELEMENT FOUND IN THE POSITION %d \n",i);
            return;
        }
        temp=temp->next;
    }
    printf("ELEMENT NOT FOUND \n");
}
//DEFINITION FOR REVERSING A SLL
void sll :: reverse(){
    if(head == NULL){
        printf("THE LIST IS EMPTY \n");
        return;
    }
    if(head->next==NULL){
        return;
    }
    struct node *cur = head;
    struct node *prev = NULL;
    struct node *temp = NULL;
    while(cur!=NULL){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    head = prev; 
} 
//DEFINITION FOR DISPLAYING REVERSE SLL 
void sll :: displayreverse(){
    if(head == NULL){
        printf("THE LIST IS EMPTY \n"); 
        return;
    }
    reverse();
    display();
    reverse();
}
//DEFINITION FOR DISPLAYING THE LIST
void sll :: display(){
    if(head == NULL){
        printf("LIST IS EMPTY \n");
        return;
    }
    struct node *temp = head;
    while(temp->next!=NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}
