#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(){}
//for integar postions like grid alliment
GameObject::GameObject(const char* texturesheet, int x, int y, int IMHeight, int IMWidth,int scale)
{
objectTexture = TextureManager::LoadTexture(texturesheet);

xpos = x;
ypos = y;
height = IMHeight;
width = IMWidth;
this->scale=scale;

}

//for float postions like player and ememy
GameObject::GameObject(const char* texturesheet, int IMHeight, int IMWidth, float fx, float fy,int scale)
{
  objectTexture = TextureManager::LoadTexture(texturesheet);
fxpos = fx;
fypos = fy;
height = IMHeight;
width = IMWidth;
this->scale=scale;
}

GameObject::~GameObject(){}

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
void GameObject::fUpdate()
{
  int ScaledHeight = 0;
  int ScaledWidth = 0;
  ScaledHeight = height * scale;
  ScaledWidth = width * scale;

  srcRect.h = ScaledHeight;
  srcRect.w = ScaledWidth;
  srcRect.x = 0;
  srcRect.y = 0;

  destRect.x = fxpos;
  destRect.y = fypos;
  destRect.w = srcRect.w;
  destRect.h = srcRect.h;
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer,objectTexture,&srcRect,&destRect);
}