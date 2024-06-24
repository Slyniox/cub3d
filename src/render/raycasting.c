/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balt <balt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:42:35 by balt              #+#    #+#             */
/*   Updated: 2024/06/23 19:19:13 by balt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast(t_game *game)
{
	game->player->x_dir = -1;
	game->player->y = 10.5;
	game->player->x = 8.5;
	game->player->y_dir = 0;
	game->player->x_plane = 0;
	game->player->y_plane = 0.66;
}

void	raycast(t_game *game)
{
	double	x_camera;
	double	dir_xRay;
	double	dir_yRay;
	double	dist_toXside;
	double	dist_toYside;
	double	deltaX;
	double	deltaY;
	int	stepX;
	int stepY;
	int	x;
	int x_case;
	int	y_case;
	int	wall;
	int	dist_to_wall;
	int	wallheight;
	int	direction;
	int	start_draw;
	int	end_draw;

	x = -1;
	wall = 0;
	init_raycast(game);
	printf("player pos : [%f, %f] \n", game->player->x, game->player->y);
	while (++x < WIN_SIZE)
	{
		x_camera = 2 * x / (double) WIN_SIZE - 1;
		dir_xRay = game->player->x_dir + game->player->x_plane * x_camera;
		dir_yRay = game->player->y_dir + game->player->y_plane * x_camera;
		x_case = (int) game->player->x;
		y_case = (int) game->player->y;
		deltaX = fabs(1 / dir_xRay);
		deltaY = fabs(1 / dir_yRay);
		if (dir_xRay < 0)
		{
			stepX = -1;
			dist_toXside = (game->player->x - x_case) * deltaX;
		}
		else
		{
			stepY = 1;
			dist_toYside = (y_case + 1 - game->player->y) * deltaX;
		}
		if (dir_yRay < 0)
		{
			stepY = -1;
			dist_toYside = (game->player->y - y_case) * deltaY;
		}
		else
		{
			stepY = 1;
			dist_toYside = (y_case + 1 - game->player->y) * deltaY;
		}
		while (wall == 0)
		{
			if (dist_toXside < dist_toYside)
			{
				dist_toXside += deltaX;
				x_case += stepX;
				direction = 0;
			}
			else
			{
				dist_toYside += deltaY;
				y_case += stepY;
				direction = 1;
			}
			if (game->map->map[x_case][y_case] == '1')
				wall = 1;
		}
		if (direction == 0)
			dist_to_wall = (dist_toXside - deltaX);
		else
			dist_to_wall = (dist_toYside - deltaY);
		wallheight = (int)(WIN_SIZE / (dist_to_wall + 1));
		start_draw = -wallheight / 2 + WIN_SIZE / 2;
		if (start_draw < 0)
			start_draw = 0;
		end_draw = wallheight / 2 + WIN_SIZE / 2;
		if (end_draw >= WIN_SIZE)
			end_draw = WIN_SIZE - 1;
	}
	int color = 0xFFFFFF;

	for(int y = 0; y < 640; y++)
	for(int x = 0; x < 640; x++)
	{
		game->map->img.addr[(y * game->map->img.line_length) + x] = color;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->map->img.img, 0, 0);
	//mlx_destroy_image(game->mlx, game->map->img.img);
}
