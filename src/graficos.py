
import pandas as pd
import matplotlib.pyplot as plt

# Lê o arquivo CSV com os dados
arquivo_csv = 'dados_simulados.csv'
df = pd.read_csv(arquivo_csv)

# Gráfico 1: Temperatura vs Umidade
plt.figure()
plt.scatter(df['Temperatura (°C)'], df['Umidade (%)'], c='blue', edgecolor='black')
plt.title('Temperatura vs Umidade')
plt.xlabel('Temperatura (°C)')
plt.ylabel('Umidade (%)')
plt.grid(True)
plt.savefig('grafico_temperatura_umidade.png')

# Gráfico 2: Potência vs Corrente
plt.figure()
plt.plot(df.index, df['Corrente (A)'], label='Corrente (A)', color='blue')
plt.plot(df.index, df['Potência (W)'], label='Potência (W)', color='red')
plt.title('Corrente e Potência ao Longo das Amostras')
plt.xlabel('Amostra')
plt.ylabel('Valor')
plt.legend()
plt.grid(True)
plt.savefig('grafico_potencia_corrente.png')

# Gráfico 3: Pressão ao longo da coleta
plt.figure()
plt.plot(df.index, df['Pressão (hPa)'], 'g-')
plt.title('Variação da Pressão Atmosférica')
plt.xlabel('Índice da Amostra')
plt.ylabel('Pressão (hPa)')
plt.grid(True)
plt.savefig('grafico_pressao.png')

# Exibe mensagem de saída
print("Gráficos gerados e salvos com sucesso.")
