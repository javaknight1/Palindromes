/***************************************************************************
**
** Filename: Project1.c
** Rob Avery
** Date:2/6/2012
** Section Number: 02
** UMBC email: pw97976@umbc.edu
**
**     It allows the user to enter a number in and find out if that
** number is a palindrome. If not, it shows if how long it would take to add the
** reverse number to the original to get a palindrom. The user enters a
** filename of lyschrel candidates so if one of the number entered was in the
** file, the program will tell the user if it a candidate.
**
***************************************************************************/

#define TRUE 1
#define FALSE 0


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {

   int lychrel = FALSE;
   int i;
   int fileNum;
   int iter;
   int numInput = 0;
   int len = 0;
   int count = 0;
   long candidates[60];
   unsigned long long fwdNum;
   unsigned long long revNum;
   unsigned long long totalNum;
   char fwdStr[32];
   char revStr[32];
   char filename[101];
   FILE* inFile;


   printf("Enter the name of the file: ");
   scanf("%s", filename);
   
   //Opens the file, and if doesnt exist, it displays an error
   //and closes the program
   inFile = fopen(filename, "r");
   if( inFile == NULL) {
      printf("ERROR: File not read.\n");
      return (-1);
   }

   //Loops the file and adds everything to an array
   while( fscanf(inFile, "%d", &fileNum ) != EOF ) {
      candidates[count] = fileNum;
      count++;
   }
   fclose( inFile );

   //Promts the suer for an input
   printf("Enter a of number for N: ");
   scanf("%d", &numInput);


   //Loops until the user enters a "0"
   while(numInput) {
      i = 0;
      
      //Looks to see if the input is a lychrel candidate
      while( lychrel == FALSE && i != count ) {
         if( candidates[i] == numInput) {
            lychrel = TRUE;
         }
         i++;
      }

      //Creates a forward string and a reverse string of the input
      sprintf(fwdStr, "%d", numInput);
      len = strlen(fwdStr);

      for (i=0; i<len; i++) {
         revStr[i] = fwdStr[len-1-i];
      }
      revStr[len] = 0;
      
      //Determines its a palindrome
      if( strcmp(fwdStr, revStr) == 0) {
         printf("%d is a palindrome.\n\n", numInput);
      }
      //Determines its a lychrel candidate
      else if ( lychrel == TRUE ) {
         printf("%d is a lychrel candidate.\n\n", numInput);
      }
      //Determines its not a palindrome
      else {
         iter = 0;

         //Loops through taking the input and adding the reverse until it
         //becomes a palindrome
         while( strcmp(fwdStr, revStr) != 0 ) {

            fwdNum = strtoull( fwdStr, NULL, 10 );
            revNum = strtoull( revStr, NULL, 10 );
            totalNum = fwdNum + revNum;
            printf("%10llu + %10llu = %10llu\n", fwdNum, revNum, totalNum);

            sprintf(fwdStr, "%llu", totalNum);
            len = strlen(fwdStr);
            for (i=0; i<len; i++) {
               revStr[i] = fwdStr[len-1-i];
            }
            revStr[len] = 0;
            iter++;
        }
        printf("A palindrome was obtained through %d iterations.\n\n", iter);
      }
      lychrel = FALSE;
      
      //Prompts the user for input
      printf("Enter number for N: ");
      scanf("%d", &numInput);
   }

   return 0;
}
