#include <Adafruit_NeoPixel.h>
#define Z 0x0000FF//AZUL
#define VERDE 0x008000//VERDE
#define Rosa 0x800080//ROXO
#define V  0xFF0000//VERMELLHO;
#define Roxo 0xFFC0CB//ROSE
#define A 0xFFFF00//AMARELO
#define B 0xFFFFFF//BRANCO

#define PIN 4// Pino de controle
#define LED_COUNT 81// Quantidade de LED's (COLOQUEI 20 PARA CARREGAR MAIS RÃ�PIDO NO THINKERCAD)
//Cria uma instÃ¢ncia da Classe Adafruit NeoPixel chamado "leds"
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
      //leds.setBrightness(128); função de controlar o brilho 0 apagado 255 brilho máximo. (valor padrão da fita é 255 100% aceso).

  int SETD[9][9]={ {0,0,0,0,1,1,0,0,0},
                   {0,0,0,0,1,1,1,0,0},
                   {1,1,1,1,1,1,1,1,0},
                   {1,1,1,1,1,1,1,1,1},
                   {1,1,1,1,1,1,1,1,1},
                   {1,1,1,1,1,1,1,1,0},
                   {0,0,0,0,1,1,1,0,0},
                   {0,0,0,0,1,1,0,0,0},
                   {0,0,0,0,1,1,0,0,0}};

int SETE[9][9]={{0,0,0,0,1,1,0,0,0},
               {0,0,0,1,1,1,0,0,0},
               {0,0,1,1,1,1,1,1,1},
               {0,1,1,1,1,1,1,1,1},
               {0,1,1,1,1,1,1,1,1},
               {0,0,1,1,1,1,1,1,1},
               {0,0,0,1,1,1,0,0,0},
               {0,0,0,0,1,1,0,0,0},
               {0,0,0,0,1,1,0,0,0}};
       
int SETC[9][9]={{0,0,0,0,1,1,0,0,0},
                {0,0,0,1,1,1,1,0,0},
                {0,0,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1},
                {1,1,1,1,1,1,1,1,1},
                {0,0,0,1,1,1,1,0,0},
                {0,0,0,1,1,1,1,0,0},
                {0,0,0,1,1,1,1,0,0},
                {0,1,1,0,0,0,0,0,0}};

int I[9][9]={  {0,0,0,1,1,1,1,0,0},
               {0,0,0,0,1,1,0,0,0},
               {0,0,0,0,1,1,0,0,0},
               {0,0,0,0,1,1,0,0,0},
               {0,0,0,0,1,1,0,0,0},
               {0,0,0,0,1,1,0,0,0},
               {0,0,0,0,1,1,0,0,0},
               {0,0,0,0,1,1,0,0,0},
               {0,0,0,1,1,1,1,0,0}};

int F[9][9]= {{0,1,1,1,1,1,1,1,0},
               {0,1,1,1,1,1,1,1,0},
               {0,1,1,0,0,0,0,0,0},
               {0,1,1,1,1,1,0,0,0},
               {0,1,1,1,1,1,0,0,0},
               {0,1,1,0,0,0,0,0,0},
               {0,1,1,0,0,0,0,0,0},
               {0,1,1,0,0,0,0,0,0},
               {0,1,1,0,0,0,0,0,0}};

int E[9][9]={  {0,1,1,1,1,1,1,1,1},
               {0,1,1,0,0,0,0,1,1},
               {0,1,1,0,0,0,0,0,0},
               {0,1,1,1,1,1,1,0,0},
               {0,1,1,1,1,1,1,0,0},
               {0,1,1,1,1,1,1,0,0},
               {0,1,1,0,0,0,0,0,0},
               {0,1,1,0,0,0,0,1,1},
               {0,1,1,1,1,1,1,1,1}};

int P[9][9]={ {0,1,1,1,1,1,1,1,0},
               {0,1,1,0,0,0,1,1,0},
               {0,1,1,0,0,0,1,1,0},
               {0,1,1,1,1,1,1,1,0},
               {0,1,1,1,1,1,1,0,0},
               {0,1,1,0,0,0,0,0,0},
               {0,1,1,0,0,0,0,0,0},
               {0,1,1,0,0,0,0,0,0},
               {0,1,1,0,0,0,0,0,0}};
               

