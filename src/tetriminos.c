/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 19:37:49 by pmartine          #+#    #+#             */
/*   Updated: 2016/01/18 14:34:22 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_istetriminos(char *tetriminos, int i, char letter)
{
	int		hash;

	hash = 0;
	if (i >= 0 && i < 20 && tetriminos[i] == '#')
	{
		tetriminos[i] = letter;
		hash++;
		hash = hash + ft_istetriminos(tetriminos, i + 1, letter);
		hash = hash + ft_istetriminos(tetriminos, i + 5, letter);
		hash = hash + ft_istetriminos(tetriminos, i - 1, letter);
		hash = hash + ft_istetriminos(tetriminos, i - 5, letter);
	}
	return (hash);
}

int		ft_counthash(char *tetriminos, int i)
{
	int		counthash;

	counthash = 0;
	while (tetriminos[i])
	{
		if (tetriminos[i] == '#')
			counthash++;
		i++;
	}
	return (counthash);
}

void	ft_reset_tetriminos(char *tetriminos)
{
	int i;

	i = 0;
	while (tetriminos[i])
	{
		if (tetriminos[i] <= 'Z' && tetriminos[i] >= 'A')
			tetriminos[i] = tetriminos[i] + 32;
		i++;
	}
}

void	ft_reset_all_tetriminos(char **tetriminos)
{
	int		i;

	i = 0;
	while (tetriminos[i])
	{
		ft_reset_tetriminos(tetriminos[i]);
		i++;
	}
}

void	ft_init_solution(char *solution, int width)
{
	int		i;

	i = 0;
	while (i < (width + 1) * width)
	{
		if ((i + 1) % (width + 1) != 0)
			solution[i] = '.';
		else
			solution[i] = '\n';
		i++;
	}
}
