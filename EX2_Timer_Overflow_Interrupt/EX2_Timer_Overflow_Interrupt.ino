/*
  Timer1 Overflow Example
  by Dhamdhawach Horsuwan
  18/6/2018
  Bangkok Thailand
  https://www.facebook.com/menglabfanpage
  Thanks for instruction from
  http://maxembedded.com/
*/
void setup() {
  Serial.begin(115200);
  //set Timer/Counter1 Control Register
  TCCR1A = 0;             // normal counting mode
  TCCR1B = 0;             // Not counting until setting complete
  //set The Timer/Counter Interrupt Mask Register
  TIMSK1 |= _BV(TOIE1);   // set Timer Overflow Interrupt Enable
  TCCR1B = _BV(CS11);     // set prescaler of 8 , start timer
}

void loop() {}

ISR(TIMER1_OVF_vect)
{
   Serial.println(micros());
}




