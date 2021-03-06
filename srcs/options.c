/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 19:53:52 by mmeziyan          #+#    #+#             */
/*   Updated: 2017/09/24 19:53:55 by mmeziyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	*g_opt;

void	error_opt(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\nusage: ls [-AFRacgloprtu1] [file ...]", 2);
	exit(1);
}

int		opt(char *s)
{
	int i;

	i = -1;
	if (!g_opt)
		return (-1);
	while (s[++i])
		if (ft_strchr(g_opt, s[i]))
			return (1);
	return (0);
}

int		option(char **av)
{
	int		i;
	int		j;
	char	*correct_opt;
	char	*ptr;

	i = 0;
	correct_opt = ft_strdup("AFRacgloprtu1");
	g_opt = ft_strdup("-");
	while (av[++i] && av[i][0] == '-' && av[i][1])
	{
		j = 0;
		if (av[i][1] == '-' && av[i][2] == '\0')
			return (i + 1);
		while (av[i][++j])
		{
			(!ft_strchr(correct_opt, av[i][j])) ? error_opt(g_opt[j]) : 0;
			ptr = av[i][j] == 'p' ? ft_strchr(g_opt, 'F') : NULL;
			av[i][j] == 'F' ? ptr = ft_strchr(g_opt, 'p') : NULL;
			av[i][j] == 'c' ? ptr = ft_strchr(g_opt, 'u') : NULL;
			av[i][j] == 'u' ? ptr = ft_strchr(g_opt, 'c') : NULL;
			ptr ? NULL : (g_opt = ft_add_char(g_opt, av[i][j], "right"));
			ptr ? *ptr = av[i][j] : 0;
		}
	}
	return (i);
}
