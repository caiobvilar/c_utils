#include <stdio.h>

/* program that copy its input to its output, replacing each
 * string of one or more blanks with a single blank*/

int main(int argc, char *argv[])
{
	int c=0;
	int prev=0;
	while((c = getchar()) != EOF)
	{
		if(c == ' ')
		{
			if(prev != ' ')
			{
				putchar(c);
			}
		}
		if(c != ' ')
		{
			putchar(c);
		}
		prev = c;
	}
	return 0;
}

