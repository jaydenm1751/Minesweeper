//
// Created by jayde on 11/18/2022.
//

#ifndef PROJECT3_TILE_H
#define PROJECT3_TILE_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "TextureManager.h"

using namespace std;

class Tile{
private:
    string fileName;
    bool isRevealed;
    sf::Sprite tileSprite;
    float xCoordinate;
    float yCoordinate;
public:
    Tile(string fileName){
        isRevealed = false;
        this->fileName = fileName;
        xCoordinate = 0;
        yCoordinate = 0;
    }
    void setPosition(float x, float y){
        xCoordinate = x * 32;
        yCoordinate = y * 32;
        tileSprite = sf::Sprite(TextureManager::GetTexture(fileName));
        tileSprite.setPosition(xCoordinate, yCoordinate);
    }
    void draw(sf::RenderWindow &window){
        window.draw(tileSprite);
    }
    void reveal() {
        isRevealed = !isRevealed;
    }
};
#endif //PROJECT3_TILE_H
