/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:39:07 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/12 13:24:56 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

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

int		ft_isdigit(int c);
int		valid_char(const char *s);
int		repeat_char(char *str);

s_list	*ft_lstlast(s_list *lst);
s_list	*ft_lst_before_last(s_list *lst);

void	rotate_down_both(s_list **stack_a, s_list **stack_b);
void	rotate_down(s_list **stack);
void	rotate_both(s_list **stack_a, s_list **stack_b);
void	rotate(s_list **stack);
void	swap_both(s_list **stack_a, s_list **stack_b);
void	swap(s_list **list);
void	push(s_list **give, s_list **receive);

#endif