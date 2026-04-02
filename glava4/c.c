#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "totaller.h"

struct exercise{
    const char *description;
    float duration;
};
struct meal{
    const char *ingredients;
    float weight;
};
struct preferences{
    struct meal food;
    struct exercise exercise;
};
struct fish{
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preferences care;
};

 void catalog(struct fish f)
{
    printf("%s - eto %s c %i zubami. Emu %i age\n",
        f.name, f.species, f.teeth, f.age);
}

int main()
{
    struct fish snappy={"Zubastic","pirania",69,4};
    catalog(snappy);
    return 0;
}

