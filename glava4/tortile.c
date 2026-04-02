#include <stdio.h>

typedef struct{
    const char *name;
    const char *species;
    int age;
}tortle;
void dr(tortle *t)
{
    (*t).age=(*t).age+1;
    printf("С днём рождения, %s! Теперь тебе %i лет!\n",
    (*t).name, (*t).age);
}
int main()
{
    tortle myrtle={"Тортила", "Кожистая черепихи",99};
    dr(&myrtle);
    printf("%s прожила %i лет\n", myrtle.name, myrtle.age);
    return 0;
}