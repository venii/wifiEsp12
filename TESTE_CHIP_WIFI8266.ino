#include <SoftwareSerial.h>
 
SoftwareSerial esp8266(2,3); //make RX Arduino line is pin 2, make TX Arduino line is pin 3.
                           
void setup()
{
  Serial.begin(9600);
  esp8266.begin(9600);
}
 
void loop()
{
  if(esp8266.available())
  {
    while(esp8266.available())
    {
     
      char c = esp8266.read(); 
      Serial.write(c);
   
    }  
  }
  
 
  
  if(Serial.available())
  {
    
    
     
    delay(2000); 
    String command="";
    
    while(Serial.available())
    {
        // read one character
      command+=(char)Serial.read();
       
    
    }
    esp8266.println(command);
    delay(10);
  }
 
}
