/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:50:25 by lloginov          #+#    #+#             */
/*   Updated: 2024/10/16 18:11:35 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../printf/ft_printf.h"
# include "../GNL/get_next_line.h"

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures; // MLX image pointers (on the stack)
	char 		**map;
	int			ligne_len;
	int			nb_ligne;
	int         count;
	int			player_count;
	int			exit_count;
	int			fruit_count;
	int			k;
}	t_data;



//so_long_utils

int			ft_strlen(char *str);
void		define_var(t_data *data);
void		bersing(int ac, char *av1, t_data *data);

//error 
void		free_exit(t_data *data, char *str);

//parsing

void		map_parsing(char *map, t_data *data);
void 		get_map_size(char *av1, int fd, t_data *data);
void 		map_dup(char *av1, int fd, t_data *data);
void 		one_map(t_data *data);
void		pars(t_data *data);

//utilse

char		*ft_strdup(char *s1, char *s2, t_data *data);


#endif