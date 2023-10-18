#include "main.h"

/**
 * main - entry to my shell
 * @c: number of main argument
 * @aargv: argument vectors
 * @env: environmental variables
 * Return: Success(0)
 */

int main(int c, char **argv, char **env)
{
	start_shell(env, argv);
	return (0);
}
