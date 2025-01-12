/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/12 15:25:18 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char **argv)
{
	// if (argc < 2)
	// 	return (0);
	// printf("%d", valid_param(argv));
	// getBit(5, 10);
	// printbin(5);
	// bin(7);
	int	tab[] = {2, 13, 3, 7};
	int	tab2[] = {8, 29, 4, 12};
	s_list	*stack_a = NULL;
	s_list	*stack_b = NULL;
	s_list	*test = NULL;
	stack_a = assign_list(tab, 4);
	stack_b = assign_list(tab2, 4);
	
	
	// print_list(stack_a);
	// printf("\n");
	// print_list(stack_b);

}