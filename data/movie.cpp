#include <cstdio>
#include <cstring>
#include "movie.h"
#include "cartoon.h"
#include "game.h"
#include "documentary.h"
#include "../rnd_files/rnd.h"

Movie::Movie(const char *name, int year_of_release) : year_of_release_(year_of_release) {
    strcpy(name_, name);
}

const char *Movie::getName() const {
    return name_;
}

int Movie::getYearOfRelease() const {
    return year_of_release_;
}

Movie *Movie::in(FILE *ifst) {
    int k;
    if (fscanf(ifst, "%d", &k) == EOF)
        return nullptr;

    switch (k) {
        case 1:
            return Game::in(ifst);
        case 2:
            return Cartoon::in(ifst);
        case 3:
            return Documentary::in(ifst);
        default:
            return nullptr;
    }
}

Movie *Movie::inRnd() {
    int k = Random::RandomRange(1, 3);
    switch (k) {
        case 1:
            return Game::inRnd();
        case 2:
            return Cartoon::inRnd();
        case 3:
            return Documentary::inRnd();
        default:
            return nullptr;
    }
}

void Movie::out(FILE *ofst) {
    fprintf(ofst, " Name = %s, year of release = %d. Task result: %f\n", name_, year_of_release_, calculateTask());
}

double Movie::calculateTask() const {
    double res = 0;
    res = year_of_release_;
    res /= (double) sizeof(name_);
    return res;
}
