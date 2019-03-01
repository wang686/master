/******************************************************************************
                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include <stdio.h>
#include <string.h>
struct player{
    char name[32];
    char team[32];
    float bat;
};

struct team{
    char name[32];
};


int main() {
    int teamNum;
    int playerNum;
    int i,j,k;
    
//take and store user input, then construct an array of teams
    printf("input teamNum: ");
    scanf("%d",&teamNum);
    struct team teams[teamNum];//<----------declared new variable;
    
//for each element in teams array, take user input and store it as its team name.    
    for(i = 0; i<teamNum;i++){
        printf("enter teamName: ");
        scanf("%s",teams[i].name);
    }

//let user decide which plaer belongs which team.
    printf("input playerNum: ");
    scanf("%d",&playerNum);
    struct player players[playerNum];//<----------declared new variable;
    
//take user input for each player    
    for (i = 0; i < playerNum; i++) {
        printf("Enter the %d Player name, Team name, and batting average: ",i+1);
        scanf("%s",&players[i].name);
        scanf("%s",&players[i].team);
        scanf("%f",&players[i].bat);
    }
    
    for (i = 0; i < teamNum; i++) {
        printf("%s-\n",teams[i].name);
        for (int j = 0; j < playerNum; j++) {
            if(strcmp(players[j].team,teams[i].name) == 0){//filter players with the team name.
                printf("        %s       %f\n",players[j].name, players[j].bat);
            }
        }
    }
 


    return 0;
}
