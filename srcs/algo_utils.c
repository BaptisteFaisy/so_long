/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:25:45 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/29 16:27:46 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_if_9_all(t_list_pos *head)
{
	if (head->next == NULL)
		return (0);
	else
		return (1);
}

int	check_items(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*find_items(char **str)
{
	int	i;
	int	j;
	int	*tab;

	tab = malloc(sizeof(int) * 2);
	if (!tab)
		exit (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\n' && str[i][j] != '\0')
		{
			if (str[i][j] == 'C')
			{
				tab[0] = i;
				tab[1] = j;
				return (tab);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

char	**replace_9_by_0(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] == '9')
				str[i][j] = '0';
			j++;
		}
		i++;
	}
	return (str);
}
