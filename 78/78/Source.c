#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LINELENGTH 80
#define LINEPERPAGE 10

void print(FILE*, FILE*);

int main(int argc, const char* argv[])
{
	FILE* fp;
	char* prog = argv[0];
	int linecount = 0;

	if (argc == 1)
	{
		printf(stderr, "No file detected"); exit(0);
	}

	while (--argc > 0)
	{
		fp = fopen(*++argv, "r");

		if (!fp)
			printf("Error, can't open %s\n", *argv); exit(0);
		
		printf("\n\n\t\t\tFile: %s\n\n", *argv);
		print(fp, stdout);
		fclose(fp);
	}
	return 0;
}

void print(FILE* ifp, FILE* ofp)
{
	int c;
	int line = 0;
	int pg = 1;

	while ((c = getc(ifp)) != EOF)
	{
		putc(c, ofp);
		if (c == '\n')
		{
			line += 1;
			if (line == LINEPERPAGE)
			{
				printf("\n\t\t\tPage %d End\n\n", pg);
				pg += 1;
				line = 0;
			}
		}
	}
}