/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:48:59 by bfaisy            #+#    #+#             */
/*   Updated: 2024/02/02 16:10:44 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exitfloor(t_storage stock, int fd1, int fd2)
{
	ft_putstr_fd("Error : Textures : Floor error \n", 1);
	freetab((stock).tab);
	freetab((stock).tab2);
	mlx_destroy_window((stock).vars.mlx, (stock).vars.win);
	mlx_destroy_display((stock).vars.mlx);
	free((stock).vars.mlx);
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);
	exit (1);
}
