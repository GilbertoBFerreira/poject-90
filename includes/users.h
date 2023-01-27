#include "../includes/datas.h"
#include <glib.h>

typedef struct hUsers {
        GHashTable *user;
} *HASHUSER;

typedef struct user{
        char* username;
        char* name;
        int gender;
        DATA birth_date;
        DATA account_creation;
        char* pay_method;
        char* account_status;
} *USER;


int genderToint (char* gender);

void adicionaUser (HASHUSER h,USER user);

USER inicializaUser (char* username,char* name, int gender,DATA birth_date,DATA account_creation,char* pay_method,char* account_status);
