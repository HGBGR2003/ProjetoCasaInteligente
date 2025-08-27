/*Alunos: Henrique Gabriel; Matheus Guerra;*/

const int pinoRelePortao = 7;
const int pinoSensorPortao = 2;
const int pinoReleCasa = 5;
const int pinoSensorCasa = 4;
const long delayPadrao = 5000;
const int pinoA1 = A1;
int limiarEscuro = 500;

void setup (){
  pinMode(pinoRelePortao, OUTPUT);
  pinMode(pinoSensorPortao, INPUT);
  pinMode(pinoReleCasa, OUTPUT);
  pinMode(pinoSensorCasa, INPUT);
  pinMode(pinoA1, INPUT);
}

int sensorPortao = 0;
int sensorCasa = 0;

void loop (){

  int valorDaLumisiodade = analogRead(pinoA1);

  if(digitalRead(pinoSensorPortao) == HIGH && valorDaLumisiodade < limiarEscuro){
    digitalWrite(pinoRelePortao, HIGH);
    delay(delayPadrao);
  } else {
    digitalWrite(pinoRelePortao, LOW);
  }

  if(digitalRead(pinoSensorCasa) == HIGH){
    digitalWrite(pinoReleCasa, HIGH);
    delay(delayPadrao);
  } else {
    digitalWrite(pinoReleCasa, LOW);
  }
}