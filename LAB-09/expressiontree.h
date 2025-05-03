#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
//TO CREATE A BINARY TREE TO IMPLEMENT THE FOLLOWING OPERATIONS 
#include<cstdio>
#include<cstdlib>
#include<stack>
using namespace std;
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
    //MEMBER FUNCTION TO CONSTRUCT THE EXPRESSION TREE 
    struct node*constructexpressiontree(char postfix[]){
        stack<node*> st;
        for(int i = 0;postfix[i]!='\0';i++){
            char ch = postfix[i];
            if((ch>='0'&&ch <='9')||(ch>='a' && ch<='z')||(ch>='A' && ch<='Z')){
                st.push(newnode(ch));
            }else{
                struct node*op = newnode(ch);
                op->right = st.top();
                st.pop();
                op->left = st.top();
                st.pop();
                st.push(op);
            }
        }
        return st.top();
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
    bool isvalidpostfix(char postfix[]);
    void call_expressiontree(char postfix[]);
};
//MEMBER FUNCTION DEFINITION FOR CALLING INSERTION 
void Binarytree :: insertion(char data){
    if(root == NULL){
        root = newnode(data);
    }else{
        insert(root,data);
    }
}
//MEMBER FUNCTION DEFINITION FOR INORDER TRAVERSAL
void Binarytree :: inorder(struct node*Node){
    if(Node!=NULL){
        inorder(Node->left);
        printf("%c ",Node->data);
        inorder(Node->right);
    }
}
//MEMBER FUNCTION DEFINITION FOR CALLING INORDER TRAVERSAL
void Binarytree :: displayinorder(){
    inorder(root);
    printf("\n");
}
//MEMBER FUNCTION DEFINITION FOR PREORDER TRAVERSAL
void Binarytree :: preorder(struct node * Node){
    if(Node!=NULL){
       printf("%c ",Node->data);
       preorder(Node->left);
       preorder(Node->right);
    }
}
//MEMBER FUNCTION DEFINITION FOR CALLING PREORDER TRAVERSAL
void Binarytree :: displaypreorder(){
    preorder(root);
    printf("\n");
}
//MEMBER FUNCTION DEFINITION FOR POSTORDER TRAVERSAL
void Binarytree :: postorder(struct node *Node){
    if(Node!=NULL){
        postorder(Node->left);
        postorder(Node->right);
        printf("%c ",Node->data);
    }
}
//MEMBER FUNCTION DEFINITION FOR CALLING POSTORDER TRAVERSAL
void Binarytree :: displaypostorder(){
    postorder(root);
    printf("\n");
}
//MEMBER FUNCTION DEFINITION FOR CALLING SEARCH
bool Binarytree :: searched(char data){
   return search(root,data)!=NULL; 
}
//TO CHECK WHETHER THE ENTERED POSTFIX IS VALID OR NOT 
bool Binarytree :: isvalidpostfix(char postfix[]){
    int operatorcount = 0,operandcount = 0;
    for(int i = 0;postfix[i]!='\0';i++){
        char ch = postfix[i];
        if((ch >= '0' && ch <='9') || (ch>='a'&&ch<='z') || (ch>='A' && ch<='Z')){
            operandcount++;
        }
        else if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')){
            operatorcount++;
            if(operandcount<2)return false;
            operandcount--;
        }else{
            return false;
        }
    }
    return (operandcount==1 && operatorcount>0);
}
//MEMBER FUNCTION TO CALL CONSTRUCTION OF EXPRESSION TREE
void Binarytree :: call_expressiontree(char postfix[]){
    if(!isvalidpostfix(postfix)){
        printf("INVALID POSTFIX EXPRESSION TRY AGAIN :(\n");
        return;
    }
    root = constructexpressiontree(postfix);
} 
#endif
