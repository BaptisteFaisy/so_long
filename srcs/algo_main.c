/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:43:55 by bfaisy            #+#    #+#             */
/*   Updated: 2024/02/06 18:41:21 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	freelist(t_list_pos *head);
int		fini(t_list_pos *head, int *pos_p, int *pos_e, t_storage stock);

int	main_algo(t_storage stock)
{
	int			*pos_p;
	int			*pos_e;
	int			*pos_tmp;
	t_list_pos	*head;

	head = NULL;
	pos_e = NULL;
	pos_p = cpy_tab_and_find_chara(stock.tab2);
	while (check_items(stock.tab2) == 1)
	{
		pos_tmp = pos_e;
		pos_e = find_items(stock.tab2);
		if (pos_tmp != pos_e)
			stock.tab2 = replace_9_by_0(stock.tab2);
		free(pos_tmp);
		freelist(head);
		head = malloc(sizeof(t_list_pos));
		if (!head)
			exit(0);//
		create_4_node_start(pos_p, pos_e, stock.tab2, head);
		if (fini(head, pos_p, pos_e, stock) == 1)
			return (freelist(head), 0);
	}
	stock.tab2 = replace_9_by_0(stock.tab2);
	return (free(pos_e), main_find(stock.tab2, head, pos_p));
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

int	fini(t_list_pos *head, int *pos_p, int *pos_e, t_storage stock)
{
	while (TRUE)
	{
		if (check_if_9_all(head) == 0)
		{
			free(pos_p);
			free(pos_e);
			return (1);
		}
		if (goto_min_items(head, stock, pos_p) == 1)
			return (0);
		create_4_node(pos_p, pos_e, &stock.tab2, head);
	}
}

int	goto_min(t_list_pos *head, char **str, int *pos_p)
{
	t_list_pos	*last;

	last = get_first(head);
	if (last == NULL)
		return (1);
	if (checkifclose(pos_p, str) == 1)
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
