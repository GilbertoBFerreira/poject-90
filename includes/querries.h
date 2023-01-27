#include "../includes/parseDrives.h"
#include "../includes/parseRides.h"
#include "../includes/parseUsers.h"

GHashTable *get_HashDrivers(HASHDRIVER l);
char* getDriversCarClass(DRIVER d);
int getIdDriver (RIDE d);
int getIdRide (RIDE d);
char* getRideCity (RIDE d);
int getDistance (RIDE d);
int getEvalD (RIDE d);
char* getUser (RIDE d);
int getEvalU (RIDE d);
int calculaIdade (DATA2 birth_date);
void evalMediaD (int IdDriver, RIDEL t);
void evalMediaU (char* username, RIDEL t);
int verificaCidade(char* cidade,RIDE t);
char* verificaClasse(int id_driver,HASHDRIVER d);
int query4 (HASHDRIVER t, RIDEL d, char* city);