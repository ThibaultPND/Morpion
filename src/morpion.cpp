#include "morpion.h"


morpion::morpion() {
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = vide;
        }
    }
    this->txVide = LoadTexture("img/vide.bmp");
    this->txCroix = LoadTexture("img/croix.bmp");
    this->txRond = LoadTexture("img/rond.bmp");
    std::cout << "+ morpion" << std::endl;
}

morpion::~morpion() {
    std::cout << "- morpion" << std::endl;
}
void morpion::render() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            SDL_Rect rect = {
                .x = i*TILE_SIZE,
                .y = j*TILE_SIZE,
                .w = TILE_SIZE,
                .h = TILE_SIZE
            };
            SDL_RenderCopy(gRenderer, getTexture(grid[i][j]), NULL, &rect);
        }
    }
}

SDL_Texture *morpion::getTexture(tile_t type) {
    switch (type){
        case vide:
            return txVide;
        case croix:
            return txCroix;
        case rond:
            return txRond;
    
    default:
        return txVide;
    }
    
}

void morpion::place(int x, int y) {
    if (grid[y][x] != vide) {
        return;
    }
    grid[y][x] = (turn) ? rond : croix;
    turn = !turn;
}

void morpion::clear() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = vide;
        }
    }
}

bool morpion::checkIfWin() {
    for (int i = 0; i < 3; i++)
    {
        if ( ( grid[i][0] != vide && (grid[i][0] == grid[i][1]) && (grid[i][0] == grid[i][2]) )
        ||   ( grid[0][i] != vide && (grid[0][i] == grid[1][i]) && (grid[0][i] == grid[2][i]) )) {
            return true;
        }
    }
    if ( grid[1][1] != vide
    &&  ((grid[0][0] == grid[1][1]) && (grid[0][0] == grid[2][2])
    ||   (grid[0][2] == grid[1][1]) && (grid[0][2] == grid[2][0]))){
        return true;
    }

    return false;
}

tile_t morpion::joueurActuel() {
    return (turn) ? rond : croix;
}