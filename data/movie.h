#ifndef AVS_HW2_MOVIE_H
#define AVS_HW2_MOVIE_H

#include <cstdio>

class Movie {
private:
    char name_[256];
    int year_of_release_;

public:
    Movie(const char *name, int year_of_release);

    const char *getName() const;

    int getYearOfRelease() const;


    // Ввод параметров фильма из файла
    static Movie *in(FILE *ifst);

    // Случайный ввод обобщенного фильма
    static Movie *inRnd();

    // Вывод параметров фильма в форматируемый поток
    virtual void out(FILE *ofst);

    // Доп задание по условию варината
    double calculateTask() const;
};


#endif //AVS_HW2_MOVIE_H
