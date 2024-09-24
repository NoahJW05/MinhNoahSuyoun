#include "GameObject.hpp"
#include "TextureManager.hpp"


GameObject::GameObject(const char* texturesheet, int x, int y, int IMHeight, int IMWidth,int scale)
{
objectTexture = TextureManager::LoadTexture(texturesheet);

xpos = x;
ypos = y;
height = IMHeight;
width = IMWidth;
this->scale=scale;

}

void GameObject::Update()
{
  int ScaledHeight = 0;
  int ScaledWidth = 0;
  ScaledHeight = height * scale;
  ScaledWidth = width * scale;

  srcRect.h = ScaledHeight;
  srcRect.w = ScaledWidth;
  srcRect.x = 0;
  srcRect.y = 0;

  destRect.x = xpos;
  destRect.y = ypos;
  destRect.w = srcRect.w;
  destRect.h = srcRect.h;

}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer,objectTexture,&srcRect,&destRect);
}