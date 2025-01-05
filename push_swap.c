/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/05 17:18:16 by dahmane          ###   ########.fr       */
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

void getBit(int num, int i)
{
	if ((num & (1 << i)) != 0)
		printf("1");
	else 
		printf("0");
}
void printbin(int n)
{
	if (n > 1)
		printbin(n / 2);
	printf("%d", n % 2);
}
int main(int argc, char **argv)
{
	// if (argc < 2)
	// 	return (0);
	// printf("%d", valid_param(argv));
	// getBit(5, 10);
	// printbin(5);
	int	tab[] = {2, 3, 5, 4};
	
}