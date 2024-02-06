/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:54:55 by bfaisy            #+#    #+#             */
/*   Updated: 2024/02/06 18:17:16 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_spawn_and_end(char **tab);
int	check_input(char **tab);

int	check_main(t_storage stock)
{
	if (check_bord(stock.tab2) == 0 || check_spawn_and_end(stock.tab2) == 0
		|| check_input(stock.tab2) == 0 || check_rect(stock.tab2) == 0
		|| main_algo(stock) == 0)
	{
		ft_putstr_fd("Error : \nInvalid map", 1);
		freetab(stock.tab);
		freetab(stock.tab2);
		exit (1);
	}
	return (1);
}

// les fonctions vont check si jamais la map est entoure de mur
int	check_bord_v2(char **tab, int i, int j);

int	check_bord(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[0][j] != '\n' && tab[0][j] != '\0')
	{
		if (tab[0][j] != '1')
			return (0);
		j++;
	}
	while (tab[i] != NULL)
	{
		if (tab[i][0] != '1')
			return (0);
		i++;
	}
	if (check_bord_v2(tab, i, j) == 0)
		return (0);
	return (1);
}

int	check_bord_v2(char **tab, int i, int j)
{
	int	k;

	i--;
	j--;
	k = 0;
	while (tab[k] != NULL)
	{
		if (tab[k][j] != '1')
			return (0);
		k++;
	}
	j = 0;
	while (tab[i][j] != '\n' && tab[i][j] != '\0')
	{
		if (tab[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_spawn_and_end(char **tab)
{
	int	i;
	int	j;
	int	nbr_end;
	int	nbr_spawn;

	nbr_end = 0;
	nbr_spawn = 0;
	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\n' && tab[i][j] != '\0')
		{
			if (tab[i][j] == 'P')
				nbr_spawn++;
			else if (tab[i][j] == 'E')
				nbr_end++;
			j++;
		}
		i++;
	}
	if (nbr_end != 1 || nbr_spawn != 1)
		return (0);
	return (1);
}

int	check_input(char **tab)
{
	int	i;
	int	j;
	int	cond;

	cond = false;
	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\n' && tab[i][j] != '\0')
		{
			if (tab[i][j] != '0' && tab[i][j] != '1' && tab[i][j] != 'P'
				&& tab[i][j] != 'C' && tab[i][j] != 'E')
				return (0);
			j++;
			if (tab[i][j] == 'C')
				cond = true;
		}
		i++;
	}
	if (cond == false)
		return (0);
	return (1);
}
