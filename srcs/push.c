/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:51:21 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/05 10:46:30 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*node_b;

	if (!*b)
		return ;
	node_b = *b;
	(*b) = node_b->next;
	node_b->next = NULL;
	node_b->next = (*a);
	(*a) = node_b;
	ft_printf("pa\n");
}

void	push_b(t_list **b, t_list **a)
{
	t_list	*node_a;

	if (!*a)
		return ;
	node_a = *a;
	(*a) = node_a->next;
	node_a->next = NULL;
	node_a->next = (*b);
	(*b) = node_a;
	ft_printf("pb\n");
}
