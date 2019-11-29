///////max9814 wiring arduino!!!!!!
#include <AnalogSmooth.h>
#include <EEPROM.h>
const int AOUTpin= 7 ;
const int ledPin= 3;
int buzzer = 2 ;

int theLoopCounter;
int timeMakrOn;
int TimeMarkOff;
float treshold;
int _tone;
////

double value;
bool soundHigh;\
unsigned long onTime,offTime;
AnalogSmooth as = AnalogSmooth(10);
void setup()
{
  Default();
//  Save();
randomSeed(random(2000,10000));
Serial.begin(9600);
pinMode(AOUTpin, INPUT);
//_tone = random(2000,10000);
soundHigh = true;
pinMode (buzzer, OUTPUT) ;
pinMode (ledPin, OUTPUT) ;
SendStatus();
}

void loop()
{

value = SoundPeaks(100);
// Serial.print("sound value: ");
//      Serial.println(value);
if(value >treshold & treshold!=0){
  if(onTime<100)
  onTime ++;
  for(int i=0;i<theLoopCounter;i++){
  int theTone = _tone * random(10,1000);
  delay (2);
  Active(true,theTone);
  }
  }
  else 
  { if(offTime<100)
      offTime ++;
  soundHigh = false;
  }
  
// Serial.print("onTime: ");
//Serial.println(onTime);

//unsigned long thisTime = onTime-offTime;

if(offTime > TimeMarkOff){
  onTime = 0;
  offTime = 0;
}

if(onTime > timeMakrOn){
Serial.println("!!!!");
onTime=0;
noTone(buzzer);
delay (2000);
}
//Active(false,0);
  
//Serial.print("Time: ");
//onTime = millis();
//Serial.println(onTime);



//    Serial.println(count);
   
   


}
void Active (bool ledState, int _tone){
   digitalWrite(ledPin, ledState);
   noTone(buzzer);
   delay (1) ;
   tone (buzzer, _tone) ; //send tone
   delay (10) ;
   noTone(buzzer);
   digitalWrite(ledPin, false);
//   delay (random(2,15)) ;
}

double SoundPeaks(int sampleWindow){
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level

   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;

   // collect data for 50 mS

   while (millis() - startMillis < sampleWindow)
   {
      int sample = analogRead(AOUTpin);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
     double volts = (peakToPeak * 5.0) / 1024;  // convert to volt
     return volts;
}
