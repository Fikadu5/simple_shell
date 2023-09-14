#include "shell.h"

/**
 * handle_var_replacement - Handles dollar vars '$'
 * @commands: Array of commands
 */

void handle_var_replacement(char **commands)
{
	int j;
	char *env_val;

	if (commands[0] == NULL)
		return;

	/* Scan command args and replace the needed ones using PATH, and $$, $? */
	for (j = 1; commands[j] != NULL; j++)
	{
		if (commands[j][0] != '$')
			continue;
		/* Here the arg starts with '$' */

		if (_strcmp(&commands[j][1], "?") == 0)
		{
			free(commands[j]);
			commands[j] = num_to_str(*process_exit_code());
			return;
		}

		if (_strcmp(&commands[j][1], "$") == 0)
		{
			free(commands[j]);
			commands[j] = num_to_str(getpid());
			return;
		}
		env_val = _getenv(&commands[j][1]);
		if (env_val != NULL)
		{
			free(commands[j]);
			commands[j] = duplicate_string(env_val);
		}
	}

}
