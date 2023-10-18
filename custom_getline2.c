#include "main.h"

/**
 * my_getline - exit from shell
 * @buffer: the buffer
 * @buffer_size: size of the buffer
 * @input: input string
 * Return: char_count
 */


ssize_t my_getline(char **buffer, size_t *buffer_size, FILE *input)
{
	if (buffer == NULL || buffer_size == NULL || input == NULL)
		return (-1);

	if (*buffer == NULL)
	{
		*buffer_size = 128;
		*buffer = (char *)malloc(*buffer_size);
		if (*buffer == NULL)
			return (-1);
	}

	size_t char_count = 0;
	int character;

	while (true)
	{
		character = getc(input);

		if (character == EOF)
			break;

		if (char_count + 1 >= *buffer_size)
		{
			*buffer_size *= 2;
			char *new_line = (char *)malloc(*buffer_size);

			if (new_line == NULL)
				return (-1);


			for (size_t i = 0; i < char_count; i++)
				new_line[i] = (*buffer)[i];

			free(*buffer);
			*buffer = new_line;
		}

		(*buffer)[char_count++] = (char)character;

		if (character == '\n')
		{
			(*buffer)[char_count] = '\0';
			return (char_count);
		}
	}

	if (char_count == 0)
		return (-1);

	(*buffer)[char_count] = '\0';
	return (char_count);
}

