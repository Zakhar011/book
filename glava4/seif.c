#include <stdio.h>
typedef struct{
    const char *description;
    float value;
}swag;
typedef struct{
    swag *swag;
    const char *sequence;
}combination;
typedef struct{
    combination numders;
    const char *make;
}safe;
 int main()
 {
 swag gold = {"Золото!",1000000.0};
 combination numders = {&gold, "6502"};
 safe s ={numders, "RAMACON250"};
 printf ("Содержимое= %s\n", s.numders.swag->description);
 }