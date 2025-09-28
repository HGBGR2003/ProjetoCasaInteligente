/*Alunos: Henrique Gabriel; Matheus Guerra;*/

const int pinoReleCasa = 5; 
const int pinoSensorCasa = 4;    
const int pinoA1 = A1;         
unsigned long tempoEspera = 10000UL;
int limiarLuminosidade = 400;
bool ldrMaiorComLuz = true;
bool releCasaLigado = false;
unsigned long tempoUltimoMovimento = 0;
const bool moduloReleActiveLow = true;

void setup() {
  pinMode(pinoReleCasa, OUTPUT);
  pinMode(pinoSensorCasa, INPUT);
  pinMode(pinoA1, INPUT);

  if (moduloReleActiveLow) digitalWrite(pinoReleCasa, HIGH);
  else digitalWrite(pinoReleCasa, LOW);

  Serial.begin(9600);
  Serial.println("___________________________ Iniciando automacao de iluminacao ___________________________");
  delay(500);
}

void loop() {
  int valorLDR = analogRead(pinoA1);
  int leituraPIR = digitalRead(pinoSensorCasa);
  if(leituraPIR == 0){
    Serial.println("Tudo PARADO!");
  }

  if(leituraPIR == 1){
    Serial.println("TEM MOVIMENTO ai!");
  }

  unsigned long agora = millis();

  bool ambienteClaro;
  if (ldrMaiorComLuz) ambienteClaro = (valorLDR >= limiarLuminosidade);
  else ambienteClaro = (valorLDR <= limiarLuminosidade);

  if (ambienteClaro) {
    desligarRele();
    tempoUltimoMovimento = 0;
    delay(50);
    return;
  }

  if (leituraPIR == HIGH) {
    tempoUltimoMovimento = agora;
    if (!releCasaLigado) {
      ligarRele();
    }
  }

  if (releCasaLigado && tempoUltimoMovimento != 0 && (agora - tempoUltimoMovimento) > tempoEspera) {
    desligarRele();
    tempoUltimoMovimento = 0;
  }

  delay(50);
}

void ligarRele() {
  if (moduloReleActiveLow) digitalWrite(pinoReleCasa, LOW);
  else digitalWrite(pinoReleCasa, HIGH);
  releCasaLigado = true;
}

void desligarRele() {
  if (moduloReleActiveLow) digitalWrite(pinoReleCasa, HIGH);
  else digitalWrite(pinoReleCasa, LOW);
  releCasaLigado = false;
}
