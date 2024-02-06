/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:09:49 by bfaisy            #+#    #+#             */
/*   Updated: 2024/02/06 17:28:20 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	usefull(int cond, int i, char *str);

int	bercheck(char *str)
{
	int	i;
	int	cond;

	cond = 0;
	i = 0;
	while (str[i])
	{
		if (cond == 4)
			return (0);
		cond = usefull(cond, i, str);
		if (cond == -1)
			return (0);
		if (str[i] == '.')
			cond = 1;
		i++;
	}
	if (cond == 4)
		return (1);
	return (0);
}

static int	usefull(int cond, int i, char *str)
{
	if (cond == 1)
	{
		if (str[i] == 'b')
			cond++;
		else
			return (-1);
	}
	else if (cond == 2)
	{
		if (str[i] == 'e')
			cond++;
		else
			return (-1);
	}
	else if (cond == 3)
	{
		if (str[i] == 'r')
			cond++;
		else
			return (-1);
	}
	return (cond);
}

int	checkifclose(int *pos_p, char **str)
{
	if (str[pos_p[0]][pos_p[1] - 1] == 'E'
		|| str[pos_p[0]][pos_p[1] + 1] == 'E'
			|| str[pos_p[0] - 1][pos_p[1]] == 'E'
				|| str[pos_p[0] + 1][pos_p[1]] == 'E')
		return (1);
	else
		return (0);
}
