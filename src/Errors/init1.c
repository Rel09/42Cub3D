/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 22:55:51 by dpotvin           #+#    #+#             */
/*   Updated: 2023/09/19 19:48:40 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	readfile_error_5(void)
{
	printf("[-] Error\n[-] Tester is crazy - Fix brain\n");
	return (false);
}

bool	readfile_error_6(void)
{
	printf("[-] Error\n[-] Couldnt Malloc the Map [0]\n");
	return (false);
}

void	free_everything(void)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (i < 2)
		{
			if (game()->s_mapfile.rgb_color[i])
				free(game()->s_mapfile.rgb_color[i]);
		}
		if (game()->s_mapfile.texture_file[i])
			free(game()->s_mapfile.texture_file[i]);
		if (gettexture()->textures[i])
			mlx_delete_texture(gettexture()->textures[i]);
	}
	free_map(game()->nmap, game()->map_y);
	if (game()->img)
		mlx_delete_image(game()->mlx, game()->img);
	if (game()->mlx)
		mlx_terminate(game()->mlx);
	ft_bzero(game(), sizeof(t_gamedata));
	ft_bzero(gettexture(), sizeof(t_texture));
	printf(BLACK_BG PINK_TEXT "[+] Goodbye\x1B[0m\n");
}

bool	readfile_error_7(char *mapcontent)
{
	if (!mapcontent)
	{
		printf("[-] Error\n[-] Bad Map File\n");
		return (false);
	}
	else if (!ft_strstr(mapcontent, ","))
	{
		printf("[-] Error\n[-] Wrong Map Input\n");
		return (false);
	}
	return (true);
}

// Make sure we actually have RGB Value
bool	readfile_error_8(void)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (!game()->s_mapfile.rgb_color[i])
		{
			printf("[-] Error\n[-] Couldn't read RGB Inputs\n");
			return (false);
		}
		i++;
	}
	return (true);
}
