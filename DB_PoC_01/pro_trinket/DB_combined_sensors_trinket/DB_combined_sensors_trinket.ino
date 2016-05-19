/* DB PoC
 * Implementation of 3x additional sensors using a Pro Trinket 
 * Developer Evangelist Team @ relayr ;)
 * Naweli, Klemen, José & Jaime
 */



// Libraries
#include <FreqMeasure.h>
#include "HardwareSerial.h"



// Sensor Pins
#define VIBRATIONPIN 6
#define RANGERPIN 5
// The RADAR is connected to pin 8, as defined in the "FreqMeasure" library
// More info: https://www.pjrc.com/teensy/td_libs_FreqMeasure.html



// Variables
int count = 0;
long vibration;
float frequency;
float rangerSpeed;
float rangerDistance;
double frequencySum = 0;
double vibrationSum = 0;
double rangerSum = 0;




// Function Prototypes
//long TP_init();



// Setup function
void setup()
{
  // Initializing serial port
  Serial.begin(9600);

  // Initializing FreqMeasure
  FreqMeasure.begin();

  // Initializing pins
  pinMode(RANGERPIN, INPUT);
  pinMode(VIBRATIONPIN, INPUT);
}



// Main loop
void loop()
{
  // If the radar is available, it takes the reading and sums it up
  if(FreqMeasure.available())
    frequencySum = frequencySum + FreqMeasure.read();
  // If not, it keeps using the previous value
  else
    frequencySum = frequencySum + frequencySum;
      
  
  vibrationSum = vibrationSum + pulseIn (VIBRATIONPIN, HIGH);
  rangerSum = rangerSum + pulseIn(RANGERPIN, HIGH);
  count = count + 1;
    
  if (count > 5)
  {
    frequency = FreqMeasure.countToFrequency(frequencySum / count);
    rangerSpeed = frequency / 19.49; //conversion from freq to km/h
    Serial.print("AVERAGE SPEED: ");
    Serial.print(rangerSpeed);
    Serial.println(" km/h");


    vibration = vibrationSum / count;
    Serial.print("AVERAGE VIBRATION: ");
    Serial.print(vibration);
    Serial.println(" counts");


    rangerDistance = (rangerSum / count) / 147 * 2.54;
    Serial.print("AVERAGE DISTANCE: ");
    Serial.print(rangerDistance);
    Serial.println(" cm");

    Serial.println("");
    for (int i=0; i <= rangerDistance/5; i++)
      Serial.print("|");
    Serial.println("|");
    Serial.println("");
      
    frequencySum = 0;
    vibrationSum = 0;
    rangerSum = 0;
    count = 0;
  }



//  //Ultrasonic ranger
//  val = pulseIn(RANGERPIN, HIGH);
//  val = val / 147 * 2.54;
//  Serial.println(val);

////vibration
////  vibration = TP_init();
//  vibration = pulseIn (VIBRATIONPIN, HIGH);
//  //delay(10);
//  Serial.print("measurement = ");
//  Serial.println(vibration);
//  if (vibration > 1000){
//    Serial.println("you are in High");
//  }
//  else{
//    Serial.println("you are in low");
//  }

////radar
//  if (FreqMeasure.available()) {
//    // Average of readings
//    sum = sum + FreqMeasure.read();
//    count = count + 1;
//    if (count > 30) {
//      float frequency = FreqMeasure.countToFrequency(sum / count);
//      float spd = frequency / 19.49; //conversion from freq to km/h
////      Serial.print(frequency);
////      Serial.print(" Hz \t");
//      Serial.print(spd);
//      Serial.println(" km/h");
//      sum = 0;
//      count = 0;
//    }
//  }

}

