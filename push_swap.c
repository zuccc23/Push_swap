/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/19 01:12:19 by dahmane          ###   ########.fr       */
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
	sort_b_to_a(&(*stack_a), &(*stack_b));
	sort_final(&(*stack_a));
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
	assign_all(&(*stack_a), &(*stack_b));
	while (stack_length(*stack_a) > 3)
	{
		push_cheapest_to_b(&(*stack_a), &(*stack_b));
	}
	sort_3(&(*stack_a));
}

void	sort_b_to_a(s_list **stack_a, s_list **stack_b)
{
	assign_all2(&(*stack_a), &(*stack_b));
	while ((*stack_b)->data != (*stack_a)->data)
	{
		push_cheapest_to_a(&(*stack_a), &(*stack_b));
	}
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
			}
			return;
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

void	find_targetv2(s_list *stack_a, s_list **stack_b)
{
	s_list	*target;
	s_list	*a_temp;
	s_list	*b_temp;

	a_temp = stack_a;
	b_temp = *stack_b;
	target = NULL;
	while (a_temp != NULL)
	{
		if (a_temp->data > b_temp->data)
		{
			if (target == NULL || target->data > a_temp->data)
				target = a_temp;
		}
		a_temp = a_temp->next;
	}
	if (target == NULL)
		b_temp->target = min_node(stack_a);
	else
		b_temp->target = target;
}

int main(int argc, char **argv)
{
	// PARSING //////////////////////////////////////////////////////////////
	// if (argc < 2)
	// 	return (0);
	// printf("%d", valid_param(argv));
	
	// INIT //////////////////////////////////////////////////////////////////
	int	tab[] = {72, 18, 59, 43, 91, -36, 5, 68, 14, 82, 33, 50, 27};
	int	tab2[] = {49, 54, 5, 112, 91, 882};
	s_list	*stack_a = NULL;
	s_list	*stack_b = NULL;
	s_list	*temp = NULL;
	stack_a = assign_list(tab, 5);
	// stack_b = assign_list(tab2, 6);
	
	// SORT_A_TO_B /////////////////////////////////////////////////////////////////////

	
	// assign_all(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);

	
	// move_b(stack_a, &stack_b);
	// move_a(&stack_a, stack_b);
	// push(&stack_a, &stack_b);
	
	// SORT_B_TO_A /////////////////////////////////////////////////////////////////////
	
	push_swap(&stack_a, &stack_b);
	// sort_final(&stack_a);
	// assign_all2(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// sort_b_to_a(&stack_a, &stack_b);
	// move_b3(&stack_b, stack_a);
	// move_a3(stack_b, &stack_a);
	// push(&stack_b, &stack_a);
	
	// assign_target_a(&stack_a, &stack_b);
	// index_assign(&stack_a, &stack_b);
	// median_assign(&stack_a, &stack_b);
	// cost_of_push(&stack_b, &stack_a);
	// individual_cost(&stack_a);
	// individual_cost(&stack_b);
	// rotate_down(&stack_a);
	// push(&stack_b, &stack_a);
	
	// TEST OF ALL VARIABLES ////////////////////////////////////////////////////
	
	// assign_all(&stack_a, &stack_b);
	// assign_all2(&stack_a, &stack_b);
	// while (stack_a != NULL)
	// {
	// 	printf("|| index : %d || value : %d || target(value) : %d || cost : %d || cheapest : %d || median : %d ||\n", stack_a->index, stack_a->data, stack_a->target->data, stack_a->cost, stack_a->cheapest, stack_a->above_median);
	// 	stack_a = stack_a->next;
	// }
	// while (stack_b != NULL)
	// {
	// 	printf("|| index : %d || value : %d || target(value) : %d || cost : %d || cheapest : %d || median : %d ||\n", stack_b->index, stack_b->data, stack_b->target->data, stack_b->cost, stack_b->cheapest, stack_b->above_median);
	// 	stack_b = stack_b->next;
	// }
	
	// TEST OF 1 VARIABLE /////////////////////////////////////////////////////////
	
	// assign_target_a(&stack_a, &stack_b);
	// while (stack_b != NULL)
	// {
	// 	// find_targetv2(stack_a, &stack_b);
	// 	printf("%d target : %d\n", stack_b->data, stack_b->target->data);
	// 	stack_b = stack_b->next;
	// }
	// printf("\n");

	//////////////////////////////////////////////////////////////////////
	
	// temp = stack_b;
	// while (temp != NULL)
	// {
	// 	find_targetv2(&stack_a, &temp);
	// 	temp = temp->next;
	// }
	
	// find_targetv2(&stack_a, &temp);
	// temp = temp->next;
	// find_targetv2(&stack_a, &temp);
	// temp = temp->next;
	// find_targetv2(&stack_a, &temp);
	// temp = temp->next;
	// find_targetv2(&stack_a, &temp);
	// temp = temp->next;
	// find_targetv2(&stack_a, &temp);
	// temp = temp->next;
	// find_targetv2(&stack_a, &temp);
	// temp = temp->next;
	// find_targetv2(&stack_a, &temp);
	// temp = temp->next;
	// find_targetv2(&stack_a, &temp);
	// temp = temp->next;

	///////////////////////////////////////////////////////////////////////

	// while (stack_b != NULL)
	// {
	// 	printf("%d target : %d\n", stack_b->data, stack_b->target->data);
	// 	stack_b = stack_b->next;
	// }
	// printf("\n");
	
	// while (stack_b->data != 92)
	// {
	// 	stack_b = stack_b->next;
	// }
	// // find_targetv2(&stack_a, &stack_b);
	// printf("%d\n", stack_b->data);
	// printf("%d target : %d\n", stack_b->data, stack_b->target->data);
	
	// PRINT LISTS ///////////////////////////////////////////////////////////////////
	
	// printf("\nStack A :\n");
	// print_list(stack_a);
	// printf("\nStack B :\n");
	// print_list(stack_b);
}