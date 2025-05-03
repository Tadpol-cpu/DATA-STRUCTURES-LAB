//TO CREATE A BINARY TREE TO IMPLEMENT THE FOLLOWING OPERATIONS 
#include<cstdio>
#include<cstdlib>
//CLASS FOR BINARY TREE
class Binarytree{
    private :
    struct node{
       char data;
       struct node*left;
       struct node*right;
    }*root;
    public :
    Binarytree(){
        root = NULL;
    }
    //MEMBER FUNCTION TO CREATE A NEWNODE
    struct node*newnode(char data){
        struct node*newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    //MEMBER FUNCTION TO INSERT A NEWNODE
    void insert(struct node * Node,char data){
        if(Node->left == NULL){
            Node->left = newnode(data);
        }else if(Node->right == NULL){
            Node->right = newnode(data);
        }else if(Node->left != NULL){
            insert(Node->left,data);
        }else if(Node->right != NULL){
            insert(Node->right,data);
        }
    }
    //MEMBER FUNCTION TO SEARCH FOR THE FIRST OCCURANCE OF AN ELEMENT FROM THE BINARY TREE
    struct node *search(struct node*Node,char data){
        if(Node==NULL){
            return NULL;
        }else if(Node->data == data){
            return Node;
        }
        struct node*found = search(Node->left,data);
        if(found!=NULL){
           return found;
        }
        return search(Node->right,data);
    }
    //MEMBER FUNCTIONS FOR CALLING INSERTION AND SEARCH FUNCTIONS
    //MEMBER FUNCTIONS FOR INORDER ,PREORDER,POSTORDER AND THEIR CALLING FUNCTIONS 
    void insertion(char data);
    void inorder(struct node* Node); 
    void displayinorder();
    void preorder(struct node* Node);
    void displaypreorder();
    void postorder(struct node *Node);
    void displaypostorder();
    bool searched(char data);
};
//DRIVER CODE
int main(){
    Binarytree tree;
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
            tree.displayinorder();
            break;
        case 3 :
            tree.displaypreorder();
            break;
        case 4 :
            tree.displaypostorder();
            break;
        case 5 :
            printf("ENTER THE ELEMENT TO BE SEARCHED FOR : ");
            scanf(" %c",&data);
            flag = tree.searched(data);
            if(flag==1){
                printf("ELEMENT FOUND \n");
            }else{
                printf("ELEMENT NOT FOUND \n");
            }
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
//MEMBER FUNCTION FOR CALLING INSERTION 
void Binarytree :: insertion(char data){
    if(root == NULL){
        root = newnode(data);
    }else{
        insert(root,data);
    }
}
//MEMBER FUNCTION FOR INORDER TRAVERSAL
void Binarytree :: inorder(struct node*Node){
    if(Node!=NULL){
        inorder(Node->left);
        printf("%c ",Node->data);
        inorder(Node->right);
    }
}
//MEMBER FUNCTION FOR CALLING INORDER TRAVERSAL
void Binarytree :: displayinorder(){
    inorder(root);
    printf("\n");
}
//MEMBER FUNCTION FOR PREORDER TRAVERSAL
void Binarytree :: preorder(struct node * Node){
    if(Node!=NULL){
       printf("%c ",Node->data);
       preorder(Node->left);
       preorder(Node->right);
    }
}
//MEMBER FUNCTION FOR CALLING PREORDER TRAVERSAL
void Binarytree :: displaypreorder(){
    preorder(root);
    printf("\n");
}
//MEMBER FUNCTION FOR POSTORDER TRAVERSAL
void Binarytree :: postorder(struct node *Node){
    if(Node!=NULL){
        postorder(Node->left);
        postorder(Node->right);
        printf("%c ",Node->data);
    }
}
//MEMBER FUNCTION FOR CALLING POSTORDER TRAVERSAL
void Binarytree :: displaypostorder(){
    postorder(root);
    printf("\n");
}
//MEMBER FUNCTION FOR CALLING SEARCH
bool Binarytree :: searched(char data){
   return search(root,data)!=NULL; 
}
