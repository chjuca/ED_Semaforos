int semaforoP[] = {8,9,10};
int semaforoS[] = {11,12,13};
int pinSensor = 7;
boolean sensor=true;

void setup() {
 for(int i=8;i<=13;i++){
  pinMode(i,OUTPUT);
 }
 pinMode(pinSensor, INPUT);
}

void loop() {
  sensor=digitalRead(pinSensor);
  if(sensor){
    estadoInicial();
  }else{
    secuenciaSemaforo(semaforoP,semaforoS);
}
delay(8000);
sensor=false;
}
//________________________________________Estado Inicial_______________________________
void estadoInicial(){
  digitalWrite(semaforoP[2],HIGH);
  digitalWrite(semaforoS[0],HIGH);
}
//________________________________________SECUENCIA SEMAFORO________________________

void secuenciaSemaforo(int semaforoP[],int semaforoS[]) {
  prenderUnSoloLed(semaforoP, semaforoP[1]);
  delay(2000);
  prenderUnSoloLed(semaforoP, semaforoP[0]);
  prenderUnSoloLed(semaforoS, semaforoS[2]);
  delay(5000);
  prenderUnSoloLed(semaforoS, semaforoS[1]);
  delay(2000);
  prenderUnSoloLed(semaforoP, semaforoP[2]);
  prenderUnSoloLed(semaforoS, semaforoS[0]);
  delay(5000);
  estadoInicial();
}

void prenderUnSoloLed(int semaforo[], int led) {
    for (int i = 0; i <= 2 ; i++) {
      digitalWrite(semaforo[i], LOW);
  }
  digitalWrite(led, HIGH);
}

//_________________________________________________
