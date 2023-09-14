#include "shell.h"

/**
 * _realloc - Reallocates a memory block
 * @ptr: Pointer to the memory to be reallocated
 * @old_size: Size in bytes of the actual allocated memory
 * @new_size: Size in bytes for the new allocated memory
 *
 * Return:Pointer to the newly allocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	int limit, j;
	void *pointer;

	if (old_size == new_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	pointer = malloc(new_size);

	if (old_size > new_size)
		limit = new_size;
	else
		limit = old_size;

	for (j = 0; j < limit; j++)
		((char *)pointer)[j] = ((char *)ptr)[j];

	free(ptr);

	return (pointer);
}
