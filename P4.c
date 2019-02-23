/*Filename: P4.c *
*/
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

int demo_function ();		
void DisplayStats ();		

struct person{				
  char first[32];		
  char last[32];		
  int year;		
  double ppg;			
};

int main (void){
  struct person teacher;
  int i;
  teacher.year = 2005;
  teacher.ppg = 10.4;
  strcpy (teacher.first, "Adam");
  strcpy (teacher.last, "Hoover");
  demo_function ();
  return (0);
}

int demo_function (){
  struct person class[54];
  int i;

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
  strcpy (class[3].first, "Ada");
  strcpy (class[3].last, "Ada");
  
  class[3].year = 2007;
  class[3].ppg = 4.3;
  strcpy (class[3].first, "Bob");
  strcpy (class[3].last, "Bob");
  
  class[4].year = 2008;
  class[4].ppg = 4.0;
  strcpy (class[4].first, "Clara");
  strcpy (class[4].last, "Clara");
  
  class[5].year = 2008;
  class[5].ppg = 4.0;
  strcpy (class[5].first, "Dean");
  strcpy (class[5].last, "Dean");
  
  class[6].year = 2008;
  class[6].ppg = 4.0;
  strcpy (class[6].first, "Brian");
  strcpy (class[6].last, "Smith");
  
  for(i = 0; i < 7; i++)
    //printf("%d",i);
    DisplayStats(&(class[i]));
}

void DisplayStats(struct person *input){
printf ("%s, %s:  ",(*input).first,(*input).last);
printf ("year: %d points per game: %lf\n", (*input).year, (*input).ppg);
}
