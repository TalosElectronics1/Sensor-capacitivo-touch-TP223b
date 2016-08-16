//Declaración de variables
int Estado = 0;
int Sensor_Touch = 2;
int Carga_Led = 3;
int Bandera=0;

void setup()
{
  pinMode(Sensor_Touch, INPUT);//Definir el pin 2 como entrada
  pinMode(Carga_Led, OUTPUT);//Definir el pin 3 como salida
  digitalWrite(Carga_Led, LOW);//iniciar con la carga apagada
}

void loop()
{
  Estado = digitalRead(Sensor_Touch);//Realizar la lectura del sensor
  if(Estado==1&&Bandera==0)//Si el carga esta apagado y se presiona el sensor
  {
    digitalWrite(Carga_Led,HIGH);//Encender la carga
    while(Estado==1)//Recordar el estado en el que se encuentra
    {
     Estado = digitalRead(Sensor_Touch);//actualizar el estado del sensor
     Bandera=1;//Variable para recordar que se encendio la carga
    }
  }
  if(Estado==1&&Bandera==1)//Si la carga esta encendida y se presiona el sensor
  {
    digitalWrite(Carga_Led,LOW);//Apagar la carga
    while(Estado==1)
    {
     Estado = digitalRead(Sensor_Touch);//actualizar el estado del sensor
     Bandera=0;//Variable para recordar que se apago la carga
    }
  }
}


