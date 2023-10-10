#define pin2 2 //define name of pins used
#define switch1 8
#define _______ __
#define _______ __
#define _______ __
#define _______ __
#define _______ __
//define the delays for each LED
int LED_blink = 700;
//define variable for switch press
int switch_read; //defining a variable which will read the state of the switch
int LED_sequence=1; //defining which way the LEDs will light up (left to right or right to left)
int delay_timer (int miliseconds)
{
 int count = 0;
 while(1)
 {
 if(TCNT0 >= 16) // Checking if 1 milisecond has passed
 {
 TCNT0=0;
 count++;
 if (count == miliseconds) //checking if required miliseconds delay has passed
 {
 count=0;
 break; // exits the loop
 }
 }
 }
 return 0;
}
void setup() {
 //define pins connected to LEDs as outputs and the switch as input
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 //set up timer
 TCCR0A = 0b00000000;
 TCCR0B = 0b00000101; //setting prescaler for timer clock
 TCNT0=0;
}
void loop() {
 switch_read=digitalRead(switch1);
 if (switch_read==LOW){
 LED_sequence=!LED_sequence;
 }
 if (LED_sequence==1){
 //to make green1 LED blink
 digitalWrite(2, HIGH);
 delay_timer(LED_blink);
 digitalWrite(2, LOW);

 //to turn red1 LED blink
 digitalWrite(3, HIGH);
 delay_timer(LED_blink);
 digitalWrite(3, LOW);

 //green2 blink and so on
 digitalWrite(4, HIGH);
 delay_timer(LED_blink);
 digitalWrite(4, LOW);

 digitalWrite(5,HIGH);
 delay_timer(LED_blink);
 digitalWrite(5, LOW);

 digitalWrite(6, HIGH);
 delay_timer(LED_blink);
 digitalWrite(6, LOW);
 //green2 blink and so on
 digitalWrite(7, HIGH);
 delay_timer(LED_blink);
 digitalWrite(7, LOW);
// digitalWrite(_______, HIGH);
// digitalWrite(_______, HIGH);
// digitalWrite(_______, HIGH);
// digitalWrite(_______, HIGH);
// digitalWrite(_______, HIGH);
// digitalWrite(_______, HIGH);
// delay_timer(LED_blink);
// delay_timer(LED_blink);
// digitalWrite(_______, LOW);
// digitalWrite(_______, LOW);
// digitalWrite(_______, LOW);
// digitalWrite(_______, LOW);
// digitalWrite(_______, LOW);
// digitalWrite(_______, LOW);
//
 delay_timer(LED_blink);

 }
 else {

 digitalWrite(7, HIGH);
 delay_timer(LED_blink);
 digitalWrite(7, LOW);
 digitalWrite(6, HIGH);
 delay_timer(LED_blink);
 digitalWrite(6, LOW);
 digitalWrite(5, HIGH);
 delay_timer(LED_blink);
 digitalWrite(5, LOW);
 digitalWrite(4, HIGH);
 delay_timer(LED_blink);
 digitalWrite(4, LOW);
 digitalWrite(3, HIGH);
 delay_timer(LED_blink);
 digitalWrite(3, LOW);
 digitalWrite(2, HIGH);
 delay_timer(LED_blink);
 digitalWrite(2, LOW);
 delay_timer(LED_blink);

 }
}
