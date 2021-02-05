#include <stdio.h>

/* Copy input to output */
int main()
{
	int c;
	c = getchar();
	while ((c = getchar()) != EOF)
	{
		putchar(c);
	}
}
