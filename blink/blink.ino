int data = 0;

// put your setup code here, to run once:
void setup() {
  // maak een seriële connectie met 9600 baudrate
  Serial.begin(9600);
}

// put your main code here, to run repeatedly:
void loop() {
  Serial.println(data);
  delay(1000);               // wait for a second
  data = data+1;
}
