/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:28:43 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/08 02:55:14 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_dup(t_list *s)
{
	t_list	*temp;

	temp = NULL;
	while (s)
	{
		temp = s;
		temp = temp->next;
		while (temp)
		{
			if (s->content == temp->content)
			{
				ft_printf("Error\n");
				exit(0);
			}
			temp = temp->next;
		}
		s = s->next;
	}
	return (1);
}

void	create_list_after_success(char *temp_argv, t_list	**s)
{
	size_t	k;

	k = -1;
	if (temp_argv[0] == '-' && ft_isdigit(temp_argv[1]))
		k++;
	while (++k < ft_strlen(temp_argv))
	{
		if (!ft_isdigit((temp_argv[k])))
		{
			ft_printf("Error\n");
			ft_lstclear(s, del);
			free(temp_argv);
			exit(0);
		}
	}
	ft_lstadd_back(s, ft_lstnew(ft_atoi(temp_argv)));
	free(temp_argv);
	temp_argv = NULL;
}

t_list	*parse(char *argv[])
{
	char		**temp_argv;
	int			i;
	t_list		*s;
	int			j;

	s = NULL;
	i = 0;
	temp_argv = NULL;
	while (argv[++i])
	{
		j = -1;
		temp_argv = ft_split(argv[i], ' ');
		while (temp_argv[++j])
			create_list_after_success(temp_argv[j], &s);
		free(temp_argv);
		temp_argv = NULL;
	}
	check_dup(s);
	return (s);
}
