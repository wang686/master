/*Filename: P4.c *
*/
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

//function prototypes 
int demo_function ();
void DisplayStats ();	

//a struct of a person defined with four properties
//first name, last name, year and ppg.
struct person{				
  char first[32];		
  char last[32];		
  int year;		
  double ppg;			
};//an important seme-colon


//driver to demo the two functions no parameter.
int main (void){
  printf("---------------SecondStruct-----------\n");
  demo_function ();
  printf("---------------SecondStruct ended-----------\n");
  
  printf("---------------LinkedList-----------\n");
  printf("---------------LinkedList ended-----------\n");
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
