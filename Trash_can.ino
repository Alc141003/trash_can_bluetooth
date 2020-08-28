char DATO;                                   // creamos la variable DATO
int ang = 0;                                 // creamos la variable ang y le damos valor 0
#include <Servo.h>                           // incluimos la libreria servo
Servo servo;                                 // creamos el objeto llamado servo        
void setup() {
servo.attach(3,1000,2000);                   //inicializamos el servo determinando pin , el pulso minimo y el pulso maximo
servo.write(0);                              // iniciamos con angulo 0
pinMode(13,OUTPUT);                          // determinamos los pines 13 12 11 10 como salida (l298n)
pinMode(12,OUTPUT);   
pinMode(11,OUTPUT);   
pinMode(10,OUTPUT);   
Serial.begin(9600);                          // inicializamos la comunicacion serie 
 
}
 
void loop() {
if(Serial.available()){                      // verificamos si hay un caracter disponible 
  DATO = Serial.read();                      // lo asignamos a la variable DATO
  Serial.println(DATO);                      // enviamos el dato al control
}
 
if(DATO == 'F'){                             // si el caracter es F avanzan los motores A y B
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}
  
else if(DATO == 'G'){                        // si el caracter es B retroceden los motores A y B                                          
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
 
else if(DATO == 'L'){                        // si el caracter es L gira el motor A 
  digitalWrite(11,HIGH);
}
 
else if(DATO == 'R'){                        // si el caracter es R gira el motor B
  digitalWrite(13,HIGH);
}

 
else if(DATO == 'S'){                        // si el caracter es S se detienen los motores A y B
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
 else  if (DATO == 'X'){                     // si el caracter es X se abre la tapa 
      ang = ang + 180; 
      Serial.print(ang); 
      }
    else if (DATO == 'Y'){                   // si el caracter es Y se cierra la tapa 
      ang = ang - 180;
      Serial.print(ang);
      }
     
    ang = constrain(ang,0,180);              // se limita el angulo de 0 a 180
    
 servo.write(ang);                           // le asignamos al servo el dato de la variable ang
 delay(100);                                 // se espera 100 milisegundos 
}
