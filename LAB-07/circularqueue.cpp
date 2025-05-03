//CODE TO IMPLEMENT CIRCULAR QUEUE ADT USING INTEGER ARRAY
#include<cstdio>
#include<cstdlib>
//CLASS FOR CIRCULAR LINKED LIST 
class circular{
    //PRIVATE MEMBER FUNCTIONS AND DATA MEMBERS 
    private :
    int arr[5];
    int rear,front,count;
    //PUBLIC MEMBER FUNCTIONS 
    public :
    circular(){
        rear = front = 0;
        count = 0;
    }
    bool isfull(){
        return count == 5;
    }
    bool isempty(){
        return count == 0;
    }
    void enqueue(int data);
    void dequeue();
    void peek();
    void display();
};
//DRIVER CODE 
int main(){
    class circular c;
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
        c.enqueue(data);
        break;
        case 2 :
        c.dequeue();
        break;
        case 3 : 
        c.peek();
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
void circular :: enqueue(int data){
    if(isfull()){
      printf("THE CIRCULAR QUEUE IS FULL \n");
      return; 
    }
    arr[rear] = data;
    rear = (rear+1)%5;
    count++;
}
//MEMBER FUNCTION DEFINITION FOR DEQUEUE
void circular :: dequeue(){
    if(isempty()){
        printf("THE CIRCULAR QUEUE IS ALREADY EMPTY \n");
        return;
    }
    printf("THE DEQUEUED ELEMENT = %d\n",arr[front]);
    front = (front+1)%5;
    count--;
}
//MEMBER FUNCTION DEFINITION FOR PEEKING
void circular :: peek(){
    if(isempty()){
        printf("THE CIRCULAR QUEUE IS EMPTY \n");
        return;
    }
    printf("THE FRONT ELEMENT = %d\n",arr[front]);
}
//MEMBER FUNCTION DEFINTION FOR DISPLAY 
void circular :: display(){
    if(isempty()){
        printf("THE CIRCULAR QUEUE IS EMPTY \n");
        return;
    }
    for(int i = 0;i<count ;i++){
        printf("%d ",arr[(front+i)%5]);
    }
    printf("\n");
}
