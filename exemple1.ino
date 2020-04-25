const int sensorPin = A0;
int switchstate = 0;
int sensorvalue = 0;

void setup() {  
  
  // declare the switch pin as an input
  pinMode(2, INPUT);
  
  // declare the LED pins as outputs
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  // declare the piezo pin as an output
  pinMode(8, OUTPUT);
 
  Serial.begin(9600); 
}

void loop() {

  // read the value of the switch
  switchstate = digitalRead(2);

  // read the value of the sensor and print value
  sensorvalue = analogRead(sensorPin);
  Serial.println(sensorvalue);

  // if the button is not pressed
  // turn on the green LED, and off the red LEDs and the piezo sound
  if (switchstate == LOW  && sensorvalue > 20) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);  
    digitalWrite(5, LOW);  
    noTone(8);
  }
  // if the switch is not LOW (the button is pressed)
  // turn off the green LED, and blink alternatively the red LEDs, and tone the piezo
  else {
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW);  
    digitalWrite(5, HIGH);

    tone(8, 262, 2000);
    
    delay(250);
    
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);  

    tone(8, 2000);
    
    delay(250);
  }
}
