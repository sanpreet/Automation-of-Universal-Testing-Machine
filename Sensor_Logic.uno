/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
#include <stdio.h>
#include <stdlib.h>
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  
  // read the input on analog pin 0:
  int sensorvalue[2];
  int sensorvalue1[2];
   sensorvalue[1] = analogRead(A1);
   sensorvalue1[1] = analogRead(A2);
  // print out the value you read:
  Serial.println(sensorvalue[1]);
  Serial.println(sensorvalue1[1]);
  delay(2000);
   sensorvalue[2] = analogRead(A1);
   sensorvalue1[2] = analogRead(A2);
  // print out the value you read:
  Serial.println(sensorvalue[2]);
  Serial.println(sensorvalue1[2]);
  delay(2000);
  if (sensorvalue[1]>sensorvalue[2]&& sensorvalue1[1]>sensorvalue1[2])
     exit(1); 
  else
  {
  }
      // delay in between reads for stability
}
FILE *fp = fopen("/dev/ttyUSB0" ,"r+");  // fp is the pointer of file // gives read and write permission to the text file.
char ch;
ch = getc(fp);                     // Pics the character one by one.
while (ch!= EOF)
{
ch= getc(ch);
putc(ch);                         // Print the character to the terminal
}