int matriz[9][9]={ {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0}};          
char buffer[4]={'I','F','P','E' };  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//Inicia a serial com baud rate
  leds.begin(); // Inicia a fita de LED
  clearLEDs();   // Apaga todos os LEDs
  leds.show(); // Atualiza o estados dos LEDs

}

void loop() {
  // put your main code here, to run repeatedly:
 // acende();
 int temp=0;
 
 for (int i=0;i<4;i++){
  if (buffer[i]=='I'){
        temp=0;
      }else if (buffer[i]=='F'){
        temp=1;
      }else if (buffer[i]=='P'){
        temp=2;
      }else if (buffer[i]=='E'){
        temp=3; 
      }
      troca(temp);
 }

  /*
  if (Serial.available() > 0){
   Serial.println("Uma letra I F P E");
   Serial.flush();
   Serial.readBytes(buffer,1);
      for (int i=0;i<4;i++){
      if (buffer[i]=='I'){
        temp=0;9
      }else if (buffer[i]=='F'){
        temp=1;
      }else if (buffer[i]=='P'){
        temp=2;
      }else if (buffer[i]=='E'){
        temp=3; 
      }
      troca (temp);
    }
    }
    limpar();
    */
//acendeLEDs();
//clearLEDs();


}

void limpar (){
  for (int i=0;i<4;i++){
  buffer[i]= ' ';
  }
}


void troca(int temp){
for (int j=0;j<9;j++){
    for (int i=0;i<9;i++){
      if (temp==0){
        matriz[i][8] = I[i][j];
      }else if (temp==1){
        matriz[i][8] = F[i][j];
      }else if (temp==2){
        matriz[i][8] = P[i][j];
      }else if (temp==3){
        matriz[i][8] = E[i][j];
      }
        }
      if(j<9){
        shift();
      }
      
      acendeLetra();
      delay(50-);
    }
}

void shift(){
for (int j=0;j<9;j++){
    for (int i=0;i<9;i++){
        matriz[i][j]=matriz[i][j+1];
        }
    }
}

void acendeLetra(){
int a=0;
for (int i=0;i<9;i++){//Vai de linha a linha
    if (i%2==0){        // Verifica se a linha Ã© par 
      for (int j=0;j<9;j++){ // Se a linha for par vai da esq para dir
        if (matriz[i][j]==1){ //Verifica se o elemento da matriz é 1
            leds.setPixelColor(a,VERDE);// Se for 1 acende
        }else{ // Caso contrÃ¡rio (for 0)
            leds.setPixelColor(a,0);// Se for zero apaga o LED
            }
            leds.show(); // atualiza a fita
           a++; // incrementa no final  for para o prÃ³ximo elemento da lista
          }
        }else{ // Caso a linha for ímpar
          for (int j=8;j>=0;j--){ // Se a linha for Ã­mpar vai da dir para esq
              if (matriz[i][j]==1){ // Verifica se o elemento da matriz Ã© 1
                leds.setPixelColor(a,VERDE); // se for 1 acende
              }else{
                leds.setPixelColor(a,0); // Se for 0 apaga o LED
             }
             leds.show(); // atualiza a fita
             a++; // incrementa no final  for para o prÃ³ximo elemento da lista
          }
        }
        ///atençãoo incremento necessário
       //a++; // Só vai ser usado quando acabar a linha incrementa um para ir para o primeiro elemento da proxima linha 
  }
    }

//FunÃ§Ã£o apaga LEDs geral
void clearLEDs()
{

  for (int p=0; p<LED_COUNT; p++)
  {
    leds.setPixelColor(p, 0);
    leds.show();
  }
}
//FunÃ§Ã£o acende LEDs geral
void acendeLEDs()
{
  for (int p=0; p<LED_COUNT; p++)
  {
    
      leds.setPixelColor(p, V);
      leds.show();
      delay (100);
      
  }
}
