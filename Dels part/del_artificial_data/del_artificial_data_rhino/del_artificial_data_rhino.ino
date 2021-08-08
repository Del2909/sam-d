#include <Gaussian.h>
// The number of "slots" to record the hits of gaussian random


int value = 0;
long randNumber;
void resting()
{
     delay(100);
     Gaussian g1 = Gaussian(60, 5);
     Serial.println(int(g1.random()));
     Serial.println("Resting");

}

void elevated(){
     delay(100);
     Gaussian g1 = Gaussian(80, 5);
     Serial.println(int(g1.random()));
     Serial.println("Elevated");

}
void attacked(){
     delay(100);
     Gaussian g1 = Gaussian(100, 5);
     Serial.println(int(g1.random()));
     Serial.println("Attacked");
}
void coordinates(){
  delay(1000);
  float latitude = random(170, 500) / 100.0;
  float longitude = random(10000,10300)/100.0;
  Serial.print(latitude);
  Serial.print(",");
  Serial.print(longitude);
  
}
void setup(){
  Serial.begin(9600);
  
}

void loop() {
  int inputvariable;
  
  if(Serial.available())
  {
    inputvariable = (Serial.readStringUntil('\r')).toInt();
    while (inputvariable == 0)
    {
      elevated();
      coordinates();
      if((Serial.available()) == 0){continue;}
      else{break;}
    }
    while (inputvariable == 1)
    {
      attacked();
      coordinates();
      if((Serial.available()) == 0){continue;}
      else{break;}
    }
    
  }
  else{
    resting();
    coordinates();
  }


}
