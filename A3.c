/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main(){
    
    int menuSelection = 0;
    char menu[] = "1. Perform Left Bit Shift Operation (one value)\n2. Perform Right Bit Shift Operation (one value)\n3. Perform Binary AND Operation (two values)\n4. Perform Binary OR Operation (two values)\n5. Perform Binary One's Complement (~) Operation (one value)\n6. Perform Binary XOR Operation (two values)\n7. Quit\n\n";
//    scanf("%d",&menuSelection);
//   printf("%d",menuSelection);
while(1){
    printf("%s",menu);
    scanf("%d",&menuSelection);
    
    
    switch(menuSelection){
        case 1: 
            printf("spmething 1");
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
            printf("spmething 5");
            break;
        case 6:
            printf("spmething 6");
            break;
        case 7:
            printf("spmething 7");
            break;
        default:
            printf("Invalid input");
            break;
        
        
        
        
    }
    
}


    return 0;
}
