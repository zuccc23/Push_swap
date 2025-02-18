/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:44:18 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/29 12:22:09 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				count++;
			i++;
		}
	}
	return (count);
}

long	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	n;

	i = 0;
	sign = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0' && str[i] != '\0')
	{
		n = (n * 10) + str[i] - '0';
		i++;
	}
	if (sign == 1)
		n = n * (-1);
	return (n);
}

long	get_number(char *s)
{
	long	number;

	number = ft_atoi(s);
	return (number);
}

long	*add_numbers(long *tab, char *s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[j] != '\0')
	{
		tab[i] = get_number(&s[j]);
		i++;
		while (s[j] != '\0' && s[j] != ' ')
		{
			j++;
		}
		if (s[j] == ' ')
			j++;
	}
	return (tab);
}

int	ft_split(char *s, char c, long **tab, int *size)
{
	if (!s)
		return (0);
	*size = count_word(s, c);
	if (*size < 2)
	{
		return (0);
	}
	*tab = malloc((*size) * sizeof(long));
	if (!*tab)
		return (0);
	*tab = add_numbers(*tab, s);
	return (*size);
}
