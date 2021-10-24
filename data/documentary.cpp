#include <cstring>
#include "documentary.h"
#include "../rnd_files/rnd.h"

Documentary::Documentary(const char *name, int year_of_release, int duration) : Movie(name, year_of_release), duration_(duration) {}

Documentary *Documentary::in(FILE *ifst) {
    int year;
    char name[256];
    if (fscanf(ifst, "%s %d", name, &year) == EOF)
        return nullptr;
    int duration;
    if (fscanf(ifst, "%d", &duration) == EOF)
        return nullptr;

    return new Documentary(name, year, duration);
}

Documentary *Documentary::inRnd() {
    int year_of_release = Random::RandomRange(1910, 2022);
    int duration = Random::RandomRange(30, 240);
    char name[256];
    Random::RandomString(name, 11);


    return new Documentary(name, year_of_release, duration);
}

void Documentary::out(FILE *ofst) {
    int duration;
    duration = duration_;
    fprintf(ofst, "This is documentary: duration = %d.", duration);
    Movie::out(ofst);
}
