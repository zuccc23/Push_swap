/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:01:58 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/29 12:19:24 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_to_tab(char **argv, int argc, long **tab, int *size)
{
	int	i;
	int	k;

	if (ft_isspace(argv) == 1)
		return (0);
	i = 1;
	k = 0;
	*size = (argc - 1);
	*tab = malloc((*size) * sizeof(long));
	if (*tab == NULL)
		return (0);
	while (argv[i])
	{
		(*tab)[k] = ft_atoi(argv[i]);
		i++;
		k++;
	}
	return (*size);
}

int	double_numbers(long *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	max_and_min(long *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] > 2147483647 || tab[i] < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	check_numbers(long **tab, int size)
{
	if (double_numbers(*tab, size) == 1)
	{
		free(*tab);
		return (1);
	}
	if (max_and_min(*tab, size) == 1)
	{
		free(*tab);
		return (1);
	}
	return (0);
}

int	ft_isspace(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
