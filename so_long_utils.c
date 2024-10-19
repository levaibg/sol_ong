/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:53:59 by lloginov          #+#    #+#             */
/*   Updated: 2024/10/18 19:12:33 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bersing(int ac, char *av1, t_data *data)
{
	int len;
	if(ac != 2)
		free_exit(&data, "Wrong number of argumets\n");
	
	len = ft_strlen(av1);
	if (av1[len - 1] == 'r' && av1[len - 2] == 'e' && av1[len - 3] == 'b'
		&& av1[len - 4] == '.')
		free_exit(&data, "Map no good\n");
	exit(1);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if(!str)
		return(i);
	while(str[i])
		i++;
	return(i);
}

void	define_var(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->textures =NULL;
	data->map = NULL;
	data->ligne_len = 0;
	data->nb_ligne = 0;
	data->count = 0;
	data->exit_count = 0;
	data->fruit_count = 0;
	data->player_count = 0;
	data->k = 1;
	data->Player_y_pos = 0;
	data->Player_x_pos = 0;
	data->map2 = NULL;
}