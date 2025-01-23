/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:23 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/23 13:43:08 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_to_tab(char **argv, int argc, long **tab)
{
	int	i;
	int	j;
	int	k;
	int	size;

	i = 1;
	k = 0;
	size = (argc - 1);
	*tab = malloc(size * sizeof(long));
	if (*tab == NULL)
		return (0);
	while (argv[i])
	{
		(*tab)[k] = ft_atoi(argv[i]);
		i++;
		k++;
	}
	return (size);
}
