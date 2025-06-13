#include "DHTesp.h"  // Biblioteca **DHTesp**, otimizada para ESP32/ESP8266 ao lidar com sensores DHT‑11/22

#define DHT_PIN 15        // Define o pino **GPIO 15** como conexão do sensor DHT22
DHTesp dht;               // Instância `dht` para gerenciar a comunicação e leitura

void setup() {
  Serial.begin(115200);   // Inicializa a porta serial a 115200 bps
  delay(1000);            // Pequena pausa para garantir a estabilidade da conexão
  dht.setup(DHT_PIN, DHTesp::DHT22);  
  // Configura o sensor DHT22 no pino indicado (DHTesp lida automaticamente com os timings) 
  Serial.println("Iniciando simulação DHT22 no GPIO15...");
}

void loop() {
  TempAndHumidity th = dht.getTempAndHumidity();  
  // Lê temperatura e umidade em uma única chamada

  float temp = isnan(th.temperature)
               ? random(200, 350) / 10.0  // Se falhar (NaN), gera valor aleatório entre 20.0–35.0 °C
               : th.temperature;

  int umid = isnan(th.humidity)
             ? random(30, 70)           // Se falhar, gera umidade aleatória de 30–69 %
             : int(th.humidity);

  // Simula outros sensores para criar um cenário IoT completo:
  float vibracao = random(0, 51) / 10.0;         // 0.0 – 5.0 g
  float corrente = random(0, 101) / 10.0;        // 0.0 – 10.0 A
  float tensao   = random(2100, 2310) / 100.0;   // 21.00 – 23.10 V
  float potencia = corrente * tensao;            // Potência (W)
  int   pressao  = random(950, 1051);           // 950 – 1050 hPa

  // Envia todos os dados formatados no Serial Monitor:
  Serial.printf(
    "T:%.1f°C, U:%d%%, V:%.1fg, I:%.1fA, Vlt:%.2fV, P:%.1fW, Pr:%dhPa\n",
    temp, umid, vibracao, corrente, tensao, potencia, pressao
  );

  delay(3000);  // Espera 3 segundos até a próxima leitura
}
