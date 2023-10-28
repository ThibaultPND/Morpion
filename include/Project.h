#ifndef __PROJECT_H__
#define __PROJECT_H__

    // Inclusions
    #include <iostream>
    #include <string>
    #include <SDL2/SDL.h>
    #include "GlobalRenderer.h"

    // Maccros dimension fenêtre
    #define HAUTEUR_FENETRE 600
    #define LARGEUR_FENETRE 600
    #define TILE_SIZE 200

    namespace project {


    class Application {
        public:
            Application();
            ~Application();

        private:
    };

    }

#endif // __PROJECT_H__