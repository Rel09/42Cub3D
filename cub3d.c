/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:03:59 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/27 00:50:33 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc_isbad(argc) || map_isbad(argv[1]))
	{
		free_everything();
		return (1);
	}
	mlx_loop_hook(game()->mlx, gameloop, 0);
	mlx_loop(game()->mlx);
	free_everything();
	return (0);
}
