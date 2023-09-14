#include "shell.h"

/**
 * _getenv - Returns a pointer to a env var value
 * @name: Environment variable name
 *
 * Return: Pointer to environment variable value
 */

char *_getenv(char *name)
{
	int j;

	for (j = 0; __environ[j] != NULL; j++)
		if (_strncmp(__environ[i], name, _strlen(name)) == 0)
			return (&__environ[j][_strlen(name) + 1]);

	return (NULL);
}
