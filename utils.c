/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:57:55 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/02 19:21:17 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	valid_char(const char *s)
{
	int	i;

	i = 0;
	while (s[i]) 
	{
		if (ft_isdigit(s[i]) == 0 && s[i] != ' ' && s[i] != '+' && s[i] != '-')
		{
			return (1);
		}
		i++;
	}
	return (0);
}


int	repeat_char(char *str)
{
	int i;

	i = 0;
	while (str[i + 1])
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
			return (1);
		if (str[i] == '+' && ft_isdigit(str[i + 1]) == 0)
			return (1);
		if (str[i] == '-' && ft_isdigit(str[i + 1]) == 0)
			return (1);
		i++;
	}
	return (0);
}