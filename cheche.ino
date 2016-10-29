int i;
String inString = "";
char inChar = ' ';
char con=' ';
int INA = 4;
int PWMA = 5;
int INB = 7;
int PWMB = 6;

void setup()
{
  pinMode(INA, 1);
  pinMode(INB, 1);
  Serial.begin(9600);
}

void loop()
{
  
    while(Serial.available())
    { // i=0;
      inChar = Serial.read();
      if(isDigit(inChar))
      {
          inString += inChar;
      }
     
      else if(inChar =='\n'){
        i = inString.toInt();
          Serial.println(i);
          delay(1);
          // i=0;
          // inString = "";
      }

      else 
      {
        con = inChar;
        Serial.println(con);
      }
      switch (con)
    {
      case'W':  
        
        qian(i);
        break;
      /////////
      case'S':
     
       
        hou(i);
        break;
      ////////
      case'A':
     
        zuo(i);
        break;
      ///////
      case'D':
       
        you(i);
        break;
      /////
      case'Z':
        digitalWrite(INA, 0);
        analogWrite(PWMA, 255);
        digitalWrite(INB, 0);
        analogWrite(PWMB, 255);
        break;
      //////////
       //////////
      case'Q':
        digitalWrite(INA, 1);
        analogWrite(PWMA, 255);
        digitalWrite(INB, 0);
        analogWrite(PWMB, 255);
        break;
      //////////
       //////////
      case'H':
        digitalWrite(INA, 0);
        analogWrite(PWMA, 255);
        digitalWrite(INB, 1);
        analogWrite(PWMB, 255);
        break;
      //////////
      case'Y':
     
        digitalWrite(INA, 1);
        analogWrite(PWMA, 255);
        digitalWrite(INB, 1);
        analogWrite(PWMB, 255);
        break;
      ////
      case'T':
        digitalWrite(INA, 0);
        analogWrite(PWMA, 0);
        digitalWrite(INB, 0);
        analogWrite(PWMB, 0);
        
        break;

        i=0;
    }
   
   
     
  }

  }

  void qian(int p)
  { 
    digitalWrite(INA, 1);
    analogWrite(PWMA, p);
    digitalWrite(INB, 0);
    analogWrite(PWMB, p);
  }
  void hou(int p)
  { 
    digitalWrite(INA, 0);
    analogWrite(PWMA, p);
    digitalWrite(INB, 1);
    analogWrite(PWMB, p);
  }
  void zuo(int p)
  {
    digitalWrite(INA, LOW);
    analogWrite(PWMA, p);
    digitalWrite(INB, LOW);
    analogWrite(PWMB, 255-p);
  }
  void you(int p)
  { 
    digitalWrite(INA, 1);
    analogWrite(PWMA, 255-p);
    digitalWrite(INB, 1);
    analogWrite(PWMB, p);
  }








