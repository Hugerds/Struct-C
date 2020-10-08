#include <stdio.h>
#include <time.h>


int main( int argc, char * argv[] )
{
    time_t agora;
    char datahora[100];

    /* Recupera a quantidade de segundos desde 01/01/1970 */
    agora = time(NULL);

    /* Formata a data e a hora da forma desejada */
    strftime( datahora, sizeof(datahora), "%d.%m.%Y - %H:%M:%S", localtime( &agora ) );

    printf( "Data/Hora: %s\n", datahora );

    return 0;
}
