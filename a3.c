#include <stdio.h>

#include<stdio.h>
#include<string.h>
#define ROW 6
#define COL 10
#define NAME 30
#define FIRST 2
#define BUS 4
#define ECO 10
void printSeatMap(char allSeats[][COL][NAME]);
int first(char allSeats[][COL][NAME]);
int second(char allSeats[][COL][NAME]);
int third(char allSeats[][COL][NAME]);
int findFirst(char allSeats[][COL][NAME]);
int findSecond(char allSeats[][COL][NAME]);
int findThird(char allSeats[][COL][NAME]);

int main(){
  int i,j,k;
  int sold,class;
  char seatMap[ROW][COL][NAME] ={{"a"}};
  int menuSelection = 0;
  char menu[] = "\n\tPlease type 1 for \"first class\"\n\tPlease type 2 for \"business class\"\n\tPlease type 3 for \"economy class\"\n\n";

  //init a three d array row number, col number, name.
  for(i = 0; i< ROW;i++){
    for(j = 0; j < COL;j++)
      strcpy(seatMap[i][j],"0");
  }
  
  printf("%s", menu);
  scanf("%d",&menuSelection);
  
  
  switch(menuSelection){
      case 1:
            first(seatMap);
        break;
      case 2:
            second(seatMap);
        break;
      case 3:
            third(seatMap);
        break;
      default:
        break;
        
      
  }
  
  
  
 
  
  
  
  
  
  
  

  //printSeatMap(seatMap);
  printf("\n%s",seatMap[i][j]);

  return 0;
}


void printSeatMap(char allSeats[][COL][NAME]){
  int i = 0,j=0,ascii=65;
  printf(" ");//upperleft offset
  for(i = 1; i <= COL; i++){
      printf("% d",i); // column header
  }
  puts("");

//-------------------------

  for(i = 0; i < ROW; i++){
    printf("%c ",ascii+i); // A - F aisles
    //------------------------ // elements
    for(j = 0;j< COL;j++){
      if(allSeats[i][j][0] == '0'){// check if it is the init value.
        printf("0 ");
      }else{
        printf("1 ");//printf("%s ",allSeats[i][j]);
      }
    }
    puts("");
  }
  printf("\n%s",allSeats[0][0]);
}

int first(char allSeats[][COL][NAME]){
  int i,j,k;
  char name[NAME];
  
  printf("Enter your name: \n");
  scanf("%29s",name);
  
  for(i = 0; i < COL;i++){
    for(j = 0; j< FIRST;j++){
        if(allSeats[i][j][0] == '0'){
          strcpy(allSeats[i][j],name);
          return 0;
        }
    }
  }
  printf("First class is full, would you like a business class?\nType 1 to proceed\n");
  scanf("%d",&k);
  if(k == 1){
      second(allSeats);
  }else{
      printf("\nexit");
      return 0;
  }
  
}
  

int second(char allSeats[][COL][NAME]){
  int i,j,k;
  char name[NAME];
  
  printf("Enter your name: \n");
  scanf("%29s",name);
  
  for(i = 0; i < COL;i++){
    for(j = FIRST; j< BUS;j++){
        if(allSeats[i][j][0] == '0'){
          strcpy(allSeats[i][j],name);
          return 0;
        }
    }
  }
  printf("Business class is full, would you like a economy class?\nType 1 to proceed\n");
  scanf("%d",&k);
  if(k == 1){
      third(allSeats);
  }else{
      printf("\nexit");
      return 0;
  }
}


int third(char allSeats[][COL][NAME]){
  int i,j,k;
  char name[NAME];
  
  printf("Enter your name: \n");
  scanf("%29s",name);
  
  for(i = 0; i < COL;i++){
    for(j = BUS; j< ECO;j++){
        if(allSeats[i][j][0] == '0'){
          strcpy(allSeats[i][j],name);
          return 0;
        }
    }
  }
    printf("\nexit");
    return 0;
}

/*int findFirst(char allSeats[][COL][NAME]){
  int i,j,k;
  for(i = 0; i < COL;i++){
    for(j = 0; j< FIRST;j++){
        if(allSeats[i][j][0] == '0'){
          return 0;
        }
    }
  }
  return -1;
}

int findSecond(char allSeats[][COL][NAME]){
  int i,j,k;
  for(i = 0; i < COL;i++){
    for(j = FIRST; j< BUS;j++){
        if(allSeats[i][j][0] == '0'){
          return 0;
        }
    }
  }
  return -1;
}


int findThird(char allSeats[][COL][NAME]){
  int i,j,k;
  
  for(i = 0; i < COL;i++){
    for(j = BUS; j< ECO;j++){
        if(allSeats[i][j][0] == '0'){
          return 0;
        }
    }
  }
  return -1;
}*/
