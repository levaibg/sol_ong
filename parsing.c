/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:24:32 by lloginov          #+#    #+#             */
/*   Updated: 2024/10/16 18:18:55 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_parsing(char *av1, t_data *data)
{
	int fd;

	fd = open(av1, O_RDONLY);
	if (fd < 0)
		free_exit(&data, "Error : invalid fd");
	get_map_size(av1, fd, data);
	data->map = malloc(sizeof(char *) * (data->nb_ligne));
	map_dup(av1, fd, &data);
	one_map(&data);
}
void get_map_size(char *av1, int fd, t_data *data)
{
	int i;
	char *ligne;

	i = 0;
	ligne = NULL;
	while (1)
	{
		ligne = get_next_line(fd);
		if (!ligne)
			break;
		if (i == 0)
			data->ligne_len = ft_strlen(ligne);
		if (ft_strlen(ligne) != data->ligne_len)
			free_exit(data, "Error : diff line size\n");
		i = 1;
		data->nb_ligne++;
		free(ligne);
	}
	close(fd);
}

void map_dup(char *av1, int fd, t_data *data)
{
	char *ligne;
	int i;

	i = 0;
	ligne = NULL;

	while (i <= data->nb_ligne)
	{
		ligne = get_next_line(ligne);
		data->map[i] = ft_strdup(data->map[i], ligne, data);
		i++;
	}
}

void one_map(t_data *data)
{
	int i;
	int j;

	j = 0;
	while (j <= data->nb_ligne)
	{
		i = 0;
		if (j == 0 || j == data->nb_ligne - 1)
		{
			while (data->map[i])
			{
				if (data->map[i] != '1' || data->map[i] != '\n')
					free_exit(&data, "Error : Wrong map bordure(up/down)\n");
				i++;
			}
		}
		else if (data->map[0] != '1' || data->map[data->ligne_len - 1] != '1')
			free_exit(&data, "Error :Wrong map bordure (sides)\n");
		j++;
	}
}

void pars(t_data *data)
{
	int i;

	while (data->k < data->nb_ligne)
	{
		i = 1;
		if (data->k >= 1 || data->k <= data->nb_ligne - 2)
		{
			while (data->map[i])
			{
				if (data->map[i] == 'P')
					data->player_count++;
				else if (data->map[i] == 'C')
					data->fruit_count++;
				else if (data->map[i] == 'E')
					data->exit_count++;
				else if (data->map[i] != '0')
					free_exit(&data, "Error : Not enought '0' \n");
				i++;
			}
		}
		data->k++;
	}
	if (data->player_count != 1 || data->exit_count != 1 || data->fruit_count < 1)
		free_exit(&data, "Error : CPE problem ! \n");
}
