#ifndef AVS_HW2_RND_H
#define AVS_HW2_RND_H


#include <stdlib.h>

class Random {
public:
    // Возвращает случайное число в диапазоне [min, max]
    static int RandomRange(int min, int max);

    // Случайная строка. Сама выделяет память.
    static char *RandomString(char *str, size_t size);
};



#endif //AVS_HW2_RND_H
