/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:13:19 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/29 16:48:33 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_list_pos	*get_first(t_list_pos *head);

double	calculus(int pos_p0, int pos_p1, int *pos_e)
{
	double	result;

	result = (pos_e[0] - pos_p0) * (pos_e[0] - pos_p0)
		+ (pos_e[1] - pos_p1) * (pos_e[1] - pos_p1);
	return (result);
}

void	add_to_list(t_list_pos *head, t_list_pos *add)
{
	while (head)
	{
		if (head->next && add->data.dist > head->next->data.dist)
			head = head->next;
		else
		{
			if (head->next)
				add->next = head->next;
			else
				add->next = NULL;
			head->next = add;
			break ;
		}
	}
}

int	goto_min_items(t_list_pos *head, char **str, int *pos_p)
{
	t_list_pos	*last;
	int			b;

	last = get_first(head);
	if (str[last->data.y][last->data.x] == 'C')
	{
		b = 1;
	}
	else
		b = 0;
	str[last->data.y][last->data.x] = 'P';
	str[pos_p[0]][pos_p[1]] = '9';
	pos_p[0] = last->data.y;
	pos_p[1] = last->data.x;
	head->next = last->next;
	if (last)
		free(last);
	return (b);
}

t_list_pos	*get_first(t_list_pos *head)
{
	if (head->data.dist == -1)
		head = head->next;
	return (head);
}
