/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:26:59 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/25 04:46:02 by dpotvin          ###   ########.fr       */
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
    
    // Strafe Left
    if (isKeyDown(MLX_KEY_D))
    {
        // Calculate the strafe direction by rotating 90 degrees to the left.
        float strafeAngleRad = angleRad - (M_PI / 2.0);
        float newXFloat = getplayerunit()->Coord.x + cos(strafeAngleRad) * getplayerunit()->movementSpeed * deltaTime;
        float newYFloat = getplayerunit()->Coord.y + sin(strafeAngleRad) * getplayerunit()->movementSpeed * deltaTime;
        if (isValidTile((s_coord){newXFloat, newYFloat}))
        {
            getplayerunit()->Coord.x = newXFloat;
            getplayerunit()->Coord.y = newYFloat;
        }
    }

    // Strafe Right
    else if (isKeyDown(MLX_KEY_A))
    {
        // Calculate the strafe direction by rotating 90 degrees to the right.
        float strafeAngleRad = angleRad + (M_PI / 2.0);
        float newXFloat = getplayerunit()->Coord.x + cos(strafeAngleRad) * getplayerunit()->movementSpeed * deltaTime;
        float newYFloat = getplayerunit()->Coord.y + sin(strafeAngleRad) * getplayerunit()->movementSpeed * deltaTime;
        if (isValidTile((s_coord){newXFloat, newYFloat}))
        {
            getplayerunit()->Coord.x = newXFloat;
            getplayerunit()->Coord.y = newYFloat;
        }
    }
	

    // Left rotation
    if (isKeyDown(MLX_KEY_RIGHT))
    {
        getplayerunit()->angle -= getplayerunit()->rotationSpeed * deltaTime;
        getplayerunit()->angle = fmodf(getplayerunit()->angle, 360.0f);
    }

    // Right rotation
    else if (isKeyDown(MLX_KEY_LEFT))
    {
        getplayerunit()->angle += getplayerunit()->rotationSpeed * deltaTime;
        getplayerunit()->angle = fmodf(getplayerunit()->angle, 360.0f);  
    }

}
