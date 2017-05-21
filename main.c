#include "monty.h"
/**
 * main - entry point for Monty project
 * @argc: number of arguments
 * @argv: array of pointers to those arguments
 * Return: Always 0 on success
 */
int main(int ac, char **av)
{
	size_t line_number, line_len;
	int retval;
	FILE *fp;
	char *line;
	char **tokens;

	line_number = 0;
	line = NULL;
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], O_RDONLY);
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (line_len = getline(&line, &line_len, fp) != -1)
	{
		tokens = strtow(line, ' '); /* tokenize line */
		if (tokens == NULL)
		{
			printf("Error: malloc failed\n");
			retval = -1;
			break;
		}
		line_number++;
		if (strncmp(token[0], "push", 4) == 0)
			//call push f-on
			retval = push;
		else
		//call selector of f-ons (tokens[0], line_number)
			retval = select;
		if (retval == -1)
			break;
	}
	free(line);
	fclose(fp);
	free(stack);
	free_array(tokens);
	if (retval == -1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}