//TO IMPLEMENT TREE ADT USING BINARY SEARCH TREE 
#include<cstdio>
#include<cstdlib>
class bin{
    //MEMBER FUNCTIONS AND DATA MEMBERS 
    private :
    struct node{
        char data;
        struct node*left;
        struct node*right;
    }*root;
    public :
    //CONSTRUCTOR
    bin(){
        root = NULL;
    }
    //MEMBER FUNCTION DEFINITIONS 
    struct node*insert(struct node*p,char data){
        struct node*temp;
        if(p==NULL){
            temp=(struct node *)malloc(sizeof(struct node));
            temp->data=data;
            temp->left = temp->right = NULL;
            return temp;
        }
        else if(data<p->data){
            p->left = insert(p->left,data);
        }
        else{
            p->right = insert(p->right,data);
        }
        return p;
    }
    struct node*search(struct node*p,char key){
        if(p==NULL){
            return NULL;
        }
        else if(key==p->data){
            return p;
        }
        else if(key < p->data){
            return search(p->left,key);
        }
        else{
            return search(p->right,key);
        }
    }
    //MEMBER FUNCTION DECLARATIONS OR PROTOTYPES 
    void insertion(char data);
    void searched(char data);
    void inorder(struct node*Node);
    void display_inorder();
    void preorder(struct node*Node);
    void display_preorder();
    void postorder(struct node*Node);
    void display_postorder();
};
//DRIVER CODE 
int main(){
    bin tree;
    int choice,flag;
    char data;
    do{
      printf("MENU : \n");
      printf("1.INSERT A NODE \n");
      printf("2.INORDER \n");
      printf("3.PREORDER \n");
      printf("4.POSTORDER \n");
      printf("5.SEARCH \n");
      printf("6.EXIT \n");
      printf("ENTER YOUR CHOICE : ");
      scanf("%d",&choice);
      switch(choice){
        case 1 :
            printf("ENTER THE DATA TO BE INSERTED : ");
            scanf(" %c",&data);
            tree.insertion(data);
            break;
        
        case 2 :
            tree.display_inorder();
            break;
        case 3 :
            tree.display_preorder();
            break;
        case 4 :
            tree.display_postorder();
            break;
        case 5 :
            printf("ENTER THE ELEMENT TO BE SEARCHED FOR : ");
            scanf(" %c",&data);
            tree.searched(data);
            break;
        case 6 :
            printf("EXITED SUCCESSFULLY :) \n");
            break;
        default :
            printf("INCORRECT CHOICE TRY AGAIN :( \n");    
      }
    }while(choice!=6);
    return 0;
}
//MEMBER FUNCTION CALL FOR INSERTION 
void bin :: insertion(char data){
    root = insert(root,data);
}
//MEMBER FUNCTION DEFINITION FOR INORDER TRAVERSAL
void bin :: inorder(struct node *Node){
    if(Node!=NULL){
        inorder(Node->left);
        printf("%c ",Node->data);
        inorder(Node->right);
    }
}
//MEMBER FUNCTION DEFINITION FOR CALLING INORDER TRAVERSAL 
void bin :: display_inorder(){
    inorder(root);
    printf("\n");
}
//MEMBER FUNCTION DEFINITION FOR PREORDER TRAVERSAL
void bin :: preorder(struct node * Node){
    if(Node!=NULL){
       printf("%c ",Node->data);
       preorder(Node->left);
       preorder(Node->right);
    }
}
//MEMBER FUNCTION DEFINITION FOR CALLING PREORDER TRAVERSAL
void bin :: display_preorder(){
    preorder(root);
    printf("\n");
}
//MEMBER FUNCTION DEFINITION FOR POSTORDER TRAVERSAL
void bin :: postorder(struct node *Node){
    if(Node!=NULL){
        postorder(Node->left);
        postorder(Node->right);
        printf("%c ",Node->data);
    }
}
//MEMBER FUNCTION DEFINITION FOR CALLING POSTORDER TRAVERSAL
void bin :: display_postorder(){
    postorder(root);
    printf("\n");
}
//MEMBER FUNCTION TO CALL SEARCH 
void bin :: searched(char data){
    if(search(root,data)==NULL){
        printf("ELEMENT NOT FOUND \n");
    }else{
        printf("ELEMENT FOUND \n");
    }
}
