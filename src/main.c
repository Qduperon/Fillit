/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 19:57:01 by pmartine          #+#    #+#             */
/*   Updated: 2016/01/18 15:35:12 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_error(void)
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
	if (!tetriminos)
		ft_error();
	if (close(fd) < 0)
		exit(1);
	if (tetriminos == NULL)
		ft_error();
	solution = ft_resolve(tetriminos);
	if (!solution)
		ft_error();
	ft_putstr(solution);
	ft_clear_tab(tetriminos);
	free(solution);
	exit(0);
}
