const int micPin = A0;
const int buzzerPin = 8;
const int ledPin = 13;  // Pino do LED
const int sampleWindow = 50; // Janela de amostragem em milissegundos
unsigned int sample;

unsigned long previousMillis = 0; // Armazena o tempo do último piscar do LED
const long interval = 500;        // Intervalo de tempo para o piscar (em milissegundos)

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(buzzerPin, LOW); // Garante que o buzzer comece desligado
  digitalWrite(ledPin, LOW);    // Garante que o LED comece apagado
}

void loop() {
  // Desliga o buzzer e LED durante a medição para evitar interferência
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);

  unsigned long startMillis = millis();
  unsigned int peakToPeak = 0;
  unsigned int signalMax = 0;
  unsigned int signalMin = 1023;

  while (millis() - startMillis < sampleWindow) {
    sample = analogRead(micPin);
    if (sample < 1023) {
      if (sample > signalMax) {
        signalMax = sample;
      }
      if (sample < signalMin) {
        signalMin = sample;
      }
    }
  }

  peakToPeak = signalMax - signalMin;

  // Convertendo para tensão
  float voltage = (peakToPeak * 5.0) / 1023.0;

  // Calibrado: 0.323V ≈ 63 dB
  float dB = 20.0 * log10(voltage / 0.000229);

  Serial.print("Pico a Pico: ");
  Serial.print(peakToPeak);
  Serial.print(" | Tensão: ");
  Serial.print(voltage, 3);
  Serial.print(" V | Estimativa: ");
  Serial.print(dB, 1);
  Serial.println(" dB");

  // Após a medição, decide se dá o alerta
  if (dB >= 77.6) {  
    tone(buzzerPin, 2900); // Toca um som de 2.9 kHz

    // Pisca o LED enquanto o som é emitido
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;  // Armazena o tempo do último piscar

      // Se o LED estiver aceso, apaga; caso contrário, acende
      int ledState = digitalRead(ledPin);
      digitalWrite(ledPin, (ledState == LOW) ? HIGH : LOW);
    }

    delay(5000);               // Mantém o alerta por 5 segundos
    noTone(buzzerPin);         // Desliga o buzzer
    digitalWrite(ledPin, LOW); // Garante que o LED fique apagado
  } else {
    digitalWrite(ledPin, LOW); // Garante que o LED esteja apagado se o dB for baixo
  }

  delay(300); // Espera antes de uma nova leitura
}
