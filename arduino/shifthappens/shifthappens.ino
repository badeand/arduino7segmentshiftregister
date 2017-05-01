int DS_pin = 8;     // serial data input
int STCP_pin = 9;   // latch
int SHCP_pin = 10;  // clock

int a = 0;
int b = 0;


byte blank[8] = {0, 0, 0, 0, 0, 0, 0, 0};

byte numbers[10][8] = {
  { 1, 1, 1, 1, 1, 1, 0, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0, 1 }, // 1
  { 1, 1, 0, 1, 1, 0, 1, 0 }, // 2
  { 1, 1, 1, 1, 0, 0, 1, 1 }, // 3
  { 0, 1, 1, 0, 0, 1, 1, 0 }, // 4
  { 1, 0, 1, 1, 0, 1, 1, 1 }, // 5
  { 1, 0, 1, 1, 1, 1, 1, 0 }, // 6
  { 1, 1, 1, 0, 0, 0, 0, 1 }, // 7
  { 1, 1, 1, 1, 1, 1, 1, 0 }, // 8
  { 1, 1, 1, 1, 0, 1, 1, 1 }  // 9
};

void setup()
{
  pinMode(DS_pin, OUTPUT);
  pinMode(STCP_pin, OUTPUT);
  pinMode(SHCP_pin, OUTPUT);
  writereg(blank, blank);
}

// byte registers[8];


void writereg(byte r1[], byte r2[])
{
  digitalWrite(STCP_pin, LOW);
  wait();
  for (int i = 7; i >= 0; i--)
  {
    digitalWrite(SHCP_pin, LOW);
    wait();
    digitalWrite(DS_pin, r1[i] );
    wait();
    digitalWrite(SHCP_pin, HIGH);
    wait();
  }
  wait();



  for (int i = 7; i >= 0; i--)
  {
    digitalWrite(SHCP_pin, LOW);
    wait();
    digitalWrite(DS_pin, r2[i] );
    wait();
    digitalWrite(SHCP_pin, HIGH);
    wait();
  }
  digitalWrite(STCP_pin, HIGH);
  wait();
}

void loop()
{

 

  for ( int a = 0 ; a < 10 ; a++ ) {
    for ( int b = 0 ; b < 10 ; b++ ) {

      writereg(numbers[a], numbers[b]);
      delay(200);

    }

  }
}

void wait()
{
  delay(00);
}

