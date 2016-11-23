/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 08:33:02 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/23 08:52:04 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		zoom(t_mlx *mlx, int key, int x, int y)
{
	if (key == 4 || key == 69)
	{
		mlx->img.zoom *= 1.1;
		mlx->fractal.x += ((float)x - W / 2) / mlx->img.zoom / 10;
		mlx->fractal.y += ((float)y - H / 2) / mlx->img.zoom / 10;
		mlx->fractal.i_max += (mlx->img.zoom > W / 5) ? 1 : 0;
	}
	else if (key == 5 || key == 78)
	{
		mlx->img.zoom *= 0.9;
		mlx->fractal.x -= ((float)x - W / 2) / mlx->img.zoom / 10;
		mlx->fractal.y -= ((float)y - H / 2) / mlx->img.zoom / 10;
		mlx->fractal.i_max -= (mlx->fractal.i_max > I_MAX) ? 1 : 0;
	}
}

int			mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->win.mouse_x = mlx->fractal.pause ? mlx->win.mouse_x : (x - W / 2);
	mlx->win.mouse_y = mlx->fractal.pause ? mlx->win.mouse_x : (y - H / 2);
	return (1);
}

int			mouse_hook(int key, int x, int y, t_mlx *mlx)
{
	if (x && y && (key == 4 || key == 5))
		zoom(mlx, key, x, y);
	return (1);
}
