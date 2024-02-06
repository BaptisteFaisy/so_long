/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_at_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:07:06 by bfaisy            #+#    #+#             */
/*   Updated: 2024/02/02 16:36:52 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_wall(t_storage stock, int i, int j)
{
	t_img	img;
	int		p;
	int		d;

	p = open("./t/wall.xpm", O_RDONLY);
	d = open("./t/wall.xpm", O_DIRECTORY);
	if (p == -1 || d != -1)
	{
		ft_putstr_fd("Error : Textures : Wall error \n", 1);
		freetab((stock).tab);
		freetab((stock).tab2);
		mlx_destroy_window((stock).vars.mlx, (stock).vars.win);
		mlx_destroy_display((stock).vars.mlx);
		free((stock).vars.mlx);
		if (p != -1)
			close(p);
		if (d == -1)
			close(d);
		exit (1);
	}
	close(p);
	img.img = mlx_xpm_file_to_image(stock.vars.mlx, "./t/wall.xpm", &p, &d);
	mlx_put_image_to_window(stock.vars.mlx, stock.vars.win,
		img.img, (i * 64), (j * 64));
	mlx_destroy_image(stock.vars.mlx, img.img);
}

void	put_items(t_storage stock, int i, int j)
{
	t_img	img;
	int		p;
	int		d;

	p = open("./t/o.xpm", O_RDONLY);
	d = open("./t/o.xpm", O_DIRECTORY);
	if (p == -1 || d != -1)
	{
		ft_putstr_fd("Error : Textures : Wall error \n", 1);
		freetab((stock).tab);
		freetab((stock).tab2);
		mlx_destroy_window((stock).vars.mlx, (stock).vars.win);
		mlx_destroy_display((stock).vars.mlx);
		free((stock).vars.mlx);
		if (p != -1)
			close(p);
		if (d == -1)
			close(d);
		exit (1);
	}
	close(p);
	img.img = mlx_xpm_file_to_image(stock.vars.mlx, "./t/o.xpm", &p, &d);
	mlx_put_image_to_window(stock.vars.mlx, stock.vars.win,
		img.img, (i * 64), (j * 64));
	mlx_destroy_image(stock.vars.mlx, img.img);
}

void	put_end(t_storage stock, int i, int j)
{
	t_img	img;
	int		p;
	int		d;

	p = open("./t/e.xpm", O_RDONLY);
	d = open("./t/e.xpm", O_DIRECTORY);
	if (p == -1 || d != -1)
	{
		ft_putstr_fd("Error : Textures : Wall error \n", 1);
		freetab((stock).tab);
		freetab((stock).tab2);
		mlx_destroy_window((stock).vars.mlx, (stock).vars.win);
		mlx_destroy_display((stock).vars.mlx);
		free((stock).vars.mlx);
		if (p != -1)
			close(p);
		if (d == -1)
			close(d);
		exit (1);
	}
	close(p);
	img.img = mlx_xpm_file_to_image(stock.vars.mlx, "./t/e.xpm", &p, &d);
	mlx_put_image_to_window(stock.vars.mlx, stock.vars.win,
		img.img, (i * 64), (j * 64));
	mlx_destroy_image(stock.vars.mlx, img.img);
}

void	put_character(t_storage stock, int i, int j)
{
	t_img	img;
	int		p;
	int		d;

	p = open("./t/c/c1.xpm", O_RDONLY);
	d = open("./t/c/c1.xpm", O_DIRECTORY);
	if (p == -1 || d != -1)
	{
		ft_putstr_fd("Error : Textures : Wall error \n", 1);
		freetab((stock).tab);
		freetab((stock).tab2);
		mlx_destroy_window((stock).vars.mlx, (stock).vars.win);
		mlx_destroy_display((stock).vars.mlx);
		free((stock).vars.mlx);
		if (p != -1)
			close(p);
		if (d == -1)
			close(d);
		exit (1);
	}
	close(p);
	img.img = mlx_xpm_file_to_image (stock.vars.mlx, "./t/c/c1.xpm", &p, &d);
	mlx_put_image_to_window(stock.vars.mlx, stock.vars.win,
		img.img, (i * 64), (j * 64));
	mlx_destroy_image(stock.vars.mlx, img.img);
}
