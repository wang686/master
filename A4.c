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

int main(){
    cricket();
    return(0);
}


void cricket() {
    int teamNum;
    int playerNum;
    int i,j,k;
    
//take and store user input, then construct an array of teams
    printf("Enter the number of teams you wish to record: ");
    scanf("%d",&teamNum);
    struct team teams[teamNum];//<----------declared new variable;
    
//for each element in teams array, take user input and store it as its team name.    
    for(i = 0; i<teamNum;i++){
        printf("Enter the name(s) of the teams: ");
        scanf("%s",teams[i].name);
    }

//let user decide which plaer belongs which team.
    printf("Enter the TOTAL number of players for all teams: ");
    scanf("%d",&playerNum);
    struct player players[playerNum];//<----------declared new variable;
    
//take user input for each player    
    for (i = 0; i < playerNum; i++) {
        printf("Enter the %d Player name, Team name, and batting average: ",i+1);
        scanf("%s",&players[i].name);
        scanf("%s",&players[i].team);
        scanf("%f",&players[i].bat);
    }
    
    printf("\nListing of players and batting average according to team names: \n\n");
//print out result
//1. loop to print team name in teams array
//2. nested in the first, prints out all players whose team name match the current iteration's.
    for (i = 0; i < teamNum; i++) {
        printf("%s-\n",teams[i].name);
        for (int j = 0; j < playerNum; j++) {
            if(strcmp(players[j].team,teams[i].name) == 0){//filter players with the team name.
                printf("        %s       %f\n",players[j].name, players[j].bat);
            }
        }
    }//forloop
 
}//cricket
