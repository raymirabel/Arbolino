#include <avr/power.h>
#include <avr/sleep.h>
#include <RFu_JeeLib.h>  

ISR(WDT_vect) { Sleepy::watchdogEvent(); }                            // Attached JeeLib sleep function to Atmega328 watchdog -enables MCU to be put into sleep mode inbetween readings to reduce power consumption 

#define VERDE1 6
#define VERDE2 9
#define ROJO1  3
#define ROJO2  5
#define AZUL1  10
#define AZUL2  11

#define TSLEEP 60000L


byte secuencia1[] = {1,3,5,2,4,6,1,4,3,6,2,5,6,4,2,5,3,1,6,3,4,5,2,1,3,5,2,4,6,1,4,3,6,2,5,6,4,2,5,3,1,6,3,4,5,2};

// the setup routine runs once when you press reset:
void setup() {            
  boolean debug=0;                                       //Set to 1 to few debug serial output, turning debug off increases battery life  
  
   //################################################################################################################################
  // Power Save  - turn off what we don't need - http://www.nongnu.org/avr-libc/user-manual/group__avr__power.html
  //################################################################################################################################
  ACSR |= (1 << ACD);                     // disable Analog comparator    
  if (debug==0) power_usart0_disable();   //disable serial UART
  power_twi_disable();                    //Disable the Two Wire Interface module.
  // power_timer0_disable();              //don't disable necessary for the DS18B20 library
  power_timer1_disable();
  power_spi_disable();
  

}


// the loop routine runs over and over again forever:
void loop() {
  int led,n,i,t;
  
  t = 30;
  for(i=0;i<=5;i++){
    for(n=0;n<=46;n++){
      led = secuencia1[n];
      switch(led){
        case 1:
          lverde1(255);
          delay(t);
          lverde1(0);        
          break;
        case 2:
          lverde2(255);
          delay(t);
          lverde2(0);        
          break;
        case 3:
          lrojo1(255);
          delay(t);
          lrojo1(0);        
          break;
        case 4:
          lrojo2(255);
          delay(t);
          lrojo2(0);        
          break;
        case 5:
          lazul1(255);
          delay(t);
          lazul1(0);        
          break;
        case 6:
          lazul2(255);
          delay(t);
          lazul2(0);        
          break;  
      }
    }
  }
  
  dodelay(TSLEEP);
  dodelay(TSLEEP);
  dodelay(TSLEEP);
  dodelay(TSLEEP);
  dodelay(TSLEEP);  

  for(n=0;n<=20;n++){
    led = secuencia1[n];
    switch(led){
      case 1:
        lt1();
        break;
      case 2:
        lt2();
        break;
      case 3:
        lt3();
        break;
      case 4:
        lt4();
        break;
      case 5:
        lt5();
        break;
      case 6:
        lt6();
        break;  
    }
  }
  
  dodelay(TSLEEP);
  dodelay(TSLEEP);
  dodelay(TSLEEP);
  dodelay(TSLEEP);
  dodelay(TSLEEP);  
  
  t = 50;
  for(n=0;n<10;n++){
    lverde1(255);
    dodelay(t);
    lverde1(0);  
    dodelay(2000);  
    lrojo1(255);
    dodelay(t);
    lrojo1(0);  
    dodelay(2000);  
    lazul1(255);
    dodelay(t);
    lazul1(0);  
    dodelay(2000);  
    lverde2(255);
    dodelay(t);
    lverde2(0);  
    dodelay(2000);  
    lrojo2(255);
    dodelay(t);
    lrojo2(0);  
    dodelay(2000);  
    lazul2(255);
    dodelay(t);
    lazul2(0);  
    dodelay(2000);  
  }
  
  
  dodelay(TSLEEP);
  dodelay(TSLEEP);
  dodelay(TSLEEP);
  dodelay(TSLEEP);
  dodelay(TSLEEP);  
  
  
  for(n=0;n<=10;n++){
    led = secuencia1[n];
    switch(led){
      case 1:
        lt(VERDE1);
        break;
      case 2:
        lt(ROJO1);
        break;
      case 3:
        lt(AZUL2);
        break;
      case 4:
        lt(VERDE1);
        break;
      case 5:
        lt(ROJO2);
        break;
      case 6:
        lt(AZUL2);
        break;  
    }
  }
  
 dodelay(TSLEEP);
 dodelay(TSLEEP);
 dodelay(TSLEEP);  
 dodelay(TSLEEP); 
 dodelay(TSLEEP); 
  
}

