/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:05:29 by lloginov          #+#    #+#             */
/*   Updated: 2024/10/16 18:18:55 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_exit(t_data *data, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_printf("%s\n",str);
	while(data->map[j])
	{
		free(data->map);
	}

	exit(1);	
}