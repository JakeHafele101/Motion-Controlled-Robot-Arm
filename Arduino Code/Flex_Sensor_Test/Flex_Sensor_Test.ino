#define FLEX_PIN A0

void setup() {
  // put your setup code here, to run once:
  pinMode(FLEX_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int flex = analogRead(FLEX_PIN);
  Serial.println(flex);
}
