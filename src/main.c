/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 19:57:01 by pmartine          #+#    #+#             */
/*   Updated: 2016/01/19 22:07:23 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_error(void)
{
	ft_putendl("error");
	exit(1);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	**tetriminos;
	char	*solution;

	if (argc != 2)
		ft_error();
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error();
	tetriminos = ft_check_file(fd);
	if (close(fd) < 0)
		ft_error();
	if (tetriminos == NULL)
		ft_error();
	solution = ft_resolve(tetriminos);
	if (solution == NULL)
		ft_error();
	ft_putstr(solution);
	ft_clear_tab(tetriminos);
	free(solution);
	return (0);
}
