/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/15 19:26:49 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(s_list **stack_a, s_list **stack_b)
{
	if (stack_length(*stack_a) == 3)
		return (sort_3(&(*stack_a)));
	if (stack_length(*stack_a) == 2)
		return (sort_2(&(*stack_a)));
	sort_a_to_b(&(*stack_a), &(*stack_b));
	// sort_b_to_a(&(*stack_a), &(*stack_b));
	// sort_final(&(*stack_a));
}
void	sort_a_to_b(s_list **stack_a, s_list **stack_b)
{
	if (stack_length(*stack_a) == 4)
		push(&(*stack_a), &(*stack_b));
	if (stack_length(*stack_a) > 4)
	{
		push(&(*stack_a), &(*stack_b));
		push(&(*stack_a), &(*stack_b));
	}
	while (stack_length(*stack_a) > 3)
	{
		assign_all(&(*stack_a), &(*stack_b));
		push_cheapest_to_b(&(*stack_a), &(*stack_b));
	}
	return (sort_3(&(*stack_a)));
}

void	sort_b_to_a(s_list **stack_a, s_list **stack_b)
{
	while (*stack_b != NULL)
	{
		printf("test\n");
		assign_all2(&(*stack_a), &(*stack_b));
		printf("bob\n");
		push_cheapest_to_a(&(*stack_a), &(*stack_b));
		
	}
	// printf("boby");
	// push(&(*stack_b), &(*stack_a));
}
void	sort_final(s_list **stack)
{
	s_list	*temp;

	index_assign(&(*stack), &(*stack));
	median_assign(&(*stack), &(*stack));
	temp = max_node(*stack);
	if (temp->index != stack_length(*stack))
	{
		if (temp->above_median == 1)
		{
			while (temp->index != stack_length(*stack))
			{
				rotate(&(*stack));
				index_assign(&(*stack), &(*stack));
				return;
			}
		}
		if (temp->above_median == 0)
		{
			while (temp->index != stack_length(*stack))
			{
				rotate_down(&(*stack));
				index_assign(&(*stack), &(*stack));
			}
		}
	}
}

int main(int argc, char **argv)
{
	// PARSING //////////////////////////////////////////////////////////////
	// if (argc < 2)
	// 	return (0);
	// printf("%d", valid_param(argv));
	
	// INIT //////////////////////////////////////////////////////////////////
	int	tab[] = {39, 201, 11, 28, 1, 97, 44};
	int	tab2[] = {49, 54, 5, 112, 91, 882};
	s_list	*stack_a = NULL;
	s_list	*stack_b = NULL;
	stack_a = assign_list(tab, 7);
	// stack_b = assign_list(tab2, 6);
	

	
	push_swap(&stack_a, &stack_b);
	// sort_b_to_a(&stack_a, &stack_b);
	// assign_target_a(&stack_a, &stack_b);
	push_cheapest_to_a(&stack_a, &stack_b);
	

	// TEST OF ALL VARIABLES ////////////////////////////////////////////////////
	// assign_all(&stack_a, &stack_b);
	// while (stack_a != NULL)
	// {
	// 	printf("|| index : %d || value : %d || target(value) : %d || cost : %d || cheapest : %d || median : %d ||\n", stack_a->index, stack_a->data, stack_a->target->data, stack_a->cost, stack_a->cheapest, stack_a->above_median);
	// 	stack_a = stack_a->next;
	// }
	
	// TEST OF 1 VARIABLE /////////////////////////////////////////////////////////
	// while (stack_a != NULL)
	// {
	// 	printf("index : %d\n", stack_a->index);
	// 	stack_a = stack_a->next;
	// }
	// printf("\n");
	
	// PRINT LISTS ///////////////////////////////////////////////////////////////////
	print_list(stack_a);
	printf("\n");
	print_list(stack_b);
}