#define POT A0
#define FORWARD_EN 5
#define REVERSE_EN 9

int dutyCycle;
int pot;

void setup() {
  Serial.begin(9600);
  pinMode(POT, INPUT);

  //Set PWM frequency to 61Hz for pins D9 D10 D5 D6
  TCCR1A = 0b00000001;  
  TCCR1B = 0b00001101;
  TCCR0A = 0b00000011;
  TCCR0B = 0b00000101;

}

void loop() {
  pot = analogRead(0);
  dutyCycle = map(pot, 500, 1023, 0, 255);
  if (pot<=488) {
  analogWrite(REVERSE_EN, -dutyCycle);
  digitalWrite(FORWARD_EN, LOW);
  }
  else if (pot>=536) {
  analogWrite(FORWARD_EN, dutyCycle);
  digitalWrite(REVERSE_EN, LOW);
  }
  else {
  digitalWrite(FORWARD_EN, HIGH);
  digitalWrite(REVERSE_EN, HIGH);
  }
  
  
//Serial.println(pot);
//Serial.println(dutyCycle);  
}



