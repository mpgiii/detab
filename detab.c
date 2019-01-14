/*  
 *  detab.c - a program which takes in a text file
 *  as an input (through stdio.h) and outputs a new
 *  file which has replaced tabs with spaces.
 *
 *  This program assumes the size of a tab in an
 *  editor to be up to 8 spaces and adds spaces
 *  accordingly. This can be changed by changing
 *  the definition of TAB size at the top of this
 *  file.
 *
 *  Michael Georgariou
 *  01/14/2019
 *  CPE 357-01
 */

#include <stdio.h>

#define TAB 8 

int main(int argc, char *argv[]) {
   int spot = 0;                           //saves how far into a line you are
   int c;                                  //stores the character
   while ((c = getchar()) != EOF) {        //get the next character. end if at end of file
      switch(c) {                          //look at the character
         case '\n':                        //if new line or carriage return,
         case '\r':
            spot = 0;                      //reset spot you are at
            putchar(c);                    //write the character to the new file
            break;                         //and leave switch case.
         case '\b':                        //if backspace,
            if (spot)                      //and if spot != 0,
               spot -= 1;                  //go back a spot.
            putchar(c);                    //write this character to the new file
            break;                         //and leave switch case.
         case '\t':                        //if tab:
            do {
               putchar(' ');               //write a space (always at least 1)
            } while ((++spot % TAB) != 0); //if we hit a multiple of TAB, stop adding spaces.
            break;                         //and leave switch case.
         default:                          //on any other character:
            spot += 1;                     //increment the spot
            putchar(c);                    //write the character to the new file
            break;                         //and leave switch case.
      }
   }
   return 0;                               //once we get here everything worked normally.
}
