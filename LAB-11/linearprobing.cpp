//PROGRAM TO IMPLEMENT HASH ADT WITH LINEAR PROBING 
#include<cstdio>
#include<cstdlib>
//CONSTANTS
#define SIZE 10
#define EMPTY -1
#define DELETED -2
//CLASS FOR LINEAR PROBING 
class hashlinearprobing{
    //PRIVATE MEMBER FUNCTIONS AND DATA MEMBER 
    private :
    int table[SIZE];
    int hash(int key){
        return key % SIZE;
    }
    //PUBLIC DATA MEMBERS AND MEMBER FUNCTIONS 
    public :
    hashlinearprobing(){
        for(int i = 0;i<SIZE;i++){
            table[i] = EMPTY;
        }
    }
    //MEMBER FUNCTION TO CHECK WHETHER THE HASH TABLE IS EMPTY OR NOT
    bool isempty(){
        for(int i = 0;i<SIZE;i++){
            if(table[i]!=EMPTY&&table[i]!=DELETED){
               return false;
            }
        }
        return true;
    }
    //MEMBER FUNCTIONS PROTOTYPES OR DECLARATIONS 
    void insert(int key);
    void remove(int key);
    void search(int key);
    void display();
};
//DRIVER CODE 
int main(){
    class hashlinearprobing h;
    int key,choice;
    do{
       printf("MENU :\n");
       printf("1.INSERT\n");
       printf("2.DELETE\n");
       printf("3.SEARCH\n");
       printf("4.DISPLAY\n");
       printf("5.EXIT\n");
       printf("ENTER YOUR CHOICE : ");
       scanf("%d",&choice);
       switch(choice){
        case 1:
        printf("ENTER THE KEY TO BE INSERTED : ");
        scanf("%d",&key);
        h.insert(key);
        break;
        case 2:
        printf("ENTER THE KEY TO BE DELETED : ");
        scanf("%d",&key);
        h.remove(key);
        break;
        case 3:
        printf("ENTER THE KEY TO BE SEARCHED : ");
        scanf("%d",&key);
        h.search(key);
        break;
        case 4:
        h.display();
        break;
        case 5:
        printf("EXITED SUCCESSFULLY :)\n");
        break;
        default:
        printf("INVALID CHOICE ENTER AGAIN :(\n");
       }
    }while(choice!=5);
    return 0;
}
//MEMBER FUNCTION DEFINITION FOR INSERTION 
void hashlinearprobing :: insert(int key){
    int index = hash(key);
    int start = index;
    while(table[index]!=EMPTY && table[index]!=DELETED){
        index = (index + 1)%SIZE;
        if(index == start){
            printf("HASH TABLE IS FULL CANNOT INSERT \n");
            return;
        }
    }
    table[index]=key;
}
//MEMBER FUNCTION DEFINITION FOR DELETION 
void hashlinearprobing :: remove(int key){
    if(isempty()){
        printf("THE HASH TABLE IS ALREADY EMPTY \n");
        return;
    }
    int index = hash(key);
    int start = index;
    while(table[index]!=EMPTY){
        if(table[index]==key){
            table[index] = DELETED;
            printf("DELETED ELEMENT %d FROM INDEX %d \n",key,index);
            return;
        }
        index = (index + 1)%SIZE;
        if(index == start){
           break;
        }
    }
    printf("KEY NOT FOUND HENCE CANNOT BE DELETED \n");
}
//MEMBER FUNCTION DEFINITION FOR SEARCHING AND PRINTING THE 1ST APPEARANCE OF THE KEY 
void hashlinearprobing :: search(int key){
    if(isempty()){
        printf("THE HASH TABLE IS EMPTY \n");
        return;
    }
    int index = hash(key);
    int start = index;
    while(table[index]!=EMPTY){
        if(table[index]==key){
            printf("KEY FOUND IN THE INDEX %d\n",index);
            return;
        }
        index = (index + 1)%SIZE;
        if(index == start){
            break;
        }
    }
    printf("KEY NOT FOUND \n");
}
//MEMBER FUNCTION DEFINTION FOR DISPLAY 
void hashlinearprobing :: display(){
    if(isempty()){
        printf("THE HASH TABLE IS EMPTY \n");
        return;
    }else{
        for(int i = 0;i<SIZE;i++){
            if(table[i] == EMPTY || table[i]==DELETED){
                printf("EMPTY ");
            }else{
                printf("%d ",table[i]);
            }
        }
        printf("\n");
    }
}
