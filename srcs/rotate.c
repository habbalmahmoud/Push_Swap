/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:07:21 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/04 16:19:08 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_list **a)
{
	t_list	*temp;
	t_list	*node;

	if (!*a || !(*a)->next)
		return ;
	temp = (*a);
	(*a) = (*a)->next;
	node = *a;
	while (node->next)
		node = node->next;
	node->next = temp;
	temp->next = NULL;
	ft_printf("ra\n");
}

void	rotate_b(t_list **b)
{
	t_list	*temp;
	t_list	*node;

	if (!*b || !(*b)->next)
		return ;
	temp = (*b);
	(*b) = (*b)->next;
	node = *b;
	while (node->next)
		node = node->next;
	node->next = temp;
	temp->next = NULL;
	ft_printf("rb\n");
}

void	r_rotate(t_list **a, t_list **b)
{
	rotate_a(a);
	rotate_b(b);
}
