/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:03:59 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/22 22:47:36 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	/*	Menu with map checking
	if (argc == 1)
	{
		
	}
	*/
	
	if (argc_isbad(argc) || map_isbad(argv[1]))
	{
		// free
		return (1);
	}

	
	
	mlx_loop_hook(getgamedata()->mlx, gameloop, 0);
	mlx_loop(getgamedata()->mlx);
	mlx_terminate(getgamedata()->mlx);
	return (0);
}
