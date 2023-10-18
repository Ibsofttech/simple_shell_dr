#include "main.h"


/**
 * exec_cmd - exec found command
 * @argv_c: argument vector copy
 * @buf: buffer
 * @buf_c: buffer copy
 * @env: environment variable
 * @argv: argument vectors
 */

void exec_cmd(char **argv_c, char *buf, char *buf_c, char **env, char **argv)
{
		pid_t child_pid;
		char *route = get_path(argv_c);
		if (route == NULL)
        {
            perror(argv_c[0]);
            exit(EXIT_FAILURE);
        }
		child_pid = fork();

		if (child_pid < 0)
		{
			perror("error forking");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			if (execve(route, argv_c, env) == -1)
			{
				perror(argv[0]);
				exit(0);
			}
		}
		else
		{
			int status;

			wait(&status);
		}

}

/**
 * special_cmd - exec found command
 * @argv_c: argument vector copy
 * @buf: buffer
 * @buf_cpy: buffer copy
 * @env: environment variable
 */

void special_cmd(char **argv_c, char *buf, char *buf_cpy, char **env)
{
	int exit_code = 0;

	if (strncmp(argv_c[0], "exit", 5) == 0)
	{
		exit_code = atoi(argv_c[0] + 5);
        free(buf);
		free(buf_cpy);
		exit(exit_code);
	}
	else if (strcmp(argv_c[0], "exit") == 0)
	{
		free(buf);
		free(buf_cpy);
		exit(exit_code);
	}
	else if (strcmp(argv_c[0], "env") == 0)
	{
		print_env(env);
	}
}


/**
 * exit_with_ctrl_D - exec found command
 * @char_count: character counted
 * @buffer: buffer
 */

void exit_with_ctrl_D(ssize_t char_count, char *buffer)
{
		if (char_count == -1)
		{
			free(buffer);
			exit(0);
		}
}
