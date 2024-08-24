/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:10:44 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/08 00:44:10 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"

void	del(int content)
{
	content -= content;
}

int	main(int argc, char *argv[])
{
	t_list		*a;
	t_list		*b;

	if (argc == 1)
		return (0);
	a = parse(argv);
	b = NULL;
	if (!a)
	{
		ft_printf("Error\n");
		ft_lstclear(&a, del);
		exit(0);
	}
	if (is_sorted(&a))
	{
		ft_lstclear(&a, del);
		exit(0);
	}
	handle_sort(&a, &b);
	ft_lstclear(&a, del);
	ft_lstclear(&b, del);
}
