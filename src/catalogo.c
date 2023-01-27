#include "../includes/catalogo.h"

typedef struct cat{
    HASHUSER husers;
    HASHDRIVER hdrivers;
    RIDEL ridel;
} *CATALOGO;

HASHUSER inithUsers(){
    HASHUSER h = malloc(sizeof(HASHUSER));
    h->user = g_hash_table_new (NULL, NULL);
    return h;
}

HASHDRIVER inithDrivers(){
    HASHDRIVER dr = malloc(sizeof(HASHDRIVER));
    dr->driver = g_hash_table_new (NULL, NULL);
    return dr;
}

RIDEL initRide(){ 
    RIDEL r = malloc(sizeof(RIDEL));
    r ->curr_ride = NULL;
    r -> next = NULL;
    return r;
}

CATALOGO initCat (){
    CATALOGO c = malloc(sizeof(struct cat));
    c ->husers = inithUsers();
    c ->hdrivers = inithDrivers();
    c ->ridel = initRide();
    return c; 

}


HASHUSER getUSERS (CATALOGO c){
    return c->husers;
}

HASHDRIVER getDrivers (CATALOGO c){
    return c->hdrivers;
}

RIDEL getRidel (CATALOGO c){
    return c ->ridel;

}


CATALOGO carregaCatalogo (){
    CATALOGO cat = initCat();
    adicionarUsers(getUSERS(cat));
    adicionarDrivers(getDrivers(cat));
    adicionarRide(getRidel(cat));
    return cat;
}
















