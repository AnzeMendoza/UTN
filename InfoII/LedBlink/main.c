/*-------------------------------------------*/
#include <stdio.h>
/*-------------------------------------------*/
enum ESTADOS{ENCENDIDO, APAGADO, RESET};
static int estado = RESET;
int teclado;
/*-------------------------------------------*/
int tecla(){
    int teclaPresionada;

    scanf("%d", &teclaPresionada);
    return (teclaPresionada);
}
/*-------------------------------------------*/
int cambio(){
    static int estadoAnteriorTecla = 0;
    estadoAnteriorTecla= scanf("%d", &teclado);
    return ()? 1: 0);

}
/*-------------------------------------------*/
void ledOFF(){
    printf("Led apagado\n");
}
/*-------------------------------------------*/
void ledON(){
    printf("Led encendido\n");
}
/*-------------------------------------------*/



int main()
{

    while (1) {

        printf("# %d #\n",cambio());
        /*
        teclado = tecla();

        switch (estado) {
            case RESET:
                ledOFF();
                estado = APAGADO;
            break;

            case ENCENDIDO:
                if(cambio()){
                    ledON();
                    estado = APAGADO;
                }
            break;

            case APAGADO:
                if(cambio()){
                    ledOFF();
                    estado = ENCENDIDO;
                }
            break;

        }
    */
    }

    return 0;
}
