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
      if((Serial.available()) == 0){continue;}
      else{break;}
    }
    while (inputvariable == 1)
    {
      attacked();
      if((Serial.available()) == 0){continue;}
      else{break;}
    }
    
  }
  else{
    resting();
  }


}
