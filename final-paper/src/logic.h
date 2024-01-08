#ifndef LOGIC_H
#define LOGIC_H

#include "types.h"

/**
 * @file logic.h
 * @brief Cabeçalho das funções principais de lógica do programa.
 *
 * Este ficheiro de cabeçalho define as interfaces das funções principais relacionadas à lógica
 * do programa. Inclui funções para gerir os planos alimentares dos pacientes, calcular a ingestão
 * calórica, listar e comparar refeições planeadas, entre outras operações essenciais. As funções
 * aqui declaradas são cruciais para a execução das principais funcionalidades do programa, lidando
 * com a manipulação e análise de dados relacionados a dietas e planos alimentares.
 *
 * As funções declaradas neste ficheiro incluem:
 * - Impressão de tabelas com resumos de planos alimentares e consumo calórico.
 * - Preenchimento de períodos com datas de início e fim.
 * - Cálculo do número de pacientes que excederam um limite de calorias.
 * - Verificação do consumo calórico em relação aos planos alimentares.
 * - Listagem de refeições conforme critérios específicos.
 * - Cálculo da média de calorias consumidas por um paciente.
 *
 * @note Este ficheiro depende das definições das estruturas de dados em 'types.h'.
 */

//Funcoes 

/**
 * @brief Imprime uma tabela com o resumo dos planos alimentares e o consumo calórico dos pacientes.
 *
 * Esta função constrói e imprime uma tabela detalhada que mostra o plano alimentar de cada paciente,
 * incluindo os tipos de refeição, o período de cada plano, as calorias mínimas e máximas estipuladas,
 * e o total de calorias consumidas. A função itera sobre os arrays 'mealPlans' e 'diets', preenchendo
 * uma estrutura auxiliar 'infoTable' para armazenar as informações consolidadas antes de imprimir.
 *
 * @param mealPlans Ponteiro para o array de estruturas 'MealPlan', representando os planos alimentares.
 * @param diets Ponteiro para o array de estruturas 'Diet', representando o consumo de calorias dos pacientes.
 * @param patients Ponteiro para o array de estruturas 'Patients', contendo informações sobre os pacientes.
 * @param max_size Tamanho máximo dos arrays 'mealPlans', 'diets' e 'patients'.
 *
 * @note Esta função pressupõe que os arrays 'mealPlans', 'diets' e 'patients' são válidos e que o tamanho máximo
 *       dos arrays é respeitado. Além disso, assume-se que os IDs dos pacientes são únicos.
 *
 * @warning A função utiliza um array fixo 'infoTable' de tamanho 100 para armazenar as informações consolidadas.
 *          Se houver mais de 100 pacientes únicos, a tabela não poderá representar todos eles.
 */
void printTable(MealPlan *mealPlans, Diet *diets, Patients *patients, int max_size);

/**
 * @brief Calcula o número de pacientes que excederam um limite de calorias num determinado período.
 *
 * Esta função percorre um array de estruturas 'Diet' e identifica quantos pacientes
 * consumiram mais calorias do que o limite especificado durante um período de tempo definido.
 * Usa um array auxiliar 'idCalories' para armazenar e somar as calorias consumidas por cada paciente.
 *
 * @param diet Ponteiro para o array de estruturas 'Diet', que contém os dados de consumo de calorias.
 * @param max_size Tamanho máximo do array 'diet'.
 * @param calories Limite de calorias a ser considerado para determinar o excesso de consumo.
 * @param period Estrutura 'Period' que define o período de tempo durante o qual o consumo é avaliado.
 *
 * @return Retorna o número de pacientes que excederam o limite de calorias no período especificado.
 *         Retorna -1 se o número de pacientes únicos exceder 100, indicando que o limite do array foi atingido.
 *
 * @note Esta função pressupõe que o array 'diet' e a estrutura 'period' são válidos e que o tamanho máximo
 *       do array 'diet' é respeitado nas chamadas da função.
 *
 * @warning A função utiliza um array fixo de tamanho 100 para rastrear os pacientes. Se houver mais de 100
 *          pacientes únicos no período especificado, a função não poderá rastreá-los todos e retornará -1.
 */
int exceededCalories(Diet *diet,int max_size, int calories, Period period);

