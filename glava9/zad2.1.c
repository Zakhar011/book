#include <stdio.h>
#include <unistd.h> // Обязательно для функции execle

int main()
{
    char *my_env[] = {"JUICE=персик и яблоко", NULL};
    execle("./zad2", "./zad2", "4", NULL, my_env);
    puts("Упс! Произошла ошибка. Файл diner_info не найден.");
    return 1;
}