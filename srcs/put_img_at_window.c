/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_at_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:07:06 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/24 13:44:42 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_wall(t_storage stock, int i, int j)
{
	t_img	img;
	int		p;
	int		d;

	img.img = mlx_xpm_file_to_image(stock.vars.mlx, "./assets/wall.xpm",
			&p, &d);
	mlx_put_image_to_window(stock.vars.mlx, stock.vars.win,
		img.img, (i * 64), (j * 64));
	mlx_destroy_image(stock.vars.mlx, img.img);
}

void	put_items(t_storage stock, int i, int j)
{
	t_img	img;
	int		p;
	int		d;

	img.img = mlx_xpm_file_to_image(stock.vars.mlx, "./assets/object.xpm",
			&p, &d);
	mlx_put_image_to_window(stock.vars.mlx, stock.vars.win,
		img.img, (i * 64), (j * 64));
	mlx_destroy_image(stock.vars.mlx, img.img);
}

void	put_end(t_storage stock, int i, int j)
{
	t_img	img;
	int		p;
	int		d;

	img.img = mlx_xpm_file_to_image(stock.vars.mlx, "./assets/end.xpm",
			&p, &d);
	mlx_put_image_to_window(stock.vars.mlx, stock.vars.win,
		img.img, (i * 64), (j * 64));
	mlx_destroy_image(stock.vars.mlx, img.img);
}

void	put_character(t_storage stock, int i, int j)
{
	t_img	img;
	int		p;
	int		d;

	img.img = mlx_xpm_file_to_image
		(stock.vars.mlx, "./assets/chara_down/charadown1.xpm", &p, &d);
	mlx_put_image_to_window(stock.vars.mlx, stock.vars.win,
		img.img, (i * 64), (j * 64));
	mlx_destroy_image(stock.vars.mlx, img.img);
}
