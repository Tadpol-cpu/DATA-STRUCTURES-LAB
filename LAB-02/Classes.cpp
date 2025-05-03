//PROGRAM TO CALCULATE AREA OF SQUARE ,CUBE,RECTANGLE AND CUBOID USING CLASSES 
#include<cstdio>
#include<cstdlib>
class area{
   int length;int breadth;int height;
   public :
       area(){
        length =1;breadth=1;height=1;
       }
       void setlength(int len);
       void setbreadth(int bre);
       void setheight(int hei);
       int square_area(){
        return length*length;
       }
       int cube_area(){
        return 4*length*length;
       }
       int rectangle_area(){
        return length*breadth;
       }
       int cuboid_area(){
        return 2*((length*breadth)+(length*height)+(height*breadth));
       }
};
int main(){
    int choice=0;
    int length_user;
    int breadth_user;
    int height_user;
    area obj;
    int square;
    int cube;
    int rectangle;
    int cuboid_user;
    do{
       printf("MENU :\n");
       printf("1.SQUARE\n");
       printf("2.CUBE\n");
       printf("3.RECTANGLE\n");
       printf("4.CUBOID\n");
       printf("5.EXIT\n");
       printf("ENTER YOUR CHOICE : ");
       scanf("%d",&choice);
       switch(choice){
        case 1:
        printf("ENTER THE SIDE OF CUBE : ");
        scanf("%d",&length_user);
        if(length_user<0){
            printf("INVALID DIMENSION \n");
        }else{
            obj.setlength(length_user);
            square = obj.square_area();
            printf("THE AREA OF THE SQUARE IS : %d \n",square);
        }
        break;
        case 2:
        printf("ENTER THE SIDE OF CUBE : ");
        scanf("%d",&length_user);
        if(length_user<0){
            printf("INVALID DIMENSION \n");
        }else{
            obj.setlength(length_user);
            cube = obj.cube_area();
            printf("THE AREA OF CUBE IS : %d \n",cube);
        }
        break;
        case 3:
        printf("ENTER THE LENGTH AND BREADTH OF RECTANGLE : ");
        scanf("%d%d",&length_user,&breadth_user);
        if(length_user<0 || breadth_user<0){
            printf("INVALID DIMENSION \n");
        }else{
            obj.setlength(length_user);
            obj.setbreadth(breadth_user);
            rectangle = obj.rectangle_area();
            printf("THE AREA OF RECTANGLE IS : %d \n",rectangle);
        }
        break;
        case 4:
        printf("ENTER THE LENGTH ,BREADTH AND HEIGHT OF THE CUBOID : ");
        scanf("%d%d%d",&length_user,&breadth_user,&height_user);
        if(length_user<0 || breadth_user<0|| height_user<0){
            printf("INVALID DIMENSION \n");
        }else{
            obj.setlength(length_user);
            obj.setbreadth(breadth_user);
            obj.setheight(height_user);
            cuboid_user = obj.cuboid_area();
            printf("THE AREA OF CUBOID IS : %d \n",cuboid_user);
        break;
        case 5:
        printf("EXITED SUCCESSFULLY !\n");
        break;
        default:
        printf("INCORRECT CHOICE ENTER AGAIN \n");
        }
       }
       
    }while(choice != 5);
    return 0;

}

void area::setlength(int len){
    length = len;
}
void area::setbreadth(int bre){
    breadth = bre;
}
void area::setheight(int hei){
    height = hei;
}
