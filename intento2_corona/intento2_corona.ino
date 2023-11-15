  int motor = 7;
  int cilindro = 6;
  int botonEncendido = 13;
  int botonEmergencia = 2;
  long intervalo = 3000;
  long tiempoInicial1, tiempoInicial2, tiempoActual1, tiempoActual2;
  bool emergencyActive = false;

  void setup() {
  // put your setup code here, to run once:
    pinMode(motor, OUTPUT);
    pinMode(cilindro, OUTPUT);
    pinMode(botonEncendido, INPUT);
    pinMode(botonEmergencia, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(botonEmergencia), emergenciaInterrupt, FALLING);
}

  void emergenciaInterrupt(){
    emergencyActive = true;
  }

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(botonEncendido) == 1){
    girarN(intervalo);
    girarM(intervalo);
    
  } else {
    apagar();
  }
}

//en caso de que el intervalo del motor sea largo
void girarN (long intervalo1){ //3000
    tiempoInicial1 = millis();

    while (tiempoActual1-tiempoInicial1 <= intervalo1){
      digitalWrite(motor, HIGH);
      tiempoActual1 = millis();

      movimientosCilindro(intervalo1);
    }
}

void girarM (long intervalo2){ //3000
      tiempoInicial2 = millis();

    while (tiempoActual2 - tiempoInicial2 <= intervalo2){
      digitalWrite(motor, LOW);
      tiempoActual2 = millis();

      movimientosCilindro(intervalo2);
    }
}

void movimientosCilindro(long intervaloMotor){
  long intervaloLargo, intervaloCorto; //no se si se pueda hacer esto
  intervaloLargo = (75 * intervaloMotor)/200;
  intervaloCorto = (25 * intervaloMotor)/200;

  //lento
  digitalWrite(cilindro, HIGH);
  delay (intervaloLargo);
  digitalWrite(cilindro, LOW);
  delay (intervaloLargo);

  //rapido
  digitalWrite(cilindro, HIGH);
  delay (intervaloCorto);
  digitalWrite(cilindro, LOW);
  delay (intervaloCorto);
}

void apagar (){
    digitalWrite(motor, LOW);
    digitalWrite(cilindro, LOW);
}