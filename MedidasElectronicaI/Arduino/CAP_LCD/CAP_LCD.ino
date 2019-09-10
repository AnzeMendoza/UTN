/* Programa: LCD Tutorial
Autor:	Humberto Higinio
Web: www.humbertohiginio.com
Canal de Youtube: https://www.youtube.com/user/HHSolis
Video Exclusivo para mi canal de Youtube
Todos los Derechos Reservados - 2015
Código de Dominio Público */
/*----------------------------------------------------------------------------------------------*/
#include <LiquidCrystal.h> // Incluye la Libreria LiquidCrystal

void LCD (void);
void CAP(void);
void SerialPrint(void);

/*Definiciones y variables capacimetro */
#define analogPin      0          
#define chargePin      13         
#define dischargePin   8        
#define resistorValue  10000.0F  //Remember, we've used a 10K resistor to charge the capacitor
unsigned long startTime;
unsigned long elapsedTime;
float microFarads;                
float nanoFarads;

int f_nano = 0;

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Crea un Objeto LC. Parametros: (rs, enable, d4, d5, d6, d7)
/*----------------------------------------------------------------------------------------------*/
void setup() {   
    //lcd.begin(16,2); // Inicializa la interface para el LCD screen, and determina sus dimensiones (ancho y alto) del display
    /*Inicializacion capacimetro*/
    Serial.begin(9600);
    pinMode(chargePin, OUTPUT);
    digitalWrite(chargePin, LOW);
}
/*----------------------------------------------------------------------------------------------*/
void loop() { 
    //LCD();
    SerialPrint();
    CAP();
 }
/*----------------------------------------------------------------------------------------------*/
void CAP()
{
    digitalWrite(chargePin, HIGH);  
    startTime = micros();
    while(analogRead(analogPin) < 648){       
    }
    
    elapsedTime= micros() - startTime;
    microFarads =  ((float)elapsedTime / resistorValue) ;
        
    if (microFarads > 1){   
        f_nano = 0;
    }else{
        nanoFarads = microFarads * 1000.0; 
        f_nano = 1;    
    }
    
    digitalWrite(chargePin, LOW);            
    pinMode(dischargePin, OUTPUT);            
    digitalWrite(dischargePin, LOW);     //discharging the capacitor     
    
    while(analogRead(analogPin) > 0){   //This while waits till the capaccitor is discharged       
    }
    
    pinMode(dischargePin, INPUT);      //this sets the pin to high impedance

    delay(1000);
}
/*----------------------------------------------------------------------------------------------*/
void SerialPrint(){
    if(!f_nano){
        Serial.print(microFarads);
        Serial.println("  uF");
    } else {
        Serial.print(nanoFarads);
        Serial.println("  nF");
    }
        
}
/*----------------------------------------------------------------------------------------------*/
 void LCD (){

    if(!f_nano){
        lcd.setCursor(1,0); // Seteamos la ubicacion texto 0 linea 1 que sera escrita sobre el LCD
        lcd.print(microFarads);
         //delay(1000);
        lcd.setCursor(1,7);
        lcd.print("uF");
        //delay(1000);
    } else {
        lcd.setCursor(1,0); // Seteamos la ubicacion texto 0 linea 1 que sera escrita sobre el LCD
        lcd.print(nanoFarads);
        //delay(1000); 
        lcd.setCursor(1,7);
        lcd.print("nF");
        //delay(1000);
    }
   
    /*
    lcd.print("Humberto Higinio");
    delay(4000);
    lcd.clear(); // Limpia la pantalla
    delay(1500);
    
    lcd.blink(); // Displayamos el Blinking del Cursor sobre el LCD
    delay(3000);
    lcd.noBlink(); // Apagamos el Blinking del Cursor sobre el LCD
    
    lcd.print("Visita mi canal"); 
    delay(3000);   
    
    lcd.clear();
    
    lcd.print("www.youtube.com");
    
    lcd.setCursor(0,1); 
    lcd.print("/user/HHSolis");
    delay(5000);
    lcd.clear(); // 
    delay(2000);
    */ 
 }
 
