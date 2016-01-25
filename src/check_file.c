/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:53:02 by pmartine          #+#    #+#             */
/*   Updated: 2016/01/25 14:17:45 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_read_file(int fd)
{
	char			**tetriminos;
	char			buf[546];
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if ((tetriminos = (char **)malloc(sizeof(char *) * 27)) == NULL)
		return (NULL);
	ft_bzero_tetriminos(tetriminos);
	ft_bzero(buf, 546);
	if (read(fd, buf, 546) < 0)
		return (NULL);
	if (ft_strlen(buf) < 20)
		return (NULL);
	while (buf[j] != '\0')
	{
		tetriminos[i] = ft_strsub(buf, 21 * i, 21);
		j = j + (unsigned int)ft_strlen(tetriminos[i]);
		++i;
	}
	if (tetriminos[i - 1][20] != '\0')
		return (NULL);
	return (tetriminos);
}

static int		check_tetriminos(char **tetriminos)
{
	int				i;
	int				n;

	while (*tetriminos != NULL)
	{
		i = 0;
		n = 0;
		while ((*tetriminos)[i] != '\0')
		{
			if ((i + 1) % 5 == 0 && (*tetriminos)[i] == '\n')
				i++;
			if ((*tetriminos)[i] != '.' && (*tetriminos)[i] != '#' && i < 20)
				return (0);
			++i;
		}
		++tetriminos;
	}
	return (1);
}

static int		parse_tetriminos(char **tetriminos)
{
	int				i;
	char			letter;

	i = 0;
	letter = 'a';
	while (*tetriminos != NULL)
	{
		i = 0;
		while ((*tetriminos)[i] && (*tetriminos)[i] != '#')
			++i;
		if (!(*tetriminos)[i])
			return (0);
		if ((*tetriminos)[i] && ft_istetriminos(*tetriminos, i, letter) != 4)
			return (0);
		while ((*tetriminos)[i++])
			if ((*tetriminos)[i] == '#')
				return (0);
		++letter;
		++tetriminos;
	}
	return (1);
}

char			**ft_check_file(int fd)
{
	char		**tetriminos;

	tetriminos = ft_read_file(fd);
	if (!tetriminos)
		return (NULL);
	if (!check_tetriminos(tetriminos))
	{
		ft_clear_tab(tetriminos);
		return (NULL);
	}
	if (!parse_tetriminos(tetriminos))
	{
		ft_clear_tab(tetriminos);
		return (NULL);
	}
	return (tetriminos);
}
