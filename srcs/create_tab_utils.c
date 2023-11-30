/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:00:14 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/29 14:51:09 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_fail(void)
{
	ft_putstr_fd("Error :\nOpen map fail", 1);
	exit(0);
}

void	protec_str(char **str)
{
	freetab(str);
	ft_putstr_fd("Error :\nProbably malloc fail or read fail", 1);
	exit(0);
}

void	cpy_utils(char **str, char ***new_str, int i)
{
	int	j;

	j = 0;
	while (str[i][j] != '\n' && str[i][j] != '\0')
	{
		(*new_str)[i][j] = str[i][j];
		j++;
	}
	(*new_str)[i][j] = '\0';
}
