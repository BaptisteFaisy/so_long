/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:43:55 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/29 16:29:33 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	freelist(t_list_pos *head);
int		fini(t_list_pos *head, int *pos_p, int *pos_e, char **str);

int	main_algo(char **str)
{
	int			*pos_p;
	int			*pos_e;
	t_list_pos	*head;

	head = NULL;
	pos_e = NULL;
	pos_p = cpy_tab_and_find_chara(str);
	while (check_items(str) == 1)
	{
		str = replace_9_by_0(str);
		if (pos_e)
			free(pos_e);
		pos_e = find_items(str);
		freelist(head);
		head = malloc(sizeof(t_list_pos));
		if (!head)
			exit(0);
		create_4_node_start(pos_p, pos_e, &str, head);
		if (fini(head, pos_p, pos_e, str) == 1)
			return (0);
	}
	free(pos_e);
	return (main_find(str, head, pos_p));
}

void	freelist(t_list_pos *head)
{
	t_list_pos	*p;

	while (head)
	{
		p = head;
		head = head->next;
		free(p);
	}
}

int	fini(t_list_pos *head, int *pos_p, int *pos_e, char **str)
{
	while (TRUE)
	{
		if (check_if_9_all(head) == 0)
		{
			free(pos_p);
			free(pos_e);
			return (1);
		}
		if (goto_min_items(head, str, pos_p) == 1)
			return (0);
		if (create_4_node(pos_p, pos_e, &str, head) == false)
		{
			free(pos_p);
			free(pos_e);
			return (1);
		}
	}
}

int	goto_min(t_list_pos *head, char **str, int *pos_p)
{
	t_list_pos	*last;

	last = get_first(head);
	if (str[last->data.y][last->data.x] == 'E')
		return (1);
	str[last->data.y][last->data.x] = 'P';
	str[pos_p[0]][pos_p[1]] = '9';
	pos_p[0] = last->data.y;
	pos_p[1] = last->data.x;
	head->next = last->next;
	if (last)
		free(last);
	return (0);
}
