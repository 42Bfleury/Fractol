/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 09:57:45 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/23 07:44:11 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	move(t_mlx *mlx, int key)
{
	if (key == 123)
		mlx->fractal.x += 10 / mlx->img.zoom;
	else if (key == 124)
		mlx->fractal.x -= 10 / mlx->img.zoom;
	else if (key == 125)
		mlx->fractal.y -= 10 / mlx->img.zoom;
	else if (key == 126)
		mlx->fractal.y += 10 / mlx->img.zoom;
}

static void	iteration(t_mlx *mlx, int key)
{
	if (key == 69)
		mlx->fractal.i_max++;
	else if (key == 78 && mlx->fractal.i > 1)
		mlx->fractal.i_max--;
}

void		zoom(t_mlx *mlx, int key, int x, int y)
{
	if (key == 4)
	{
		mlx->img.zoom *= 1.1;
		mlx->fractal.x += ((float)x - W / 2) / mlx->img.zoom / 10;
		mlx->fractal.y += ((float)y - H / 2) / mlx->img.zoom / 10;
		mlx->fractal.i_max += (mlx->img.zoom > W / 5) ? 1 : 0;
	}
	else if (key == 5)
	{
		mlx->img.zoom *= 0.9;
		mlx->fractal.x -= ((float)x - W / 2) / mlx->img.zoom / 10;
		mlx->fractal.y -= ((float)y - H / 2) / mlx->img.zoom / 10;
		mlx->fractal.i_max -= (mlx->fractal.i_max > I_MAX) ? 1 : 0;
	}
}

int			key_hook(int key, t_mlx *mlx)
{
	if (key == 53)
		quit(mlx);
	else if (key == 69 || key == 78)
		iteration(mlx, key);
	else if (key == 49)
		init_fractal(mlx, mlx->fractal.choice);
	else if (key >= 123 && key <= 126)
		move(mlx, key);
	return (1);
}

int			mouse_hook(int key, int x, int y, t_mlx *mlx)
{
	if (x && y && (key == 4 || key == 5))
		zoom(mlx, key, x, y);
	return (0);
}
