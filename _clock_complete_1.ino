#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);  // conexoes das entradas do display

int mls=0, sec=0, temp, hora=0, pis; 
int min=0, a=0, ano=17, mode, dia=1; 
int mes=1, eoq, up, down ,diaS, soma, e;

void setup(){
  lcd.begin(16,2); //Display 16 caractere por 2 linhas.
  lcd.clear();     //Limpa display.
  pinMode(10,INPUT);  //Aumenta
  pinMode(11,INPUT);  //Diminui
  attachInterrupt(digitalPinToInterrupt(2), chan, RISING);  
}
void loop(){
  int sensor = analogRead(A1);
  float voltage = sensor * 5.04;
  voltage /= 1023;
  int temp = (voltage - 0.5) * 100;
  lcd.setCursor(11, 1);  //Seleciona o caractere 11 e linha 1.
  lcd.print(temp);       //Imprime a temperatura.
  lcd.print("\xB0");     
  lcd.print("C");
  
  if(mode == 1) dia=est(dia, 1, 0); 
  if(mode == 2) mes=est(mes, 4, 0); 
  if(mode == 3) ano=est(ano, 7, 0); 
  if(mode == 4) hora=est(hora, 1, 1);
  if(mode == 5) min=est(min, 4, 1);
  if(mode == 6) sec=est(sec, 7, 1);
  
  mls=mls+500;
  if(mls==1000){  //Segundo
    mls=0;  
    sec++;    
  }
  if(sec > 59){  //Minutos
    sec=0;
    min++;
  }
  if(min > 59){  //Hora
    sec=0;
    min=0;
    hora++;
  }
  if(min < 0){
    sec=0;
    min=59;
    hora--;
  }
  if(hora > 23){ //Dia 
    sec=0;
    min=0;
    hora=0;
    dia++;
    diaS++;
  }
  if(hora < 0){ //Volta dia da semana                
    hora=23;
    min=59;
    dia--;
    diaS--;
  }
  if(mes != 2 && (mes%2) == 1){		//meses com 30 ou 31 dias e fevereiro
    if(dia == 32){
      dia=1;
      mes++;
    }
    if(dia < 1){
      dia = 31;
      mes--;
    }
  }
  if(mes!=2 && (mes%2) == 0){
    if(dia > 31){
      dia=1;
      mes++;
    }
  	if(dia < 1){
      dia = 30;
      mes--;
    }
  }
  if(mes == 2){                  
    if(dia > 28){
      dia=1;
      mes=3;
    }
  }
  if(mes == 3){                 
    if(dia < 1){
      dia=28;
      mes=2;
    }
  }
  if(mes == 13){
    mes=1;
    ano++;
  }
  if(mes < 1){
    mes=12;
    ano--;
  }
  if(mes == 9 || mes == 11){
    if(dia > 30){
      dia=1;
      mes++;
    }
  	if(dia == 0){
      dia = 30;
      mes--;
    }
  }

  if(ano == 17) e=-1;
  if(ano == 18) e=0;
  if(ano == 19) e=1;
  if(ano == 20) e=2;
    if(mes == 1 || mes == 10){
      soma = dia+1+e;
        if(soma < 7) diaS = soma;
        if(soma >= 7 && soma < 14) diaS = soma - 7;
        if(soma >= 14 && soma < 21) diaS = soma - 14;
        if(soma >= 21 && soma < 27) diaS = soma - 21;
        if(soma >= 28 && soma < 35) diaS = soma - 28;
        if(soma >= 35) diaS = soma - 35;
    }
    if(mes == 2 || mes == 3 || mes == 11){
      soma = dia+4+e;
        if(soma < 7) diaS = soma;
        if(soma >= 7 && soma < 14) diaS = soma - 7;
        if(soma >= 14 && soma < 21) diaS = soma - 14;
        if(soma >= 21 && soma < 27) diaS = soma - 21;
        if(soma >= 28 && soma < 35) diaS = soma - 28;
        if(soma >= 35) diaS = soma - 35;
    }
    if(mes == 4 || mes == 7){
      soma = dia+0+e;
        if(soma < 7) diaS = soma;
        if(soma >= 7 && soma < 14) diaS = soma - 7;
        if(soma >= 14 && soma < 21) diaS = soma - 14;
        if(soma >= 21 && soma < 27) diaS = soma - 21;
        if(soma >= 28 && soma < 35) diaS = soma - 28;
        if(soma >= 35) diaS = soma - 35;
    }
    if(mes == 5){
      soma = dia+2+e;
        if(soma < 7) diaS = soma;
        if(soma >= 7 && soma < 14) diaS = soma - 7;
        if(soma >= 14 && soma < 21) diaS = soma - 14;
        if(soma >= 21 && soma < 27) diaS = soma - 21;
        if(soma >= 28 && soma < 35) diaS = soma - 28;
        if(soma >= 35) diaS = soma - 35;
    }
    if(mes == 6){
      soma = dia+5+e;
        if(soma < 7) diaS = soma;
        if(soma >= 7 && soma < 14) diaS = soma - 7;
        if(soma >= 14 && soma < 21) diaS = soma - 14;
        if(soma >= 21 && soma < 27) diaS = soma - 21;
        if(soma >= 28 && soma < 35) diaS = soma - 28;
        if(soma >= 35) diaS = soma - 35;
    }
    if(mes == 8){
      soma = dia+3+e;
        if(soma < 7) diaS = soma;
        if(soma >= 7 && soma < 14) diaS = soma - 7;
        if(soma >= 14 && soma < 21) diaS = soma - 14;
        if(soma >= 21 && soma < 27) diaS = soma - 21;
        if(soma >= 28 && soma < 35) diaS = soma - 28;
        if(soma >= 35) diaS = soma - 35;
    }
    if(mes == 9 || mes == 12){
      soma = dia+6+e;
        if(soma < 7) diaS = soma;
        if(soma >= 7 && soma < 14) diaS = soma - 7;
        if(soma >= 14 && soma < 21) diaS = soma - 14;
        if(soma >= 21 && soma < 27) diaS = soma - 21;
        if(soma >= 28 && soma < 35) diaS = soma - 28;
        if(soma >= 35) diaS = soma - 35;
    }
    if(diaS == 1){
      lcd.setCursor(11, 0);
      lcd.print("Dom");
    }
    if(diaS == 2){
      lcd.setCursor(11, 0);
      lcd.print("Seg");
    }
    if(diaS == 3){
      lcd.setCursor(11, 0);
      lcd.print("Ter");
    }
    if(diaS == 4){
      lcd.setCursor(11, 0);
      lcd.print("Qua");
    }
    if(diaS == 5){
      lcd.setCursor(11, 0);
      lcd.print("Qui");
    }
    if(diaS == 6){
      lcd.setCursor(11, 0);
      lcd.print("Sex");
    }
    if(diaS == 0){
      lcd.setCursor(11, 0);
      lcd.print("Sab");
    }
  
  lcd.setCursor(1, 0);      //Seleciona o caractere 1 e linha 0, onde a menssagem vai ser mostrada.
  addzero(dia);             //Imprime o o valor de "dia".
  lcd.print("/");		    //Imprime o caractere "/".
  addzero(mes);             //Imprime o o valor de "mes".
  lcd.print("/");		    //Imprime o caractere "/".
  addzero(ano);             //Imprime o o valor de "ano".
  lcd.setCursor(1, 10);     //Seleciona o caractere 1 e linha 10, onde a menssagem vai ser mostrada.
  addzero(hora);            //Imprime o o valor de "hora".
  lcd.print(":");		    //Imprime o caractere ":".
  addzero(min);             //Imprime o o valor de "min".
  lcd.print(":");		    //Imprime o caractere ":".
  addzero(sec);
  delay(500);
}
 
  
//avança o mode quando o botao é apertado.
void chan(){
  mode++;              
  if(mode >= 6){       //casas que podem ser modificadas
    mode = 0;
  }
}
//coloca o "0" antes dos nº e imprime.
void addzero(int eoq){
  if(eoq < 10){
    lcd.print("0");
    lcd.print(eoq);
  }
  if(eoq >= 10){
    lcd.print(eoq);
  }
}
//escolhe o que mudar e muda com os botoes
int est(int pi, int X, int Y){
  
  up=digitalRead(10);
  down=digitalRead(11);
  
  if(up == 1){      //Aumenta
    pi++;
  }
  if(down == 1){    //Diminui
    pi--;
  }
  lcd.setCursor(X, Y);  // x = 16 caracteres do display e y = 2 linhas do display.
  if(pis == 0){ 
  	addzero(pi); 
    delay(200);
  }
  if(pis == 1){
 	lcd.print("..");     //Seleciona quantas casas que modificar
    delay(200);
  }
  pis=(pis+1)%2;
  return pi;
}