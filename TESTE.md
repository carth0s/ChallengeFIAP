# Proposta Técnica Documentada

## Objetivos

A interrupção inesperada em linhas de produção industrial acarreta significativas perdas financeiras e operacionais. Diante desse cenário, propomos uma solução digital abrangente para a prevenção de falhas, utilizando os pilares da Inteligência Artificial (IA), Internet das Coisas (IoT) e análise de dados. Nossa proposta visa monitorar equipamentos em tempo real, identificar padrões preditivos de falhas e fornecer insights acionáveis por meio de dashboards e relatórios automatizados, capacitando a empresa a adotar medidas preventivas eficazes.


## Justificativa do Problema e Descrição da Solução Proposta

**Justificativa do Problema:** A proposta do desafio é aplicar os conhecimentos do curso de IA a um problema real, considerando o contexto de empresas que enfrentam interrupções inesperadas em seus processos produtivos, o que gera perdas financeiras e operacionais.

**Descrição da Solução Proposta:** A arquitetura da nossa solução será baseada em uma abordagem modular e escalável, utilizando tecnologias que se complementam para garantir a coleta, armazenamento, processamento, análise e visualização dos dados de forma eficiente Segue abaixo as tecnologias:

## Definição das Tecnologias

**Sensor:** ESP32

**Linguagens de Programação:** Python, R, SQL, C/C++

**Bibliotecas de IA:** TensorFlow, Keras, Pandas

**Serviços de Nuvem:** AWS

**Banco de Dados:** AWS S3, PostgreSQL


## justificativa da tecnologia e passo a passo:


## Coleta de Dados:
•	Fonte dos Dados: Os dados serão coletados em tempo real a partir de diversos sensores instalados nos equipamentos da linha de produção. Esses sensores podem monitorar variáveis como: 

o	Temperatura
o	Vibração
o	Nível de ruído
o	Consumo de energia
o	Pressão
o	Velocidade de rotação
o	Outras métricas específicas de cada equipamento.

•	Tecnologia de Coleta (Simulação Inicial / Planejamento Real): 
o	Simulação Inicial: Para a fase inicial do projeto e fins de demonstração, os dados poderão ser simulados utilizando Python. Serão gerados datasets sintéticos que imitam o comportamento de sensores reais, incluindo padrões normais e anomalias que simulam falhas.
o	Planejamento Real: Em um cenário de implementação real, utilizaríamos microcontroladores com conectividade Wi-Fi, como o ESP32. Esses dispositivos são capazes de ler os dados dos sensores e transmiti-los de forma contínua para um gateway IoT.

•	Gateway IoT: Um gateway IoT atuará como intermediário entre os sensores e o banco de dados. Ele será responsável por: 
o	Receber os dados brutos dos sensores.
o	Realizar um pré-processamento básico (filtragem, agregação inicial).
o	Garantir a comunicação segura e eficiente dos dados para a camada de armazenamento.

2.2. Armazenamento de Dados:
•	Optamos por um banco de dados em nuvem, AWS S3 e PostgreSQL.
•	Justificativa: 
o	Escalabilidade: A nuvem oferece alta escalabilidade, permitindo aumentar ou diminuir a capacidade de armazenamento conforme o volume de dados gerado pela linha de produção evolui.
o	Disponibilidade e Confiabilidade: Os serviços de banco de dados em nuvem garantem alta disponibilidade e mecanismos de backup e recuperação robustos, minimizando o risco de perda de dados.
o	Gerenciamento: A gestão do banco de dados é simplificada, com tarefas como patching, backup e manutenção sendo parcialmente ou totalmente gerenciadas pelo provedor de nuvem.
o	Custo: Para a fase inicial, um banco de dados de menor porte na nuvem pode ser mais viável financeiramente do que a implementação e manutenção de uma infraestrutura local robusta.

2.3. Camada de Processamento:
•	Tecnologias de Processamento: A camada de processamento será responsável por preparar os dados para análise e modelagem de IA. Utilizaremos principalmente Python com as bibliotecas Pandas para manipulação e limpeza dos dados e R para análises estatísticas exploratórias e validação de insights.
•	Local de Processamento: O processamento poderá ocorrer tanto em instâncias de computação na nuvem (AWS EC2 ou Google Compute Engine) quanto em um ambiente local, dependendo da sensibilidade dos dados, requisitos de latência e custos. Para a fase inicial, um ambiente local com poder de processamento adequado será suficiente. Em um cenário de produção com grande volume de dados, a escalabilidade da nuvem se torna crucial.
•	Pipeline de Dados: O pipeline de dados consistirá nas seguintes etapas: 
1.	Ingestão: Coleta dos dados do banco de dados.
2.	Limpeza e Pré-processamento: Tratamento de dados faltantes, remoção de ruídos, normalização e transformação das variáveis.
3.	Engenharia de Features: Criação de novas variáveis relevantes para a modelagem preditiva, como médias móveis, taxas de variação e desvios.
4.	Análise Exploratória (R): Utilização de R para identificar padrões iniciais, correlações e tendências nos dados, auxiliando na seleção de features e na compreensão do comportamento das falhas.

2.4. Modelos de Machine Learning:
•	Tecnologias de IA: Utilizaremos bibliotecas de Machine Learning como Scikit-learn para modelos mais tradicionais (Regressão Logística, Árvores de Decisão, Random Forest, Support Vector Machines) e Keras (com backend TensorFlow) para modelos de Deep Learning, especialmente para análise de séries temporais complexas e padrões sutis.
•	Tipos de Modelos: 
o	Classificação: Para prever a probabilidade de ocorrência de uma falha em um determinado horizonte de tempo.
o	Regressão: Para prever o tempo restante até a falha (Remaining Useful Life - RUL).
o	Detecção de Anomalias: Para identificar comportamentos incomuns nos dados dos sensores que podem indicar o início de uma falha.
•	Integração: Os modelos de IA serão treinados utilizando os dados históricos processados e integrados ao pipeline de dados. A inferência (previsão) será realizada em tempo real com os novos dados chegando dos sensores.

2.5. Dashboards e Relatórios Automatizados:
•	Tecnologias de Visualização: Utilizaremos ferramentas de visualização como Python (Matplotlib, Seaborn, Plotly) e plataformas de Business Intelligence (BI) como Tableau ou Power BI para criar dashboards interativos e relatórios automatizados.
•	Conteúdo: Os dashboards e relatórios fornecerão: 
o	Monitoramento em tempo real das métricas dos equipamentos.
o	Indicadores de saúde dos equipamentos (health scores).
o	Alertas visuais de potenciais falhas ou anomalias.
o	Previsões de falhas e o tempo estimado até a ocorrência.
o	Recomendações de ações preventivas (manutenção preditiva).
o	Análise de tendências de falhas ao longo do tempo.
o	Relatórios sumarizados para a gerência com insights e recomendações.


## Informações Adicionais

Este repositório contém a primeira etapa do projeto, que corresponde à definição da metodologia e das tecnologias a serem utilizadas na solução proposta.

# DIVISÃO DE TAREFAS (4 pessoas)

 Carlos + Leonardo ->  Simulação  e recebimento dos dados 

 Mauricio + Carlos ->  Armazenamento + tratamento e pré-processamento dos dados

 Rodrigo + Carlos + Leonardo ->  Treinamento e integração do modelo de IA

 Rodrigo + Mauricio -> Criação do dashboard + 

Todos -> apresentação final + README
