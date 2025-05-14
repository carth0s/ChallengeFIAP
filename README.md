# FIAP - Faculdade de Informática e Administração Paulista 

<p align="center">
<a href= "https://www.fiap.com.br/"><img src="assets/logo-fiap.png" alt="FIAP - Faculdade de Informática e Admnistração Paulista" border="0" width=40% height=40%></a>
</p>

<br>

# CHALLENGE REPLY

## Integrantes: 
- Carlos Daniel Silveira Do Nascimento - RM88439
- Leandro dos Santos Ribeiro - RM562633
- Mauricio Jose Ferlin Tonnera - RM565469
- Rodrigo Portugal Santos - RM564773

## Professores:
### Tutor(a) 
- Nome do Tutor
### Coordenador(a)
- Nome do Coordenador


## Objetivos

A interrupção inesperada em linhas de produção industrial acarreta perdas financeiras e operacionais significativas. Diante desse cenário, propomos uma solução digital abrangente para a prevenção de falhas, com base nos pilares da Inteligência Artificial (IA), Internet das Coisas (IoT) e análise de dados. Nossa proposta visa monitorar os equipamentos em tempo real, identificar padrões preditivos de falhas e fornecer insights acionáveis por meio de dashboards e relatórios automatizados, capacitando a empresa a adotar medidas preventivas eficazes.

## Justificativa do Problema

A proposta do desafio é aplicar os conhecimentos do curso de IA a um problema real, considerando o contexto de empresas que enfrentam interrupções inesperadas em seus processos produtivos, o que gera perdas financeiras e operacionais.

## Descrição da Solução Proposta

A arquitetura da nossa solução será baseada em uma abordagem modular e escalável, utilizando tecnologias que se complementam para garantir a coleta, armazenamento, processamento, análise e visualização dos dados de forma eficiente.

## Definição das Tecnologias

**Sensor:** ESP32
**Linguagens de Programação:** Python, R, SQL, C/C++
**Bibliotecas de IA:** TensorFlow, Keras, Pandas
**Serviços de Nuvem:** AWS
**Banco de Dados:** AWS S3, PostgreSQL

## Coleta de Dados

- **Fonte dos Dados**:  
  Os dados serão coletados em tempo real a partir de diversos sensores instalados nos equipamentos da linha de produção. Esses sensores podem monitorar variáveis como:  
  - Temperatura  
  - Vibração  
  - Nível de ruído  
  - Consumo de energia  
  - Pressão  
  - Velocidade de rotação  
  - Outras métricas específicas de cada equipamento.

- **Tecnologia de Coleta (Simulação Inicial / Planejamento Real)**:  
  - **Simulação Inicial**: Para a fase inicial do projeto e fins de demonstração, os dados poderão ser simulados utilizando Python. Serão gerados datasets sintéticos que imitam o comportamento de sensores reais, incluindo padrões normais e anomalias que simulam falhas.  
  - **Planejamento Real**: Em um cenário de implementação real, utilizaríamos microcontroladores com conectividade Wi-Fi, como o ESP32. Esses dispositivos são capazes de ler os dados dos sensores e transmiti-los de forma contínua para um gateway IoT.

- **Gateway IoT**:  
  Um gateway IoT atuará como intermediário entre os sensores e o banco de dados. Ele será responsável por:  
  - Receber os dados brutos dos sensores  
  - Realizar um pré-processamento básico (filtragem, agregação inicial)  
  - Garantir a comunicação segura e eficiente dos dados para a camada de armazenamento

## Armazenamento de Dados

- **Banco de dados**:  
  Optamos por um banco de dados em nuvem, AWS S3 e PostgreSQL.

- **Justificativa**:  
  - **Escalabilidade**: A nuvem oferece alta escalabilidade, permitindo aumentar ou diminuir a capacidade de armazenamento conforme o volume de dados gerado pela linha de produção evolui.  
  - **Disponibilidade e Confiabilidade**: Os serviços de banco de dados em nuvem garantem alta disponibilidade e mecanismos de backup e recuperação robustos, minimizando o risco de perda de dados.  
  - **Gerenciamento**: A gestão do banco de dados é simplificada, com tarefas como patching, backup e manutenção sendo parcialmente ou totalmente gerenciadas pelo provedor de nuvem.  
  - **Custo**: Para a fase inicial, um banco de dados de menor porte na nuvem pode ser mais viável financeiramente do que a implementação e manutenção de uma infraestrutura local robusta.

