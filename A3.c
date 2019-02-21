/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h>
#include<string.h>
#include <math.h>

void showbits(int input);
int main(){
    

    int menuSelection = 0;
    unsigned int alpha= 0, beta = 0;//try unsigned if out put is has -1 at begeining
    char menu[] = "1. Perform Left Bit Shift Operation (one value)\n2. Perform Right Bit Shift Operation (one value)\n3. Perform Binary AND Operation (two values)\n4. Perform Binary OR Operation (two values)\n5. Perform Binary One's Complement (~) Operation (one value)\n6. Perform Binary XOR Operation (two values)\n7. Quit\n\n";
    int i;
    
while(1){
    printf("                Main Menu\n");
    printf("                ---------\n");
    printf("\n%s",menu);
    scanf("%d",&menuSelection);
    
    
    switch(menuSelection){
        case 1: 
            printf("Enter a base 10 Integer: ");
            break;
        case 2:
            printf("spmething 2");
            break;
        case 3:
            printf("spmething 3");
            break;
        case 4:
            printf("spmething 4");
            break;
        case 5:
            printf("Enter a base 10 Integer: ");
            scanf("%d",&alpha);
            alpha = ~alpha;
            showbits(alpha);


            break;
        case 6:
            printf("spmething 6");
            break;
        case 7:
            printf("Program finished.");
            return;
        default:
            printf("Invalid input");
        
        
        
        
    }
    
}


    return 0;
}


void showbits(int input){
    int i;
    
    for(i = 31; i>=0; i--)
        printf("%d",(input&(1<<i)) >>i);
}
