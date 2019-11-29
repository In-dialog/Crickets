/////--------Comunication seriall read from unity 
char inChar;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
boolean Finished[3];
int State;

void serialEvent(){
  //////----------------------------------------------- Get serial com from Unity 
  if (Serial.available()>0) {
    inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
       stringComplete = true;
       analyseSerial(inputString);
    }
  }
  
}

void analyseSerial(String numSerial){

  char firstChar = numSerial[0];
  
    switch(firstChar)
    {
    
      case 'C'://////----------------------------------------------------------Drow pathern Program
      theLoopCounter = classifier(numSerial);   
      Save(); 
      inputString = "";
      stringComplete = false;
      break;

      
      case 'O'://////----------------------------------------------------------Calibrate Machine
      timeMakrOn = classifier(numSerial);
      Save();
      inputString = "";
      stringComplete = false;
      break;

      
      case 'F'://////----------------------------------------------------------Set Home
      TimeMarkOff = classifier(numSerial);
      Save();
      inputString = "";
      stringComplete = false;
       break;

       case 'A'://////----------------------------------------------------------Set Home
      treshold = classifier(numSerial);
      Save();
      inputString = "";
      stringComplete = false;
       break;

       case 'T'://////----------------------------------------------------------Set Home
      _tone = classifier(numSerial);
      Save();
      inputString = "";
      stringComplete = false;
       break;
       
       case 'S'://////----------------------------------------------------------Set Home
      SendStatus();
      inputString = "";
      stringComplete = false;
       break;
       
       case 'L'://////----------------------------------------------------------Set Home
     if(sizeof(inputString)>0){
      if(classifier(numSerial)==1)
      Default();
      else
       Load();
     }
      inputString = "";
      stringComplete = false;
       break;

         case 'D'://////----------------------------------------------------------Set Home
         while(firstChar =='D'){
          value = SoundPeaks(100);
      Serial.print("sound value: ");
      Serial.println(value);
      
         }
//      inputString = "";
//      stringComplete = false;
       break;
       
    }
}





int classifier(String mySerial){
mySerial.remove(0,1);
int commaIndex = mySerial.indexOf(',');
//  Search for the next comma just after the first
int secondCommaIndex = mySerial.indexOf(',', commaIndex + 1);
String firstValue = mySerial.substring(0, commaIndex);
int newValue;
 return  newValue = firstValue.toInt();
 

}





