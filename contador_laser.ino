int LDR;//variable de la fotoresistencia 
int contador=1;//donde inicia el conteo
int led=3;//led que identifica 5 o mas pasajeros  
int led1=4;//led que identifica 10 o mas pasajeros
int led2=5;//led que identifica 15 o mas pasajeros
int led3=6;//led que identifica 20 o mas pasajeros

void setup() 
{
Serial.begin(9600);
pinMode(led, OUTPUT);//sale una señal para el led de 5v
pinMode(led1, OUTPUT);//sale una señal para el led1 de 5v
pinMode(led2, OUTPUT);//sale una señal para el led2 de 5v
pinMode(led3, OUTPUT);//sale una señal para el led3 de 5v
Serial.println("buenos dias señores pasajeros");
}

void loop() 
{
LDR=analogRead(A0);
if (LDR>100)
 {
 contador;
 Serial.print("pasajero numero: ");
 Serial.println(contador++);
 while (LDR>100)
 {
 LDR=analogRead(A0); 
 }
 }
if (contador>5)//lee el estado del sensor, si detecta un objeto
  {
      digitalWrite(led,HIGH);//entonces prenda el led, detecto un objeto 
  }
  else 
  {
   digitalWrite(led,LOW); 
  }
   if (contador>10)//lee el estado del sensor, si detecta un objeto
  {
      digitalWrite(led1,HIGH);//entonces prenda el led, detecto un objeto 
  }
  else 
  {
      digitalWrite(led1,LOW);
  }
   if (contador>15)//lee el estado del sensor, si detecta un objeto
  {
      digitalWrite(led2,HIGH);//entonces prenda el led, detecto un objeto 
  }
  else
  {
     digitalWrite(led2,LOW);
  }
   if (contador==20)//lee el estado del sensor, si detecta un objeto
  {
      digitalWrite(led3,HIGH);//entonces prenda el led, detecto un objeto
  }
  else
  {
     digitalWrite(led3,LOW);
  }
   if (contador>20)
  {
    contador=1;
    Serial.println("bus lleno");
    Serial.println(contador);
  }  
}
