/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:39:07 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/23 14:08:06 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "ft_printf/ft_printf.h"

// STRUCTURE ///////////////////////////////////////////////////////

typedef struct s_list	t_stack;
struct s_list
{
	long				data;
	int				index;
	int				cost;
	int				above_median;
	int				cheapest;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*target;
};

// PARSING ////////////////////////////////////////////////////////

int		valid_param(char **strs);
int		ft_isdigit(int c);
int		valid_char(const char *s);
int		repeat_char(char *str);

// SPLIT /////////////////////////////////////////////////////////

int		ft_split(char *s, char c, long **tab);
int		count_word(const char *s, char c);
long		get_number(char *s, char c);
long		*add_numbers(long *tab, char *s, char c);
long		ft_atoi(const char *str);

// NUMBERS TO TAB ////////////////////////////////////////////////

int	argv_to_tab(char **argv, int argc, long **tab);

// LINKED LISTS ///////////////////////////////////////////////////

void	print_list(t_stack *list);
int		stack_length(t_stack *stack);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lst_before_last(t_stack *lst);
t_stack	*assign_list(long *tab, int size);
t_stack	*create_node(long data);

// CALCULATION ///////////////////////////////////////////////////

void	median_calc(t_stack **stack);
void	median_assign(t_stack **stack_a, t_stack **stack_b);
void	index_assign(t_stack **stack_a, t_stack **stack_b);
void	individual_index(t_stack **stack);
void	find_cheapest(t_stack **stack);
t_stack	*max_node(t_stack *stack);
t_stack	*min_node(t_stack *stack);

// CALCULATION A -> B ////////////////////////////////////////////

void	find_target_b(t_stack **stack_a, t_stack **stack_b);
void	assign_target_b(t_stack **stack_a, t_stack **stack_b);
void	individual_cost(t_stack **stack);
void	cost_of_push(t_stack **give, t_stack **receive);
void	assign_all(t_stack **stack_a, t_stack **stack_b);

// CALCULATION B -> A ////////////////////////////////////////////

void	find_target_a(t_stack **stack_a, t_stack **stack_b);
void	find_targetv2(t_stack *stack_a, t_stack **stack_b);
void	assign_target_a(t_stack **stack_a, t_stack **stack_b);
void	assign_all2(t_stack **stack_a, t_stack **stack_b);
void	push_cheapest_to_a(t_stack **stack_a, t_stack **stack_b);
void	move_a2(t_stack **stack_a, t_stack *stack_b);
void	move_b2(t_stack *stack_a, t_stack **stack_b);
void	move_a3(t_stack *givee, t_stack **receive);
void	move_b3(t_stack **give, t_stack *receive);

// SORTING ///////////////////////////////////////////////////////

void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	sort_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	sort_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	sort_final(t_stack **stack);

void	sort_3(t_stack **stack);
void	sort_2(t_stack **stack);
void	move_a(t_stack **stack_a, t_stack *stack_b);
void	move_b(t_stack *stack_a, t_stack **stack_b);
void	push_cheapest_to_b(t_stack **stack_a, t_stack **stack_b);

// OPERATIONS ////////////////////////////////////////////////////

void	rotate_down_both(t_stack **stack_a, t_stack **stack_b);
void	rotate_down(t_stack **stack);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	swap_both(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **list);
void	push(t_stack **give, t_stack **receive);

#endif