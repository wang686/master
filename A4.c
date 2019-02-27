/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
struct player{
    char name[32];
//    char teamName[32];
    float bat;
};

struct team{
    char name[32];
};


int main() {
    int teamNum;
    int playerNum;
    int i,j,k;
    
    printf("input teamNum: ");
    scanf("%d",&teamNum);
    struct team teams[teamNum];
    
    
    for(i = 0; i<teamNum;i++){
        printf("enter teamName: ");
        scanf("%s",teams[i].name);
    }
    
    for(i = 0; i<teamNum;i++){
        printf("%s",teams[i].name);
    }    


    return 0;
}
