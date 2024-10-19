/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:38:31 by lloginov          #+#    #+#             */
/*   Updated: 2024/10/19 19:11:09 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	Player_pos(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(data->map[j])
	{
		j = 0;
		while(data->map[j][i])
		{
			if(data->map[j][i] == 'P')
			{
				data->Player_y_pos = j;
				data->Player_x_pos = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
void	reset_var(t_data *data)
{
	data->exit_count = 0;
	data->fruit_count = 0;
	data->map2 = data->map;
}

void	flouffille(t_data *data, int x, int y)
{
	if(data->map2[data->Player_y_pos][data->Player_x_pos] == 'P'  || 
		(data->map2[data->Player_y_pos][data->Player_x_pos] == 'C'))
		data->map2[data->Player_y_pos][data->Player_x_pos] == 'X';
	if(data->map2[data->Player_y_pos][data->Player_x_pos] == 'E')
		data->map2[data->Player_y_pos][data->Player_x_pos] == '1';
	if(data->map2[data->Player_y_pos][data->Player_x_pos] == '1' || 
		data->map2[data->Player_y_pos][data->Player_x_pos] == 'X')
		return ;
	data->map2[data->Player_y_pos][data->Player_x_pos] == 'X'; 
	flouffille(&data, data->Player_y_pos, data->Player_x_pos + 1);
	flouffille(&data, data->Player_y_pos, data->Player_x_pos - 1);
	flouffille(&data, data->Player_y_pos + 1, data->Player_x_pos);
	flouffille(&data, data->Player_y_pos - 1, data->Player_x_pos);
	
}

void	apcmp(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->nb_ligne)
	{
		i = 0;
		while (data->map2[j][i])
		{
			if (data->map2[j][i] == 'C' || data->map2[j][i] == 'E')
			{
				ft_freexit(data, "Error : unplayable map \n");
			}
			i++;
		}
		j++;
	}
}