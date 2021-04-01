/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:31:38 by truby             #+#    #+#             */
/*   Updated: 2021/04/01 18:58:21 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define texWidth 64
#define texHeight 64

static double	deltadist(double rayone, double raytwo)
{
	if (rayone == 0)
		return (0);
	else
	{
		if (raytwo == 0)
			return (1);
		else
			return (fabs(1 / raytwo));
	}
}

void	draw_texture(t_data *data)
{
  	int		y;
  	int		x = -1;

	double time = 10;
	double oldTime = 0;
    while (++x < data->param.rx)
    {
      	double cameraX = 2 * x / (double)data->param.rx - 1;
      	double rayDirX = data->param.viewx + data->param.plane_x * cameraX;
      	double rayDirY = data->param.viewy + data->param.plane_y * cameraX;
      	int mapX = data->param.player_x;
      	int mapY = data->param.player_y;
      	double sideDistX;
      	double sideDistY;
		// double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
    	// double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));
		double deltaDistX = deltadist(rayDirY, rayDirX);
    	double deltaDistY = deltadist(rayDirX, rayDirY);
      	double perpWallDist;
      	int stepX;
      	int stepY;
      	int hit = 0;
      	int side;
      	if(rayDirX < 0)
      	{
        	stepX = -1;
        	sideDistX = (data->param.player_x - mapX) * deltaDistX;
      	}
      	else
      	{
        	stepX = 1;
        	sideDistX = (mapX + 1.0 - data->param.player_x) * deltaDistX;
      	}
      	if(rayDirY < 0)
      	{
        	stepY = -1;
        	sideDistY = (data->param.player_y - mapY) * deltaDistY;
      	}
      	else
      	{
        	stepY = 1;
        	sideDistY = (mapY + 1.0 - data->param.player_y) * deltaDistY;
      	}
      	while (hit == 0)
      	{
        	if (sideDistX < sideDistY)
        	{
        		sideDistX += deltaDistX;
        		mapX += stepX;
        		side = 0;
        	}
        	else
        	{
        		sideDistY += deltaDistY;
        		mapY += stepY;
        		side = 1;
        	}
        	if (data->param.map[mapY][mapX] == '1')
				hit = 1;
      	}
      	if (side == 0)
			perpWallDist = (mapX - data->param.player_x + (1 - stepX) / 2) / rayDirX;
      	else
	  		perpWallDist = (mapY - data->param.player_y + (1 - stepY) / 2) / rayDirY;
      	double lineHeight = (int)(data->param.ry / perpWallDist);
      	int drawStart = -lineHeight / 2 + data->param.ry / 2;
      	if (drawStart < 0)
	  		drawStart = 0;
      	int drawEnd = lineHeight / 2 + data->param.ry / 2;
      	if (drawEnd >= data->param.ry)
	  		drawEnd = data->param.ry;
	// 	double wallX;
	// 	if (side == 0)
	// 		wallX = data->param.player_y + perpWallDist * rayDirY;
    //   	else
	// 		wallX = data->param.player_x + perpWallDist * rayDirX;
    //   	wallX -= floor(wallX);
	// 	int texX = (int)(wallX * (double)texWidth);
    //   	if (side == 0 && rayDirX > 0)
	// 		texX = texWidth - texX - 1;
    //   	if (side == 1 && rayDirY < 0)
	// 		texX = texWidth - texX - 1;
    // 	double step = 1.0 * texHeight / lineHeight;
    // 	double texPos = (drawStart - data->param.ry / 2 + lineHeight / 2) * step;
	// 	y = drawStart - 1;
	// 	while (++y < drawEnd)
    //   	{
    //     	// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
    //     	int texY = (int)texPos & (texHeight - 1);
    //     	texPos += step;
    //     	// int color = texture[texNum][texHeight * texY + texX];
    //     	//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
    //     	if (side == 1)
	// 			color = (color >> 1) & 8355711;
    //     	// buffer[y][x] = color;
    //   	}
    // }
		y = drawStart - 1;
		while (++y < drawEnd)
			my_mlx_pixel_put(data, x, y, 0xF000FF);
	}
    //timing for input and FPS counter
    // oldTime = time;
    // time = getTicks();
    double frameTime = (time - oldTime) / 1000.0;
    double moveSpeed = frameTime * 5.0;
    double rotSpeed = frameTime * 3.0;
    if (data->key.up)
    {
		if (data->param.map[(int)data->param.player_y][(int)(data->param.player_x + data->param.viewx * moveSpeed)] == '0')
	  		data->param.player_x += data->param.viewx * moveSpeed;
    	if (data->param.map[(int)(data->param.player_y + data->param.viewy * moveSpeed)][(int)data->param.player_x] == '0')
	  		data->param.player_y += data->param.viewy * moveSpeed;
    }
    if (data->key.down)
    {
		if (data->param.map[(int)data->param.player_y][(int)(data->param.player_x - data->param.viewx * moveSpeed)] == '0')
	  		data->param.player_x -= data->param.viewx * moveSpeed;
    	if (data->param.map[(int)(data->param.player_y - data->param.viewy * moveSpeed)][(int)data->param.player_x] == '0')
	  		data->param.player_y -= data->param.viewy * moveSpeed;
    }
	if (data->key.right)
	{
		if (data->param.map[(int)(data->param.player_y + data->param.viewx * moveSpeed)][(int)data->param.player_x] == '0')
			data->param.player_y += data->param.viewx * moveSpeed;
		if (data->param.map[(int)data->param.player_y][(int)(data->param.player_x - data->param.viewy * moveSpeed)] == '0')
	  		data->param.player_x -= data->param.viewy * moveSpeed;
	}
	if (data->key.left)
	{
		if (data->param.map[(int)(data->param.player_y - data->param.viewx * moveSpeed)][(int)data->param.player_x] == '0')
	  		data->param.player_y -= data->param.viewx * moveSpeed;
    	if (data->param.map[(int)data->param.player_y][(int)(data->param.player_x + data->param.viewy * moveSpeed)] == '0')
	  		data->param.player_x += data->param.viewy * moveSpeed;
	}
    if (data->key.camleft)
    {
      double oldDirX = data->param.viewx;
      data->param.viewx = data->param.viewx * cos(-rotSpeed) - data->param.viewy * sin(-rotSpeed);
      data->param.viewy = oldDirX * sin(-rotSpeed) + data->param.viewy * cos(-rotSpeed);
      double oldPlaneX = data->param.plane_x;
      data->param.plane_x = data->param.plane_x * cos(-rotSpeed) - data->param.plane_y * sin(-rotSpeed);
      data->param.plane_y = oldPlaneX * sin(-rotSpeed) + data->param.plane_y * cos(-rotSpeed);
    }
    if (data->key.camright)
    {
      double oldDirX = data->param.viewx;
      data->param.viewx = data->param.viewx * cos(rotSpeed) - data->param.viewy * sin(rotSpeed);
      data->param.viewy = oldDirX * sin(rotSpeed) + data->param.viewy * cos(rotSpeed);
      double oldPlaneX = data->param.plane_x;
      data->param.plane_x = data->param.plane_x * cos(rotSpeed) - data->param.plane_y * sin(rotSpeed);
      data->param.plane_y = oldPlaneX * sin(rotSpeed) + data->param.plane_y * cos(rotSpeed);
    }
}