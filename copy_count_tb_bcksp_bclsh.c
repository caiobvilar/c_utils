#include <stdio.h>

/* write a program to copy its input to its output, replacing
 * each tab by \t, each backspace by \b and each backslash by \\*/

int main(int argc, char *argv[])
{
	int c;
	while((c = getchar()) != EOF)
	{
		if(c == '\t')
		{
			putchar('\\');
			putchar('t');
		}
		if(c == '\b')
		{
			putchar('\\');
			putchar('b');
		}
		if(c == '\\')
		{
			putchar('\\');
			putchar('\\');
		}
		if((c !='\t')) /* else was not presented in the book up from this exercise*/
		{
			if((c != '\b'))
			{
				if((c != '\\'))
				{
					putchar(c);
				}
			}
		}
	}
	return 0;
}
