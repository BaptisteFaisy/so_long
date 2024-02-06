/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:33:37 by bfaisy            #+#    #+#             */
/*   Updated: 2024/02/06 18:06:34 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
// les tableaux ne sont aps free
int		*cpy_tab_and_find_chara(char **str);
int		*find_end(char **str);

t_list_pos	*create_node(void)
{
	t_list_pos	*new_node;

	new_node = malloc(sizeof(t_list_pos));
	if (!new_node)
		return (0);
	new_node->next = NULL;
	return (new_node);
}

int	main_find(char	**str, t_list_pos *head, int *pos_p)
{
	int			*pos_e;

	pos_e = find_end(str);
	if (checkifclose(pos_p, str))
	{
		free(pos_p);
		freelist(head);
		return (free(pos_e), 1);
	}
	while (TRUE)
	{
		if (check_if_9_all(head) == 0)
		{
			freelist(head);
			free(pos_e);
			return (free(pos_p), 0);
		}
		if (goto_min(head, str, pos_p) == 1)
		{
			freelist(head);
			return (free(pos_e), free(pos_p), 1);
		}
		if (create_4_node(pos_p, pos_e, &str, head) == false)
			return (free(pos_e), free(pos_p), freelist(head), 0);
	}
}

int	*cpy_tab_and_find_chara(char **str)
{
	int		i;
	int		j;
	int		*tab_int;

	tab_int = malloc(sizeof(int) * 2);
	if (!tab_int)
		exit (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\n' && str[i][j] != '\0')
		{
			if (str[i][j] == 'P')
			{
				tab_int[0] = i;
				tab_int[1] = j;
				return (tab_int);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	*find_end(char **str)
{
	int		i;
	int		j;
	int		*tab_int;

	tab_int = malloc(sizeof(int) * 2);
	if (!tab_int)
		exit(0);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\n' && str[i][j] != '\0')
		{
			if (str[i][j] == 'E')
			{
				tab_int[0] = i;
				tab_int[1] = j;
				return (tab_int);
			}
			j++;
		}
		i++;
	}
	free(tab_int);
	return (0);
}
