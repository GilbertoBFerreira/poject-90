#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

DATA2 atribuiData (char* data);

HASHDRIVER getHash (HASHDRIVER h);

void adicionaDriver (HASHDRIVER h,DRIVER driver);

DRIVER inicializaDriver (int id,char* name, DATA2 birth_date, int gender,char* car_class,char* license_plate, int city, DATA2 account_creation,char* account_status);

int atribuiCidade (char* cidade);

int genderToint (char* gender);

