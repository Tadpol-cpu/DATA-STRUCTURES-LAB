//TO INCREASE THE NUMBER OF BLOCKS IN TOWER 1 IF ANY OTHER BLOCK CONTAINS MORE THAN IT 
#include<cstdio>
#include<cstdlib>
#include<queue>
//DRIVER CODE
int main(){
    std :: queue <int> q;
    int t;
    scanf("%d",&t);

    if(t>10000){
        printf("INCORRECT VALUE OF NUMBER OF TESTCASES TRY AGAIN \n");
        return 0;
    }
    while(t--){
        int n;
        scanf("%d",&n);
        if(n<2 || n>200000){
            printf("INVALID VALUE OF NUMBER OF TOWERS TRY AGAIN \n");
            t++;
            continue;
        }
        int value1,value2;
        scanf("%d",&value1);
        for(int j = 1;j<n;j++){
            scanf("%d",&value2);
            while(value2>0&&value1<value2){
                value1++;
                value2--;
            }
        }
        q.push(value1);
    }
    while (!q.empty()) {
        printf("%d\n", q.front()); // Display the front element
        q.pop(); // Remove the front element from the temporary queue
    }

    printf("\n");
    return 0;
}
