#include <USBComposite.h>

#define BAUD 115200

USBHID HID;
HIDKeyboard Keyboard(HID);
HIDMouse Mouse(HID); 

void start(){
  for(int i = 0;i<6;i++){
  digitalWrite(PC13, LOW); // ON
  delay(150);
  digitalWrite(PC13, HIGH); // OFF
  delay(150);
  }
}

void setup() {
  // initialize digital pin PB1 as an output.

  Serial1.begin(BAUD);  
  
  pinMode(PC13, OUTPUT);
  pinMode(PB4, INPUT);
  pinMode(PB5, INPUT);
  digitalWrite(PC13, HIGH); // OFF light

  HID.begin(HID_KEYBOARD_MOUSE);

  start();
}

void light(int a){  // 0 or 1
  digitalWrite(PC13, LOW); // ON
  delay(500+(1000)*a);
  digitalWrite(PC13, HIGH); // OFF
  delay(500);
}




void light_char(char * a){
  for(int i = 0;i<strlen(a);i++){
    light(a[i]-0x30);  
  }
  delay(1500);
}

char *a = "01"  ;
char *b = "1000";
char *c = "1010";
char *d = "100" ;
char *e = "0"   ;
char *f = "0010";
char *g = "110" ;
char *h = "0000";
char *i = "00"  ;
char *j = "0111";
char *k = "101" ;
char *l = "0100";
char *m = "11"  ;
char *n = "10"  ;
char *o = "111" ;
char *p = "0110";
char *q = "1101";
char *r = "010" ;
char *s = "000" ;
char *t = "1"   ;
char *u = "001" ;
char *v = "0001";
char *w = "011" ;
char *x = "1001";
char *y = "1011";
char *z = "1100";
char *n0 = "11111";
char *n1 = "01111";
char *n2 = "00111";
char *n3 = "00011";
char *n4 = "00001";
char *n5 = "00000";
char *n6 = "10000";
char *n7 = "11000";
char *n8 = "11100";
char *n9 = "11110";
char *left  = "10110";
char *right = "101101";
char *down  = "001101";


void start_gpio(){
  if(!digitalRead(PB4) ){
    // THUCTF{FLAG_GPIO}
    light_char(t);
    light_char(h);
    light_char(u);
    light_char(c);
    light_char(t);
    light_char(f);
    light_char(left); 
    light_char(f);
    light_char(l);
    light_char(a);
    light_char(g);
    light_char(down);
    light_char(g);
    light_char(p);
    light_char(i);
    light_char(o);
    light_char(right);
  }
}

void start_uart() {
  Serial1.println("THUCTF{FLAG_UART}");
}

void start_swd(){
    char a[200] = "THUCTF{FLAG_SWD2}";
    delay((int)a % 1000);
    int i;
    int j;
    if((int)&i == (int)&j + i){
      Serial1.println("THUCTF{FLAG_SWD1}");
    }
}

void start_usb(){
  if(!digitalRead(PB6) && !digitalRead(PB7)  ){
    while(!USBComposite);
    Keyboard.println("THUCTF{FLAG_USB1}");
    delay(5000);
  }
}

// the loop function runs over and over again forever
void loop() {
  start_gpio();
  start_uart();
  start_swd();
  start_usb();
  delay(500);
}
