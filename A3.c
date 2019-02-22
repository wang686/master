/*
Filename: A3.c 
Part of: Homework Assignment 3
Created by: Jiaxing Wang
Created on: 2/21/2019
Last Modified by: Jiaxing Wang 
Last Modified on: 2/21/2019
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
void showbits(int);
void one(void);
void two(void);
void three(void);
void four(void);
void five(void);
void six(void);

int main(){
//declare variables for future use
    int menuSelection = 0;
//a String of expalination of functions of the menu.
    char menu[] = "1. Perform Left Bit Shift Operation (one value)\n2. Perform Right Bit Shift Operation (one value)\n3. Perform Binary AND Operation (two values)\n4. Perform Binary OR Operation (two values)\n5. Perform Binary One's Complement (~) Operation (one value)\n6. Perform Binary XOR Operation (two values)\n7. Quit\n\n";
    
while(1){
//print the menu and take input.
    printf("\n\n\n                Main Menu\n");
    printf("                ---------\n");
    printf("\n%s",menu);
    scanf("%d",&menuSelection);
    
//switch to respond user input. It runs desired functions accordingly.    
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
            return(0); //exit main()
        default:
            printf("Invalid input");
    }//switch

}//while
    return 0;
}//main

// A function to do routine work of printing bits of an integer argument.
void showbits(int input){
    int i;
    
    for(i = 31; i>=0; i--)
        if (((input&(1<<i)) >>i) < 0){
            printf("%d",((input&(1<<i)) >>i)*-1);
        }
        else{
            printf("%d",(input&(1<<i)) >>i);
        }//not sure if  abs() is allowed. sorry for messy looking.
        printf(" (base 10 %d)",input);
}

//no parameter. simply take user input and shows left shift operation. no return value
void one(){
    int alpha, beta; //declare varibales
    
    printf("Enter a base 10 Integer: ");
    scanf("%d",&alpha);

    printf("\nEnter number of places to shift bit: ");
    scanf("%d",&beta);

    printf("\n\n        Entered Integer: ");
    showbits(alpha);
    
    alpha = alpha<<beta;//do as user wanted and store result in alpha

    printf("\n        Left Shifted   : ");
    showbits(alpha);
}

//no parameter. simply take user input and shows right shift  operation. no return value
void two(){
    int alpha, beta; //declare varibales
    
    printf("Enter a base 10 Integer: ");
    scanf("%d",&alpha);

    printf("\nEnter number of places to shift bit: ");
    scanf("%d",&beta);

    printf("\n\n        Entered Integer: ");
    showbits(alpha);

    alpha = alpha>>beta;//do as user wanted and store result in alpha

    printf("\n        Right Shifted  : ");
    showbits(alpha);
}

//no parameter. simply take user input and shows AND operation. no return value
void three(){
    int alpha, beta; //declare varibales
    
    printf("Enter two base 10 Integers, separated by a space: ");
    scanf("%d",&alpha);
    scanf("%d",&beta);

    printf("\n\n        Entered Integer 1: ");
    showbits(alpha);
    printf("\n        Entered Integer 2: ");
    showbits(beta);
    
    alpha = alpha & beta;//do as user wanted and store result in alpha

    printf("\n        AND'ed           : ");
    showbits(alpha);
}

//no parameter. simply take user input and shows OR operation. no return value
void four(){
    int alpha, beta; //declare varibales
    
    printf("Enter two base 10 Integers, separated by a space: ");
    scanf("%d",&alpha);
    scanf("%d",&beta);

    printf("\n\n        Entered Integer 1: ");
    showbits(alpha);

    printf("\n        Entered Integer 2: ");
    showbits(beta);
    
    alpha = alpha | beta;//do as user wanted and store result in alpha

    printf("\n        OR'ed            : ");
    showbits(alpha);
}

//no parameter. simply take user input and shows tilde operation. no return value
void five(){
    int alpha; //declare varibales
    
    printf("Enter a base 10 Integer: ");
    scanf("%d",&alpha);

    printf("\n\n        Entered Integer: ");
    showbits(alpha);

    alpha = ~alpha;;//do as user wanted and store result in alpha

    printf("\n        ~'ed           : ");
    showbits(alpha);
}

//no parameter. simply take user input and shows XOR operation. no return value
void six(){
    int alpha, beta; //declare varibales
    
    printf("Enter two base 10 Integers, separated by a space: ");
    scanf("%d",&alpha);
    scanf("%d",&beta);

    printf("\n\n        Entered Integer 1: ");
    showbits(alpha);

    printf("\n        Entered Integer 2: ");
    showbits(beta);
    
    alpha = alpha ^ beta;//do as user wanted and store result in alpha

    printf("\n        XOR'ed           : ");
    showbits(alpha);
}
