/**
 * @brief Calcula o número de pacientes cuja ingestão calórica está fora do intervalo definido no seu plano de refeições.
 *
 * Esta função compara o consumo calórico dos pacientes, registrado no array 'diet', com os intervalos
 * calóricos definidos no seu plano de refeições, 'mealPlan', durante um determinado período. Os IDs dos
 * pacientes cuja ingestão calórica esteja fora do intervalo são armazenados e contados.
 *
 * @param diet Ponteiro para o array de estruturas 'Diet', que contém os dados de consumo de calorias dos pacientes.
 * @param mealPlan Ponteiro para o array de estruturas 'MealPlan', que define os intervalos calóricos para os pacientes.
 * @param period Estrutura 'Period' que define o período de tempo durante o qual o consumo é avaliado.
 * @param max_size Tamanho máximo dos arrays 'diet' e 'mealPlan'.
 *
 * @return Retorna o número de pacientes cujo consumo de calorias está fora do intervalo estipulado no seu plano de refeições.
 *
 * @note Esta função pressupõe que os arrays 'diet' e 'mealPlan' são válidos, e que o tamanho máximo dos arrays é respeitado.
 *       Além disso, assume-se que os IDs dos pacientes são únicos.
 *
 * @warning A função utiliza um array fixo de tamanho 100 para armazenar os IDs dos pacientes. Se houver mais de 100
 *          pacientes únicos no período especificado, a função não poderá rastrear todos e os resultados podem não ser completos.
 */
int outOfRange(Diet *diet, MealPlan *mealPlan, Period period, int max_size);

/**
 * @brief Lista as refeições de um plano alimentar para um paciente específico num dado período.
 *
 * Esta função percorre um array de estruturas 'MealPlan', listando as refeições que correspondem
 * a um determinado tipo e que foram planeadas para um paciente específico durante um período definido.
 * A função imprime os detalhes de cada refeição encontrada, incluindo datas e intervalos calóricos.
 *
 * @param mealPlan Ponteiro para o array de estruturas 'MealPlan', representando o plano de refeições.
 * @param period Estrutura 'Period' que define o período de tempo durante o qual as refeições são listadas.
 * @param max_size Tamanho máximo do array 'mealPlan'.
 * @param mealType String que representa o tipo de refeição a ser listada (ex: "almoço", "jantar").
 * @param IDNum Identificador numérico do paciente para o qual as refeições serão listadas.
 *
 * @return Retorna o número de refeições listadas que correspondem aos critérios especificados.
 *
 * @note Esta função pressupõe que o array 'mealPlan' é válido e que o tamanho máximo do array é respeitado.
 *       Além disso, assume-se que a string 'mealType' e a estrutura 'period' são válidas.
 *
 * @warning A função imprime diretamente para o standard output e não realiza a formatação avançada ou a paginação
 *          dos resultados, podendo ser menos adequada para grandes conjuntos de dados ou para a integração em interfaces
 *          de utilizador mais complexas.
 */
int listMealPlan(MealPlan *mealPlan, Period period, int max_size, char *mealType, int IDNum);

/**
 * @brief Calcula a média de calorias consumidas por um paciente num tipo específico de refeição durante um período.
 *
 * Esta função percorre um array de estruturas 'Diet', somando e contabilizando as calorias consumidas
 * pelo paciente especificado, para um tipo específico de refeição, dentro do período definido.
 * A média de calorias é calculada com base no total de calorias consumidas e no número de refeições contabilizadas.
 *
 * @param diet Ponteiro para o array de estruturas 'Diet', que contém os dados de consumo de calorias dos pacientes.
 * @param period Estrutura 'Period' que define o período de tempo durante o qual o consumo é avaliado.
 * @param max_size Tamanho máximo do array 'diet'.
 * @param mealType String que especifica o tipo de refeição a ser considerada no cálculo (ex: "almoço", "jantar").
 * @param IDNum Identificador numérico do paciente cuja média de calorias será calculada.
 *
 * @return Retorna a média de calorias consumidas pelo paciente para o tipo de refeição especificado no período dado.
 *         Se não forem encontradas refeições correspondentes, retorna 0.0.
 *
 * @note Esta função pressupõe que o array 'diet' é válido, e que o tamanho máximo do array e a estrutura 'period' são respeitados.
 *       Além disso, assume-se que a string 'mealType' é válida.
 *
 * @warning A função não verifica se a string 'mealType' corresponde a um tipo de refeição existente no array 'diet', dependendo
 *          da consistência dos dados fornecidos.
 */
float averageCalories(Diet *diet, Period period, int max_size, char *mealType, int IDNum);

#endif // LOGIC_H
