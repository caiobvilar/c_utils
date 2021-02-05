#include <stdio.h>

int main(int argc, char *argv[])
{
	int c=0;
	int blanks=0;
	int tabs=0;
	int newlines=0;
	while((c = getchar()) != EOF)
	{
		if(c == '\n')
		{
			printf("newline\n");
			++newlines;
		}
		if(c == '\t')
		{
			printf("tab\n");
			++tabs;
		}
		if(c == ' ')
		{
			printf("blank\n");
			++blanks;
		}
	}
	printf("Blanks: %d | Tabs: %d | Newlines: %d\n",blanks, tabs, newlines);
}
