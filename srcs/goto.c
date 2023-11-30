/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:16:25 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/29 16:27:27 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	*find_hero(char **str)
{
	int	i;
	int	j;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * 2);
	if (!tab)
		exit(0);
	while (str[i] != 0)
	{
		j = 0;
		while (str[i][j] != '\n' && str[i][j] != '\0')
		{
			if (str[i][j] == 'P')
			{
				tab[0] = i;
				tab[1] = j;
				return (tab);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	goto_left(t_storage **stock)
{
	int			i;
	int			*in;

	i = 0;
	in = find_hero((**stock).tab);
	if (!in)
		free_goto(**stock);
	if ((**stock).tab[in[0]][in[1] - 1] == 'E')
	{
		free(in);
		check_fin(**stock);
		return ;
	}
	if ((**stock).tab[in[0]][in[1] - 1] != '1'
		&& (**stock).tab[in[0]][in[1] - 1] != 'E')
	{
		(**stock).tab[in[0]][in[1] - 1] = 'P';
		(**stock).tab[in[0]][in[1]] = '0';
		(**stock).nbr++;
		ft_putnbr_fd((**stock).nbr, 1);
		ft_putchar_fd('\n', 1);
		create_img(**stock);
	}
	free(in);
}

void	goto_right(t_storage **stock)
{
	int			i;
	int			*in;

	i = 0;
	in = find_hero((**stock).tab);
	if ((**stock).tab[in[0]][in[1] + 1] == 'E')
	{
		free(in);
		check_fin(**stock);
		return ;
	}
	if ((**stock).tab[in[0]][in[1] + 1] != '1'
		&& (**stock).tab[in[0]][in[1] + 1] != 'E')
	{
		(**stock).tab[in[0]][in[1] + 1] = 'P';
		(**stock).tab[in[0]][in[1]] = '0';
		(**stock).nbr++;
		ft_putnbr_fd((**stock).nbr, 1);
		ft_putchar_fd('\n', 1);
		create_img(**stock);
	}
	free(in);
}

void	goto_up(t_storage **stock)
{
	int			i;
	int			*in;

	i = 0;
	in = find_hero((**stock).tab);
	if ((**stock).tab[in[0] - 1][in[1]] == 'E')
	{
		free(in);
		check_fin(**stock);
		return ;
	}
	if ((**stock).tab[in[0] - 1][in[1]] != '1'
		&& (**stock).tab[in[0] - 1][in[1]] != 'E')
	{
		(**stock).tab[in[0] - 1][in[1]] = 'P';
		(**stock).tab[in[0]][in[1]] = '0';
		(**stock).nbr++;
		ft_putnbr_fd((**stock).nbr, 1);
		ft_putchar_fd('\n', 1);
		create_img(**stock);
	}
	free(in);
}

void	goto_down(t_storage **stock)
{
	int			i;
	int			*in;

	i = 0;
	in = find_hero((**stock).tab);
	if ((**stock).tab[in[0] + 1][in[1]] == 'E')
	{
		free(in);
		check_fin(**stock);
		return ;
	}
	if ((**stock).tab[in[0] + 1][in[1]] != '1'
		&& (**stock).tab[in[0] + 1][in[1]] != 'E')
	{
		(**stock).tab[in[0] + 1][in[1]] = 'P';
		(**stock).tab[in[0]][in[1]] = '0';
		(**stock).nbr++;
		ft_putnbr_fd((**stock).nbr, 1);
		ft_putchar_fd('\n', 1);
		create_img(**stock);
	}
	free(in);
}
