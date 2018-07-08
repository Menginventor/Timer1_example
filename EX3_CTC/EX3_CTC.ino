/*
  Clear Timer on Compare (CTC) Example
  by Dhamdhawach Horsuwan
  18/6/2018
  Bangkok Thailand
  https://www.facebook.com/menglabfanpage
  Thanks for instruction from
  http://maxembedded.com/
*/
unsigned long last_time = micros();
#define usToTicks(_us)    (( clockCyclesPerMicrosecond()* _us) / 8)
void setup() {

  Serial.begin(115200);
  pinMode(13, OUTPUT);


  TCCR1A = 0;             // normal counting mode
  TCCR1B = _BV(WGM12);     // set CTC

  TIMSK1 |= _BV(TOIE1);   // set Timer Overflow Interrupt Enable
  TIMSK1 |= _BV(OCIE1A); // enable  Output Compare Interrupt
  OCR1A = usToTicks(25000) - 1;
  TCCR1B |= _BV(CS11);     // prescaler of 8 , start timer
}

void loop() {
 
}

ISR(TIMER1_OVF_vect)
{
  Serial.println("Never reach OVF");
}

ISR (TIMER1_COMPA_vect)
{
  unsigned long crr_time = micros();
  Serial.println(crr_time - last_time);
  last_time = crr_time;
  PORTB ^= (1 << 5); // toggles the led
}
