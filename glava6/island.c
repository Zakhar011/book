#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

island* create(char *name){
    island *i = malloc(sizeof(island));
   i->name = strdup(name);
    i->opens = "9:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

void display(island *start);
void release(island *start);

int main(){
    
// char name[80];
// fgets(name, 80, stdin);
// island *p_island0= create(name);
// fgets(name, 80, stdin);
// island *p_island1 = create(name);

// island *p = malloc(sizeof(island));
// free(p);

// island amity = {"Дружбы", "9:00", "17:00", NULL};
// island craggy = {"Скалистый", "9:00", "17:00", NULL};
// island isla_nublar = {"Туманный", "9:00", "17:00", NULL};
// island shutter = {"Проклятыхx", "9:00", "17:00", NULL};

// amity.next = &craggy;
// craggy.next = &isla_nublar;
// isla_nublar.next = &shutter;


// island skull = {"Остров черепа", "9:00", "17:00", NULL};
// isla_nublar.next = &skull;
// skull.next = &shutter;

// display(&amity);
island *start = NULL;
island *i =NULL;
island *next = NULL;
char name [80];
printf("Ctrl+D чтобы закончить):\n");
for(; fgets(name,80,stdin) != NULL; i=next){
    name[strcspn(name, "\n")] = 0;
    next = create(name);
    if (start == NULL)
        start=next;
    if(i!=NULL)
    i-> next= next;
}
display(start);
release(start);
return 0;

}
void  display(island *start)
 {
    island *i = start;
    for(;i!=NULL; i=i->next){
        printf("Name: %s open: %s-%s\n", i->name,i->opens,i->closes);
    }
 }



void release(island *start)
{
    island *i= start;
    island *next =NULL;
    for (; i!=NULL; i=next){
        next= i-> next;
        free(i->name);
        free(i);
    }
}