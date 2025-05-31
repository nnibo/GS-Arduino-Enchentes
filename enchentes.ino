// Declaracao de Variaveis
int ledGreenPin = 13;
int ledYellowPin = 12;
int ledRedPin = 11;
int buzzerPin = 10;
int moistureValue;
float moisturePercentage;
int trigPin = 9;
int echoPin = 8;
float duration, distance;

// Importacao de bibliotecas
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define col 16
#define lin  2
#define ende 0x27
LiquidCrystal_I2C lcd(ende, col, lin);

void setup() {
  // Definindo os pinos como entrada ou saída
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledYellowPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);
  
  // Ligando o display
  lcd.init();
  lcd.backlight(); // Ativando a luz de fundo
  lcd.setCursor(0, 0);
  lcd.print("Hello, Tinkercad!");
  lcd.setCursor(0, 1);
  lcd.print("LCD I2C Test");
  delay(2000);
  lcd.clear();
  Serial.begin(9600); 
}

void loop() {
  // Medição da distância com o sensor ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Dispara o pulso
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

   // Mede o tempo do pulso
  duration = pulseIn(echoPin, HIGH);
  // Converte tempo em distância (cm)
  distance = (duration * 0.0343) / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  moistureValue = analogRead(A0);
  // Transforma o valor do moisture em porcentagem
  moisturePercentage = map(moistureValue, 0, 876, 0, 100);

  Serial.print("Moisture Value: ");
  Serial.println(moisturePercentage);

  delay(500);
  
  // Caso o sensor não detecte nada, ou esteja muito alta a agua
  if (distance == 0 || distance > 300) {
    digitalWrite(ledGreenPin, LOW);
    digitalWrite(ledRedPin, LOW);
    digitalWrite(ledYellowPin, LOW);
    noTone(buzzerPin);
    lcd.setCursor(0,0);
    lcd.print("Nivel de agua");
    lcd.setCursor(0,1);
    lcd.print("Nao encontrado");
  }
  
  // Verifica se a altura da agua esta maior que 50cm
  else if (distance >= 50) {
    digitalWrite(ledRedPin, HIGH);
    digitalWrite(ledGreenPin, LOW);
    digitalWrite(ledYellowPin, LOW);
    tone(buzzerPin, 1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Nivel de agua");
    lcd.setCursor(0,1);
	lcd.print("Critico");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Aperte o botao");
    lcd.setCursor(0,1);
    lcd.print("SOS");
    delay(1000);
  }
  else {
    digitalWrite(ledRedPin, LOW);
    noTone(buzzerPin);
	// Caso a altura da agua seja menor que 50cm
  // Verifica se a porcentagem da umiadde de solo é menor que 30%
    if (moisturePercentage < 30) {
      digitalWrite(ledGreenPin, HIGH);
      digitalWrite(ledYellowPin, LOW);
      lcd.clear();      
      lcd.setCursor(0,0);
      lcd.print("Sem risco de");
      lcd.setCursor(0,1);
      lcd.print("enchentes");
      delay(1000);
    } 
    // Caso a umidade do solo seja maior do que 30%
    else {
      digitalWrite(ledGreenPin, LOW);
      digitalWrite(ledYellowPin, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Umidade alta");
      lcd.setCursor(0,1);
      lcd.print("Chuva detectada");
      delay(1000);
    }
  }
}
