#include <cstring>
#include "game.h"
#include "../rnd_files/rnd.h"

Game::Game(const char *name, int year_of_release, const char *producer) : Movie(name, year_of_release){
    strcpy(producer_, producer);
}

Game *Game::in(FILE *ifst) {
    int year;
    char name[256];
    if (fscanf(ifst, "%s %d", name, &year) == EOF)
        return nullptr;
    char producer[256];
    if (fscanf(ifst, "%s", producer) == EOF)
        return nullptr;


    return new Game(name, year, producer);
}

Game *Game::inRnd() {
    int year_of_release = Random::RandomRange(1910, 2022);
    char name[256];
    Random::RandomString(name, 11);
    char producer[256];
    Random::RandomString(producer, 15);
    return new Game(name, year_of_release, name);
}

void Game::out(FILE *ofst) {
    const char *producer;
    producer = producer_;
    fprintf(ofst, "This is Game: producers name = %s.", producer);
    Movie::out(ofst);
}
