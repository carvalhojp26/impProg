#ifndef UTILS_H
#define UTILS_H

#include "types.h"

/**
 * @file utils.h
 * @brief Cabeçalho das funções de utilidade para o programa.
 *
 * Este ficheiro de cabeçalho contém as declarações das funções de utilidade usadas
 * em várias partes do programa. Inclui funções para leitura de ficheiros, manipulação
 * de datas, ordenação de arrays, impressão de datas e períodos, e limpeza do buffer de entrada.
 * As funções aqui definidas são auxiliares à lógica principal do programa e são utilizadas
 * para realizar operações comuns de forma eficiente.
 *
 * @note Este ficheiro inclui 'types.h', que contém as definições das estruturas de dados utilizadas
 *       nas funções declaradas.
 *
 * As funções implementadas oferecem operações como:
 * - Leitura de dados de ficheiros com formatos específicos.
 * - Verificação se uma data está dentro de um período especificado.
 * - Ordenação de arrays de inteiros em ordem decrescente.
 * - Impressão formatada de datas e períodos.
 * - Limpeza do buffer de entrada para evitar leituras indesejadas.
 */

/**
 * @brief Lê dados de um ficheiro e armazena-os numa estrutura de dados especificada.
 *
 * Esta função abre um ficheiro no caminho especificado e lê os seus conteúdos linha por linha,
 * armazenando os dados numa estrutura de acordo com o tipo de ficheiro fornecido. As estruturas
 * suportadas são 'Patients', 'Diet' e 'MealPlan'. A função é capaz de interpretar diferentes formatos
 * de dados com base no tipo de ficheiro fornecido.
 *
 * @param path Caminho para o ficheiro a ser lido.
 * @param data Ponteiro para a estrutura de dados onde os dados lidos serão armazenados.
 * @param max_size Número máximo de elementos a serem lidos e armazenados na estrutura de dados.
 * @param fileType Enumeração 'FileType' que indica o tipo de dados esperado no ficheiro (ex: PATIENTS, DIET, MEAL_PLAN).
 *
 * @return Retorna o número de elementos lidos e armazenados com sucesso na estrutura de dados.
 *         Retorna 0 se não for possível abrir o ficheiro ou se o tipo de ficheiro não for suportado.
 *
 * @note A função pressupõe que o ponteiro 'data' é válido e que o espaço de memória suficiente foi alocado para armazenar os dados.
 *
 * @warning Esta função não realiza verificações extensivas de validade dos dados lidos do ficheiro. A validade e consistência
 *          dos dados no ficheiro são assumidas como corretas.
 */
int readFile(char *path, void *data, int max_size, FileType fileType);

/**
 * @brief Verifica se uma data específica está dentro de um determinado período.
 *
 * Esta função avalia se uma data fornecida está antes, dentro ou depois de um período especificado.
 * O período é definido por uma data de início e uma data de fim. A função compara a data fornecida
 * com as datas de início e fim do período, determinando a sua relação temporal com o mesmo.
 *
 * @param date Estrutura 'Date' representando a data a ser verificada.
 * @param period Estrutura 'Period' representando o período contra o qual a data será comparada.
 *
 * @return Retorna -1 se a data estiver antes do período, 1 se estiver dentro do período, e 2 se estiver após o período.
 *
 * @note Esta função assume que as estruturas 'Date' e 'Period' são válidas e que as datas estão no formato correto.
 *
 * @warning A função não verifica a coerência do período em si (por exemplo, se a data de início é anterior à data de fim).
 */
int dateInPeriod(Date date, Period period);

