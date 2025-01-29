/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/29 18:08:46 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_length(*stack_a) == 3)
		return (sort_3(&(*stack_a)));
	if (stack_length(*stack_a) == 2)
		return (sort_2(&(*stack_a)));
	sort_a_to_b(&(*stack_a), &(*stack_b));
	sort_b_to_a(&(*stack_a), &(*stack_b));
	sort_final(&(*stack_a));
}

void	init_variables(long **t, int *s, t_stack **s_a, t_stack **s_b)
{
	*s_a = NULL;
	*s_b = NULL;
	*s = 0;
	*t = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	long	*tab;
	int		size;

	init_variables(&tab, &size, &stack_a, &stack_b);
	if (argc < 2)
		return (0);
	if (valid_param(argv) == 1)
		return (ft_printf("Error\n"));
	if (argc == 2)
		if (ft_split(argv[1], ' ', &tab, &size) <= 1)
			return (ft_printf("Error\n"));
	if (argc > 2)
		if (argv_to_tab(argv, argc, &tab, &size) == 0)
			return (ft_printf("Error\n"));
	if (check_numbers(&tab, size) == 1)
		return (ft_printf("Error\n"));
	//check if list is already sorted
	stack_a = assign_list(tab, size);
	free(tab);
	if (stack_a == NULL)
		return (0);
	push_swap(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	// print_list(stack_b);
}
