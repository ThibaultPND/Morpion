/***************************************************************
**  Auteur : Thibault Chassagne
**  MAJ : 27/10/2023
*  
**  Nom : Morpion
*  
*?  Description : Ce logiciel à pour but de crée un morpion graphique.
*
g++ -o prog -Iinclude -Iinclude/SDL2 src/*.cpp -Llib -lSDL2main -lSDL2 -static -DSDL_MAIN_HANDLED && bin\monProgramme.exe
***************************************************************/
#include <Project.h>
#include <SDL2/SDL.h>
#include "TxUtils.h"
#include "morpion.h"

int main(int argc, char const *argv[]) {
    std::cout << "Debut du  programme...\n" << std::endl;
    try {
        // Initialisation
        project::Application app;
        srand(SDL_GetTicks());
        morpion grille;
        // Programme
        grille.render();
        SDL_RenderPresent(gRenderer);


        bool programLaunched = true;
        int coupJoue(0);
        tile_t winner(vide);
        int mouseX = 0, mouseY = 0;
        while (programLaunched){
            SDL_Event event;
            while (SDL_PollEvent(&event)){
                switch (event.type) {
                    case SDL_QUIT:
                        programLaunched = false;
                        break;
                    case SDL_MOUSEMOTION:
                        SDL_GetMouseState(&mouseX, &mouseY);
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        switch (event.button.button) {
                            case SDL_BUTTON_LEFT:
                                grille.place((mouseY / TILE_SIZE), mouseX/TILE_SIZE);

                                if (grille.checkIfWin()){
                                    winner = grille.joueurActuel();
                                }
                                

                                grille.render();
                                SDL_RenderPresent(gRenderer);
                                coupJoue++;

                                break;
                        }
                        break;
                    case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_BACKSPACE){
                            grille.clear();
                            grille.render();
                            SDL_RenderPresent(gRenderer);
                        }
                        
                }
            }
            if (winner != vide){
                programLaunched = false;
            }else if( coupJoue >= 9) {
                programLaunched = false;
            }
            
            SDL_Delay(16);
        }
        

        app.~Application();
        switch (winner){
        case vide:
            std::cout << "Il n'y a pas de gagnant égalité !" << std::endl;
            break;
        case rond:
            std::cout << "Le gagnant est le joueur des ronds !" << std::endl;
            break;
        case croix:
            std::cout << "Le gagnant est le joueur des croix !" << std::endl;
            break;
        }
    } catch (const std::exception& e) {
        std::cerr << "Erreur fatale dans le programme principal : " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    
    
    std::cout << "Fin du programme...\n" << std::endl;

    return EXIT_SUCCESS;
}