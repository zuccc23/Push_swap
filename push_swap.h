/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:39:07 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/16 11:06:31 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

// STRUCTURE ///////////////////////////////////////////////////////

typedef struct t_list s_list;
struct t_list
{
	int	data;
	int	index;
	int	cost;
	int	above_median;
	int	cheapest;
	struct t_list *next;
	struct t_list *prev;
	struct t_list *target;
};

// PARSING ////////////////////////////////////////////////////////

int		valid_param(char **strs);
int		ft_isdigit(int c);
int		valid_char(const char *s);
int		repeat_char(char *str);

// LINKED LISTS ///////////////////////////////////////////////////

void	print_list(s_list *list);
int		stack_length(s_list *stack);
s_list	*ft_lstlast(s_list *lst);
s_list	*ft_lst_before_last(s_list *lst);
s_list	*assign_list(int *tab, int size);
s_list	*create_node(int data);

// CALCULATION ///////////////////////////////////////////////////

void	median_calc(s_list **stack);
void	median_assign(s_list **stack_a, s_list **stack_b);
void	index_assign(s_list **stack_a, s_list **stack_b);
void	find_cheapest(s_list **stack);
s_list	*max_node(s_list *stack);
s_list	*min_node(s_list *stack);

// CALCULATION A -> B ////////////////////////////////////////////

void	find_target_b(s_list **stack_a, s_list **stack_b);
void	assign_target_b(s_list **stack_a, s_list **stack_b);
void	individual_cost(s_list **stack);
void	cost_of_push(s_list **give, s_list **receive);
void	assign_all(s_list **stack_a, s_list **stack_b);

// CALCULATION B -> A ////////////////////////////////////////////

void	find_target_a(s_list **stack_a, s_list **stack_b);
void	assign_target_a(s_list **stack_a, s_list **stack_b);
void	assign_all2(s_list **stack_a, s_list **stack_b);
void	push_cheapest_to_a(s_list **stack_a, s_list **stack_b);
void	move_a2(s_list **stack_a, s_list *stack_b);
void	move_b2(s_list **stack_a, s_list **stack_b);

// SORTING ///////////////////////////////////////////////////////

void	push_swap(s_list **stack_a, s_list **stack_b);
void	sort_a_to_b(s_list **stack_a, s_list **stack_b);
void	sort_b_to_a(s_list **stack_a, s_list **stack_b);
void	sort_final(s_list **stack);

void	sort_3(s_list **stack);
void	sort_2(s_list **stack);
void	move_a(s_list **stack_a, s_list **stack_b);
void	move_b(s_list *stack_a, s_list **stack_b);
void	push_cheapest_to_b(s_list **stack_a, s_list **stack_b);

// OPERATIONS ////////////////////////////////////////////////////

void	rotate_down_both(s_list **stack_a, s_list **stack_b);
void	rotate_down(s_list **stack);
void	rotate_both(s_list **stack_a, s_list **stack_b);
void	rotate(s_list **stack);
void	swap_both(s_list **stack_a, s_list **stack_b);
void	swap(s_list **list);
void	push(s_list **give, s_list **receive);

#endif