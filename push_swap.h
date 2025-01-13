/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:39:07 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/13 12:35:55 by dahmane          ###   ########.fr       */
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

// SORTING ///////////////////////////////////////////////////////

void	push_swap(s_list **stack_a, s_list **stack_b);
void	sort_3(s_list **stack);
void	sort_2(s_list **stack);
void	sort_a_to_b(s_list **stack_a, s_list **stack_b);
s_list	*max_node(s_list *stack);
s_list	*min_node(s_list *stack);

// OPERATIONS ////////////////////////////////////////////////////

void	rotate_down_both(s_list **stack_a, s_list **stack_b);
void	rotate_down(s_list **stack);
void	rotate_both(s_list **stack_a, s_list **stack_b);
void	rotate(s_list **stack);
void	swap_both(s_list **stack_a, s_list **stack_b);
void	swap(s_list **list);
void	push(s_list **give, s_list **receive);

#endif