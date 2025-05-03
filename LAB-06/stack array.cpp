//PROGRAM TO IMPLEMENT STACK ADT USING ARRAY IMPLEMENTATION 
#include<cstdio>
#include<cstdlib>
//CLASS FOR STACK IMPLEMENTATION USING ARRAY OF SIZE 5 
class stack{
   private : 
   char arr[5];
   int size;
   //MEMBER FUNCTION PROTOTYPES/DEFINITIONS AND CONSTRUCTOR 
   public :
   stack(){size = 0;}
   void push(char ch);
   char pop();
   void peek();
   void display();
};
//DRIVER CODE
int main(){
    stack st;
    int choice;
    char ch,t;
    do{
      printf("MENU \n");
      printf("1.PUSH\n2.POP\n3.PEEK\n4.EXIT\n");
      printf("ENTER YOUR CHOICE : ");
      scanf("%d",&choice);
      switch(choice){
        case 1 :
        printf("ENTER THE CHARACTER TO BE PUSHED INTO THE STACK : ");
        scanf(" %c",&ch);
        st.push(ch);
        break;
        case 2 :
        t = st.pop();
        if(t == '\0'){
            printf("THE STACK IS EMPTY UNDERFLOW \n");
            break;
        }
        printf("THE ELEMENT POPED =  %c\n",t);
        break;
        case 3 :
        st.peek();
        break;
        case 4 :
        printf("SUCCESSFULLY EXITED :) \n");
        break;
        default :
        printf("INVALID CHOICE TRY AGAIN :( \n");
      }
    }while(choice!=4);
    return 0;
}
//MEMBER FUNCTION DEFINITIONS FOR IMPLEMENTING STACK ADT USING ARRAY 
//DEF TO PUSH ELEMENT INTO THE STACK
void stack :: push(char ch){
    if(size==5){
        printf("STACK IS ALREADY FULL OVERFLOW \n");
        return;
    }
    arr[size]=ch;
    size++;
    return;
}
//DEF TO POP THE TOPMOST ELEMENT OF THE STACK
char stack :: pop(){
    if(size == 0){
        return '\0';
    }else{
        char s = arr[size-1];
        size--;
        return s;
    }
} 
//DEF TO LOOK AT THE TOPMOST ELEMENT IN THE STACK
void stack :: peek(){
    if(size == 0){
        printf("STACK UNDERFLOW \n");
        return;
    }
    printf("THE TOPMOST ELEMENT IN THE STACK IS : %c\n",arr[size-1]);
    return;
}
//DEF TO DISPLAY THE STACK SUCH THAT THE RIGHT MOST ELEMENT IS THE TOPMOST ELEMENT 
void stack :: display(){
    if(size == 0){
        printf("STACK IS EMPTY UNDERFLOW \n");
        return;
    }
    for(int i = 0;i<size;i++){
        printf("%c ",arr[i]);
    }
    printf("\n");
    return;
}
