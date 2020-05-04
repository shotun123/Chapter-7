#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(int argc, const char* argv[])
{
	int c;

	if (strcmp(argv[1], "lower") == 0)
		while ((c = getchar()) != EOF)
			putchar(tolower(c));
	else if (strcmp(argv[1], "upper") == 0)
		while ((c = getchar()) != EOF)
			putchar(toupper(c));
	else
		printf(stderr, "unrecognized parameters");

}