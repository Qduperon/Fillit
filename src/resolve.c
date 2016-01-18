/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:44:26 by pmartine          #+#    #+#             */
/*   Updated: 2016/01/18 14:32:50 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*ft_extend_square(char **tetriminos, char *solution, int width)
{
	free(solution);
	if (!(solution = ft_strnew((((size_t)width + 2) * ((size_t)width + 1)))))
		return (NULL);
	ft_init_solution(solution, width);
	ft_reset_all_tetriminos(tetriminos);
	return (solution);
}

static int		ft_fill_tetriminos(char *tetri, int i, char *solution, int j)
{
	int		hash;
	int		length;

	hash = 0;
	length = 0;
	while (solution[length] != '\n')
		length++;
	length++;
	if (i >= 0 && i < 20 && j >= 0 && j < (length * (length - 1)) && \
	tetri[i] >= 'a' && solution[j] == '.')
	{
		tetri[i] = tetri[i] - 32;
		solution[j] = tetri[i];
		hash++;
		hash = hash + ft_fill_tetriminos(tetri, i + 1, solution, j + 1);
		hash = hash + ft_fill_tetriminos(tetri, i + 5, solution, j + length);
		hash = hash + ft_fill_tetriminos(tetri, i - 1, solution, j - 1);
	}
	return (hash);
}

static int		ft_filler(char *tetri, char *sol, int st, char letter)
{
	int		index;
	int		j;

	index = 0;
	while (!ft_isalpha(tetri[index]))
		index++;
	if (ft_fill_tetriminos(tetri, index, sol, st) == 4)
		return (1);
	ft_reset_tetriminos(tetri);
	j = 0;
	while (sol[j])
	{
		if (sol[j] == letter)
			sol[j] = '.';
		j++;
	}
	return (0);
}

static int		ft_solver(char **tetriminos, char **solution, int index)
{
	char	*cpy_solution;
	int		i;

	i = 0;
	if (tetriminos[index] == NULL)
		return (1);
	cpy_solution = ft_strdup(*solution);
	while ((*solution)[i])
	{
		if (!ft_filler(tetriminos[index], *solution, i, 'A' + (char)index))
			i++;
		else
		{
			if (ft_solver(tetriminos, solution, index + 1))
			{
				free(cpy_solution);
				return (1);
			}
			free(*solution);
			*solution = ft_strdup(cpy_solution);
		}
	}
	free(cpy_solution);
	return (0);
}

char			*ft_resolve(char **tetriminos)
{
	char	*solution;
	int		item;
	int		width;

	item = 0;
	width = 0;
	while (tetriminos[item])
		item++;
	item = item * 4;
	while (width * width < item)
		width++;
	if (!(solution = ft_strnew(((size_t)width * ((size_t)width + 1)))))
		return (NULL);
	ft_init_solution(solution, width);
	while (!ft_solver(tetriminos, &solution, 0))
	{
		if (!(solution = ft_extend_square(tetriminos, solution, width)))
			return (NULL);
		width++;
	}
	return (solution);
}
