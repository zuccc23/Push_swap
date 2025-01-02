/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/02 19:21:28 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// doubles, not an int, 

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
// int	isdouble(char **strs)
// {
// 	int	i;
// 	int	j;
// 	int	k;

// 	k = 0;
// 	i = 0;
// 	j = 0;
// 	while (strs[i + 1])
// 	{
// 		ft_strchr(strs + (i + 1), strs[i]);
// 		i++;
// 	}
// 	return (0);
// }

char	*ft_strstr(const char *big, const char *little)
{
	size_t			i;
	size_t			j;

	j = 0;
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		while (big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return ((char *) &big[i]);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	printf("%d", valid_param(argv));
}