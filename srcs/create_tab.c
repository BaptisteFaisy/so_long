/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:47:03 by bfaisy            #+#    #+#             */
/*   Updated: 2024/02/02 16:38:07 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// premiere fonction qui definie l image et la taille de la fenetre

#include "../so_long.h"
#include <stdio.h>

void	exit_big_map(char **tab);

char	**cpy(char **str, int size, int dbu)
{
	char	**new_str;
	int		i;

	i = 0;
	new_str = malloc(sizeof(char *) * size);
	if (!new_str)
		protec_str(str);
	if (dbu == 0)
	{
		while (i < size - 1)
		{
			new_str[i] = str[i];
			i++;
		}
		new_str[i] = 0;
	}
	if (str)
		free(str);
	return (new_str);
}

char	**freetab(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

// actuellement les 2 tableaux ne sont pas clean, il n y en a qu un
char	**create_tab(char **av)
{
	int		fd;
	char	**str;
	int		i;
	int		size;
	int		dbu;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		open_fail();
	size = 2;
	i = 0;
	dbu = 1;
	str = NULL;
	while (dbu == 1 || str[i - 1] != NULL)
	{
		str = cpy(str, size, dbu);
		str[i] = get_next_line(fd);
		if (!str[i])
			return (close(fd), str);
		i++;
		size++;
		dbu = 0;
	}
	return (close (fd), NULL);
}

char	**mapwind(t_xy	*wind, char **av)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	tab = create_tab(av);
	if (!tab)
		exit_big_map(tab);
	j = 0;
	while (tab[i] != 0)
	{
		if ((*wind).y > 1080)
			exit_big_map(tab);
		(*wind).y += 64;
		i++;
	}
	i = 0;
	while (tab[i][j] != '\n' && tab[i][j] != '\0')
	{
		if ((*wind).x > 1920)
			exit_big_map(tab);
		(*wind).x += 64;
		j++;
	}
	return (tab);
}

void	exit_big_map(char **tab)
{
	freetab(tab);
	ft_putstr_fd("Error :\nThe map is too big or malloc fail", 1);
	exit(0);
}
