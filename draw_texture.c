/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture->c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student->42->fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:31:38 by truby             #+#    #+#             */
/*   Updated: 2021/04/02 20:15:06 by truby            ###   ########->fr       */
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

void	draw_texture(t_param *param, t_lod *ld, t_data *data)
{
  	int		y;
  	int		x = -1;

	ld->time = 10;
	ld->oldtime = 0;
    while (++x < param->rx)
    {
      	ld->camx = 2 * x / (double)param->rx - 1;
      	ld->raydirx = param->viewx + param->plane_x * ld->camx;
      	ld->raydiry = param->viewy + param->plane_y * ld->camx;
      	ld->mapx = param->player_x;
      	ld->mapy = param->player_y;
		ld->deltadistx = deltadist(ld->raydiry, ld->raydirx);
    	ld->deltadisty = deltadist(ld->raydirx, ld->raydiry);
      	ld->hit = 0;
      	if(ld->raydirx < 0)
      	{
        	ld->stepx = -1;
        	ld->sidedistx = (param->player_x - ld->mapx) * ld->deltadistx;
      	}
      	else
      	{
        	ld->stepx = 1;
        	ld->sidedistx = (ld->mapx + 1.0 - param->player_x) * ld->deltadistx;
      	}
      	if(ld->raydiry < 0)
      	{
        	ld->stepy = -1;
        	ld->sidedisty = (param->player_y - ld->mapy) * ld->deltadisty;
      	}
      	else
      	{
        	ld->stepy = 1;
        	ld->sidedisty = (ld->mapy + 1.0 - param->player_y) * ld->deltadisty;
      	}
      	while (ld->hit == 0)
      	{
        	if (ld->sidedistx < ld->sidedisty)
        	{
        		ld->sidedistx += ld->deltadistx;
        		ld->mapx += ld->stepx;
        		ld->side = 0;
        	}
        	else
        	{
        		ld->sidedisty += ld->deltadisty;
        		ld->mapy += ld->stepy;
        		ld->side = 1;
        	}
        	if (param->map[ld->mapy][ld->mapx] == '1'
				|| param->map[ld->mapy][ld->mapx] == '2')
				ld->hit = 1;
      	}
      	if (ld->side == 0)
			ld->perpwalldist = (ld->mapx - param->player_x + (1 - ld->stepx) / 2) / ld->raydirx;
      	else
	  		ld->perpwalldist = (ld->mapy - param->player_y + (1 - ld->stepy) / 2) / ld->raydiry;
      	ld->lineheight = (int)(param->ry / ld->perpwalldist);
      	ld->drawstart = -ld->lineheight / 2 + param->ry / 2;
      	if (ld->drawstart < 0)
	  		ld->drawstart = 0;
      	ld->drawend = ld->lineheight / 2 + param->ry / 2;
      	if (ld->drawend >= param->ry)
	  		ld->drawend = param->ry;
	// 	double wallX;
	// 	if (side == 0)
	// 		wallX = param->player_y + perpWallDist * rayDirY;
    //   	else
	// 		wallX = param->player_x + perpWallDist * rayDirX;
    //   	wallX -= floor(wallX);
	// 	int texX = (int)(wallX * (double)texWidth);
    //   	if (side == 0 && rayDirX > 0)
	// 		texX = texWidth - texX - 1;
    //   	if (side == 1 && rayDirY < 0)
	// 		texX = texWidth - texX - 1;
    // 	double step = 1->0 * texHeight / lineHeight;
    // 	double texPos = (drawStart - param->ry / 2 + lineHeight / 2) * step;
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
		y = ld->drawstart - 1;
		while (++y < ld->drawend)
			my_mlx_pixel_put(data, x, y, 0xF000FF);
	}
    //timing for input and FPS counter
    // oldTime = time;
    // time = getTicks();
    ld->frametime = (ld->time - ld->oldtime) / 1000.0;
    ld->movespeed = ld->frametime * 5.0;
    ld->rotspeed = ld->frametime * 3.0;
    if (data->key.up)
    {
		if (param->map[(int)param->player_y][(int)(param->player_x + param->viewx * ld->movespeed)] != '1'
			&& param->map[(int)param->player_y][(int)(param->player_x + param->viewx * ld->movespeed)] != '2')
	  		param->player_x += param->viewx * ld->movespeed;
    	if (param->map[(int)(param->player_y + param->viewy * ld->movespeed)][(int)param->player_x] != '1'
			&& param->map[(int)(param->player_y + param->viewy * ld->movespeed)][(int)param->player_x] != '2')
	  		param->player_y += param->viewy * ld->movespeed;
    }
    if (data->key.down)
    {
		if (param->map[(int)param->player_y][(int)(param->player_x - param->viewx * ld->movespeed)] != '1'
			&& param->map[(int)param->player_y][(int)(param->player_x - param->viewx * ld->movespeed)] != '2')
	  		param->player_x -= param->viewx * ld->movespeed;
    	if (param->map[(int)(param->player_y - param->viewy * ld->movespeed)][(int)param->player_x] != '1'
			&& param->map[(int)(param->player_y - param->viewy * ld->movespeed)][(int)param->player_x] != '2')
	  		param->player_y -= param->viewy * ld->movespeed;
    }
	if (data->key.right)
	{
		if (param->map[(int)(param->player_y + param->viewx * ld->movespeed)][(int)param->player_x] != '1'
			&& param->map[(int)(param->player_y + param->viewx * ld->movespeed)][(int)param->player_x] != '2')
			param->player_y += param->viewx * ld->movespeed;
		if (param->map[(int)param->player_y][(int)(param->player_x - param->viewy * ld->movespeed)] != '1'
			&& param->map[(int)param->player_y][(int)(param->player_x - param->viewy * ld->movespeed)] != '2')
	  		param->player_x -= param->viewy * ld->movespeed;
	}
	if (data->key.left)
	{
		if (param->map[(int)(param->player_y - param->viewx * ld->movespeed)][(int)param->player_x] != '1'
			&& param->map[(int)(param->player_y - param->viewx * ld->movespeed)][(int)param->player_x] != '2')
	  		param->player_y -= param->viewx * ld->movespeed;
    	if (param->map[(int)param->player_y][(int)(param->player_x + param->viewy * ld->movespeed)] != '1'
			&& param->map[(int)param->player_y][(int)(param->player_x + param->viewy * ld->movespeed)] != '2')
	  		param->player_x += param->viewy * ld->movespeed;
	}
    if (data->key.camleft)
    {
      double oldDirX = param->viewx;
      param->viewx = param->viewx * cos(-ld->rotspeed) - param->viewy * sin(-ld->rotspeed);
      param->viewy = oldDirX * sin(-ld->rotspeed) + param->viewy * cos(-ld->rotspeed);
      double oldPlaneX = param->plane_x;
      param->plane_x = param->plane_x * cos(-ld->rotspeed) - param->plane_y * sin(-ld->rotspeed);
      param->plane_y = oldPlaneX * sin(-ld->rotspeed) + param->plane_y * cos(-ld->rotspeed);
    }
    if (data->key.camright)
    {
      double oldDirX = param->viewx;
      param->viewx = param->viewx * cos(ld->rotspeed) - param->viewy * sin(ld->rotspeed);
      param->viewy = oldDirX * sin(ld->rotspeed) + param->viewy * cos(ld->rotspeed);
      double oldPlaneX = param->plane_x;
      param->plane_x = param->plane_x * cos(ld->rotspeed) - param->plane_y * sin(ld->rotspeed);
      param->plane_y = oldPlaneX * sin(ld->rotspeed) + param->plane_y * cos(ld->rotspeed);
    }
}