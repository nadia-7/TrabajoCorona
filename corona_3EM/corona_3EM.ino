  //INICIALIZAR VARIABLES
    int motor =7;
    int cilindro = 6;
    int button = 8;
    int y = 0;

    void setup() {
      pinMode(motor, OUTPUT);
      pinMode(cilindro, OUTPUT);
      pinMode(button, INPUT);
      }
    
    void loop (){
      if(digitalRead(button) == HIGH && y == 0){
          y = 1;
          while (y == 1){
          girarLado1();
          girarLado2();

          subirLento();
          bajarLento();
          subirRapido();
          bajarRapido();

          
            if(digitalRead(button) == HIGH && y == 1){
            y = 2;
            } 

          }

        }else if (y==0 || y==2){
          y = 0;
          bajarLento();
          bajarRapido();
          girarLado2();
        }
    }


    void subirLento(){
          digitalWrite(cilindro, HIGH);
          delay(1000);

          if(digitalRead(button) == HIGH && y == 1){
            y = 2;
          }
    }

    void bajarLento(){
          digitalWrite(cilindro, LOW);
          delay(1000);
    }


    void lento(){
      const unsigned long intervalo = 3000; //milisegundos que quiero que esté encendido
      unsigned long tiempoInicial = millis();

      while(tiempoActual-tiempoInicial <= intervalo){
      unsigned long tiempoActual = milis();
      int pin = 1;
      }

    }
    void subirRapido(){
          digitalWrite(cilindro, HIGH);
          delay(400);
    }
    void bajarRapido(){
          digitalWrite(cilindro, LOW);
          delay(400);
    }

    void girarLado1(){
        digitalWrite(motor, HIGH);
        delay(2000);
    }

    void girarLado2(){
      digitalWrite(motor, LOW);
      delay(2000);
    }