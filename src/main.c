#include "../includes/main.h"
#include <stdio.h>

// void interpretador(char* arg, CATALOGO cat){
//     int q,a;
	
	
// 	if (scanf ("%d", &q) == 0){ ;

//     switch (q){
//         case 1:
//             break;
//         case 2:
//             break;
//         case 3:
//             break;
//         case 4:
//             query4(getDrivers(cat),getRidel(cat), arg);
//             break;
//         case 5:
//             break;
//         case 6:
//             break;
// 		case 7:
// 			break;
//         case 8:
//             break;
//         case 9:
//             break;

//         }
// }
// }
    
HASHUSER inithUsers(){
    HASHUSER h = malloc(sizeof(HASHUSER));
     h->user = g_hash_table_new (NULL, NULL);
    return h;
}

int main(int argc, char *argv[]) {
    adicionarUsers(argv[1], inithUsers());

    getchar();
    
    return 0;
}
