#include "../includes/parseUsers.h"
#include <stdio.h>
#include <stdlib.h>

#define LINHAS 10000
#define NUMCHARS 1024

int genderToint (char* gender){
        int g;
        if (gender == "M") {
                g = 0;
                return g;
        }
        else if (gender == "F"){
                g = 1;
                return g;
        }
}

int adicionarU(char *line, HASHUSER h){
    char *fields = strdup(line);
    DATA birth_date, account_creation;
    int gender;
    char resto;
    char *temp , *username,*name, *pay_method,*account_status;
    USER user;
    int res = 1;
    
    for(int i=0; (temp =(strsep(&fields, ";"))) != NULL && i<7; i++){
        switch (i){
            case 0:
                username = strdup (temp);
                break;
            case 1:
                name = strdup (temp);
                break;
            case 2:
                gender = genderToint (strdup (temp));
                break;
            case 3:
                birth_date = atribuiData (strdup(temp));
                break;
            case 4:
                account_creation = atribuiData (strdup(temp));
                break;
            case 5:
                pay_method = strdup (temp);
                break;
            case 6:
                account_status = strdup (temp);
                break;
            }
	}
    user = inicializaUser(username,name,gender,birth_date,account_creation,pay_method,account_status);
    
    if (g_hash_table_lookup(h->user,&username) == NULL) adicionaUser (h,user);
    else res = 0;
   return res; 
}

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ";");
            tok && *tok;
            tok = strtok(NULL, "\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

void adicionarUsers(char* path, HASHUSER h) {
    // abrir ficheiro
    FILE *file = fopen(path, "r");

    // verificar existência do ficheiro
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // variável temporaria da linha
    char line[NUMCHARS];

    // ler linhas do ficheiro
    while (fgets(line, NUMCHARS, file)) {
        char* tmp = strdup(line);

        printf("%s ", tmp);
        printf("\n\n");
        free(tmp);
    }

    fclose(file);
}


