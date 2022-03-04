#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <string>
#include <vector>
#include <SDL2/SDL.h>

#include "Tile.hpp"
#include "Player.hpp"

class Level
{
    public:
        Level(const std::string levelData[], const int mapHeight, const int tileSize);
        void Run(SDL_Renderer* renderer, const Uint8* keys);
        void Destroy();

    private:
        std::vector<Tile*> _tiles;
        Player* _player;
        int _worldShift;
};

#endif