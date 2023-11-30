/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:46:06 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/28 12:51:57 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up_img(t_storage stock);

void	create_img(t_storage stock)
{
	int			i;
	int			j;
	int			p;
	int			u;
	t_img		img;

	j = 0;
	img.img = mlx_xpm_file_to_image(stock.vars.mlx, "./assets/floor3.xpm",
			&p, &u);
	while (stock.tab[j] != 0)
	{
		i = 0;
		while (stock.tab[j][i] != '\n' && stock.tab[j][i] != '\0')
		{
			if (stock.tab[j][i] == '0')
				mlx_put_image_to_window(stock.vars.mlx, stock.vars.win, img.img,
					(i * 64), (j * 64));
			i++;
		}
		j++;
	}
	i = 0;
	mlx_destroy_image(stock.vars.mlx, img.img);
	up_img(stock);
}

void	up_img(t_storage stock)
{
	int	i;
	int	j;

	j = 0;
	while (stock.tab[j] != 0)
	{
		i = 0;
		while (stock.tab[j][i] != '\n' && stock.tab[j][i] != '\0')
		{
			if (stock.tab[j][i] == '1')
				put_wall(stock, i, j);
			else if (stock.tab[j][i] == 'C')
				put_items(stock, i, j);
			else if (stock.tab[j][i] == 'E')
				put_end(stock, i, j);
			else if (stock.tab[j][i] == 'P')
				put_character(stock, i, j);
			i++;
		}
		j++;
	}
	i = 0;
}