## Camada de Processamento

- **Tecnologias de Processamento**:  
  A camada de processamento será responsável por preparar os dados para análise e modelagem de IA. Utilizaremos principalmente Python com as bibliotecas Pandas para manipulação e limpeza dos dados e R para análises estatísticas exploratórias e validação de insights.

- **Local de Processamento**:  
  O processamento poderá ocorrer tanto em instâncias de computação na nuvem (AWS EC2 ou Google Compute Engine) quanto em um ambiente local, dependendo da sensibilidade dos dados, requisitos de latência e custos. Para a fase inicial, um ambiente local com poder de processamento adequado será suficiente. Em um cenário de produção com grande volume de dados, a escalabilidade da nuvem se torna crucial.

- **Pipeline de Dados**:  
  O pipeline de dados consistirá nas seguintes etapas:  
  1. **Ingestão**: Coleta dos dados do banco de dados  
  2. **Limpeza e Pré-processamento**: Tratamento de dados faltantes, remoção de ruídos, normalização e transformação das variáveis  
  3. **Engenharia de Features**: Criação de novas variáveis relevantes para a modelagem preditiva, como médias móveis, taxas de variação e desvios  
  4. **Análise Exploratória (R)**: Utilização de R para identificar padrões iniciais, correlações e tendências nos dados, auxiliando na seleção de features e na compreensão do comportamento das falhas

## Modelos de Machine Learning

- **Tecnologias de IA**:  
  Utilizaremos bibliotecas de Machine Learning como Scikit-learn para modelos mais tradicionais (Regressão Logística, Árvores de Decisão, Random Forest, Support Vector Machines) e Keras (com backend TensorFlow) para modelos de Deep Learning, especialmente para análise de séries temporais complexas e padrões sutis.

- **Tipos de Modelos**:  
  - **Classificação**: Para prever a probabilidade de ocorrência de uma falha em um determinado horizonte de tempo  
  - **Regressão**: Para prever o tempo restante até a falha (Remaining Useful Life - RUL)  
  - **Detecção de Anomalias**: Para identificar comportamentos incomuns nos dados dos sensores que podem indicar o início de uma falha

- **Integração**:  
  Os modelos de IA serão treinados utilizando os dados históricos processados e integrados ao pipeline de dados. A inferência (previsão) será realizada em tempo real com os novos dados chegando dos sensores.

## Dashboards e Relatórios Automatizados

- **Tecnologias de Visualização**:  
  Utilizaremos ferramentas de visualização como Python (Matplotlib, Seaborn, Plotly) e plataformas de Business Intelligence (BI) como Tableau ou Power BI para criar dashboards interativos e relatórios automatizados.

- **Conteúdo**:  
  Os dashboards e relatórios fornecerão:  
  - Monitoramento em tempo real das métricas dos equipamentos  
  - Indicadores de saúde dos equipamentos (health scores)  
  - Alertas visuais de potenciais falhas ou anomalias  
  - Previsões de falhas e o tempo estimado até a ocorrência  
  - Recomendações de ações preventivas (manutenção preditiva)  
  - Análise de tendências de falhas ao longo do tempo  
  - Relatórios sumarizados para a gerência com insights e recomendações


# DIVISÃO DE TAREFAS 

**Simulação  e recebimento dos dados:** Carlos, Leandro.

**Armazenamento + tratamento e pré-processamento dos dados:** Carlos, Mauricio.

**Treinamento e integração do modelo de IA:** Carlos, Leonardo, Rodrigo.

**Criação do dashboard:**  Rodrigo, Mauricio.

**README & Apresentação final:** Todos.

## Licença

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/agodoi/template">MODELO GIT FIAP</a> por <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://fiap.com.br">Fiap</a> está licenciado sobre <a href="http://creativecommons.org/licenses/by/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">Attribution 4.0 International</a>.</p>
