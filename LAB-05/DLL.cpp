//PROGRAM TO IMPLEMENT LIST ADT USING DOUBLY LINKED LIST USING TAIL
#include<cstdio>
#include<cstdlib>
//CLASS FOR DLL
class dll{
    private :
    struct node{
        struct node *prev;
        int data;
        struct node *next;
    }*head,*tail;
    public :
    dll(){
        head = NULL;
        tail = NULL;
    }
    //MEMBER FUNCTION DECLARATIONS/PROTOTYPES
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
   dll dll1;
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
        dll1.insert_beg(num);
        break;
        case 2:
        printf("ENTER THE NUMBER TO BE INSERTED AT THE END : ");
        scanf("%d",&num);
        dll1.insert_end(num);
        break;
        case 3 :
        printf("ENTER THE POSITION AND NUMBER WHERE AND WHAT TO INSERT : ");
        scanf("%d%d",&pos,&num);
        if(pos<1){
            printf("INVALID POSITION \n");
            break;
        }
        dll1.insert_pos(pos,num);
        break;
        case 4 :
        dll1.delete_beg();
        break;
        case 5 :
        dll1.delete_end();
        break;
        case 6 :
        printf("ENTER THE POSITION TO BE DELETED : ");
        scanf("%d",&pos);
        dll1.delete_pos(pos);
        break;
        case 7 :
        printf("ENTER THE NUMBER TO BE SEARCHED FOR : ");
        scanf("%d",&num);
        dll1.search(num);
        break;
        case 8 :
        dll1.display();
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
//MEMBER FUNCTION DEFINITIONS 
//DEF TO INSERT AN ELEMENT AT THE BEGINNING 
void dll :: insert_beg(int num){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->prev=NULL;
    newnode->next =NULL;
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head=newnode;
    return;
}
//DEF TO INSERT AN ELEMENT AT THE END 
void dll :: insert_end(int num){
    if(head == NULL){
        insert_beg(num);
        return;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    newnode->prev=tail;
    tail->next = newnode;
    tail = newnode;
    return;
}
//DEF TO INSERT A GIVEN ELEMENT IN A GIVEN POSITION 
void dll :: insert_pos(int pos,int num){
    if(head==NULL||pos==1){
        insert_beg(num);
        return;
    }
    struct node *temp = head;
    for(int i = 1;i<pos-1 && temp!=NULL;i++){
        temp= temp->next;
    }
    if(temp==NULL){
        insert_end(num);
        return;
    }
    if(temp==tail){
        insert_end(num);
        return;
    }
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = temp->next;
    newnode->prev= temp;
    temp->next->prev= newnode;
    temp->next = newnode;
    return;
}
//DEF TO DELETE AN ELEMENT AT THE BEGINNING 
void dll :: delete_beg(){
    if(head==NULL){
        printf("THE LIST IS ALREADY EMPTY \n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        tail=NULL;
        return;
    }
    struct node*temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return;
}
//DEF TO DELETE AN ELEMENT AT THE END
void dll :: delete_end(){
    if(head == NULL){
        printf("THE LIST IS EMPTY \n");
        return;
    }
    if(head->next == NULL){
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }
    struct node *temp = tail;
    tail = tail->prev;
    free(temp);
    return;

}
//DEF TO DELETE AN ELEMENT FROM A CERTAIN POSITION 
void dll :: delete_pos(int pos){
    if(pos == 1 || head == NULL){
        delete_beg();
        return;
    }
    struct node *temp = head;
    for(int i = 1;i<pos||temp != NULL;i++){
        temp = temp->next;
    }
    if(temp == NULL){
        delete_end();
        return;
    }
    if(temp->next==NULL){
        delete_end();
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return;
}
//DEF TO SEARCH FOR A PARTICULAR ELEMENT IN A LIST AND RETURN ITS FIRST OCCURANCE POSITION 
void dll :: search(int num){
    struct node*temp = head;
    int i=0;
    while(temp!=NULL){
        i++;
        if(temp->data == num){
            printf("ELEMENT IS FOUND IN THE POSITION : %d\n",i);
            return;
        }
        temp = temp->next;
    }
    printf("ELEMENT NOT FOUND IN THE LIST \n");
    return;
}
//DEF TO DISPLAY THE DLL 
void dll :: display(){
    if(head == NULL){
        printf("THE LIST IS EMPTY \n");
        return;
    }
    struct node*temp = head;
    while(temp!=tail){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
    while(temp!=head){
        printf("%d <- ",temp->data);
        temp = temp->prev;
    }
    printf("%d\n",temp->data);
    return;
}
