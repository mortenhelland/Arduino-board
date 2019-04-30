void setup()
{
  pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, INPUT);
    pinMode(12, INPUT);
    pinMode(13, INPUT);

}

const int Locked = 1;
const int WaitForClick = 2;
const int WaitForClickTwo = 3;
const int Checking = 4;
const int Unlocked = 5;

int btnOneHandled = 0;
int btnTwoHandled = 0;

int code[]={1,1};
int codeTry[2];


int state = Locked;

void loop()
{
  int sensor = digitalRead(13);
  int btnOne = digitalRead(12);
  int btnTwo = digitalRead(8);
  
  if(btnOne == LOW) {
  	btnOneHandled = 0;
  }
  if(btnTwo == LOW) {
  	btnTwoHandled = 0;
   

   
  switch(state) {
    case Locked:
    
    digitalWrite(7, HIGH);
    
    if (sensor == HIGH) {
       digitalWrite(7, LOW);


          state = WaitForClick;
    }
    
    break;
    
    case WaitForClick:
    
    digitalWrite(4, HIGH);
    
    if ((btnOne == HIGH) && (!btnOneHandled)) {
      btnOneHandled = 1;
        delay(1000);
      digitalWrite(4,LOW);
      	delay(1000);
      state = WaitForClickTwo;
    
    
    }
        if ((btnTwo == HIGH) && (!btnTwoHandled)){
      btnTwoHandled = 1;
        delay(1000);
      digitalWrite(5,LOW);
      	delay(1000);
            state = WaitForClickTwo;
    
  }
    break;
            
    case WaitForClickTwo:
    
                	digitalWrite(4, HIGH);


            
    if ((btnOne == HIGH) && (!btnOneHandled)) {
      btnOneHandled = 1;
        delay(1000);
      digitalWrite(5,LOW);
      	delay(1000);
      state = WaitForClickTwo;
    
    
    }
        if ((btnTwo == HIGH) && (!btnTwoHandled)) {
      btnTwoHandled = 1;
        delay(1000);
      digitalWrite(5,LOW);
      	delay(1000);
            state = WaitForClickTwo;
    
        }
            break;
            
            }
  }}