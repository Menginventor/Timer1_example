/*
  Timer/Counter Register Example
  by Dhamdhawach Horsuwan
  18/6/2018
  Bangkok Thailand
  https://www.facebook.com/menglabfanpage
  Thanks for instruction from
  http://maxembedded.com/
*/
/*
Note : To use Timer1 will disable PWM on pin 9 , 10 .
*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //set Timer/Counter 1 Control Register
  TCCR1A = 0;             // normal counting mode
  TCCR1B = _BV(CS11);     // set prescaler of 8

  
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long timer_counter = TCNT1;
  Serial.println(timer_counter);
}
