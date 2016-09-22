#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
long duration, distance;
const int analogOutPin = 9; 
int sensorValue = 0;        
int outputValue = 0;        
int a;
void setup() {
  
  Serial.begin(9600);
  pinMode(12,OUTPUT);
   pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
  
}
int state;
int cnt;

int Distance()
{
  digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 return duration;
}

int k;
void loop() 
{
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 } 



  k=Distance();

  if(k<700)
  {
    cnt =1;
  }
  else
  cnt =0;
   
 if(cnt==1){
 Serial.println("Booked");
 digitalWrite(12, HIGH);}
 else if(cnt==0){
 Serial.println("Available");
 digitalWrite(12,LOW);}
 delay(1000);

}
