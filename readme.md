# INSTRUÇÕES

Os dois programas executam as funções que foram solicitadas, porém, não é possível que seja feito com a quantidade de dados apresentada no arquivo de texto "source.txt". Dessa forma foi criado um arquivo de texto "sample_mod.txt" com cerca de 12 mil entradas, sendo essas as primeiras que ocorrem no arquivo "sample.txt". Se ocorrer algum problema de erro de segmentação, a variável "arrSize" pode ser modificada em ambos os arquivos.

O programa "armazenador.exe" pega as entradas do arquivo de texto, cujo nome deve ser entrado na linha de comando da seguinte forma:

> armazenador "nome-do-arquivo"

feito isso, o executável ordena as entradas utilizando o algorítmo "quicksort" e as transfere para um arquivo "sorted.txt".

Para executar o programa "buscador.exe" a entrada na linha de comando deve ser a seguinte:

> buscador "data-inicial" "data-final" "identificador1" "identificador2" ... 

O programa, como solicitado, imprime na tela os resultados entre as datas iniciais e finais. O(s) identificador(es) é(são) opcional(ais).