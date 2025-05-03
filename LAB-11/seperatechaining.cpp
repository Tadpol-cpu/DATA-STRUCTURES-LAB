//PROGRAM TO IMPLEMENT HASH TABLE USING SEPERATE CHAINING
#include<cstdio>
#include<cstdlib>
//CONSTANTS 
#define SIZE 10
//CLASS FOR SEPERATE CHAIN
class seperatechain{
    //PRIVATE DATA MEMBERS AND MEMBER FUNCTIONS 
    private:
    struct node{
        int key;
        struct node*next;
    };
    struct node* table[SIZE];
    int hash(int key){
        return key % SIZE;
    }
    //PUBLIC DATA MEMBERS AND MEMBER FUNCTIONS 
    public:
    seperatechain(){
        for(int i = 0;i<SIZE;i++){
            table[i]=NULL;
        }
    }
    //MEMBER FUNCTION TO CHECK WHETHER THE HASH TABLE IS EMPTY 
    bool isempty(){
        for(int i = 0;i<SIZE;i++){
            if(table[i]!=NULL){
                return false;
            }
        }
        return true;
    }
    //MEMBER FUNCTION PROTOTYPES OR DECLARATION FOR OPERATIONS 
    void insert(int key);
    void delete_key(int key);
    void search(int key);
    void display();
};
//DRIVER CODE
int main(){
    class seperatechain  h;
    int key,choice;
    do{
       printf("MENU :\n");
       printf("1.INSERT\n");
       printf("2.DELETE\n");
       printf("3.SEARCH\n");
       printf("4.EXIT\n");
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
        printf("EXITED SUCCESSFULLY :)\n");
        break;
        default:
        printf("INVALID CHOICE ENTER AGAIN :(\n");
       }
    }while(choice!=4);
    return 0;
}
//MEMBER FUNCTION FOR INSERTING A KEY
void seperatechain :: insert(int key){
    int index = hash(key);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->next = table[index];
    table[index]=newnode;
}
//MEMBER FUNCTION FOR DELETING A KEY
void seperatechain :: delete_key(int key){
    int index = hash(key);
    struct node* current = table[index];
    struct node*prev = NULL;
    while(current!=NULL){
        if(current->key == key){
            if(prev == NULL){
                table[index] = current->next;  
            }else{
                prev->next = current->next;
            }
            printf("KEY %d DELETED FROM INDEX %d\n",key,index);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("KEY NOT FOUND\n");
}
//MEMBER FUNCTION FOR SEARCHING A KEY
void seperatechain :: search(int key){
    int index = hash(key);
    struct node*current = table[index];
    while(current!=NULL){
        if(current->key==key){
            printf("KEY FOUND IN THE INDEX %d\n",index);
            return;
        }
        current = current->next;
    }
    printf("KEY NOT FOUND \n");
}
//MEMBER FUNCTION FOR DISPLAYING THE HASH TABLE
void seperatechain :: display(){
    if(isempty()){
        printf("THE TABLE IS EMPTY \n");
        return;
    }
    for(int i = 0;i<SIZE;i++){
        struct node *current = table[i];
        while(current!=NULL){
            printf("%d -> ",current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}
