/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balt <balt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:49:13 by soelalou          #+#    #+#             */
/*   Updated: 2024/06/23 16:56:10 by balt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_game *game)
{
	//free_images(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	//free(game->mlx);
	//free(game->player->name);
	//free(game->player);
	//free(game->map->path);
	//free(game->map->name);
	//ft_freetab(game->map->map);
	//free(game->map);
	//free(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	open_window(t_game *game)
{
	game->window = mlx_new_window(game->mlx,
			WIN_SIZE, WIN_SIZE, game->map->name);
	if (!game->window)
		error("An error occured while creating window\n", game);
}
