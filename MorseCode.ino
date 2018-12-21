//MorseCode Reader
//
//Criado em 21/12

const char* alfabeto[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                        "....", "..", ".---", "-.-", ".-..", "--", "-.", 
                        "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                        "...-", ".--", "-..-", "-.--", "--.."};
                        
float dotTime = 0.5;
float dashTime = 1.5;

unsigned long currentTime;
unsigned long lastTime;

unsigned long intervalo;

int inputBT = 3;

int bFlag=0;

void setup() {
  attachInterrupt(digitalPinToInterrupt(inputBT), setFlag, Change);
  Serial.begin(9600);
  
}

void loop() {
  if (bFlag==1){
    currentTime = millis();
  }
  else{
    lastTime = currentTime;
    currentTime = millis();
    intervalo = currentTime - lastTime;
  }
}
    
void setFlag(){
  if (bFlag==0){
    bFlag=1;
  }
  else{
    bFlag=0;
  }
}
