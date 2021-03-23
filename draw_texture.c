/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:31:38 by truby             #+#    #+#             */
/*   Updated: 2021/03/23 19:11:49 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_texture(t_data *data)
{
 	// double posX = 22, posY = 12;  //x and y start position   							//положение игрока
  	// double dirX = 1, dirY = 0; //initial direction vector							//направление взгляда
  	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane 		//поле зрения
  	int		w = 1920;
  	int		h = 1080;
  	int		y;
  	int		x = -1;

	double time = 5; //time of current frame
	double oldTime = 0; //time of previous frame
    while (++x < w)
    {
      	//calculate ray position and direction
      	double cameraX = 2 * x / (double)w - 1; 				//x-coordinate in camera space	//средний х
      	double rayDirX = data->param.viewx + planeX * cameraX;									//направление луча по х
      	double rayDirY = data->param.viewy + planeY * cameraX;									//направление луча по у
      	//which box of the map we're in
      	int mapX = data->param.plx;														//константа с положением игрока по х
      	int mapY = data->param.ply;														//константа с положением игрока по у
      	//length of ray from current position to next x or y-side
      	double sideDistX;															//расстояние до ближайшего пересечения по х
      	double sideDistY;															//расстояние до ближайшего пересечения по у
       	//length of ray from one x or y-side to next x or y-side
		double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
    	double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));
    	//   double deltaDistX = fabs(1 / rayDirX);									//шаг до следующей клетки по х
    	//   double deltaDistY = fabs(1 / rayDirY);									//шаг до следующей клетки по у
      	double perpWallDist;
      	//what direction to step in x or y-direction (either +1 or -1)
      	int stepX;
      	int stepY;
      	int hit = 0; //was there a wall hit?										//флаг удара
      	int side; //was a NS or a EW wall hit?									//в какую сторону был удар
      	//calculate step and initial sideDist
      	if(rayDirX < 0)
      	{
        	stepX = -1;
        	sideDistX = (data->param.plx - mapX) * deltaDistX;
      	}
      	else
      	{
        	stepX = 1;
        	sideDistX = (mapX + 1.0 - data->param.plx) * deltaDistX;
      	}
      	if(rayDirY < 0)
      	{
        	stepY = -1;
        	sideDistY = (data->param.ply - mapY) * deltaDistY;
      	}
      	else
      	{
        	stepY = 1;
        	sideDistY = (mapY + 1.0 - data->param.ply) * deltaDistY;
      	}
      	//perform DDA
      	while (hit == 0)
      	{
        //jump to next map square, OR in x-direction, OR in y-direction
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
        //Check if ray has hit a wall

        	if (data->param.map[mapY][mapX] == '1')
				hit = 1;
      	}
      	//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      	if (side == 0)
			perpWallDist = (mapX - data->param.plx + (1 - stepX) / 2) / rayDirX;		//расстояние до стены
      	else
	  		perpWallDist = (mapY - data->param.ply + (1 - stepY) / 2) / rayDirY;
      	//Calculate height of line to draw on screen
      	double lineHeight = (int)(h / perpWallDist);										//высота стены
      	//calculate lowest and highest pixel to fill in current stripe
      	int drawStart = -lineHeight / 2 + h / 2;										//самый низкий и самый высокий пиксель
      	if(drawStart < 0)
	  		drawStart = 0;
      	int drawEnd = lineHeight / 2 + h / 2;											//самый низкий и самый высокий пиксель
      	if(drawEnd >= h)
	  		drawEnd = h;
		//choose wall color
    	//   ColorRGB color;
    	//   switch(worldMap[mapX][mapY])
    	//   {
    	//     case 1:  color = RGB_Red;    break; //red
    	//     case 2:  color = RGB_Green;  break; //green
    	//     case 3:  color = RGB_Blue;   break; //blue
    	//     case 4:  color = RGB_White;  break; //white
    	//     default: color = RGB_Yellow; break; //yellow
    	//   }
      	//give x and y sides different brightness
      	//draw the pixels of the stripe as a vertical line
	  	y = drawStart - 1;
	  	while (++y < drawEnd)
			my_mlx_pixel_put(data, x, y, 0x11AAAA);										//рисуем стены
	} 
    //timing for input and FPS counter
    // oldTime = time;
    // time = getTicks();
    double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    // print(1.0 / frameTime); //FPS counter
    // redraw();
    // cls();
    // //speed modifiers
    double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
    if(data->key.up)			//move forward if no wall in front of you
    {
      if(data->param.map[(int)(data->param.plx + data->param.viewx * moveSpeed)][(int)data->param.plx] == '0')
	  	data->param.plx += data->param.viewx * moveSpeed;
      if(data->param.map[(int)data->param.plx][(int)(data->param.ply + data->param.viewy * moveSpeed)] == '0')
	  	data->param.ply += data->param.viewy * moveSpeed;
    }
    if(data->key.down)		//move backwards if no wall behind you
    {
      if(data->param.map[(int)(data->param.plx - data->param.viewx * moveSpeed)][(int)data->param.ply] == '0')
	  	data->param.plx -= data->param.viewx * moveSpeed;
      if(data->param.map[(int)data->param.plx][(int)(data->param.ply - data->param.viewy * moveSpeed)] == '0')
	  	data->param.ply -= data->param.viewy * moveSpeed;
    }
	// if(data->key.left)
	// {
	// 	if(data->param.map[][] == '0')

	// 	if(data->param.map[][] == '0')

	// }
	// if(data->key.right)
	// {
	// 	if(data->param.map[][] == '0')

	// 	if(data->param.map[][] == '0')

	// }
    if (data->key.camright)		//rotate to the right
    {
      double oldDirX = data->param.viewx;
      data->param.viewx = data->param.viewx * cos(-rotSpeed) - data->param.viewy * sin(-rotSpeed);
      data->param.viewy = oldDirX * sin(-rotSpeed) + data->param.viewy * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    if (data->key.camleft)		//rotate to the left
    {
      double oldDirX = data->param.viewx;
      data->param.viewx = data->param.viewx * cos(rotSpeed) - data->param.viewy * sin(rotSpeed);
      data->param.viewy = oldDirX * sin(rotSpeed) + data->param.viewy * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
}