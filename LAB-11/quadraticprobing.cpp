//PROGRAM TO IMPLEMENT HASH ADT USING QUADRATIC PROBING 
#include<cstdio>
#include<cstdlib>
//CONSTANTS
#define SIZE 11
#define EMPTY -1
#define DELETED -2
#define C1 1
#define C2 3
//CLASS FOR QUADRATIC PROBING 
class hashquadraticprobing{
    //PRIVATE DATA MEMBERS AND MEMBER FUNCTIONS 
    private:
    int table[SIZE];
    int hash(int key){
        return key%SIZE;
    }
    //PUBLIC DATA MEMBERS AND MEMBER MEMBER FUNCTIONS 
    public:
    hashquadraticprobing(){
        for(int i = 0;i<SIZE;i++){
            table[i]=EMPTY;
        }
    }
    //MEMBER FUNCTION FOR CHECKING IF THE HASH TABLE IS FULL
    bool isfull(){
        for(int i = 0;i<SIZE;i++){
            if(table[i]==EMPTY || table[i]==DELETED){
                return false;
            }
        }
        return true;
    }
    //MEMBER FUNCTION TO CHECK IF THE HASH TABLE IS EMPTY
    bool isempty(){
        for(int i = 0;i<SIZE;i++){
            if(table[i]!=EMPTY && table[i]!=DELETED){
                return false;
            }
        }
        return true;
    }
    //MEMBER FUNCTION DECLARATIONS OR PROTOTYPES FOR OPERATIONS 
    void insert(int key);
    void delete_key(int key);
    void search(int key);
    void display();
};
//DRIVER CODE
int main(){
    class hashquadraticprobing h;
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
        h.delete_key(key);
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
//MEMBER FUNCTION DEFINITION FOR INSERTING A KEY 
void hashquadraticprobing :: insert(int key){
    if(isfull()){
        printf("THE HASH TABLE IS FULL CANNOT INSERT MORE VALUES \n");
        return;
    }
    int index = hash(key);
    int i = 0;
    int newindex;
    while(i<SIZE){
        newindex = (index + C1*i + C2*i*i)%SIZE;
        if(table[newindex]==EMPTY || table[newindex]==DELETED){
            table[newindex]=key;
            return;
        }
        i++;
    }
    printf("TABLE MIGHT BE FULL \n");
}
//MEMBER FUNCTION DEFINITION FOR DELETING A KEY 
void hashquadraticprobing ::  delete_key(int key){
    if(isempty()){
        printf("ALREADY EMPTY CANNOT DELETE \n");
        return;
    }
    int index = hash(key);
    int i = 0;
    int newindex;
    while(i<SIZE){
        newindex = (index + C1*i + C2*i*i)%SIZE;
        if(table[newindex]==EMPTY){
            break;
        }else if(table[newindex] == key){
            table[newindex]=DELETED;
            printf("THE KEY %d IS DELETED FROM THE INDEX %d\n",key,newindex);
            return;
        }
        i++;
    }
    printf("KEY NOT FOUND HENCE CANNOT BE DELETED \n");
}
//MEMBER FUNCTION DEFINITION FOR SEARCHING A KEY AND RETURNING ITS FIRST OCCURANCE
void hashquadraticprobing :: search(int key){
    if(isempty()){
        printf("THE HASH TABLE IS EMPTY \n");
        return;
    }
    int index = hash(key);
    int i = 0;
    int newindex;
    while(i<SIZE){
        newindex = (index + C1*i + C2*i*i)%SIZE;
        if(table[newindex] == key){
            printf("KEY FOUND IN THE INDEX %d\n",newindex);
            return;
        }else if(table[newindex]==EMPTY){
            break;
        }
        i++;
    }
    printf("KEY NOT FOUND\n");
}
//MEMBER FUNCTION DEFINITION FOR DISPLAYING THE HASH TABLE 
void hashquadraticprobing :: display(){
    if(isempty()){
        printf("THE HASH TABLE IS EMPTY \n");
        return;
    }
    for(int i = 0;i<SIZE;i++){
        if(table[i]==EMPTY || table[i]==DELETED){
            printf("EMPTY ");
        }else{
            printf("%d ",table[i]);
        }
    }
    printf("\n");
}
