#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "helper.h"

void main(int argc, char* argv[]){

    //tamanho máximo do vetor de dados
    const int arrSize = 20000;

    //inicialização de valores extremos para as datas iniciais e finais
    long long time_min = 0;
    long long time_max = 0;

    //sem argumentos extras inicializado como falso
    bool args = false;

    char argumentos[8][20];//todo

    char *eptr; //apenas para usar na função strtoll 

    char* fileName;
    if (argc < 3)
    {
        printf("Uso: 'buscador [data inicial][data final][opcoes]\n");
        exit(0);
    }
    else if (argc == 3)
    {
        time_min = strtoll(argv[1], &eptr, 10);
        time_max = strtoll(argv[2], &eptr, 10);

    }else if (argc > 3){
        time_min = strtoll(argv[1], &eptr, 10);
        time_max = strtoll(argv[2], &eptr, 10);
        args = true;
        for(int i = 3; i < argc; i++){
            if(strlen(argv[i]) != 8){
                printf("\nIdentificador com formato invalido");
                exit(0);
            }
        }
    }

    FILE* fp = fopen("sorted.txt", "r");
    char buffer[40] = "";
    int count = 0;
    printf("\nEntradas entre as datas de %lld e %lld:\n\n", time_min, time_max);

    unsigned long long time[arrSize];

    //inicializacao e definicao dos vetores
    char** idHex = calloc( arrSize, arrSize * sizeof( char *) );
    for ( int i = 0; i < arrSize; i++ )
    {
        idHex[i] = calloc( 9 , 9 * sizeof(char));
    }

    unsigned long long idPerson[arrSize];
    
    //armazenamento dos dados do arquivo nos vetores
    if (fp)
    {     
        fscanf (fp, "%s", &buffer);
        
        time[count] = strtoll(buffer, &eptr, 10);

        strncpy(idHex[count], &buffer[18], 8); idHex[count][9] = '\0';
        char idTemp[13];

        strncpy(idTemp, &buffer[27], 13); //idTemp[13] = '\0';
        idPerson[count] = strtoll(idTemp, &eptr, 10);

        count++;
        //pega os dados do arquivo de texto e transfere para os vetores
        while (!feof (fp) && count < arrSize ) 
            { 
                fscanf (fp, "%s", &buffer);

                time[count] = strtoll(buffer, &eptr, 10);
                
                strncpy(idHex[count], &buffer[18], 8);
                
                //printf("%d\n", count);

                strncpy(idTemp, &buffer[27], 13); //idTemp[13] = '\0';
                idPerson[count] = strtoll(idTemp, &eptr, 10);

                count++;

            }
        fclose (fp);

    }
    else
    {
        exit(0);
    }

    //encontra os índices mínimos e máximos das datas digitadas
    int index_min = modBinarySearch(time, 0, count - 1, time_min, -1);
    int index_max = modBinarySearch(time, 0, count - 1, time_max, 1);
    
    //Quando não há argumentos opcionais
    if (args == false)
    {
        for(int i = index_min; i < index_max ; i++)
        {
            printf("%lld;%s;%lld\n", time[i], idHex[i],idPerson[i] );
        }
    }

    //Quando há argumentos opcionais
    else
    {
        for(int i = index_min; i < index_max ; i++)
        {
            for(int j = 3; j < argc; j++)
            {
                if(strcmp(argv[j],idHex[i]) == 0)
                {
                    printf("%lld;%s;%lld\n", time[i], idHex[i],idPerson[i] );
                }   
            }
        }
    }

    free(idHex);
}