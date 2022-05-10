#include "monty.h"

global_t access = {NULL, 0, 0, 0};

int main(int argc, char *argv[])
{
	FILE *montyFile;
	char *montyLine = NULL;
	size_t len = 0;
        int read;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit (EXIT_FAILURE);
	}

	montyFile = fopen(argv[1], "r");

	if (montyFile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}

	read = getline(&montyLine, &len, montyFile);

	if (read == -1)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		free(montyLine);
		fclose(montyFile);
		exit (EXIT_FAILURE);
	}

	while (read != -1)
	{
		access.lineNum++;
		printf("%s", montyLine);
		printf("line number is %d\n", access.lineNum);
		/* call function to tokenise and the perform */
		read = getline(&montyLine, &len, montyFile);
	}

	fclose(montyFile);
	free(montyLine);
	return (0);
}
