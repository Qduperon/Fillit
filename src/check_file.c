/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:53:02 by pmartine          #+#    #+#             */
/*   Updated: 2016/01/18 15:36:09 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_bzero_tetriminos(char **tetriminos)
{
	int		i;

	i = 0;
	while (i < 26)
	{
		*tetriminos = NULL;
		tetriminos++;
		i++;
	}
}

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
	if ((read(fd, buf, 546) < 0) || buf[0] == '\0')
		return (NULL);
	while (buf[j] != '\0')
	{
		if ((ft_strlen(buf) >= 20))
			tetriminos[i] = ft_strsub(buf, 21 * i, 21);
		else
			return (NULL);
		j = j + (unsigned int)ft_strlen(tetriminos[i]);
		tetriminos[i][ft_strlen(tetriminos[i])] = '\0';
		i++;
	}
	return (tetriminos);
}

static int		check_tetriminos(char **tetriminos)
{
	int			i;

	while (*tetriminos != NULL)
	{
		i = 0;
		if (*(tetriminos + 1) == NULL)
		{
			if (ft_strlen(*tetriminos) != 20)
				return (0);
		}
		else if (ft_strlen(*tetriminos) != 21)
			return (0);
		while ((*tetriminos)[i])
		{
			if ((*tetriminos)[i] != '.' && (*tetriminos)[i] != '#' \
					&& (i + 1) % 5 != 0 && (i + 1) % 21 != 0)
				return (0);
			else if ((*tetriminos)[i] != '\n' && ((i + 1) % 5 == 0 || \
						(i + 1) % 21 == 0))
				return (0);
			i++;
		}
		tetriminos++;
	}
	return (1);
}

static int		parse_tetriminos(char **tetriminos)
{
	int			j;
	char		letter;

	j = 0;
	letter = 'a';
	while (*tetriminos)
	{
		j = 0;
		while ((*tetriminos)[j] && (*tetriminos)[j] != '#')
			j++;
		if ((*tetriminos)[j] && ((ft_counthash(*tetriminos, j) != 4) || \
					(ft_istetriminos(*tetriminos, j, letter) != 4)))
			return (0);
		letter++;
		tetriminos++;
	}
	return (1);
}

char			**ft_check_file(int fd)
{
	char		**tetriminos;

	tetriminos = ft_read_file(fd);
	if (!tetriminos)
		return (NULL);
	if (check_tetriminos(tetriminos) == 0)
	{
		ft_clear_tab(tetriminos);
		return (NULL);
	}
	if (parse_tetriminos(tetriminos) == 0)
	{
		ft_clear_tab(tetriminos);
		return (NULL);
	}
	return (tetriminos);
}
