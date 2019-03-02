/******************************************************************************
                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/
struct Node{
    int data; 
    struct Node* next; 
};

#include <stdio.h>
#include <stdlib.h>

//void one();void two();void three();void four();void five();void six();void seven();void showlist();

int main(){
    int i,j,k;
    int menu;
    int nodedata;
    
    struct Node *head;
    head = (struct Node *) malloc (sizeof (struct Node));
    head->data = NULL;
    head->next = NULL;
    
    char menulist[] = ("1. INSERT a node at the END of linklist");;// \n2. INSERT a node at the BEGINNING of linklist \n3. DELETE a node at the END of linklist \n4. DELETE a node from the BEGINNING of linklist \n5. INSERT a node in the MIDDLE of linklist \n6. DELETE a node from the MIDDLE of linklist \n7. MODIFY any node in linklist \n8: EXIT";
    
    while(1){
        //show menu, prompt user, take user input.
        printf("\n\n--------Menu-------- \n\n");
        printf("%s\n",menulist);
        printf("Make your choice: ");
        scanf("%d",&menu);
        
        //call related functions accordingly
        switch(menu){
            case 1:
            printf("Enter your node in the list: ");
            scanf("%d",&nodedata);
            one(head, nodedata);
            showlist(head);
            break;
            
            case 2:
            printf("Enter your node in the list: ");
            scanf("%d",&nodedata);
            two(head, nodedata);
            break;
            
            case 3:
            three(head);
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

void one(struct Node *input, int num){
    //empty case;
    if(input->data == NULL){
        input->data = num;
    }
    else{
        //find the last node and points to it
        while(input->next != NULL){
            input = input->next;
        }
        input->next = (struct Node *) malloc (sizeof (struct Node));
        input->next->data = num;
        input->next->next = NULL;
    }
}
void two(struct Node *input, int num){
    //empty case;
    if(input->data == NULL){
        input->data = num;
        showlist(input);
    }
    else{
        struct Node *temp;
        temp = (struct Node *) malloc (sizeof (struct Node));
        temp->next = input;
        temp->data = num;
        showlist(temp);
    }
}
void three(struct Node *input){
    
    struct Node *temp = input;
    if(input->next == NULL){
    input->data = NULL;
    input->next = NULL;
    }
    else{
    while(temp->next != NULL){
        input=temp;
        temp=temp->next;
    }
    input->next = NULL;
    }

}
void four();
void five();
void six();
void seven();
void showlist(struct Node *head){
    while(head->next != NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    if(head->data != NULL)
    printf("%d",head->data);
}
