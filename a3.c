
#include<stdio.h>
#include<string.h>
#define ROW 6
#define COL 10
#define NAME 30
#define FIRST 2
#define BUS 4
#define ECO 10
//print map 0 mean available, 1 means sold
void printSeatMap(char allSeats[][COL][NAME]);
void printManifest(char allSeats[][COL][NAME]);
void printBoardingPass(char allSeats[][COL][NAME], int d, char c);
//assign a seat in first class. return -1 if it's full
int first(char allSeats[][COL][NAME]); 
//assign a seat in business class. return -1 if it's full
int second(char allSeats[][COL][NAME]); 
//assign a seat in economy class. return -1 if it's full
int third(char allSeats[][COL][NAME]); 
//check availablity for first class
int findFirst(char allSeats[][COL][NAME]); 
//check availablity for business class
int findSecond(char allSeats[][COL][NAME]); 
//check availablity for economy class
int findThird(char allSeats[][COL][NAME]); 

int main(){
  int i,j,k,s;
  int d; char c;
  int sold,class;
  char seatMap[ROW][COL][NAME] ={{"a"}};
  int menuSelection = 0;
  char menu[] = "\n\t-----------MENU----------\n\tPlease type 1 for \"first class\"\n\tPlease type 2 for \"business class\"\n\tPlease type 3 for \"economy class\"\n\tPlease type 4 to see available seats\n\tPlease type 5 to see passenger manifest\n\tPlease type 6 to print boarding pass\n";

  //init a three d array row number, col number, name.
  for(i = 0; i< ROW;i++){
    for(j = 0; j < COL;j++)
      strcpy(seatMap[i][j],"0");
  }
  
  
  while(1){
  printf("\n%s", menu);
  scanf("%d",&menuSelection);
  
  int initSelection = 0;
  int availOne = 0;
  int availTwo = 0;
  int availThree = 0;

  

  switch(menuSelection){
      case 1:
            initSelection = first(seatMap);
            availTwo = findSecond(seatMap);
            availThree = findSecond(seatMap);
            if(initSelection == -1 && availTwo == 0){
                printf("First class sold out. Would you like to be in business cabinet? press 1 to proceed\n");
                scanf("%d",&s);
                if(s == 1){second(seatMap);}
            }
            else if(initSelection == -1 && availThree == 0){
                printf("\nBusiness class sold out. Would you like to be in economy cabinet? press 1 to proceed\n");
                scanf("%d",&s);
                if(s == 1){third(seatMap);}
            }
            else if(availTwo == -1 && availThree == -1){
                printf("Next flight leaves in 3 hours");
            }

        break;
      case 2:
            initSelection = second(seatMap);
            availOne = findFirst(seatMap);
            availThree = findSecond(seatMap);
            
            if(initSelection == -1 && availOne == 0){
                printf("\nBusiness class sold out. Would you like to be in first cabinet? press 1 to proceed\n");
                scanf("%d",&s);
                if(s == 1){first(seatMap);}
            }
            else if(initSelection == -1 && availThree == 0){
                printf("\nBusiness class sold out. Would you like to be in economy cabinet? press 1 to proceed\n");
                scanf("%d",&s);
                if(s == 1){third(seatMap);}
            }
            else if(availTwo == -1 && availThree == -1){
                printf("Next flight leaves in 3 hours");
            }
            

            
        break;
      case 3:
            initSelection = third(seatMap);
            int availOne = findFirst(seatMap);
            int availTwo = findSecond(seatMap);
            if(initSelection == -1 && availTwo == 0){
                printf("\nEconomy class sold out. Would you like to be in Business cabinet? press 1 to proceed\n");
                scanf("%d",&s);
                if(s == 1){second(seatMap);}
            }
            else if(initSelection == -1 && availOne == 0){
                printf("\nEconomy class sold out. Would you like to be in first cabinet? press 1 to proceed\n");
                scanf("%d",&s);
                if(s == 1){first(seatMap);}
            }
            else if(availTwo == -1 && availOne == -1){
                printf("Next flight leaves in 3 hours");
            }

            
        break;
      case 4:
        printSeatMap(seatMap);
        //printf("\n%s",seatMap[i][j]);
        break;
      case 5:
        printManifest(seatMap);
        break;
      case 6:
        printf("\nEnter digit ");
        scanf("%d",&d);
        printf("\nEnter letter(Upper Case) ");
        scanf(" %c",&c);
        printBoardingPass(seatMap,d,c);
        break;
      
      default:
        break;
        
      
  }
  }
  
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

void printManifest(char allSeats[][COL][NAME]){
    int i = 0,j=0,ascii=65;
    printf("\n\t-----PASSENGER MANIFEST-----");
    
    for(i = 0; i < ROW; i++){
        for(j = 0;j< COL;j++){
            if(allSeats[i][j][0] != '0'){
                printf("\n\t%s--%d%c",allSeats[i][j],j+1,ascii+i);
            }
        }
    }
}

void printBoardingPass(char allSeats[][COL][NAME], int d, char c){
    if(d<= 10 && c<= 70 && d>= 1 && c>=65){
        if(allSeats[d-1][c-65] != 0){
            printf("\n\t%s--%d%c",allSeats[d-1][c-65],d,c);
            if(d < 2){
                printf("\tfirst class");
            }else if(d < 5){
                printf("\tbusiness class");
            }else{
                printf("\teconomy class");
            }
        }else{
            printf("\nSeat Unassigned - No Boarding pass available. Try Again!");
        }
    }
    else{
        printf("\nInvalid input");
    }
    
    
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
    //printf("\nfirst class sold out.\n");
    return -1;
  
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
  //printf("\nbusiness class sold out.\n");
  return -1;
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
    //printf("\neconomy class sold out.\n");
    return -1;
}

int findFirst(char allSeats[][COL][NAME]){
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
}
