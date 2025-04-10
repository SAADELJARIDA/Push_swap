/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:34:19 by sel-jari          #+#    #+#             */
/*   Updated: 2025/04/10 00:34:21 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_args(char *str, char *av)
{
	char	*temp;

	temp = ft_strjoin(str, " ");
	free(str);
	if (temp == NULL)
		return (NULL);
	str = ft_strjoin(temp, av);
	free(temp);
	return (str);
}

static void	check_valid_arg(int ac, char **av)
{
	int	i;
	int	j;
	int	value;

	i = 1;
	while (i < ac)
	{
		j = 0;
		value = 0;
		while (av[i][j])
		{
			if (ft_isalnum(av[i][j]))
				value = 1;
			j++;
		}
		if (!value)
			ft_exit(1);
		i++;
	}
}

char	**normalize_input_args(int ac, char **av)
{
	int		i;
	char	**arr;
	char	*str;

	check_valid_arg(ac, av);
	str = ft_strdup(av[1]);
	if (str == NULL)
		return (NULL);
	i = 2;
	while (i < ac)
	{
		str = join_args(str, av[i]);
		if (str == NULL)
			return (NULL);
		i++;
	}
	arr = ft_split(str, ' ');
	free(str);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
