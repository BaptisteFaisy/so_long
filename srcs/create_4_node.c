/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_4_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:48:02 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/29 17:03:33 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdbool.h>

bool	create_4_node_next1(int *pos_p, char ***str,
			t_list_pos *head_main, t_mouv mouv);
bool	create_4_node_next2(int *pos_p, char ***str,
			t_list_pos *head_main, t_mouv mouv);

bool	create_4_node(int *pos_p, int *pos_e, char ***str,
	t_list_pos *head_main)
{
	t_mouv	mouv;

	mouv.pos_e = pos_e;
	mouv.is_created = false;
	if ((*str)[pos_p[0]][pos_p[1] - 1] != '1' &&
		(*str)[pos_p[0]][pos_p[1] - 1] != '9')
	{
		mouv.is_created = true;
		mouv.left = create_node();
		mouv.left->data.dist = (calculus(pos_p[0], pos_p[1] - 1, mouv.pos_e));
		mouv.left->data.y = pos_p[0];
		mouv.left->data.x = pos_p[1] - 1;
		add_to_list(head_main, mouv.left);
	}
	return (create_4_node_next1(pos_p, str, head_main, mouv));
}

bool	create_4_node_next1(int *pos_p, char ***str,
	t_list_pos *head_main, t_mouv mouv)
{
	if ((*str)[pos_p[0]][pos_p[1] + 1] != '1' &&
		(*str)[pos_p[0]][pos_p[1] + 1] != '9')
	{
		mouv.is_created = true;
		mouv.right = create_node();
		mouv.right->data.dist = (calculus(pos_p[0], pos_p[1] + 1, mouv.pos_e));
		mouv.right->data.y = pos_p[0];
		mouv.right->data.x = pos_p[1] + 1;
		add_to_list(head_main, mouv.right);
	}
	if ((*str)[pos_p[0] - 1][pos_p[1]] != '1' &&
		(*str)[pos_p[0] - 1][pos_p[1]] != '9')
	{
		mouv.is_created = true;
		mouv.up = create_node();
		mouv.up->data.dist = (calculus(pos_p[0] - 1, pos_p[1], mouv.pos_e));
		mouv.up->data.y = pos_p[0] - 1;
		mouv.up->data.x = pos_p[1];
		add_to_list(head_main, mouv.up);
	}
	return (create_4_node_next2(pos_p, str, head_main, mouv));
}

bool	create_4_node_next2(int *pos_p, char ***str,
	t_list_pos *head_main, t_mouv mouv)
{
	if ((*str)[pos_p[0] + 1][pos_p[1]] != '1' &&
		(*str)[pos_p[0] + 1][pos_p[1]] != '9')
	{
		mouv.is_created = true;
		mouv.down = create_node();
		mouv.down->data.y = pos_p[0] + 1;
		mouv.down->data.x = pos_p[1];
		mouv.down->data.dist = (calculus(pos_p[0] + 1, pos_p[1], mouv.pos_e));
		add_to_list(head_main, mouv.down);
	}
	return (mouv.is_created);
}
