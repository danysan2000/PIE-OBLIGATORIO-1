#include <stdio.h>
/*  #include <curses.h> */

/* PIE
 * OBLIGATORIO 1 .
 * Archivo principal.
 * Ojetivo:
 *      Probar las funciones de la libreria libbits.a
 * Implementacion:
 *     La funcion main imprimira un meno en modo texto y
 *     preguntara la opcion deseada.     
 */

/* ----- Macros ------*/

/* mando cursor coordenadas 1,1 y clear screen */

#define CLR_SCREEN   printf("\033[H\033[2J");

static char *msg[30] = {
   "Menu principal:\n",
   "   [0] Salir",
   "   [1] bit",
   "   [2] ver_binario",
   "   [3] print_binario",
   "   [4] setbit",
   "   [5] concatena",
   "   [6] crear_mascara",
   "   [7] espejar",
   "   [8] extraer",
   0
};
    

int main()
{
    int aux1;
    int menu;
    int flg1= 1;  /* flag de control loop menu */

    do 
    {
        CLR_SCREEN
        /* presentacion */
        printf("             PIE\nOBLIGATORIO 1\nPrueba de funciones de libbits\n\n");
        for(aux1 = 0 ; msg[aux1] ; aux1++ )
            printf("%s\n",msg[aux1]);
        printf("Opcion: "); scanf("%d", &menu);
        switch( menu )
        {
            case 0:
                flg1=0;
                break;
           case 1:
                break;
           case 2:
                break;
           case 3:
                break;
           case 4:
                break;
           case 5:
                break;
           case 6:
                break;
           case 7:
                break;
           case 8:
                break;
         }
    } while ( flg1 ); /* loop principal */
    CLR_SCREEN
    return 0;
}

