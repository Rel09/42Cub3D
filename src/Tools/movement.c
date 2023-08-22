/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:26:59 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/22 02:30:12 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Why not
bool	isKeyDown(int key)
{
	return (mlx_is_key_down(getgamedata()->mlx, key));
}


void movePlayer()
{
    bool shift = isKeyDown(MLX_KEY_LEFT_SHIFT);
    if (shift) 
        getplayerunit()->movementSpeed = 15.0;
    else
        getplayerunit()->movementSpeed = 5.0;
    
    float deltaTime = getgamedata()->mlx->delta_time;
    float angleRad = getplayerunit()->angle * (M_PI / 180.0);
    float movementSpeed = getplayerunit()->movementSpeed * deltaTime;
    float dx = cos(angleRad);
    float dy = sin(angleRad);
        
    // Move Forward
    if (isKeyDown(MLX_KEY_W))
    {
        float newXFloat = getplayerunit()->Coord.x + dx * movementSpeed;
        float newYFloat = getplayerunit()->Coord.y + dy * movementSpeed;
        if (isValidTile((s_coord){newXFloat, newYFloat}))
        {
            getplayerunit()->Coord.x = newXFloat;
            getplayerunit()->Coord.y = newYFloat;
        }
    }
    
    // Move Backward
    else if (isKeyDown(MLX_KEY_S))
    {
        float newXFloat = getplayerunit()->Coord.x - dx * movementSpeed;
        float newYFloat = getplayerunit()->Coord.y - dy * movementSpeed;
        if (isValidTile((s_coord){newXFloat, newYFloat}))
        {
            getplayerunit()->Coord.x = newXFloat;
            getplayerunit()->Coord.y = newYFloat;
        }
    }
    
    // Left rotation
    if (isKeyDown(MLX_KEY_D))
    {
        getplayerunit()->angle -= getplayerunit()->rotationSpeed * deltaTime;
        getplayerunit()->angle = fmodf(getplayerunit()->angle, 360.0f);
    }

    // Right rotation
    else if (isKeyDown(MLX_KEY_A))
    {
        getplayerunit()->angle += getplayerunit()->rotationSpeed * deltaTime;
        getplayerunit()->angle = fmodf(getplayerunit()->angle, 360.0f);  
    }

}
