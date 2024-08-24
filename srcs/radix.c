/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:11:24 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/08 09:44:29 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix(t_list **a, t_list **b, int *i)
{
	int			j;
	int			size;

	j = 0;
	size = ft_lstsize(*a);
	while (j < size)
	{
		if ((((*a)->index >> *i) & 1) == 1)
			rotate_a(a);
		else
			push_b(b, a);
		j++;
	}
	while (ft_lstsize((*b)) != 0)
		push_a(a, b);
	*i = *i + 1;
	if (!is_sorted(a))
		radix(a, b, i);
}
