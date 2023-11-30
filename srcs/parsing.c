/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:54:55 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/28 16:02:53 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_spawn_and_end(char **tab);
int	check_input(char **tab);

int	check_main(char **tab)
{
	if (check_bord(tab) == 0 || check_spawn_and_end(tab) == 0
		|| check_input(tab) == 0 || check_rect(tab) == 0
		|| main_algo(tab) == 0)
		return (0);
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
		}
		i++;
	}
	return (1);
}
