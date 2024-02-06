/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:32:36 by bfaisy            #+#    #+#             */
/*   Updated: 2024/02/06 17:48:45 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <stdbool.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

typedef struct s_storage
{
	t_vars	vars;
	t_xy	pos;
	char	**tab;
	int		nbr;
	char	**tab2;
	int		*map;
}	t_storage;

typedef struct s_img
{
	void	*img;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
}	t_img;

typedef struct s_dist
{
	double	dist;
	int		x;
	int		y;
}	t_dist;

typedef struct s_list_pos
{
	t_dist				data;
	struct s_list_pos	*next;
}	t_list_pos;

typedef struct s_mouv
{
	t_list_pos	*left;
	t_list_pos	*right;
	t_list_pos	*up;
	t_list_pos	*down;
	bool		is_created;
	int			*pos_e;
	int			p;
}	t_mouv;

char		**mapwind(t_xy	*wind, char **av);
char		**freetab(char **str);
void		create_img(t_storage stock);
void		put_wall(t_storage stock, int i, int j);
void		put_items(t_storage stock, int i, int j);
void		put_end(t_storage stock, int i, int j);
int			bercheck(char *str);
void		put_character(t_storage stock, int i, int j);
int			check_bord(char **tab);
int			check_main(t_storage stock);
int			check_rect(char **tab);
void		protec_str(char **str);
void		open_fail(void);
void		goto_left(t_storage **stock);
void		goto_right(t_storage **stock);
void		goto_up(t_storage **stock);
void		goto_down(t_storage **stock);
int			strlencustom(char *tab);
void		check_fin(t_storage stock);
int			free_goto(t_storage stock);
void		cpy_utils(char **str, char ***new_str, int i);
char		**create_tab(char **av);
void		protec_str(char **str);
void		up_img(t_storage stock);
int			main_find(char	**str, t_list_pos *head, int *pos_p);
int			goto_min(t_list_pos *head, char **str, int *pos_p);
int			check_if_9_all(t_list_pos *head);
double		calculus(int pos_p0, int pos_p1, int *pos_e);
void		add_to_list(t_list_pos *head, t_list_pos *add);
t_list_pos	*create_node(void);
bool		create_4_node(int *pos_p, int *pos_e, char ***str,
				t_list_pos *head_main);
int			check_items(char **str);
int			*find_items(char **str);
int			main_algo(t_storage stock);
int			*cpy_tab_and_find_chara(char **str);
int			*find_end(char **str);
void		create_4_node_start(int *pos_p, int *pos_e, char **str,
				t_list_pos	*head_main);
int			goto_min_items(t_list_pos *head, t_storage stock, int *pos_p);
char		**replace_9_by_0(char **str);
void		freelist(t_list_pos *head);
t_list_pos	*get_first(t_list_pos *head);
void		ft_free_for_map(t_storage *stock, int p);
int			checkifclose(int *pos_p, char **str);
void		exitfloor(t_storage stock, int fd1, int fd2);

# define SL_X11_EVENT_DESTROY_NOTIFY 17
# define TRUE 1
# define FALSE 0

#endif