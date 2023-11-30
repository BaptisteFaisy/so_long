/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:45:05 by bfaisy            #+#    #+#             */
/*   Updated: 2023/11/30 16:01:02 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_l
{
	int	readed;
	int	fin;
}	t_1;
char	*get_next_line(int fd);
int		found_newline(t_list *stash);
t_list	*ft_lst_get_last(t_list *stash);
int		read_and_stash(int fd, t_list **stash);
void	add_to_stash(t_list **stash, char *buf, int readed);
void	extract_line(t_list *stash, char **line);
void	generate_line(char **line, t_list *stash);
void	clean_stash(t_list **stash);
int		ft_strlen(const char *str);
void	free_stash(t_list *stash);

#endif