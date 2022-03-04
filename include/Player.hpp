#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL.h>

#define PLAYER_SPEED 8.0F

class Player
{
    public:
        Player(SDL_Color color, SDL_FPoint position, int w, int h);
        void Update(const Uint8* keys);
        void Draw(SDL_Renderer* renderer);

    public:
        inline void Fill(SDL_Color color) { _color = color; }
        inline int GetWidth() { return _width; }
        inline int GetHeight() { return _height; }
        inline bool IsWalkingLeft() { return _directionX < 0; }
        inline bool IsWalkingRight() { return _directionX > 0; }
        inline void SetSpeed(float speed) { _speed = speed; }
        inline float GetX() { return _position.x; }
        inline float GetY() { return _position.y; }

    private:
        SDL_Color _color;
        SDL_FPoint _position;
        float _directionX;
        int _width;
        int _height;
        float _speed;
};

#endif