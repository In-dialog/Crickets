void Default(){
   theLoopCounter = 4;
 timeMakrOn = 40;
 TimeMarkOff = 10;
 treshold = 2.5f;
 _tone = 10;
  }

void Load(){
    EEPROM.get(0, timeMakrOn);
    EEPROM.get(sizeof(timeMakrOn), TimeMarkOff);
    EEPROM.get(sizeof(TimeMarkOff)+ sizeof(timeMakrOn)+ sizeof(theLoopCounter), theLoopCounter);
    EEPROM.get(sizeof(TimeMarkOff)+ sizeof(timeMakrOn)+ sizeof(theLoopCounter)+ sizeof(treshold), treshold);
    EEPROM.get(sizeof(TimeMarkOff)+ sizeof(timeMakrOn)+ sizeof(theLoopCounter)+ sizeof(treshold)+  sizeof(_tone), _tone);
  Serial.print("////_tone:  ");
  Serial.print( EEPROM.get(sizeof(TimeMarkOff)+ sizeof(timeMakrOn)+ sizeof(theLoopCounter)+ sizeof(treshold)+  sizeof(_tone),_tone));
  
  }

  void Save(){
    EEPROM.put(0, timeMakrOn);
    EEPROM.put(sizeof(timeMakrOn), TimeMarkOff);
    EEPROM.put(sizeof(TimeMarkOff)+ sizeof(timeMakrOn)+ sizeof(theLoopCounter), theLoopCounter);
    EEPROM.put(sizeof(TimeMarkOff)+ sizeof(timeMakrOn)+ sizeof(theLoopCounter)+ sizeof(treshold), treshold);
    EEPROM.put(sizeof(TimeMarkOff)+ sizeof(timeMakrOn)+ sizeof(theLoopCounter)+ sizeof(treshold)+  sizeof(_tone), _tone);
  }

void SendStatus(){
  Menu();
Serial.println("----------------");
Serial.print("timeMakrOn , TimeMarkOff: ");
Serial.print(timeMakrOn);

Serial.print(" / ");
Serial.println(TimeMarkOff);

Serial.println("----------------");
Serial.print("theLoopCounter: ");
Serial.println(theLoopCounter);

Serial.println("----------------");
Serial.print("treshold: ");
Serial.println(treshold);

Serial.println("----------------");
Serial.print("_tone: ");
Serial.println(_tone);

Serial.println("----------------");
}
void Menu(){
    Serial.println(
      "'C' = LoopCounter  "
      "'O' = maximum time on  " 
      "'F' = secound till reset  "
      "'A' = AudioTreshold  "
      "'T' = tone  "
      "'S'= stats  "
      "'L'= load");
}
