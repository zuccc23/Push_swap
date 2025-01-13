/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/13 13:18:42 by dahmane          ###   ########.fr       */
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
}

void	target_a_to_b(s_list **stack_a, s_list **stack_b)
{
	s_list	*temp_a;
	s_list	*temp_b;
	s_list	*target_temp;

	temp_a = *stack_a;
	temp_b = *stack_b;
	target_temp = NULL;
	while (temp_b != NULL)
	{
		if (temp_a->data > temp_b->data)
		{
			if (temp_b->data > target_temp || target_temp == NULL)
			{
				temp_a->target = temp_b;
				target_temp = temp_b;
			}
		}
		temp_b = temp_b->next;
	}
	temp_b = *stack_b;
	if (temp_a->target == NULL)
		temp_a->target = max_node(temp_b);
}

int main(int argc, char **argv)
{
	// if (argc < 2)
	// 	return (0);
	// printf("%d", valid_param(argv));
	// getBit(5, 10);
	// printbin(5);
	// bin(7);
	int	tab[] = {3, 2, 1, 7, 4, 19};
	int	tab2[] = {8, 29, 4, 12};
	s_list	*stack_a = NULL;
	s_list	*stack_b = NULL;
	s_list	*test = NULL;
	stack_a = assign_list(tab, 6);
	// stack_b = assign_list(tab2, 4);
	
	push_swap(&stack_a, &stack_b);
	
	stack_a = stack_a->next;
	target_a_to_b(&stack_a, &stack_b);
	test = stack_a->target;
	printf("%d\n", test->data);
	
	
	// print_list(stack_a);
	// printf("\n");
	// print_list(stack_b);
}