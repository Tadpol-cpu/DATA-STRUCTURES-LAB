//TO IMPLEMENT QUEUE USING INTEGER LINKED LIST
#include<cstdio>
#include<cstdlib>
//CLASS FOR IMPLEMENTING QUEUE 
class queue{
    //PRIVATE MEMBER FUNCTIONS AND DATA MEMBERS 
    private :
    struct node{
        int data;
        struct node*next;
    }*front,*rear;
    //PUBLIC MEMBER FUNCTIONS AND DATA MEMBERS 
    public :
    queue(){
        front = rear = NULL;
    }
    void enqueue(int data);
    void dequeue();
    void peek();
    void display();
};
//DRIVER CODE 
int main(){
    class queue q;
    int choice,data;
    do{
      printf("MENU \n");
      printf("1.ENQUEUE \n");
      printf("2.DEQUEUE\n");
      printf("3.PEEK\n");
      printf("4.EXIT\n");
      printf("ENTER YOU CHOICE : ");
      scanf("%d",&choice);
      switch(choice){
        case 1 :
        printf("ENTER THE VALUE TO BE ENQUEUED : ");
        scanf("%d",&data);
        q.enqueue(data);
        break;
        case 2 :
        q.dequeue();
        break;
        case 3 : 
        q.peek();
        break;
        case 4:
        printf("SUCCESSFULLY EXITED :) \n");
        break;
        default : 
        printf("INVALID CHOICE ENTER AGAIN :( \n");
      }
    }while(choice!=4);
    return 0;
}
//MEMBER FUNCTION DEFINITION FOR ENQUEUE
void queue :: enqueue(int data){
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if(front == NULL){
      front = newnode;
      rear = newnode;
      return;
    }
    rear->next = newnode;
    rear = newnode;
}
//MEMBER FUNCTION DEFINITION FOR DEQUEUE 
void queue :: dequeue(){
    if(front == NULL){
        printf("THE QUEUE IS ALREADY EMPTY \n");
        return;
    }
    struct node*temp = front;
    front=front->next;
    printf("THE DEQUEUED ELEMENT IS %d\n",temp->data);
    free(temp);
}
//MEMBER FUNCTION DEFINITION FOR PEEK
void queue :: peek(){
    if(front == NULL){
        printf("THE QUEUE IS EMPTY \n");
        return;
    }
    printf("THE FRONT ELEMENT IS %d \n",front->data);
}
//MEMBER FUNCTION DEFINTITON FOR DISPLAY
void queue :: display(){
    if(front == NULL){
        printf("THE QUEUE IS EMPTY \n");
        return;
    }
    struct node * temp = front;
    while(temp->next !=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}
