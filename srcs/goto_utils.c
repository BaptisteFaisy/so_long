/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:51:15 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/29 17:22:07 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_fin(t_storage stock)
{
	int	i;
	int	j;

	i = 0;
	while (stock.tab[i])
	{
		j = 0;
		while (stock.tab[i][j])
		{
			if (stock.tab[i][j] == 'C')
			{
				ft_putstr_fd("You didn't collect all the items\n", 1);
				return ;
			}
			j++;
		}
		i++;
	}
	ft_putstr_fd("GG", 1);
	freetab(stock.tab);
	freetab(stock.tab2);
	mlx_destroy_window((stock).vars.mlx, (stock).vars.win);
	mlx_destroy_display((stock).vars.mlx);
	free((stock).vars.mlx);
	exit(0);
}

int	free_goto(t_storage stock)
{
	ft_putstr_fd("Error :\nMalloc fail", 1);
	freetab(stock.tab);
	mlx_destroy_window((stock).vars.mlx, (stock).vars.win);
	mlx_destroy_display((stock).vars.mlx);
	free((stock).vars.mlx);
	exit(0);
}
