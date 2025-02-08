int green = 13; //defining the pins
int yellow = 8;
int red =7;
int button = 2;//defining input
unsigned long prevMillis=0;
const long interval=1000;//time gap between two LEDs 
int led=0;



void setup(){
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(button,INPUT);
}

void loop(){
  if(digitalRead(button) == HIGH){  //detects the button press
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
  }
  else{//when button is not pressed
    unsigned long presentMillis = millis();//initializing millis function

    if(presentMillis- prevMillis >=1000){
      prevMillis = presentMillis;

      if(led==0){
        digitalWrite(green,HIGH);
        digitalWrite(yellow,LOW);
        digitalWrite(red,LOW);
      }else if(led==1){
        digitalWrite(green,LOW);
        digitalWrite(yellow,HIGH);
        digitalWrite(red,LOW);
      }else if(led==2){
        digitalWrite(green,LOW);
        digitalWrite(yellow,LOW);
        digitalWrite(red,HIGH);

      }
      led = (led +1)%3;//updating the value
    }
  }
}
