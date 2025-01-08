/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:39:07 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/08 16:05:49 by dahmane          ###   ########.fr       */
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
	struct t_list *next;
	struct t_list *prev;
};

int		ft_isdigit(int c);
int		valid_char(const char *s);
int		repeat_char(char *str);
s_list	*ft_lstlast(s_list *lst);

#endif