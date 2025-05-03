//PROGRAM TO IMPLEMENT STACK ADT USING SLL 
#include<cstdio>
#include<cstdlib>
//CLASS FOR IMPLEMENTING STACK ADT USING SLL
class stack{
  private :
  struct node{
    char data;
    struct node* next;
  }*top;
  //MEMBER FUNCTION PROTOTYPES/DECLARATIONS AND CONSTRUCTOR 
  public :
  stack(){top = NULL;}
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
//MEMBER FUNCTION DEFINITIONS FOR STACK ADT IMPLEMENTATION USING SLL
//DEF TO PUSH AN ELEMENT INTO THE STACK
void stack :: push(char ch){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ch;
    if(top == NULL){
        top = newnode;
        newnode->next = NULL;
        return;
    }
    newnode->next = top;
    top = newnode;
    return;
}
//DEF TO POP THE TOPMOST ELEMENT FROM THE STACK 
char stack :: pop(){
    if(top == NULL){
        return '\0';
    }
    char s = top->data;
    struct node*temp = top;
    top = top->next;
    free(temp);
    return s;
}
//DEF TO PRINT THE TOPMOST ELEMENT FROM THE STACK
void stack :: peek(){
    if(top == NULL){
        printf("STACK UNDERFLOW \n");
        return;
    }
    printf("THE TOPMOST ELEMENT IN THE STACK = %c\n",top->data);
    return;
}
//DEF TO DISPLAY THE STACK SUCH THAT LEFT MOST IS THE TOPMOST AND THE SERIES CONTINUES
void stack :: display(){
    if(top == NULL){
        printf("STACK UNDERFLOW \n");
        return;
    }
    struct node *temp = top;
    while(temp->next != NULL){
        printf("%c -> ",temp->data);
        temp = temp->next;
    }
    printf("%c\n",temp->data);
    return;
}
