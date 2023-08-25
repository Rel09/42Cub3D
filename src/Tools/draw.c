/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:33:42 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/25 04:38:03 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
// Function to draw a line on the minimap connecting two points (x1, y1) and (x2, y2)
void drawLineOnMinimap(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = fmaxf(fabsf(dx), fabsf(dy));
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;
    float x = x1;
    float y = y1;

    for (int i = 0; i < steps; i++) {
        if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
            mlx_put_pixel(getgamedata()->img, x, y, getcolor()->minimapplayerangleline); // Red color for the line
        }
        x += xIncrement;
        y += yIncrement;
    }
}

void drawSquare(uint16_t x, uint16_t y, uint16_t tilesize_x, uint16_t tilesize_y)
{
    uint16_t x_end = x + tilesize_x;
    uint16_t y_end = y + tilesize_y;

    // Ensure that the square is within the screen boundaries
    if (x_end > SCREEN_WIDTH || y_end > SCREEN_HEIGHT)
        return;

    // Draw the square with the given color
    for (uint16_t i = x; i < x_end; i++) {
        for (uint16_t j = y; j < y_end; j++) {
            mlx_put_pixel(getgamedata()->img, i, j, getcolor()->minimapwall);
        }
    }
}

void drawMiniMap()
{
    int map_x = getgamedata()->map_x;
    int map_y = getgamedata()->map_y;

    // Calculate the tile size for both x and y directions
    int tilesize_x = SCREEN_WIDTH / (4 * map_x);
    int tilesize_y = SCREEN_HEIGHT / (4 * map_y);

    for (int i = 0; i < (map_x * tilesize_x); i++) {
        for (int j = 0; j < (map_y * tilesize_y); j++) {
            mlx_put_pixel(getgamedata()->img, i, j, getcolor()->minimapbackground);
        }
    }

    // Draw Grid
    for (int i = 0; i < map_y; i++) {
        for (int j = 0; j < map_x; j++) {

            if (getgamedata()->nmap[i][j] != 1)
                continue;
            int xo = j * tilesize_x;
            int yo = i * tilesize_y;
            drawSquare(xo, yo, tilesize_x, tilesize_y);

        }
    }
}

void drawPlayer()
{
    int dx;
    int dy;
    int map_x = getgamedata()->map_x;
    int map_y = getgamedata()->map_y;

    // Calculate the scaling factors for both x and y directions using tilesize
    float scaleX = (SCREEN_WIDTH) / (4 * map_x);
    float scaleY = (SCREEN_HEIGHT) / (4 * map_y);

    // Get the player's coordinates
    float playerX = getplayerunit()->Coord.x;
    float playerY = getplayerunit()->Coord.y;

    // Calculate the player's position on the minimap using the tilesize-based scaling
    float xo = playerX * scaleX;
    float yo = playerY * scaleY;

    // Calculate the player's icon size on the minimap based on the tilesize
    int playerSize = 5;

    // Draw the player's position on the minimap
    for (int i = -playerSize; i <= playerSize; i++) {
        for (int j = -playerSize; j <= playerSize; j++) {
            dx = j;
            dy = i;
            if (sqrt(dx * dx + dy * dy) <= playerSize) {
                float x = xo + i;
                float y = yo + j;
                if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
                    mlx_put_pixel(getgamedata()->img, x, y, getcolor()->minimapplayer);
            	}
            }
        }
    }

    // Draw the direction line (assuming you have a drawLineOnMinimap function)
	
    float lineLength = 10.0f; // Length of the direction line in pixels (you can adjust this as needed)

    // Convert the angle to radians
    float angleRad = degreesToRadians(getplayerunit()->angle);

    // Calculate the endpoint of the line based on the player's angle relative to the player's position
    float endX = xo + lineLength * cos(angleRad);
    float endY = yo + lineLength * sin(angleRad);

    // Draw the line on the minimap
    drawLineOnMinimap(xo, yo, endX, endY);
}

void raycasting()
{
    int feature_aiming_mode = 0;
    int precision = 300;
    float angleRad = degreesToRadians(getplayerunit()->angle);
    float halfFovAngleRad = degreesToRadians(getplayerunit()->fov / 2.0f);
    float cameraPlaneDist = (SCREEN_WIDTH + feature_aiming_mode / 2.0f) / tan(halfFovAngleRad);

    for (int width = 0; width < SCREEN_WIDTH; width++)
    {
        float rayAngle = atan2(SCREEN_WIDTH / 2.0f - width + 0.5, cameraPlaneDist) + angleRad;
        float rayX = getplayerunit()->Coord.x;
        float rayY = getplayerunit()->Coord.y;
        float rayCos = cos(rayAngle) / precision;
        float raySin = sin(rayAngle) / precision;

        bool wall = false;
        bool wallIsVertical = true;

        while (!wall)
        {
            rayX += rayCos;
            rayY += raySin;
            wall = getgamedata()->nmap[(int)(rayY)][(int)(rayX)] == 1;
            if (wall)
            {
                wallIsVertical = getgamedata()->nmap[(int)(rayY)][(int)(rayX - rayCos)] != 1;
            }
        }

        int textureIndex = -1;

        // Determine the texture index based on the ray's angle
        if (wallIsVertical)
        {
            if (rayCos > 0)
                textureIndex = 2; // East-facing wall
            else
                textureIndex = 3; // West-facing wall
        }
        else
        {
            if (raySin > 0)
                textureIndex = 1; // South-facing wall
            else
                textureIndex = 0; // North-facing wall
        }

        int wallHeight = (cameraPlaneDist / (get_distance(getplayerunit()->Coord, (s_coord){rayX, rayY}) * cos(rayAngle - angleRad)));

       for (int height = 0; height < SCREEN_HEIGHT; height++)
		{
			// Calculate the texture Y coordinate
			float textureY = (height - (SCREEN_HEIGHT - wallHeight) / 2) / (float)wallHeight * gettexture()->textures[0]->height;

			// Wall
			if (height >= (SCREEN_HEIGHT - wallHeight) / 2 && height < (SCREEN_HEIGHT + wallHeight) / 2)
			{
				float textureX;
				if (wallIsVertical)
				{
					if (textureIndex == 0)
					{
						textureX = (rayY - floor(rayY)) * gettexture()->textures[textureIndex]->width;
						textureX = gettexture()->textures[textureIndex]->width - textureX - 1.0;
					}
					else if (textureIndex == 2)
						textureX = (1.0 - (rayY - floor(rayY))) * gettexture()->textures[textureIndex]->width;
					else
						textureX = (rayY - floor(rayY)) * gettexture()->textures[textureIndex]->width;
				}
				else
				{
					if (textureIndex == 0 )
					{
						textureX = (rayX - floor(rayX)) * gettexture()->textures[textureIndex]->width;
						textureX = gettexture()->textures[textureIndex]->width - textureX - 1.0;
					}
					else
					{
						textureX = (rayX - floor(rayX)) * gettexture()->textures[textureIndex]->width;
					}
				}

				mlx_put_pixel(getgamedata()->img, width, height, texture_to_pixel(gettexture()->textures[textureIndex], textureX, textureY));
			}
			// Roof
			else if (height < (SCREEN_HEIGHT - wallHeight) / 2)
			{
				mlx_put_pixel(getgamedata()->img, width, height, gettexture()->rgb[1]);
			}
			// Floor
			else
			{
				mlx_put_pixel(getgamedata()->img, width, height, gettexture()->rgb[0]);
			}
		}
    }
}


