/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_4_node_start.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:08:51 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/29 17:18:50 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_4_node_start_next3(int *pos_p, char ***str,
			t_list_pos	*head_main, t_mouv mouv);
void	create_4_node_start_next1(int *pos_p, char ***str,
			t_list_pos	*head_main, t_mouv mouv);
void	create_4_node_start_next2(int *pos_p, char ***str,
			t_list_pos	*head_main, t_mouv mouv);

void	create_4_node_start(int *pos_p, int *pos_e, char ***str,
	t_list_pos	*head_main)
{
	t_mouv	mouv;

	mouv.pos_e = pos_e;
	mouv.p = 0;
	head_main->data.dist = -1;
	if ((*str)[pos_p[0]][pos_p[1] - 1] != '1')
	{
		mouv.left = create_node();
		if (mouv.left)
		{
			mouv.left->data.dist = (calculus(pos_p[0],
						(pos_p[1] - 1), mouv.pos_e));
			mouv.left->data.y = pos_p[0];
			mouv.left->data.x = pos_p[1] - 1;
			if (mouv.p == 0)
				head_main->next = mouv.left;
			else
				add_to_list(head_main, mouv.left);
			mouv.p = 1;
		}
	}
	create_4_node_start_next1(pos_p, str, head_main, mouv);
}

void	create_4_node_start_next1(int *pos_p, char ***str,
	t_list_pos	*head_main, t_mouv mouv)
{
	if ((*str)[pos_p[0]][pos_p[1] + 1] != '1')
	{
		mouv.right = create_node();
		if (mouv.right)
		{
			mouv.right->data.dist = (calculus(pos_p[0],
						pos_p[1] + 1, mouv.pos_e));
			mouv.right->data.y = pos_p[0];
			mouv.right->data.x = pos_p[1] + 1;
			if (mouv.p == 0)
			{
				head_main->next = mouv.right;
				mouv.p = 1;
			}
			else
				add_to_list(head_main, mouv.right);
		}
	}
	create_4_node_start_next2(pos_p, str, head_main, mouv);
}

void	create_4_node_start_next2(int *pos_p, char ***str,
	t_list_pos	*head_main, t_mouv mouv)
{
	if ((*str)[pos_p[0] - 1][pos_p[1]] != '1')
	{
		mouv.up = create_node();
		if (mouv.up)
		{
			mouv.up->data.dist = (calculus(pos_p[0] - 1, pos_p[1], mouv.pos_e));
			mouv.up->data.y = pos_p[0] - 1;
			mouv.up->data.x = pos_p[1];
			if (mouv.p == 0)
			{
				head_main->next = mouv.up;
				mouv.p = 1;
			}
			else
				add_to_list(head_main, mouv.up);
		}
	}
	create_4_node_start_next3(pos_p, str, head_main, mouv);
}

void	create_4_node_start_next3(int *pos_p, char ***str,
	t_list_pos	*head_main, t_mouv mouv)
{
	if ((*str)[pos_p[0] + 1][pos_p[1]] != '1')
	{
		mouv.down = create_node();
		if (mouv.down)
		{
			mouv.down->data.dist = (calculus(pos_p[0] + 1,
						pos_p[1], mouv.pos_e));
			mouv.down->data.y = pos_p[0] + 1;
			mouv.down->data.x = pos_p[1];
			if (mouv.p == 0)
			{
				head_main->next = mouv.down;
				mouv.p = 1;
			}
			else
				add_to_list(head_main, mouv.down);
		}
	}
}
