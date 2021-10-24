#include "container.h"

Container::Container() {
    cont = new Movie *[MAX_LEN];
}

Container::~Container() {
    for (int i = 0; i < len_; i++) {
        delete cont[i];
    }

    delete[] cont;
}

void Container::in(FILE *ifst) {
    Movie *newMovie;
    while ((newMovie = Movie::in(ifst)) != nullptr) {
        cont[len_] = newMovie;
        len_++;
    }
}

void Container::inRnd(int size) {
    while (len_ < size) {
        if ((cont[len_] = Movie::inRnd()) != nullptr) {
            len_++;
        }
    }
}

void Container::out(FILE *ofst) {
    fprintf(ofst, "Container contains %d elements.\n", len_);
    for (int i = 0; i < len_; i++) {
        fprintf(ofst, "%d: ", i);
        cont[i]->out(ofst);
    }
}


//Функция по условию варианта. Не самый эффективный, но всегда работающий способ.
void Container::sortShellContainer() {
    for (int s = len_ / 2; s > 0; s /= 2) {
        for (int i = 0; i < len_; i++) {
            for (int j = i + s; j < len_; j += s) {
                if (cont[i]->calculateTask() > cont[j]->calculateTask()) {
                    Movie *temp = cont[j];
                    cont[j] = cont[i];
                    cont[i] = temp;
                }
            }
        }
    }
}
