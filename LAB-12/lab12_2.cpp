//PROGRAM TO IMPLEMENT ADJACENCY LIST USING GRAPH ADT
#include<cstdio>
#include<list>
using namespace std;
class graph_adt {
    private:
        int V;                     
        list<int>* adj;             
    public:
        graph_adt(int vertices) {
            V = vertices;
            adj = new list<int>[V]; 
        }
        bool isvalid(int);
        void insert(int,int);
        void deletion(int,int);
        void search(int,int);
        void display();
        ~graph_adt(){
            delete[]adj;
        }
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
                        printf("EXITED SUCCESSFULLY \n");
                        break;
                    default:
                        printf("INVALID CHOICE\n");
                    }
                }while(choice!=5);
                return 0;
        }
        bool graph_adt:: isvalid(int v) {
            return (v >= 0 && v < V);
        }
        //FUNCTION TO INSERT AN EDGE
        void graph_adt::insert(int u,int v){
            if(isvalid(u)&&isvalid(v)){
                adj[u].push_back(v);
                adj[v].push_back(u);
                printf("EDGE INSERTED BETWEEN %d AND %d\n",u,v);
            }
            else{
                printf("INVALID VERTEX NUMBER\n");
            }
        }
        void graph_adt::deletion(int u,int v){
            if(isvalid(u)&&isvalid(v)){
                adj[u].remove(v);
                adj[v].remove(u);
                printf("EDGE DELETED BETWEEN %d AND %d\n",u,v);
            }
            else{
                printf("INVALID VERTEX NUMBER\n");
            }
        }
        void graph_adt::search(int u,int v){
            if(isvalid(u)&&isvalid(v)){
                bool found=false;
                for(int val:adj[u]){
                    if(val==v){
                        found=true;
                        break;
                    }
                }
                if(found){
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
        void graph_adt::display(){
            printf("ADJACENCY LIST\n");
            for(int i=0;i<V;i++){
                printf("%d:",i);
                for(int x:adj[i]){
                    printf("%d ->",x);
                }
            printf("\n");
            }
        }
