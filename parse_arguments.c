/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:19:26 by ncathy            #+#    #+#             */
/*   Updated: 2022/01/28 17:19:26 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_array_of_args(char **argv)
{
	int		i;
	char	*tmp_line;
	char	*line_of_args;
	char	**args;

	i = 1;
	line_of_args = ft_strdup(argv[1]);
	while (argv[++i])
	{
		tmp_line = ft_strjoin(line_of_args, " ");
		free(line_of_args);
		line_of_args = ft_strjoin(tmp_line, argv[i]);
		free(tmp_line);
	}
	args = ft_split(line_of_args, ' ');
	free(line_of_args);
	return (args);
}

int	check_isdigit(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == '-')
				j++;
			if (ft_isdigit(args[i][j]))
				j++;
			else
			{
				free_array(args);
				write(1, "Error\n", 6);
				exit(1);
			}
		}
		i++;
	}
	return (0);
}

int	check_for_dublicates(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
			{
				free_array(args);
				write(1, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_the_value(char **argv)
{
	int		i;
	char	**args;
	int		number;

	i = 0;
	args = get_array_of_args(argv);
	while (args[i])
	{
		number = ft_atoi(args[i]);
		if (number == 1 && (args[i][0] != '1' || args[i][1] != '\0'))
		{
			free_array(args);
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	check_isdigit(args);
	check_for_dublicates(args);
	free_array(args);
	return (0);
}
