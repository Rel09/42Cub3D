/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:39:34 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/25 03:55:05 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Game Loop
void gameloop()
{
		movePlayer();
        raycasting();
        drawMiniMap();
        drawPlayer();

}
