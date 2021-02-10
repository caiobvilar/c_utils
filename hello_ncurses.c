#include <ncurses.h>
// compile and link: gcc source.c -lncurses -o binary_name

int main(int argc, char *argv[])
{
	initscr();								/* Start curses mode 			*/
	printw("Hello world.");		/* Print hello world 			*/
	refresh();								/* Print it on the screen */
	getch();									/* Wait for user input 		*/
	endwin();									/* End curses mode 				*/
	return 0;
}
