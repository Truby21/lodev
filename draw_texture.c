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

static void sortsprites(int* order, double* dist, int amount)
{
  std::vector<std::pair<double, int>> sprites(amount);
  for(int i = 0; i < amount; i++) {
    sprites[i].first = dist[i];
    sprites[i].second = order[i];
  }
  std::sort(sprites.begin(), sprites.end());
  // restore in reverse order to go from farthest to nearest
  for(int i = 0; i < amount; i++) {
    dist[i] = sprites[amount - i - 1].first;
    order[i] = sprites[amount - i - 1].second;
  }
}

void	draw_texture(t_param *param, t_lod *ld, t_data *data)
{
  	int		y;
  	int		x = -1;
	double 	ZBuffer[data->param.rx];

	ld->time = 15;
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
		if (ld->side == 0)
			ld->wallx = param->player_y + ld->perpwalldist * ld->raydiry;
    	else
			ld->wallx = param->player_x + ld->perpwalldist * ld->raydirx;
    	ld->wallx -= floor(ld->wallx);
		ld->texx = (int)(ld->wallx * (double)texWidth);
      	if (ld->side == 0 && ld->raydirx > 0)
			ld->texx = texWidth - ld->texx - 1;
      	if (ld->side == 1 && ld->raydiry < 0)
			ld->texx = texWidth - ld->texx - 1;
    	ld->step = 1.0 * texHeight / ld->lineheight;
    	ld->texpos = (ld->drawstart - param->ry / 2 + ld->lineheight / 2) * ld->step;
		y = ld->drawstart - 1;
		while (++y < ld->drawend)
		{
			if (ld->side == 0 && ld->stepx > 0)
				data->txtr[4] = data->txtr[3];
			else if (ld->side == 0 && ld->stepx < 0)
				data->txtr[4] = data->txtr[2];
			else if (ld->side == 1 && ld->stepy < 0)
				data->txtr[4] = data->txtr[0];
			else if (ld->side == 1 && ld->stepy > 0)
				data->txtr[4] = data->txtr[1];
			ld->texy = (int)ld->texpos & (texHeight - 1);
        	ld->texpos += ld->step;
			unsigned int *color = pixel_take(&data->txtr[4], ld->texy, ld->texx);
			pixel_put(data, x, y, (int)*color);
		}
	}
	//  S  P  R  I  T  E  S
	//sort sprites from far to close
    for(int i = 0; i < numSprites; i++)
    {
      spriteOrder[i] = i;
      spriteDistance[i] = ((data->param.player_x - sprite[i].x) * (data->param.player_x - sprite[i].x) + (data->param.player_y - sprite[i].y) * (data->param.player_y - sprite[i].y)); //sqrt not taken, unneeded
    }
    sortsprites(spriteOrder, spriteDistance, numSprites);

    //after sorting the sprites, do the projection and draw them
    for(int i = 0; i < numSprites; i++)
    {
      //translate sprite position to relative to camera
      double spriteX = sprite[spriteOrder[i]].x - data->param.player_x;
      double spriteY = sprite[spriteOrder[i]].y - data->param.player_y;

      //transform sprite with the inverse camera matrix
      // [ planeX   dirX ] -1                                       [ dirY      -dirX ]
      // [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
      // [ planeY   dirY ]                                          [ -planeY  planeX ]

      double invDet = 1.0 / (planeX * dirY - dirX * planeY); //required for correct matrix multiplication

      double transformX = invDet * (dirY * spriteX - dirX * spriteY);
      double transformY = invDet * (-planeY * spriteX + planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])

      int spriteScreenX = int((w / 2) * (1 + transformX / transformY));

      //parameters for scaling and moving the sprites
      #define uDiv 1
      #define vDiv 1
      #define vMove 0.0
      int vMoveScreen = int(vMove / transformY);

      //calculate height of the sprite on screen
      int spriteHeight = abs(int(h / (transformY))) / vDiv; //using "transformY" instead of the real distance prevents fisheye
      //calculate lowest and highest pixel to fill in current stripe
      int drawStartY = -spriteHeight / 2 + h / 2 + vMoveScreen;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + h / 2 + vMoveScreen;
      if(drawEndY >= h) drawEndY = h - 1;

      //calculate width of the sprite
      int spriteWidth = abs( int (h / (transformY))) / uDiv;
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= w) drawEndX = w - 1;

      //loop through every vertical stripe of the sprite on screen
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        int texX = int(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) it's on the screen (left)
        //3) it's on the screen (right)
        //4) ZBuffer, with perpendicular distance
        if(transformY > 0 && stripe > 0 && stripe < w && transformY < ZBuffer[stripe])
        for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
        {
          int d = (y-vMoveScreen) * 256 - h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
          int texY = ((d * texHeight) / spriteHeight) / 256;
          Uint32 color = texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
          if((color & 0x00FFFFFF) != 0) buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
        }
      }
    }
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