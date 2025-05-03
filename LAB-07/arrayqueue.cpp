//TO IMPLEMENT QUEUE ADT USING INTEGER ARRAY 
#include<cstdio>
#include<cstdlib>
//CLASS QUEUE 
class queue{
    //PRIVATE MEMBERS FUNCTIONS AND DATA MEMBERS 
   private :
   int arr[5];
   int rear,front;
   //PUBLIC MEMBER FUNCTIONS AND DATA MEMBERS 
   public:
   queue(){
    front = 0;
    rear = 0;
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
//MEMBER FUNCTION DEFINITION TO ENQUEUE DATA
void queue :: enqueue(int data){
    if(rear==5){
        printf("THE QUEUE IS FULL \n");
        return;
    }
    arr[rear++] = data;
}
//MEMBER FUNCTION DEFINITION TO DEQUEUE DATA
void queue :: dequeue(){
    if(front == rear){
       printf("THE QUEUE IS EMPTY \n");
       return;
    }
    printf("THE DEQUEUED ELEMENT IS %d\n",arr[front++]);
    if(rear == front){
        rear = front = 0;
    }
}
//MEMBER FUNCTION DEFINITION TO PEEK THE TOPMOST OR FRONT ELEMENT 
void queue :: peek(){
    if(rear == front){
        printf("IT IS AN EMPTY QUEUE \n");
        return;
    }
    printf("THE FRONT ELEMENT OF THE LIST IS %d\n",arr[front]);
}
//MEMBER FUNCTION DEFINITION TO DISPLAY THE QUEUE 
void queue :: display(){
    if(rear==front){
        printf("THE QUEUE IS EMPTY \n");
        return;
    }
    for(int i=front;i<rear;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
