/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
struct Node{
    int data; 
    struct Node *next; 
};
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
    int nodedata;
    
    int data;
    struct Node *head;
    
    char menu[] = "1. INSERT a node at the END of linklist \n2. INSERT a node at the BEGINNING of linklist \n3. DELETE a node at the END of linklist \n4. DELETE a node from the BEGINNING of linklist \n5. INSERT a node in the MIDDLE of linklist \n6. DELETE a node from the MIDDLE of linklist \n7. MODIFY any node in linklist \n8: EXIT";
    
    while(1){
        //show menu, prompt user, take user input.
        printf("\n\n--------Menu-------- \n\n");
        printf("%s\n",menu);
        printf("Make your choice: ");
        scanf("%d",&input);
        
        //call related functions accordingly
        switch(input){
            case 1:
            printf("Enter your node in the list: ");
            scanf("%d",&nodedata);
            one(head, nodedata);
            showlist(head);
            break;
            
            
            case 8:
            return(0);
            default:
            printf("try another input");
            
            
        }
        
        
        
        
        
    }

    return 0;
}

void one(struct Node *head, int input){
    //empty list case 
    if(head == NULL){
        head = (struct Node *) malloc (sizeof (struct Node));
        head->next->data = input;
        head->next->next = NULL;
    }
    else{
        //find the last node and points to it
        while(head->next != NULL){
        head = head->next;
        }
        head->next = (struct Node *) malloc (sizeof (struct Node));
        head->next->data = input;
        head->next->next = NULL;
    }

}
void two();
void three();
void four();
void five();
void six();
void seven();
void showlist(struct Node *head){
    while(head->next != NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("%d",head->data);
}
