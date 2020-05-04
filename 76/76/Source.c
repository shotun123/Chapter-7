#include<stdio.h>
#include<string.h>

#define MAXLINE 1000

void diff_line(char* line1, char* line2, int linenum);

int main(int argc, const char* argv[])
{
	FILE* fp1, * fp2;
	char fp1_line[MAXLINE], fp2_line[MAXLINE];
	int i = 0;

	if (argc != 3)
	{
		fprintf(stderr, "Needs more files\n"); exit(0);
	}
	fp1 = fopen(argv[1], "r");
	if (!fp1)
		printf("Error, can't open %s\n", argv[1]); exit(0);

	fp2 = fopen(argv[2], "r");
	if (!fp2)
		printf("Error, can't open %s\n", argv[2]); exit(0);

	while (fgets(fp1_line, MAXLINE, fp1) != NULL && fgets(fp2_line, MAXLINE, fp2) != NULL)
	{
		diff_line(fp1_line, fp2_line, i);
		i++;
	}
	return 0;
}

void diff_line(char* line1, char* line2, int linenum)
{
	if (strcmp(line1, line2) != 0)
		printf("%d: %s\n%d: %s\n", linenum, line1, linenum, line2);
}