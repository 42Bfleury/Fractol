/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 09:57:45 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/23 09:01:33 by bfleury          ###   ########.fr       */
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

static void	pause_fractal(t_mlx *mlx)
{
	mlx->fractal.pause = (mlx->fractal.pause) ? 0 : 1;
}

static void	iteration(t_mlx *mlx, int key)
{
	if (key == 34)
		mlx->fractal.i_max++;
	else if (key == 40 && mlx->fractal.i > 1)
		mlx->fractal.i_max--;
}

int			key_hook(int key, t_mlx *mlx)
{
	if (key == 53)
		quit(mlx);
	else if (key == 15)
		init_fractal(mlx, mlx->fractal.choice);
	else if (key == 49)
		pause_fractal(mlx);
	else if (key == 34 || key == 40)
		iteration(mlx, key);
	else if (key == 69 || key == 78)
		zoom(mlx, key, W / 2, H / 2);
	else if (key >= 123 && key <= 126)
		move(mlx, key);
	return (1);
}
