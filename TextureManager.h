//
// Created by jayde on 11/20/2022.
//

#ifndef PROJECT3_TEXTUREMANAGER_H
#define PROJECT3_TEXTUREMANAGER_H
#include <SFML/Graphics.hpp>
using namespace std;

class TextureManager{
private:
    static map<string, sf::Texture> tiles;
public:
    static void LoadTexture(string textureName){
        string path = "images/";
        path += textureName + ".png";
       // string path = "images/tile_hidden.png";

        tiles[textureName].loadFromFile(path);
    }
    static sf::Texture& GetTexture(string textureName){
        if (tiles.find(textureName) == tiles.end()){
            LoadTexture(textureName);
        }
        return tiles[textureName];
    }
    static void Clear(){
        tiles.clear();
    }
};

#endif //PROJECT3_TEXTUREMANAGER_H