/**
 * @brief Ordena um array de inteiros em ordem decrescente.
 *
 * Esta função realiza a ordenação de um array de inteiros utilizando o algoritmo de ordenação
 * 'bubble sort' modificado. A ordenação é feita em ordem decrescente, onde o maior elemento é colocado
 * no início do array e o menor no final. O algoritmo compara pares de elementos adjacentes e os troca
 * de lugar se estiverem na ordem errada, continuando este processo até que todo o array esteja ordenado.
 *
 * @param ids Array de inteiros que será ordenado.
 * @param numberEl Número de elementos no array 'ids'.
 *
 * @note A função modifica o array 'ids' diretamente. Portanto, o array original será alterado para refletir
 *       a nova ordem dos elementos.
 *
 * @warning A função assume que o tamanho do array 'ids' é pelo menos igual a 'numberEl'. Passar um valor
 *          de 'numberEl' maior do que o tamanho real do array pode resultar em comportamento indefinido.
 */
void sortDescending(int ids[], int numberEl);

/**
 * @brief Imprime uma data no formato padrão DD-MM-AAAA.
 *
 * Esta função recebe uma estrutura 'Date' e imprime-a no standard output (stdout) no formato
 * dia-mês-ano (DD-MM-AAAA), onde DD é o dia, MM é o mês e AAAA é o ano. A função é útil para
 * exibir datas de forma legível e padronizada.
 *
 * @param date Estrutura 'Date' que contém a data a ser impressa.
 *
 * @note Esta função assume que a estrutura 'Date' fornecida é válida e que os valores de dia, mês
 *       e ano estão dentro de intervalos aceitáveis para representar uma data válida.
 *
 * @warning A função não realiza validação da data fornecida; portanto, a validade da data (como dias
 *          corretos para determinados meses, anos bissextos, etc.) deve ser garantida antes de chamar esta função.
 */
void printDate(Date date);

/**
 * @brief Imprime um período, mostrando as datas de início e fim.
 *
 * Esta função recebe uma estrutura 'Period' e imprime as datas de início e fim do período
 * no standard output (stdout). Utiliza a função 'printDate' para imprimir as datas de início e fim
 * no formato padrão. É útil para exibir períodos de forma legível e clara, mostrando claramente a
 * duração de um intervalo de tempo.
 *
 * @param period Estrutura 'Period' que contém as datas de início e fim a serem impressas.
 *
 * @note Esta função assume que as datas de início e fim dentro da estrutura 'Period' são válidas e
 *       que a data de início precede a data de fim.
 *
 * @warning A função não realiza validação das datas dentro do período; portanto, a coerência do
 *          período (como a data de início sendo anterior à data de fim) deve ser garantida antes de chamar esta função.
 */
void printPeriod(Period period);

/**
 * @brief Limpa o buffer de entrada do standard input (stdin).
 *
 * Esta função remove todos os caracteres remanescentes no buffer de entrada do stdin até
 * encontrar um caractere de nova linha ('\n') ou o fim do ficheiro (EOF). É particularmente
 * útil após a leitura de dados de entrada para garantir que nenhuma entrada indesejada
 * permaneça no buffer e afete leituras futuras.
 *
 * @note Esta função deve ser utilizada com cuidado, especialmente em ambientes onde o buffer
 *       de entrada pode conter dados relevantes que não devem ser descartados.
 *
 * @warning A função pode bloquear a execução se não houver dados no buffer de entrada e não for
 *          atingido o fim do ficheiro, especialmente em ambientes não interativos.
 */
void clearInputBuffer();

/**
 * @brief Preenche um período com datas de início e fim.
 *
 * Esta função solicita ao utilizador que introduza as datas de início e fim de um período.
 * As datas são lidas do standard input (teclado) e armazenadas na estrutura de período fornecida.
 *
 * @param period Ponteiro para a estrutura de período que será preenchida.
 *               Espera-se que este ponteiro seja válido e não seja NULL.
 *
 * @warning A função usa `scanf` para leitura de dados, o que pode levar a erros de entrada
 *          se o formato esperado não for respeitado.
 *
 * Exemplo de uso:
 * @code
 * Period meuPeriodo;
 * fillPeriod(&meuPeriodo);
 * @endcode
 */
void fillPeriod(Period *period);

#endif // UTILS_H
