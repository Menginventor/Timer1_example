/*
  Timer Interrupt Example
  by Dhamdhawach Horsuwan
  18/6/2018
  Bangkok Thailand
  https://www.facebook.com/menglabfanpage
  Thanks for instruction from
  http://maxembedded.com/
*/

#define usToTicks(_us)    (( clockCyclesPerMicrosecond()* _us) / 8)     // converts microseconds to tick (assumes prescale of 8)  // 12 Aug 2009
#define ticksToUs(_ticks) (( (unsigned long)_ticks * 8)/ clockCyclesPerMicrosecond() )
unsigned long set_ticks;
unsigned long ticks_count = 0;
unsigned long last_time = micros();
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  set_ticks = usToTicks(100000);
  TCCR1A = 0;             // normal counting mode
  TCCR1B = 0;

  TIMSK1 |= _BV(TOIE1);   // set Timer Overflow Interrupt Enable
  TIMSK1 |= _BV(OCIE1A); // enable compare interrupt
  OCR1A = (set_ticks % 65536) - 1;

  Serial.println(set_ticks);
  Serial.println(OCR1A);
  delay(2000);
  TCCR1B =  _BV(CS11);     // set prescaler of 8 , start counter
}

void loop() {


}

ISR(TIMER1_OVF_vect)
{
  //Serial.println(millis());
  ticks_count += 65536;
  
}
ISR (TIMER1_COMPA_vect)
{
 if (ticks_count+TCNT1 >= set_ticks) {
    timer_interrupt_handle();
    ticks_count = 0;
    TCNT1 -= OCR1A;
  }
}
void timer_interrupt_handle() {

  unsigned long crr_time = micros();
  Serial.println(crr_time - last_time);
  last_time = crr_time;
}

