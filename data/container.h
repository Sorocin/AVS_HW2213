//
// Created by Александр on 20.10.2021.
//

#ifndef AVS_HW2_CONTAINER_H
#define AVS_HW2_CONTAINER_H


#include <cstdio>
#include "movie.h"

class Container {
private:
    const int MAX_LEN = 10000; // Макс. длина.
    int len_ = 0; // Временная текущая длинна.
    Movie **cont;

public:
    Container();

    ~Container();

    // Ввод содержимого контейнера из указанного потока
    void in(FILE *ifst);

    // Случайный ввод содержимого контейнера
    void inRnd(int size);

    // Вывод содержимого контейнера в указанный поток
    void out(FILE *ofst);

    // Сортировка Шелла по возрастанию
    void sortShellContainer();
};


#endif //AVS_HW2_CONTAINER_H
