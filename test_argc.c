#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("Argc %d\n", argc);
	int i;

	for(i=0; i < argc; i++)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
	}
	return 0;
}
