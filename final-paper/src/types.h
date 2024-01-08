#ifndef TYPES_H
#define TYPES_H


/**
 * @file types.h
 * @brief Definição de estruturas de dados e tipos enumerados para o programa.
 *
 * Este ficheiro de cabeçalho contém as definições das principais estruturas de dados e tipos enumerados
 * utilizados no programa. Inclui estruturas para representar datas, períodos, informações de pacientes,
 * detalhes de dietas, planos de refeições e outras informações relevantes. Este ficheiro é a base para a
 * manipulação de dados em todo o programa, fornecendo os blocos de construção essenciais para as operações de lógica e utilidade.
 *
 * As estruturas e tipos enumerados definidos incluem:
 * - 'Date': Representa uma data.
 * - 'Period': Define um período com datas de início e fim.
 * - 'Patients': Armazena informações sobre pacientes.
 * - 'Diet': Detalha uma dieta, incluindo a ingestão calórica.
 * - 'IDCalories': Associa um ID a um valor calórico.
 * - 'MealPlan': Define um plano de refeições com limites calóricos.
 * - 'InfoTable': Estrutura para armazenar e apresentar informações consolidadas.
 * - 'FileType': Enumeração dos tipos de ficheiros para operações de leitura de dados.
 *
 * @note Estas estruturas e tipos enumerados são fundamentais para a estrutura de dados do programa e são amplamente
 *       utilizados nas diversas funções e operações implementadas.
 */

//DataTypes

/**
 * @struct Date
 * @brief Estrutura para representar uma data.
 *
 * Esta estrutura é utilizada para representar uma data, incluindo dia, mês e ano.
 * É ideal para armazenar e manipular datas em diversos contextos dentro do programa,
 * como datas de nascimento, eventos ou outros marcos temporais relevantes.
 *
 * @var Date::day
 * Membro 'day' representa o dia do mês. Deve ser um valor entre 1 e 31, dependendo do mês e do ano.
 *
 * @var Date::month
 * Membro 'month' representa o mês do ano. Deve ser um valor entre 1 (Janeiro) e 12 (Dezembro).
 *
 * @var Date::year
 * Membro 'year' representa o ano. Deve ser um valor inteiro que representa o ano, como 2023.
 */
typedef struct {
        int day;
        int month;
        int year;
} Date;

/**
 * @struct Period
 * @brief Estrutura para representar um período de tempo definido por uma data de início e uma data de fim.
 *
 * Esta estrutura é usada para definir um intervalo de tempo, especificando uma data de início e uma data de fim.
 * Cada uma destas datas é representada por uma estrutura 'Date', que inclui dia, mês e ano.
 * Este tipo de estrutura é particularmente útil para representar períodos de tempo em aplicações que necessitam
 * de gerir eventos, intervalos de disponibilidade, períodos de validade, entre outros.
 *
 * @var Period::begin
 * Membro 'begin' é uma estrutura 'Date' que representa a data de início do período.
 *
 * @var Period::end
 * Membro 'end' é uma estrutura 'Date' que representa a data de fim do período.
 *
 * @note É importante garantir a coerência das datas, onde a data de início deve ser anterior ou igual à data de fim.
 */
typedef struct {
        Date begin;
        Date end;
} Period;

/**
 * @struct Patients
 * @brief Estrutura para representar as informações de um paciente.
 *
 * Esta estrutura é utilizada para armazenar e manipular dados relacionados aos pacientes.
 * Inclui identificador único, nome e número de telefone. É essencial para gerir informações
 * de pacientes em contextos como clínicas, hospitais, ou qualquer sistema que necessite 
 * manter um registo detalhado dos pacientes.
 *
 * @var Patients::ID
 * Membro 'ID' representa um identificador único para o paciente. É um valor inteiro.
 *
 * @var Patients::name
 * Membro 'name' armazena o nome do paciente. É uma cadeia de caracteres com um tamanho máximo de 50 caracteres.
 *
 * @var Patients::phoneNumber
 * Membro 'phoneNumber' armazena o número de telefone do paciente. É um valor inteiro que representa o número de telefone.
 */
typedef struct {
        int ID;
        char name[50];
        int phoneNumber;
} Patients;

/**
 * @struct Diet
 * @brief Estrutura para representar informações sobre a dieta de um paciente.
 *
 * Esta estrutura é utilizada para armazenar detalhes sobre as refeições consumidas por um paciente,
 * incluindo a data da refeição, o tipo de refeição, os alimentos consumidos e o total de calorias.
 * É essencial para sistemas de gestão de saúde ou nutrição, onde é necessário monitorizar e analisar
 * a dieta e o consumo calórico dos pacientes.
 *
 * @var Diet::ID
 * Membro 'ID' representa um identificador único para o paciente associado a esta entrada da dieta.
 * É um valor inteiro.
 *
 * @var Diet::date
 * Membro 'date' armazena a data em que a refeição foi consumida. É uma estrutura 'Date' que inclui dia, mês e ano.
 *
 * @var Diet::meal
 * Membro 'meal' armazena o tipo de refeição (por exemplo, 'almoço', 'jantar'). É uma cadeia de caracteres com um tamanho máximo de 50 caracteres.
 *
 * @var Diet::food
 * Membro 'food' descreve os alimentos consumidos na refeição. É uma cadeia de caracteres com um tamanho máximo de 50 caracteres.
 *
 * @var Diet::calories
 * Membro 'calories' representa o total de calorias consumidas na refeição. É um valor inteiro.
 */
