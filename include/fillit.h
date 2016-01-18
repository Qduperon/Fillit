/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:38:23 by pmartine          #+#    #+#             */
/*   Updated: 2015/12/18 16:40:24 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>

char	**ft_check_file(int fd);
int		ft_istetriminos(char *tetriminos, int i, char letter);
int		ft_counthash(char *tetriminos, int i);
char	*ft_resolve(char **tetriminos);
void	ft_reset_tetriminos(char *tetriminos);
void	ft_reset_all_tetriminos(char **tetriminos);
void	ft_init_solution(char *solution, int width);
#endif
