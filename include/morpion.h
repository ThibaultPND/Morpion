#if !defined(__MORPION_H__)
    #define __MORPION_H__

    #include <iostream>
    #include <SDL2/SDL.h>
    #include "TxUtils.h"
    #include "Project.h"
    
    typedef enum{
        vide = 0,
        croix,
        rond
    }tile_t;

    class morpion {
        private:

            bool turn = true; // TRUE for CIRCLE
            
            tile_t grid[3][3];
            SDL_Texture *txCroix;
            SDL_Texture *txRond;
            SDL_Texture *txVide;

            
            SDL_Texture *getTexture(tile_t type);
        public:
            morpion();
            ~morpion();
            void render();
            void clear();
            void place(int x, int y );
            bool checkIfWin();
            tile_t joueurActuel();
    };
    


#endif // __MORPION_H__
