/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void showlist();

int main(){
    int i,j,k;
    int input;
    
    char menu[] = "1. INSERT a node at the END of linklist \n2. INSERT a node at the BEGINNING of linklist \n3. DELETE a node at the END of linklist \n4. DELETE a node from the BEGINNING of linklist \n5. INSERT a node in the MIDDLE of linklist \n6. DELETE a node from the MIDDLE of linklist \n7. MODIFY any node in linklist \n8: EXIT";
    
    while(1){
        printf("\n\n--------Menu-------- \n\n");
        printf("%s\n",menu);
        printf("Make your choice: ");
        scanf("%d",&input);
        
        
        switch(input){
            case 1:
            printf("one");
            break;
            case 8:
            return;
            default:
            printf("try another input");
            
            
        }
        
        
        
        
        
    }

    return 0;
}

void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void showlist();
