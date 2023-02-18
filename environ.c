#include "shell.h"

/**
 * _myenv - prints the current environment
 * @struc: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *struc)
{
	print_list_str(struc->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @struc: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *struc, const char *name)
{
	list_t *node = struc->env;
	char *g;

	while (node)
	{
		g = starts_with(node->str, name);
		if (g && *g)
			return (g);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @struc: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *struc)
{
	if (struc->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(struc, struc->argv[1], struc->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @struc: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_t *struc)
{
	int i;

	if (struc->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= struc->argc; i++)
		_unsetenv(struc, struc->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @struc: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *struc)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	struc->env = node;
	return (0);
}
