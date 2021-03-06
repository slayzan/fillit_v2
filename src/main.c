/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamayo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:51:59 by mchamayo          #+#    #+#             */
/*   Updated: 2019/04/22 12:45:54 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve_all(int count, int fd)
{
	char		**tab;
	int			bloc;
	t_tetri		**first_tetri;
	t_square	*square;

	tab = NULL;
	bloc = count / 4;
	first_tetri = NULL;
	tab = ft_stocktetra(fd, count, bloc);
	if (!(ft_check_shape(tab, count)))
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	count = (count + 1) / 5;
	first_tetri = ft_createlist(tab, count);
	square = ft_solve(first_tetri, count);
	ft_printresult(square->square, square->size);
	ft_freetab(tab);
	free_square(square);
	ft_freelist(first_tetri, count);
}

int		main(int argc, char **argv)
{
	int			fd;
	int			fd2;

	if (argc != 2)
	{
		ft_putendl("usage : ./fillit source_file");
		return (0);
	}
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (!(fd2 = open(argv[1], O_RDONLY)))
	{
		close(fd2);
		exit(EXIT_FAILURE);
	}
	if (!(argc = ft_parser(fd)))
	{
		ft_putendl("error");
		return (0);
	}
	solve_all(argc, fd2);
	return (0);
}
