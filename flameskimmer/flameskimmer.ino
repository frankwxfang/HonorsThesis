#define dirPin 8
#define pulPin 9
#define enaPin 10

/////////////////////////////////////////////////////////////////////
int pd = 10; // traverse speed
double Nrev = 0.25; // number of revolutions you wanna run for each new measurement
/////////////////////////////////////////////////////////////////////


long stepRev = 6400; // steps per revolution
bool isAway = 1; // true = away from motor

bool DIR;

long Nstep = Nrev*stepRev;
//double Lplus = 2;
//double Lminus = 3;
//double dy = 0.5; //mm
//double distperrev = 2; //mm per revolution
//int delaytime = 1000; //milliseconds
//long Nstep = stepRev*dy/distperrev; //number of steps per dy
//long Nrun = (long)(Lplus+Lminus)/dy; // total number of measurement locations
//long NLplus = stepRev*Lplus/distperrev;
//long NLminus = stepRev*Lminus/distperrev;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("");
//  Serial.println(Lplus);
//  Serial.println(Nstep);
//  Serial.println(NLplus);
//  Serial.println("Nrun");
//  Serial.println(Nrun);
  pinMode(pulPin, OUTPUT);      
  pinMode(dirPin, OUTPUT);
  digitalWrite(enaPin, LOW); // enable the motor

  if (isAway)
  {
    DIR = LOW;
  }
  else
  {
    DIR = HIGH;
  }
  digitalWrite(dirPin,DIR);
  delay(500);

  // Move from center to L+ 
  for(int x = 0; x < Nstep; x++) //
  {
      digitalWrite(pulPin,HIGH);
      delayMicroseconds(pd);
      digitalWrite(pulPin,LOW);
      delayMicroseconds(pd);
  }

  // Change direction
  DIR = !DIR;
  digitalWrite(dirPin,DIR);
  delay(1500);

  

  // Return to center
  // Move from L- to center
  for(int x = 0; x < Nstep; x++) //
  {
      digitalWrite(pulPin,HIGH);
      delayMicroseconds(pd);
      digitalWrite(pulPin,LOW);
      delayMicroseconds(pd);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

















