typedef struct {
        int ID;
        Date date;
        char meal[50];
        char food[50];
        int calories;
} Diet;

/**
 * @struct IDCalories
 * @brief Estrutura para representar o consumo de calorias associado a um identificador de paciente.
 *
 * Esta estrutura é usada para associar um identificador de paciente (ID) com a quantidade de calorias consumidas.
 * É particularmente útil em sistemas de monitorização nutricional ou de saúde, onde é necessário acompanhar
 * e analisar o consumo calórico dos pacientes. A estrutura permite uma rápida correlação entre o paciente 
 * e suas calorias consumidas, facilitando o processamento e análise desses dados.
 *
 * @var IDCalories::ID
 * Membro 'ID' representa um identificador único do paciente. É um valor inteiro.
 *
 * @var IDCalories::calories
 * Membro 'calories' armazena o total de calorias consumidas pelo paciente. É um valor inteiro que representa
 * o consumo calórico.
 */
typedef struct {
        int ID;
        int calories;
} IDCalories;

/**
 * @struct MealPlan
 * @brief Estrutura para representar um plano alimentar para um paciente.
 *
 * Esta estrutura é utilizada para armazenar informações detalhadas sobre um plano alimentar específico
 * de um paciente. Inclui um identificador do paciente, a data da refeição planeada, o tipo de refeição, 
 * e os limites de calorias (mínimo e máximo) estipulados para essa refeição. É essencial para a gestão 
 * e monitorização de planos nutricionais em contextos clínicos ou de saúde e bem-estar, permitindo o 
 * acompanhamento e a adequação da ingestão calórica às necessidades individuais de cada paciente.
 *
 * @var MealPlan::ID
 * Membro 'ID' representa o identificador único do paciente a quem o plano alimentar se destina. É um valor inteiro.
 *
 * @var MealPlan::date
 * Membro 'date' armazena a data em que a refeição planeada deve ser consumida. É uma estrutura 'Date' que inclui dia, mês e ano.
 *
 * @var MealPlan::meal
 * Membro 'meal' armazena o tipo de refeição planeada (por exemplo, 'almoço', 'jantar'). É uma cadeia de caracteres com um tamanho máximo de 50 caracteres.
 *
 * @var MealPlan::minCal
 * Membro 'minCal' define o limite mínimo de calorias recomendado para a refeição. É um valor inteiro.
 *
 * @var MealPlan::maxCal
 * Membro 'maxCal' define o limite máximo de calorias recomendado para a refeição. É um valor inteiro.
 */
typedef struct {
        int ID;
        Date date;
        char meal[50];
        int minCal;
        int maxCal;
} MealPlan;

/**
 * @struct InfoTable
 * @brief Estrutura para representar informações detalhadas de um plano alimentar e o consumo real de um paciente.
 *
 * Esta estrutura é usada para combinar informações sobre um paciente com detalhes específicos de uma refeição,
 * incluindo o período em que a refeição está planeada, o intervalo calórico recomendado (mínimo e máximo) e o total
 * de calorias efetivamente consumidas. Serve como um registro abrangente para comparar o plano alimentar proposto
 * com o consumo real, permitindo análises e ajustes no acompanhamento nutricional do paciente.
 *
 * @var InfoTable::patient
 * Membro 'patient' armazena informações sobre o paciente. É uma estrutura 'Patients' que inclui identificador, nome e número de telefone.
 *
 * @var InfoTable::meal
 * Membro 'meal' representa o tipo de refeição planeada (por exemplo, 'almoço', 'jantar'). É uma cadeia de caracteres com um tamanho máximo de 50 caracteres.
 *
 * @var InfoTable::period
 * Membro 'period' define o período de tempo para o qual o plano alimentar é válido. É uma estrutura 'Period' que inclui datas de início e fim.
 *
 * @var InfoTable::minCal
 * Membro 'minCal' especifica o limite mínimo de calorias recomendado para a refeição. É um valor inteiro.
 *
 * @var InfoTable::maxCal
 * Membro 'maxCal' especifica o limite máximo de calorias recomendado para a refeição. É um valor inteiro.
 *
 * @var InfoTable::calories
 * Membro 'calories' representa o total de calorias consumidas pelo paciente na refeição. É um valor inteiro que ajuda a monitorizar a adesão ao plano alimentar.
 */
typedef struct {
        Patients patient;
        char meal[50];
        Period period;
        int minCal;
        int maxCal;
        int calories;
} InfoTable;

/**
 * @enum FileType
 * @brief Enumeração para representar diferentes tipos de ficheiros utilizados no sistema.
 *
 * Esta enumeração é usada para distinguir entre diferentes tipos de ficheiros de dados
 * que podem ser lidos e processados pelo programa. Facilita a manipulação e o processamento
 * de diferentes conjuntos de dados, permitindo que o programa identifique e trate
 * adequadamente cada tipo de ficheiro.
 *
 * @var FileType::PATIENTS
 * Representa um ficheiro de dados contendo informações sobre pacientes.
 *
 * @var FileType::DIET
 * Representa um ficheiro de dados contendo informações sobre as dietas dos pacientes.
 *
 * @var FileType::MEAL_PLAN
 * Representa um ficheiro de dados contendo informações sobre os planos alimentares dos pacientes.
 */
typedef enum {
        PATIENTS,
        DIET,
        MEAL_PLAN
} FileType;

#endif // TYPES_H
