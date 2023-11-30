/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:09:49 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/29 15:57:53 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**cpytab(char **src)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	tab = malloc(sizeof(char *) * tabcount(src));
	if (!tab)
		exit(0);
	while (src[i])
	{
		j = 0;
		tab[i] = malloc(sizeof(char) * ft_strlen(src[i]));
		while (src[i][j] != '\n' && src[i][j] != '\0')
		{
			tab[i][j] == src[i][j];
			j++;
		}
		i++;
	}
	return (tab);
}

int	tabcount(char **src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}
