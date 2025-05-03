//PROGRAM TO EXECUTE ADJACENCY MATRIX USING GRAPH ADT
#include<cstdio>
class graph_adt{
    private:
        int matrix[100][100];
        int n;
    public:
        graph_adt(int vertices){
            n=vertices;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        bool isvalid(int);
        void insert(int,int);
        void deletion(int,int);
        void search(int,int);
        void display();
};
int main(){
    int n;
    printf("ENTER THE NUMBER OF VERTICES:\n");
    scanf("%d",&n);
    graph_adt obj(n);
    int u,v,choice;
    do{
        printf("\nMENU\n1.INSERTION OF EDGE\n2.DELETION OF EDGE\n3.SEARCH EDGE\n4.DISPLAY EDGE\n5.EXIT\n");
        printf("ENTER YOUR CHOICE:\n");
        scanf("%d",&choice);
        
            switch(choice){           
                case 1:
                    printf("ENTER THE U VERTICE TO INSERT AN EDGE:\n");
                    scanf("%d",&u);
                    printf("ENTER THE V VERTICE TO INSERT AN EDGE:\n");
                    scanf("%d",&v);
                    obj.insert(u,v);
                    break;
                case 2:
                    printf("ENTER THE U VERTICE TO DELETE AN EDGE:\n");
                    scanf("%d",&u);
                    printf("ENTER THE V VERTICE TO DELETE AN EDGE:\n");
                    scanf("%d",&v);
                    obj.deletion(u,v);
                    break;
                case 3:
                    printf("ENTER THE U VERTICE TO SEARCH AN EDGE:\n");
                    scanf("%d",&u);
                    printf("ENTER THE V VERTICE TO SEARCH AN EDGE:\n");
                    scanf("%d",&v);
                    obj.search(u,v);
                    break;
                case 4:
                    obj.display();
                    break;
                case 5:
                    printf("SUCCESSFULLY EXITED :) \n");
                    break;
                default:
                    printf("INVALID CHOICE\n");
                }
            }while(choice!=5);
            return 0;
    }
    //VALID CHECK FUNCTION
    bool graph_adt::isvalid(int v){
        return (v>=0&&v<n);
    }
    //FUNCTION TO INSERT AN EDGE
    void graph_adt:: insert(int u,int v){
        if(isvalid(u)&&isvalid(v)){
            matrix[u][v]=1;
            matrix[v][u]=1;
            printf("EDGE INSERTED BETWEEN %d AND %d\n",u,v);
        }
        else{
            printf("INVALID VERTEX NUMBER\n");
        }
    }
    //FUNCTION TO DELETE AN EDGE
    void graph_adt::deletion(int u,int v){
        if(isvalid(u)&&isvalid(v)){
            matrix[u][v]=0;
            matrix[v][u]=0;
            printf("EDGE DELETED BETWEEN %d AND %d\n",u,v);
        }
        else{
            printf("INVALID VERTEX NUMBER\n");
        }
    }
    //FUNCTION TO SEARCH AN EDGE
    void graph_adt::search(int u,int v){
        if(isvalid(u)&&isvalid(v)){
            if(matrix[u][v]==1){
                printf("EDGE EXIST BETWEEN %d AND %d\n",u,v);
            }
            else{
                printf("EDGE DOES NOT EXIST BETWEEN %d AND %d\n",u,v);
            }
        }
        else{
            printf("INVALID VERTEX\n");
        }
    }
    //FUNCTION TO DISPALY THE MATRIX
    void graph_adt::display(){
        printf("ADJACENCY MATRIX\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d",matrix[i][j]);
            }
            printf("\n");
        }
    }
