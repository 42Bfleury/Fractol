/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 09:57:26 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/23 07:50:59 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_instruction(void)
{
	ft_putendl("--------------- Fract'ol ----------------");
	ft_putendl("Move Up                               [^]");
	ft_putendl("Move Down                             [v]");
	ft_putendl("Move Left                             [<]");
	ft_putendl("Move Right                            [>]");
	ft_putendl("Change Fractal                        [F]");
	ft_putendl("More Iteration                        [+]");
	ft_putendl("Less Iteration                        [-]");
	ft_putendl("Reset Fractal                     [SPACE]");
	ft_putendl("Zoom In                     [SCROLL DOWN]");
	ft_putendl("Zoom Out                      [SCROLL UP]");
}

int		main(int ac, char **av)
{
	int		fractal;

	if (ac != 2 && ac != 3)
		die(NULL, "Usage : ./fractol <fractal>!");
	fractal = ft_atoi(av[1]);
	if ((ft_strlen(av[1]) != 1) || (ft_isdigit(av[1][0]) != 1)
		|| fractal < 0 || fractal > 6)
		die(NULL, "Usage : ./fractol <fractal>!");
	init(fractal);
	return (0);
}
