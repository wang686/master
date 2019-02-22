/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h>
#include<string.h>
#include <math.h>

void showbits(int);
void one(void);
void two(void);
void three(void);
void four(void);
void five(void);
void six(void);

int main(){
    

    int menuSelection = 0;
    int alpha= 0, beta = 0;
    char menu[] = "1. Perform Left Bit Shift Operation (one value)\n2. Perform Right Bit Shift Operation (one value)\n3. Perform Binary AND Operation (two values)\n4. Perform Binary OR Operation (two values)\n5. Perform Binary One's Complement (~) Operation (one value)\n6. Perform Binary XOR Operation (two values)\n7. Quit\n\n";
    int i;
    
//while(1){
    printf("                Main Menu\n");
    printf("                ---------\n");
    printf("\n%s",menu);
    scanf("%d",&menuSelection);
    
    
    switch(menuSelection){
        case 1: 
            one();
            break;
        case 2:
            two();
            break;
        case 3:
            three();
            break;
        case 4:
            four();
            break;
        case 5:
            five();
            break;
        case 6:
            six();
            break;
        case 7:
            printf("Program finished.");
            return(0);
        default:
            printf("Invalid input");
        
        
        
        
    }

//}//while


    return 0;
}


void showbits(int input){
    int i;
    
    for(i = 31; i>=0; i--)
        printf("%d",abs((input&(1<<i)) >>i));
        printf(" (base 10 %d)",input);
}

void one(){
    int alpha, beta;
    
    printf("Enter a base 10 Integer: ");
    scanf("%d",&alpha);
    printf("\nEnter number of places to shift bit: ");
    scanf("%d",&beta);
    printf("\n\n        Entered Integer: ");
    showbits(alpha);
    alpha = alpha<<beta;
    printf("\n        ~'ed           : ");
    showbits(alpha);
}

void two(){
    int alpha, beta;
    
    printf("Enter a base 10 Integer: ");
    scanf("%d",&alpha);
    printf("\nEnter number of places to shift bit: ");
    scanf("%d",&beta);
    printf("\n\n        Entered Integer: ");
    showbits(alpha);
    alpha = alpha>>beta;
    printf("\n        ~'ed           : ");
    showbits(alpha);
}

void three(){
    int alpha, beta;
    
    printf("Enter two base 10 Integers, separated by a space: ");
    scanf("%d",&alpha);
    scanf("%d",&beta);
    printf("\n\n        Entered Integer 1: ");
    showbits(alpha);
    printf("\n        Entered Integer 2: ");
    showbits(beta);
    
    alpha = alpha & beta;
    printf("\n        AND'ed           : ");
    showbits(alpha);
}
void four(){
    int alpha, beta;
    
    printf("Enter two base 10 Integers, separated by a space: ");
    scanf("%d",&alpha);
    scanf("%d",&beta);
    printf("\n\n        Entered Integer 1: ");
    showbits(alpha);
    printf("\n        Entered Integer 2: ");
    showbits(beta);
    
    alpha = alpha | beta;
    printf("\n        OR'ed            : ");
    showbits(alpha);
}
void five(){
    int alpha;
    
    printf("Enter a base 10 Integer: ");
    scanf("%d",&alpha);
    printf("\n\n        Entered Integer: ");
    showbits(alpha);
    alpha = ~alpha;
    printf("\n        ~'ed           : ");
    showbits(alpha);
}

void six(){
    int alpha, beta;
    
    printf("Enter two base 10 Integers, separated by a space: ");
    scanf("%d",&alpha);
    scanf("%d",&beta);
    printf("\n\n        Entered Integer 1: ");
    showbits(alpha);
    printf("\n        Entered Integer 2: ");
    showbits(beta);
    
    alpha = alpha ^ beta;
    printf("\n        XOR'ed           : ");
    showbits(alpha);
}











