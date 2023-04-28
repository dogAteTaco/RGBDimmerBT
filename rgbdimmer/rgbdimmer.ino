#include <EEPROM.h>

int intensity = 0; //Variable que se utilizara para manejar la intensidad
int word_address = 0; //Direccion de donde se guarda la intensidad
String incomingLine; //Variable con la que se recibira el valor de intensidad

void setup() {
  Serial.begin(9600);
  byte value;
  value = EEPROM.read(word_address); //Se lee la intensidad almacenada
  Serial.println(int(value)); //Se imprime la intensidad almacenada

  pinMode(2,OUTPUT); //Se usa el PIN 2 para encender el dispositivo Bluetooth
  digitalWrite(2,HIGH); //Se enciede el dispositivo Bluetooth
}

// the loop function runs over and over again forever
void loop() {
  Serial.println(int(value));
  if (Serial.available() > 0) {
    incomingLine = Serial.readStringUntil('\n'); //Lee los valores hasta que hay un 'Enter'
    incomingLine.replace("\r", ""); //Remueve el 'Enter' en la cadena
    Serial.println(incomingLine);
    intensity = incomingLine.toInt();
    //Guarda la nueva intensidad del foco
    EEPROM.write(word_address,(uint8_t) intensity);
  }
}
