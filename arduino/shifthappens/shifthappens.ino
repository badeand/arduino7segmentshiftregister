int DS_pin = 8;     // serial data input
int STCP_pin = 9;   // latch
int SHCP_pin = 10;  // clock

void setup()
{
  pinMode(DS_pin, OUTPUT);
  pinMode(STCP_pin, OUTPUT);
  pinMode(SHCP_pin, OUTPUT);
  //writereg();
}

byte registers[8];

byte numbers[10][8] = {
  { 1, 1, 1, 1, 1, 1, 0, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1, 0 }, // 2
  { 1, 1, 1, 1, 0, 0, 1, 0 }, // 3
  { 0, 1, 1, 0, 0, 1, 1, 0 }, // 4
  { 1, 0, 1, 1, 0, 1, 1, 0 }, // 5
  { 1, 0, 1, 1, 1, 1, 1, 0 }, // 6
  { 1, 1, 1, 0, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1, 0 }, // 8
  { 1, 1, 1, 1, 0, 1, 1, 0 }  // 9

};

void writereg(byte r[])
{
  digitalWrite(STCP_pin, LOW);
  wait();
  for (int i = 7; i >= 0; i--)
  {
    digitalWrite(SHCP_pin, LOW);
    wait();
    digitalWrite(DS_pin, r[i] );
    wait();
    digitalWrite(SHCP_pin, HIGH);
    wait();
  }
  digitalWrite(STCP_pin, HIGH);
  wait();
}

void loop()
{

for( int i = 0 ; i < 10 ; i++ ) {
  writereg(numbers[i]);
  delay(2000);
  }

/*
  writereg(numbers[1]);
  delay(500);
  writereg(numbers[2]);
  delay(500);
  writereg(numbers[3]);
  delay(500);
  writereg(numbers[4]);
  delay(500);
  writereg(numbers[5]);
  delay(500);
  writereg(numbers[6]);
  delay(500);
  writereg(numbers[7]);
  delay(500);
  /*
    for (int i = 0; i < 8; i++) {
    //blank();
    registers[i] = HIGH;
    delay(100);
    writereg(registers);
    }
    for (int i = 7; i > 0; i--)
    {
    // blank();
    registers[i] = LOW;
    delay(100);
    writereg(registers);
    }
  */

}

void wait()
{
  //delay(50);
}

void blank()
{
  for (int i = 0; i < 8; i++) {
    registers[i] = LOW;
  }
}
