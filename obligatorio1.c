#include <stdio.h>
#include "bits.h"

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
        printf("Autor : Daniel Sanchez\n");
        printf("------------------------------------------\n");
        for(aux1 = 0 ; msg[aux1] ; aux1++ )
            printf("%s\n",msg[aux1]);
        printf("Opcion: "); scanf("%d", &menu); getchar();
        switch( menu )
        {
            case 0:
                flg1=0;
                break;
           case 1:         /* bit */
                {
                    int buf, nb , sal ;
                    printf(" Valor del buffer: "); scanf("%d",&buf);getchar();
                    printf(" Bit numero:");scanf("%d",&nb);getchar();
                    sal = bit(buf,nb);
                    if ( sal == -1 )
                        printf("Error en fun bit, parametro incorrecto\n" );
                    printf("buffer: "); print_binario(buf,32);
                    printf(" El bit numero %d del buffer %d es %d\n",nb,buf, bit(buf,nb) );
                    printf("Enter para continuar");getchar();
                }
                break;
           case 2:         /*  ver_binario */
                {
                    int buf, nb ;
                    printf("Valor del buffer:"); scanf("%d",&buf);getchar();
                    printf("Cantidad de bit:"); scanf("%d",&nb);getchar();
                    if( ver_binario( buf, nb,stdout ) == -1 )
                        printf("Error en ver_binario: argumento incorrecto \n");
                    printf("\nEnter para continuar");getchar();
                }
                break;
           case 3:         /* print_binario */
                {
                    int buf, nb ;
                    printf("Valor del buffer:"); scanf("%d",&buf);getchar();
                    printf("Cantidad de bits:"); scanf("%d",&nb);getchar();
                    print_binario( buf, nb );
                    printf("Enter para continuar");getchar();
                }
                break;
           case 4:         /*  setbit */
                {
                    int buf, nb , val_ent, val_sal ;
                    printf("Valor del buffer: "); scanf("%d",&buf); getchar();
                    print_binario( buf, 32 );
                    printf("Bit numero: "); scanf("%d",&nb); getchar();
                    printf("Valor a setear:"); scanf("%d",&val_ent); getchar();
                    val_sal = setbit(buf,nb,val_ent);
                    printf("El buffer seteado es : %d\n", val_sal );
                    print_binario( val_sal, 32 );
                    printf("Enter para continuar");getchar();
                }
                break;
           case 5:         /* concatena  */
                {
                    int buf, nb , codigo, sal ;
                    printf("Valor del buffer:"); scanf("%d",&buf); getchar();
                    printf("Valor del codigo:"); scanf("%d",&codigo); getchar();
                    printf("Cantidad de bits:"); scanf("%d",&nb); getchar();
                    sal = concatena( buf, codigo , nb );
                    printf("Resultado: %d\n", sal );
                    print_binario(sal,32);
                    printf("Enter para continuar");getchar();
                }
                break;
           case 6:         /* crear_mascara */
                {
                    int  max, min ;
                    unsigned int sal;
                    printf("Valor Maximo:"); scanf("%d",&max); getchar();
                    printf("Valor Minimo:"); scanf("%d",&min); getchar();
                    sal = crear_mascara( max, min) ;
                    printf("Valor de mascara : "); print_binario(sal,32);
                    printf("Enter para continuar");getchar();
                }
                break;
           case 7:        /* espejar */
                {
                    int buf, nb ,  sal ;
                    printf("Valor del buffer:"); scanf("%d",&buf); getchar();
                    printf("Cantidad de bits:"); scanf("%d",&nb); getchar();
                    printf("Valor buffer: "); print_binario( buf, 32);
                    sal = espejar( buf, nb );
                    printf("Valor espejado: %d\n",sal); print_binario( sal,32);
                    printf("Enter para continuar");getchar();
                }
                break;
           case 8:         /* extraer */
                {
                    int buf, min, max, sal ;
                    printf("Valor del buffer:"); scanf("%d",&buf); getchar();
                    printf("Valor min:"); scanf("%d",&min); getchar();
                    printf("Valor max:"); scanf("%d",&max); getchar();
                    printf("Valor del buffer:"); print_binario(buf,32);
                    sal = extraer( buf, min, max );
                    printf("Valor extraido  :"); print_binario(sal,32);
                    printf("Enter para continuar"); getchar();
                }
                break;
         }
    } while ( flg1 ); /* loop principal */
    CLR_SCREEN
    return 0;
}

