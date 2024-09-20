#include "GameObject.hpp"
#include "TextureManager.hpp"


GameObject::GameObject(const char* texturesheet,int x,int y)
{
objectTexture = TextureManager::LoadTexture(texturesheet);

xpos = x;
ypos = y;
}

void GameObject::Update()
{
    xpos = 0;
    ypos = 0;

srcRect.h = 32;
srcRect.w = 32;
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