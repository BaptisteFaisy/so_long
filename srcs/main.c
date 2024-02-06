/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:32:43 by bfaisy            #+#    #+#             */
/*   Updated: 2024/02/05 20:34:40 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_for_map(t_storage *stock, int p);
int		x11_destroy_event(t_storage *stock);
int		acces(char *str);

int	ftclose(int keycode, t_storage *stock)
{
	if (keycode == 0xFF1B)
		x11_destroy_event(stock);
	else if (keycode == 0x61)
		goto_left(&stock);
	else if (keycode == 0x77)
		goto_up(&stock);
	else if (keycode == 0x64)
		goto_right(&stock);
	else if (keycode == 0x73)
		goto_down(&stock);
	return (0);
}

int	x11_destroy_event(t_storage *stock)
{
	freetab((*stock).tab);
	freetab((*stock).tab2);
	mlx_destroy_window((*stock).vars.mlx, (*stock).vars.win);
	mlx_destroy_display((*stock).vars.mlx);
	free((*stock).vars.mlx);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_xy		wind;
	t_storage	stock;

	wind.x = 0;
	wind.y = 0;
	if (ac != 2)
		return (1);
	stock.pos.x = 0;
	stock.pos.y = 0;
	stock.nbr = 0;
	if (acces(av[1]) == 0)
		return (1);
	stock.tab = mapwind(&wind, av);
	stock.tab2 = create_tab(av);
	if (check_main(stock) == 0)
		return (1);
	stock.vars.mlx = mlx_init();
	if (stock.vars.mlx == NULL)
		ft_free_for_map(&stock, 1);
	stock.vars.win = mlx_new_window(stock.vars.mlx, wind.x, wind.y, "So_long");
	create_img(stock);
	mlx_key_hook(stock.vars.win, ftclose, &stock);
	mlx_hook(stock.vars.win,
		SL_X11_EVENT_DESTROY_NOTIFY, 0L, x11_destroy_event, &stock);
	mlx_loop(stock.vars.mlx);
}

void	ft_free_for_map(t_storage *stock, int p)
{
	if (p == 1)
	{
		ft_putstr_fd("Error : \nmlx_init fail", 1);
		freetab((*stock).tab);
		free((*stock).vars.mlx);
		exit(0);
	}
}

int	acces(char *str)
{
	int	fd;

	if (bercheck(str) == 0)
		return (0);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error : I can't open the map\n", 1);
		return (0);
	}
	close(fd);
	fd = open(str, O_DIRECTORY);
	if (fd == -1)
	{
		return (1);
	}
	close(fd);
	ft_putstr_fd("Error : Directory found, file expected \n", 1);
	return (0);
}
