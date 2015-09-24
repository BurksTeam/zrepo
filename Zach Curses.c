#include <curses.h>
#include <stdlib.h>
#include <string.h>
//Zach
//I think we'll need to fix the array setup I've got going, but this is supposed to read
//the file and put it into an array that can be edited.

int main()
{
 FILE * cfPtr;
 cfPtr = fopen("zfile.txt", "r");

 char lineInput[1000];
 int i = 0;

 char fullText[100][100];

 while(!feof(cfPtr))
 {

     fgets(lineInput, 100, cfPtr);
     int j =0;
        for (j=0;j<100;j++)
        {
            fullText[i][j]=lineInput[j];
        }


     i++;


 }

 fclose(cfPtr);

 initscr();  //initializes the screen
        int j =0;
        int linesInFile = 3;

        for (j=0;j<linesInFile;j++)
        {
            printw(fullText[j]);
        }

        refresh();  //show the buffer on the screen
        getch();    //wait for a character to be pushed
        endwin();   //end curses mode


 return 0;
}
