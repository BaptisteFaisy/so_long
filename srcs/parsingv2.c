/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:19:29 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/22 16:38:13 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	strlencustom(char *tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\n' && tab[i] != '\0')
		i++;
	return (i);
}

int	check_rect(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (tab[i + 1] != NULL)
			if (strlencustom(tab[i]) != strlencustom(tab[i + 1]))
				return (0);
		i++;
	}
	return (1);
}
