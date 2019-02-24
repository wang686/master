/*Filename: P4.c *
*/
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

//a struct of a person defined with four properties
//first name, last name, year and ppg.
struct person{				
  char first[32];		
  char last[32];		
  int year;		
  double ppg;			
};//an important seme-colon


//struct of a node which has a integer and a pointer that should points to another node.
struct NODE {
int number;
struct NODE *next; 
};//semi-colon

//function prototypes 

//SecondStruct
int demo_function ();
void DisplayStats ();
//LinkedLists
int linkedList();
void append_node(struct NODE *llist, int num);
void delete_node(struct NODE *llist, int num);
int search_value(struct NODE *llist, int num);
void display_list(struct NODE *llist);




//driver to demo the two functions no parameter.
int main (void){
  printf("---------------SecondStruct-----------\n");
  demo_function ();
  printf("---------------LinkedList-----------\n");
  linkedList();
  printf("---------------Program ended-----------\n");
  return (0);
}

//---------------SecondStruct-----------
int demo_function (){
  int i;//counter for a loop
  struct person class[54];//declare an array capble of 54 people.
  
  //init 7 people in the 7 blocks below
  class[0].year = 2004;
  class[0].ppg = 5.2;
  strcpy (class[0].first, "Jane");
  strcpy (class[0].last, "Doe");
  
  class[1].year = 2005;
  class[1].ppg = 4.9;
  strcpy (class[1].first, "Brian");
  strcpy (class[1].last, "Smith");
  
  class[2].year = 2006;
  class[2].ppg = 4.6;
  strcpy (class[2].first, "Ada");
  strcpy (class[2].last, "Ada");
  
  class[3].year = 2007;
  class[3].ppg = 4.3;
  strcpy (class[3].first, "Bob");
  strcpy (class[3].last, "Bob");
  
  class[4].year = 2008;
  class[4].ppg = 4.0;
  strcpy (class[4].first, "Clara");
  strcpy (class[4].last, "Clara");
  
  class[5].year = 2008;
  class[5].ppg = 3.9;
  strcpy (class[5].first, "Dean");
  strcpy (class[5].last, "Dean");
  
  class[6].year = 2008;
  class[6].ppg = 3.6;
  strcpy (class[6].first, "Frank");
  strcpy (class[6].last, "Frank");
  
  //use a for-loop to call a helper function 
  //this would show the details of each of the 7 people.
  for(i = 0; i < 7; i++){
    DisplayStats(&(class[i]));
  }
}

//a function that takes a pointer which should be struct person
//prints the detailed info of the input
//return no value.
void DisplayStats(struct person *input){
printf ("%s, %s:  year: %d points per game: %lf\n", (*input).first,(*input).last, (*input).year, (*input).ppg);
}
//---------------SecondStruct ended -----------



int linkedList (){
  int num = 0;
  int input = 1;
  int retval = 0;
  struct NODE *llist;

// init the list with malloc 
// we need to use "->" to dereference a pointer here
  llist = (struct NODE *) malloc (sizeof (struct NODE));
  llist->number = 0;
  llist->next = NULL;

//print out the menu
  while (input != 0)
    {
      printf ("\n-- Menu Selection --\n");
      printf ("0) Quit\n");
      printf ("1) Insert\n");
      printf ("2) Delete\n");
      printf ("3) Search\n");
      printf ("4) Display\n");

      //take input
      scanf ("%d", &input);

      //switch-case loop to navigate in the program
      switch (input)
	{
	case 0:		//exit
	  printf ("Goodbye ...\n");
	  input = 0;
	  break;


	case 1:		//insert a node at the end of a list with the value
	  printf ("Your choice: 'Insertion'\n");
	  printf ("Enter the value which should be inserted: ");
	  scanf ("%d", &num);
	  append_node (llist, num);
	  break;



	case 2:		//remove a node
	  printf ("Your choice: 'Deletion'\n");
	  printf ("Enter the value which should be deleted: ");
	  scanf ("%d", &num);
	  if ((retval = search_value (llist, num)) == -1)
	    printf ("Value '%d' not found\n", num);
	  else
	    delete_node (llist, num);
	  break;


	case 3:		//find the position of a node, show position index if found
	  printf ("Your choice: 'Search'\n");
	  printf ("Enter the value you want to find: ");
	  scanf ("%d", &num);
	  if ((retval = search_value (llist, num)) == -1)
	    printf ("Value '%d' not found\n", num);
	  else
	    printf ("Value '%d' located at position '%d'\n", num, retval);
	  break;


	case 4:		//display the list 
	  printf ("You choice: 'Display'\n");
	  display_list (llist);
	  break;


	default:
	  printf ("That is not a valid menu option\n");
	  break;



	}			//switch-case
    }				//while
  free (llist);			// have to free up the memory and return them to OS

  return (0);
}//

// find the last node and change its pointer to the new node
//takes a list and an integer. no return value
void append_node (struct NODE *llist, int num)
{
  while (llist->next != NULL)
    llist = llist->next;
  llist->next = (struct NODE *) malloc (sizeof (struct NODE));
  llist->next->number = num;
  llist->next->next = NULL;
}


// to delete a node, find its position and replace it with the node it is pointing to
// the while-loop in the else branch iterates the list and do deletion
// when a node is delete we need to free the memory.
//takes a list and an integer. no return value
void delete_node (struct NODE *llist, int num)
{
  struct NODE *temp;
  temp = (struct NODE *) malloc (sizeof (struct NODE));
  if (llist->number == num)
    {

      temp = llist->next;
      free (llist);		//free memory
      llist = temp;
    }
  else
    {
      while (llist->next->number != num)
	llist = llist->next;
      temp = llist->next->next;
      free (llist->next);	// free memory
      llist->next = temp;
    }
}


//search a node using a loop
//takes a list and an integer. return index if found, -1 otherwise
int search_value (struct NODE *llist, int num)
{
  int retval = -1;
  int i = 1;
  while (llist->next != NULL)
    {
      if (llist->next->number == num)
	return i;
      else
	i++;
      llist = llist->next;
    }
  return retval;
}

//display the list by iterating the list using a loop
void display_list (struct NODE *llist)
{
  while (llist->next != NULL)
    {
      printf ("%d ", llist->number);
      llist = llist->next;
    }
  printf ("%d", llist->number);
}
