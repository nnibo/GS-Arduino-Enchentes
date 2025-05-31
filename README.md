# 🚨🌧️Sistema de Monitoramento de Enchentes com Arduino

## 📌 Descrição do Problema

Em regiões afetadas por enchentes, a falta de monitoramento preventivo e comunicação eficiente dificulta o socorro rápido, expondo moradores a sérios riscos. A ausência de dados em tempo real sobre o nível da água e umidade do solo pode agravar a situação, impedindo ações rápidas por parte das equipes de resgate. Cidadãos, muitas vezes em pânico, não conseguem registrar informações precisas, o que atrasa ainda mais a resposta dos órgãos responsáveis.

---

## 💡 Visão Geral da Solução

Nossa solução propõe um sistema automatizado e acessível, construído com Arduino, que monitora a umidade do solo e o nível da água utilizando sensores. LEDs sinalizam o estado de risco (verde = sem risco de enchentes, amarelo = chuva detectada, vermelho = nivel de agua critico) e um alarme é acionado, permitindo o acionamento do botão SOS. Esse botão permite que o cidadão registre um chamado com dados detalhados sobre a situação, localização e pessoas no local, essas informações vão diretamente para a defesa civil

### Funcionalidades principais do Arduino:

- **Sensor de Umidade** para detectar chuvas.
- **Sensor Ultrassônico** para medir o nível de água.
- **LEDs RGB** para indicar o nível de alerta.
- **Buzzer** que é ativado em caso crítico.
- **Display LCD I2C** para exibir mensagens de status.

IMAGEM

---

## 🧪 Como simular o projeto no Tinkercad
1. Clicar em Iniciar Simulação
2. Para ativar o led verde e verificar se o ambiente está seguro, clicar no sensor de umidade de solo, e colocar a umidade abaixo de 30%
3. Para ativar o led amarelo e verificar chuva, clicar no sensor de umidade de solo e colocar umidade acima de 30%
4. Para ativar o led vermelho, a buzina e verificar uma enchente, clicar no sensor ultrassonico de distancia e colocar a altura da água acima de 50cm

---

## 🔗Links para projeto e video
### 🛠️Link para o projeto no Tinkercad
[👉 Acesse o projeto no Tinkercad](https://www.tinkercad.com/things/40Utxf70id0-projeto-arduino-enchentes?sharecode=P4UBpSwNmxFsfPCsaFTYNrkDCJyizIMvRsjNJQ_MFus)

### 🎬Link para o video
FALTA O VIDEO

