#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//// funciones para el juego
///fun para inicializar tablero
    void iniciatab(char tablero[3][3] ){
     int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tablero[i][j] = ' ';

        }
    }
    }
///fun para mostrar tablero
    void showtab(char tablero [3][3]){
      printf("c 0   1   2\n");
     for (int i = 0; i < 3; i++) {
            printf("%d ", i);
         printf("f");
         for (int j = 0; j < 3; j++) {

            printf("[ %c ]", tablero[i][j]);
     }
      printf("\n");
    }
    }
///fun verificar ganador
    int ver_ganador(char tablero[3][3]){
    int i,j;
 //para filas

    for (i=0;i<3; i++){

    if(tablero[i][0]==tablero[i][1]&&tablero[i][1]==tablero[i][2]&&tablero[i][0]!=' ')
        {
            return 1;

        }
    }

  // para las columnas
    for ( j=0; j < 3; j++){

    if(tablero[0][j]==tablero[1][j]&&tablero[1][j]==tablero[2][j]&&tablero[0][j]!=' ')
        {
            return 1;

        }
    }
 // para diagonales
    if(tablero[0][0]==tablero[1][1]&&tablero[1][1]==tablero[2][2]&& tablero[0][0]!=' '){
        return 1;
    }
    if (tablero[0][2]==tablero[1][1]&&tablero[1][1]==tablero[2][0]&&tablero[0][2]!=' '){
        return 1;
    }
      return 0;
    }
///tablero lleno
    int tablleno(char tablero[3][3]){
    for(int i=0;i<3;i++){
        for(int j =0; j<3; j++){
            if (tablero[i][j]==' '){
                return 0;
            }
        }
    }
            return 1;
    }

int main() {
    printf(" BIENVENIDO! \n  ");
    printf(" # JUEGO DEL GATO # \n  ");

    char tablero[3][3];
    iniciatab(tablero);
    showtab(tablero);
    int i,j;

    char start[3];
    printf(" INICIAR PARTIDA \n  SI DESEA INICIAR LA PARTIDA ESCRIBA si. \n PARA CERRAR EL JUEGO ESCRIBA  no \n ");
    scanf("%s", start);

    int fila, columna, turno = 1;
    if (strcmp(start, "si") == 0) {
        printf("INICIANDO PARTIDA \n\n");
        do {
            if (turno % 2 == 1) {
                do {
                    printf("\nJUGADOR 1 x \n");
                    printf("ELIGE UNA FILA (del 0 al 2) \n");
                    scanf("%d", &fila);
                    printf("ELIGE UNA COLUMNA (del 0 al 2) \n");
                    scanf("%d", &columna);
                    if (tablero[fila][columna] == 'x' || tablero[fila][columna] == 'o') {
                        puts("ESTA CASILLA YA ESTA OCUPADA, SELECCIONA OTRA.\n");
                    }
                } while (tablero[fila][columna] == 'x' || tablero[fila][columna] == 'o');
                tablero[fila][columna] = 'x';
            } else {
                do {
                    printf("\nJUGADOR 2 o \n");
                    printf("ELIGE UNA FILA (del 0 al 2) \n");
                    scanf("%d", &fila);
                    printf("ELIGE UNA COLUMNA (del 0 al 2) \n");
                    scanf("%d", &columna);
                    if (tablero[fila][columna] == 'x' || tablero[fila][columna] == 'o') {
                        puts("ESTA CASILLA YA ESTA OCUPADA, SELECCIONA OTRA.\n");
                    }
                } while (tablero[fila][columna] == 'x' || tablero[fila][columna] == 'o');
                tablero[fila][columna] = 'o';
            }

            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    printf("[ %c ]", tablero[i][j]);
                }
                printf("\n");
            }

            if (ver_ganador(tablero)) {
                if (turno % 2 == 1) {
                    printf("\nX JUGADOR 1 GANA! X\n");
                } else {
                    printf("\nO JUGADOR 2 GANA! O\n");
                }
                break;
            }

            if (tablleno(tablero)) {
                printf("\n EMPATE! \n");
                break;
            }

            turno++;
        } while (1);
    }
    // Opciones extra
    else if (strcmp(start, "no") == 0) {
        printf("HASTA LA PROXIMA");
    } else {
        printf("OPCION NO VALIDA");
    }

    return 0;
}