// Enciende y apaga con pwm...
void lt(int led){
  int n;
  for(n=0;n<=255;n++){
    analogWrite(led, n);
    delayMicroseconds(3000);
  }
  for(n=255;n>=0;n--){
    analogWrite(led, n);
    delayMicroseconds(3000);
  } 
  dodelay(1000);
}

void lt1(void){
  int n;
  for(n=0;n<=255;n++){
    analogWrite(VERDE1, n);
    analogWrite(AZUL1, n);    
    delayMicroseconds(1000);
  }
  for(n=255;n>=0;n--){
    analogWrite(VERDE1, n);
    analogWrite(AZUL1, n);
    delayMicroseconds(1000);
  } 
}

void lt2(void){
  int n;
  for(n=0;n<=255;n++){
    analogWrite(ROJO1, n);
    analogWrite(VERDE2, n);    
    delayMicroseconds(1000);
  }
  for(n=255;n>=0;n--){
    analogWrite(ROJO1, n);
    analogWrite(VERDE2, n);
    delayMicroseconds(1000);
  } 
}

void lt3(void){
  int n;
  for(n=0;n<=255;n++){
    analogWrite(VERDE1, n);
    analogWrite(AZUL2, n);    
    delayMicroseconds(1000);
  }
  for(n=255;n>=0;n--){
    analogWrite(VERDE1, n);
    analogWrite(AZUL2, n);
    delayMicroseconds(1000);
  } 
}

void lt4(void){
  int n;
  for(n=0;n<=255;n++){
    analogWrite(ROJO2, n);
    analogWrite(AZUL1, n);    
    delayMicroseconds(1000);
  }
  for(n=255;n>=0;n--){
    analogWrite(ROJO2, n);
    analogWrite(AZUL1, n);
    delayMicroseconds(1000);
  } 
}

void lt5(void){
  int n;
  for(n=0;n<=255;n++){
    analogWrite(ROJO1, n);
    analogWrite(VERDE1, n);    
    analogWrite(AZUL1, n);    
    delayMicroseconds(1000);
  }
  for(n=255;n>=0;n--){
    analogWrite(ROJO1, n);
    analogWrite(VERDE1, n);    
    analogWrite(AZUL1, n);
    delayMicroseconds(1000);
  } 
}

void lt6(void){
  int n;
  for(n=0;n<=255;n++){
    analogWrite(ROJO2, n);
    analogWrite(VERDE2, n);    
    analogWrite(AZUL2, n);    
    delayMicroseconds(1000);
  }
  for(n=255;n>=0;n--){
    analogWrite(ROJO2, n);
    analogWrite(VERDE2, n);    
    analogWrite(AZUL2, n);
    delayMicroseconds(1000);
  } 
}


void ltodo(void){
  int n;
  for(n=0;n<=255;n++){
    analogWrite(VERDE1, n);
    analogWrite(VERDE2, n);    
    analogWrite(ROJO1, n);    
    analogWrite(ROJO2, n);        
    analogWrite(AZUL1, n);    
    analogWrite(AZUL2, n);        
    delayMicroseconds(250);
  }
  for(n=255;n>=0;n--){
    analogWrite(VERDE1, n);
    analogWrite(VERDE2, n);    
    analogWrite(ROJO1, n);    
    analogWrite(ROJO2, n);        
    analogWrite(AZUL1, n);    
    analogWrite(AZUL2, n);        
    delayMicroseconds(250);
  } 
}



// Enciende a un determinado brillo
void lverde1(int pwm){
  analogWrite(VERDE1, pwm);
}
void lverde2(int pwm){
  analogWrite(VERDE2, pwm);
}
void lrojo1(int pwm){
  analogWrite(ROJO1, pwm);
}
void lrojo2(int pwm){
  analogWrite(ROJO2, pwm);
}
void lazul1(int pwm){
  analogWrite(AZUL1, pwm);
}
void lazul2(int pwm){
  analogWrite(AZUL2, pwm);
}

void dodelay(unsigned int ms)
{
  byte oldADCSRA=ADCSRA;
  byte oldADCSRB=ADCSRB;
  byte oldADMUX=ADMUX;
      
  Sleepy::loseSomeTime(ms); // JeeLabs power save function: enter low power mode for x seconds (valid range 16-65000 ms)
      
  ADCSRA=oldADCSRA;         // restore ADC state
  ADCSRB=oldADCSRB;
  ADMUX=oldADMUX;
}
