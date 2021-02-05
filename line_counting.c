#include <stdio.h>
/* Count lines in input */
int main(int argc, char *argv[])
{
	int c; /* character input*/
	int nl; /* number of lines*/
	while((c = getchar()) != EOF)
	{
		if(c == '\n')
		{
			++nl;
		}
	}
	printf("%d\n",nl);
}
