/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 19:53:52 by mmeziyan          #+#    #+#             */
/*   Updated: 2017/09/24 19:53:55 by mmeziyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int g_i;

int		arg_nbr(void)
{
	return (g_i);
}

void	recursive(t_list *st)
{
	t_flst *s;

	s = (search_opt("r") ? st->end : st->begin);
	while (s)
	{
		if (s->type == 'd')
		{
			if (ft_strcmp(s->name, ".") != 0 && ft_strcmp(s->name, "..") != 0
				&& !s->links)
			{
				my_printf("\n%s:\n", 1, s->path);
				(s->right[2] == '-') ? my_printf("ls: %s: Permission denied\n"
				, 2, recup_name(s->path)) : main(-1, &s->path);
			}
		}
		s = (search_opt("r") ? s->prev : s->next);
	}
}

int		main(int ac, char **av)
{
	int n;
	// my_printf("\033[22;34msalut", 1);
	// printf("x1B[35msalut\n");
	// ft_putstr("\x1B[34m");
	// g_i = 0;
	// while(++g_i < 255)
	// 	my_printf("%d = %c\t", 1, g_i, g_i);

	g_i = 0;
	// acl(av[1]);
	if (ac != -1)
	{
		n = option(av);
		g_i = ac - n;
		(g_i == 0) ? print_folder("./") : 1;
	}
	if (g_i >= 1)
		ft_sort_params(clean_av(av, n));
	(ac == -1) ? print_folder(av[0]) : 1;
	return (0);
}
