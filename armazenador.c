#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "helper.h"

void main(int argc, char *argv[])
{
    //recebendo nome do arquivo do usuário
    char* fileName;
    if (argc != 2)
    {
        printf("Uso: 'armazenador [nome_do_arquivo]'\n");
        exit(0);
    }
    else
    {
        fileName = argv[1];
    }

    int arrSize = 20000;

    FILE* fp = fopen(fileName, "r");
    char buffer[40] = "";
    int count = 0;

    char *eptr;//apenas para usar na recursão da função strtoll

    //definicao dos vetores
    long long time[arrSize];

    char **idHex = calloc(arrSize, arrSize * sizeof(char *));
    for (int i = 0; i < arrSize; i++)
    {
        idHex[i] = calloc(9, 9 * sizeof(char));
    }

    long long idPerson[arrSize];

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
        while (!feof (fp) && count <= arrSize ) 
            { 
                fscanf (fp, "%s", &buffer);
                time[count] = strtoll(buffer, &eptr, 10);
                strncpy(idHex[count], &buffer[18], 8);
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

    printf("\nQuantidade de dados: %d\n", count);
    printf("Arquivo 'sorted.txt' criado.\n");

    quickSort(time, idHex, idPerson, 0, count - 1);

    FILE* fpw = fopen("sorted.txt", "w");

    //salva no arquivo os dados ordenados
    if (fpw)
    {
        for(int i = 0; i < count ; i++)
        {
            fprintf(fpw, "%lld;%s;%lld\n", time[i], idHex[i],idPerson[i] );
        }
        fclose (fpw);    
    }
    else
    {
        printf("\nMal sucedido.");
        exit(0);
    }

    free(time);
    free(idHex);
    free(idPerson);
}