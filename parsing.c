/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:27:31 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/12 14:28:09 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	i;

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
	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && str[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	valid_param(char **strs)
{
	int	i;

	i = 1;
	while(strs[i])
	{
		if (valid_char(strs[i]) == 1)
			return (1);
		if (repeat_char(strs[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}