#define RED 2
#define YELLOW 3
#define GREEN 4
#define BTN 8

bool btn_status = false;

void setup()
{
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BTN, INPUT);
}

void loop()
{
  delay(500);
  btn_status=digitalRead(BTN)==HIGH?!btn_status:btn_status;
btn_status?process():leds_off();
}
void leds_off()
{
  off(GREEN);
  off(YELLOW);
  off(RED);
}
bool checkBtn()
{
  delay(500);
  if(digitalRead(BTN)==HIGH)
  {
    btn_status=!btn_status;
    return true;
  }
  return false;
  
}
void process()
{
  if(checkBtn()){return;}
  on(RED);if(checkBtn()){return;}
  wait();if(checkBtn()){return;}
  off(RED);if(checkBtn()){return;}
  on(YELLOW);if(checkBtn()){return;}
  wait();if(checkBtn()){return;}
  off(YELLOW);if(checkBtn()){return;}
  on(GREEN); if(checkBtn()){return;}
  wait();if(checkBtn()){return;}
  off(GREEN);if(checkBtn()){return;}  
} 

void on(int x)
{
  digitalWrite(x, HIGH);
}

void off(int x)
{
  digitalWrite(x, LOW);
}
void wait()
{
  delay(3000);
}
