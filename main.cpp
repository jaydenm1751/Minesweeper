#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "Tile.h"
#include "TextureManager.h"

using namespace std;

int main() {

    ifstream config;
    config.open("config.cfg");
    string line;
    vector<int> dimensions;
    while(getline(config, line)){
        dimensions.push_back((stoi(line)));
    }
    // [0] = width, [1] = height, [2] = mines
    // [3] area = tile count;
    int mineCount = dimensions.at(2);
    int width = dimensions.at(0);
    int tileCount = dimensions.at(0) * dimensions.at(1);
    int height = dimensions.at(1);
    sf::RenderWindow window(sf::VideoMode(width * 32, (height * 32) + 100 ), "Minesweeper");
    Tile tile("tile_hidden");
    vector<Tile> board;

//    for (int i = 0; i < tileCount; i++){
//        board.push_back(tile);
//    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed){
                sf::Vector2i coordinates = sf::Mouse::getPosition(window);
                //cout << coordinates.x << " " << coordinates.y << endl;
                /*for (int i = 0; i < tiles.size(); i++) {
                    if (tiles[i].getBounds().contains(coordinates.x, coordinates.y) == true) {
                        tiles[i].reveal();
                    }
                }
                 */
            }
        }

        window.clear();

        for (int i = 0; i < width; i++){
            for (int j = 0; j < height; j++){
                tile.setPosition(i, j);
                board.push_back(tile);
                tile.draw(window);
            }
        }
        window.display();
    }
}