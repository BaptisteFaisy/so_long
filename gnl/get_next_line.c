/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:34:29 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/29 16:24:58 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;
	int				fin;
	static int		end = 0;

	if (end == 1)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	fin = read_and_stash(fd, &stash);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		return (stash = NULL, free(line), NULL);
	}
	if (fin == 1 && stash->content[0] != '\0' && stash->content == NULL)
	{
		free(stash->content);
		free(stash);
		end = 1;
	}
	return (line);
}

int	read_and_stash(int fd, t_list **stash)
{
	char	*buf;
	t_1		storage;

	storage.readed = 1;
	storage.fin = 0;
	while (!found_newline(*stash) && storage.readed != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (0);
		storage.readed = (int)read(fd, buf, BUFFER_SIZE);
		if (storage.readed != BUFFER_SIZE)
			storage.fin = 1;
		if ((*stash == NULL && storage.readed == 0) || storage.readed == -1)
		{
			free(buf);
			return (0);
		}
		buf[storage.readed] = '\0';
		add_to_stash(stash, buf, storage.readed);
		free(buf);
	}
	if (storage.fin == 1)
		return (storage.fin);
	return (0);
}

void	add_to_stash(t_list **stash, char *buf, int readed)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < readed)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = ft_lst_get_last(*stash);
	last->next = new_node;
}

void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	generate_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (stash == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen
					(last->content) - i) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}
