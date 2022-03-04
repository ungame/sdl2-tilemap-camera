#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "Tile.hpp"
#include "Level.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include "Settings.hpp"

Level::Level(const std::string levelData[], const int mapHeight, const int tileSize)
{
    _worldShift = 0;

    for(int row = 0; row < mapHeight; row++)
    {
        int len = levelData[row].length();

        for(int col = 0; col < len; col++)
        {
            char cell = levelData[row][col];
            
            float x = col * tileSize;
            float y = row * tileSize;
            SDL_FPoint position = { x, y };

            if(cell == 'X')
            {
                Tile* tile = new Tile(Color::Grey(), position, tileSize, tileSize);

                _tiles.push_back(tile);
            }

            if(cell == 'P')
            {
                _player = new Player(Color::Red(), position, 32, 64);
            }
        }
    }
}

void Level::Run(SDL_Renderer* renderer, const Uint8* keys)
{
    _player->Update(keys);

    if(_player->GetX() < (SCREEN_WIDTH / 4) && _player->IsWalkingLeft())
    {
        _worldShift = PLAYER_SPEED;
        _player->SetSpeed(0);
    }
    else if (_player->GetX() > SCREEN_WIDTH - (SCREEN_WIDTH / 4) && _player->IsWalkingRight())
    {
        _worldShift = -PLAYER_SPEED;
        _player->SetSpeed(0);
    }
    else
    {
        _worldShift = 0;
        _player->SetSpeed(PLAYER_SPEED);
    }

    for(Tile* tile : _tiles)
    {
        tile->Update(_worldShift);
        tile->Draw(renderer);
    }

    _player->Draw(renderer);
   
}

void Level::Destroy()
{
  if(_tiles.size() > 0)
    _tiles.clear();
}