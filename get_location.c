#include "main.h"

/**
 * location - the location of the command
 * @path: path to the command
 * @arg: argument to the comand
 * Return: pointer to the path
 */


char *location(char *path, char *arg)
{
	char *route_dup, *route_token, *file_route, *delim = ":";

	route_dup = strdup(path);
	route_token = strtok(route_dup, delim);
	file_route = malloc(strlen(arg) + strlen(route_token) + 2);

	while (route_token)
	{
		strcpy(file_route, route_token);
		strcat(file_route, "/");
		strcat(file_route, arg);
		strcat(file_route, "\0");

		if (access(file_route, X_OK) == 0)
		{
			return (file_route);
		}
		route_token = strtok(NULL, delim);
	}
		free(file_route);
		return (NULL);
}

/**
 * get_location - the location of the command
 * @arg: argument to the comand
 * Return: pointer to NULL
 */

char *get_location(char *arg)
{
	char *route = getenv("PATH");

	if (route)
		return (location(route, arg));

	return (NULL);
}

/**
 * get_path - get the location of the command
 * @argv_copy: argument copy
 * Return: route
 */


char *get_path(char **argv_copy)
{
	char *route;

	route = get_location(argv_copy[0]);
	if (route == NULL && strncmp(argv_copy[0], "/", 1) == 0)
	route = argv_copy[0];

	return (route);
}
