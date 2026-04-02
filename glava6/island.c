#include <stdio.h>
typedef struct island{
    char *name;
    char *opens;
    char *closes;
    struct island *next;
}island;
 
void display(island *start);

int main(){
    island amity = {"Дружбы", "9:00", "17:00", NULL};
    island craggy = {"Скалистый", "9:00", "17:00", NULL};
    island isla_nublar = {"Туманный", "9:00", "17:00", NULL};
    island shutter = {"Проклятых", "9:00", "17:00", NULL};

    amity.next = &craggy;
    craggy.next = &isla_nublar;
    isla_nublar.next = &shutter;


    island skull = {"Остров черепа", "9:00", "17:00", NULL};
    isla_nublar.next = &skull;
    skull.next = &shutter;

    display(&amity);

}
void  display(island *start)
 {
    island *i = start;
    for(;i!=NULL; i=i->next){
        printf("Name: %s open: %s-%s\n", i->name,i->opens,i->closes);
    }
 }


 