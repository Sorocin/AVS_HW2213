#include <cstring>
#include "cartoon.h"
#include "../rnd_files/rnd.h"

Cartoon::Cartoon(const char *name, int year_of_release, Cartoon::TYPE type1) : Movie(name, year_of_release), type(type1) {}

Cartoon *Cartoon::in(FILE *ifst) {
    int year;
    char name[256];
    if (fscanf(ifst, "%s %d", name, &year) == EOF)
        return nullptr;

    char cartoon_type[10];
    if (fscanf(ifst, "%s", cartoon_type) == EOF)
        return nullptr;

    Cartoon::TYPE new_type;
    if (strcmp(cartoon_type, "DRAW") == 0) {
        new_type = DRAW;
    } else if (strcmp(cartoon_type, "PUPPET") == 0) {
        new_type = PUPPET;
    } else if (strcmp(cartoon_type, "PLASTICINE") == 0) {
        new_type = PLASTICINE;
    } else {
        return nullptr;
    }

    return new Cartoon(name, year, new_type);
}

Cartoon *Cartoon::inRnd() {
    int year_of_release = Random::RandomRange(1910, 2022);
    char name[256];
    Random::RandomString(name, 11);

    int type_num = Random::RandomRange(0, 2);
    TYPE new_type = static_cast<TYPE>(type_num);

    return new Cartoon(name, year_of_release, new_type);
}

void Cartoon::out(FILE *ofst) {
    const char* new_type;
    if (type == DRAW) {
        new_type = "DRAW";
    } else if (type == PUPPET) {
        new_type = "PUPPET";
    } else if (type == PLASTICINE) {
        new_type = "PLASTICINE";
    } else {
        new_type = "UNKNOWN_TYPE";
    }

    fprintf(ofst, "This is cartoon: type = %s.", new_type);
    Movie::out(ofst);
}
