#include "shell.h"

/**
 * validate_env_name - Validates a env var name
 * @name: String to be validated
 *
 * Return: 0, on success, -1 on error
 */

int validate_env_name(char *name)
{
	if (name == NULL)
	{
		print_builtin_error("setenv: Needs 2 args", "");
		return (-1);
	}

	if (!is_valid_env_var_name(name))
	{
		print_builtin_error("setenv: Invalid name ", name);
		return (-1);
	}
	return (0);
}

/**
 * is_valid_env_var_name - Checks if the env name is valid
 * @name: String to be checked
 *
 * Return: 1 if is valid, 0 otherwise
 */

int is_valid_env_var_name(char *name)
{
	int j;
	/* Verify that name is a valid env_var name (without "=") */
	for (j = 0; name[j] != '\0'; j++)
		if (name[j] == '=')
			return (0);

	return (1);
}

/**
 * get_env_index - Check if a env variable exists and returns the index
 * @name: Name to be searched
 *
 * Return: Index of the env var, -1 on error
 */

int get_env_index(char *name)
{
	int j;
	int len = _strlen(name);

	for (j = 0; __environ[j] != NULL; j++)
		if (_strncmp(__environ[j], name, len) == 0)
			return (j);

	return (-1);
}
