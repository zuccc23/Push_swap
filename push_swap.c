/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/03 17:26:18 by dahmane          ###   ########.fr       */
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


int main(int argc, char **argv)
{
	// if (argc < 2)
	// 	return (0);
	// printf("%d", valid_param(argv));
	printf("%d\n", 7);
}