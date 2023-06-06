#define LED_ST 13
#define FAN 11
float Zk, Xk_1, Xk, Kk, Pk_1, Pk;
float R = 10;
float Q = 0.1;
void setup() {
  pinMode(FAN, OUTPUT);
  pinMode(LED_ST, OUTPUT);
  for (int j = 0; j <= 10; j++) {
    digitalWrite(LED_ST, 1);
    delay(50);
    digitalWrite(LED_ST, 0);
    delay(100);
    digitalWrite(LED_ST, 1);
    delay(100);
    digitalWrite(LED_ST, 0);
    delay(50);
  }
  digitalWrite(FAN, 1);
  delay(500);
  for (int i = 46; i <= 46; i++) {
    pinMode(i, INPUT);
  }
  Xk_1 = 0;
  Pk_1 = 1;
  Serial.begin(9600);
  Serial3.begin(115200);
  Serial3.setTimeout(100);
  Serial.setTimeout(100);

  Serial.setTimeout(100);
  while (!Serial) { ; }
}
int B;
void sensor() {
  int L20 = digitalRead(45);  //
  int L19 = digitalRead(44);  ///
  int L18 = digitalRead(43);  //
  int L17 = digitalRead(42);  //
  int L16 = digitalRead(33);  //
  int L15 = digitalRead(35);  //
  int L14 = digitalRead(38);  //
  int L13 = digitalRead(34);  //
  int L12 = digitalRead(41);  //
  int L11 = digitalRead(32);  //
  int L10 = digitalRead(40);  //
  int L9 = digitalRead(36);
  int L8 = digitalRead(24);
  int L7 = digitalRead(23);
  int L6 = digitalRead(25);
  int L5 = digitalRead(26);
  int L4 = digitalRead(29);
  int L3 = digitalRead(22);
  int L2 = digitalRead(27);
  int L1 = digitalRead(28);
  int A = L1 + L2 + L3 + L4 + L5 + L6 + L7 + L8 + L9 + L10 + L11 + L12 + L13 + L14 + L15 + L16 + +L17 + L18 + L19 + L20;
  B = 20 - A;
  //PID
  Zk = B;
  Kk = Pk_1 / (Pk_1 + R);
  Xk = Xk_1 + (Kk * (Zk - Xk_1));
  Pk = (1 - Kk) * Pk_1;
  Xk_1 = Xk;
  Pk_1 = Pk + Q;
  /* Serial.print(L1);
  Serial.print(" ");
  Serial.print(L2);
  Serial.print(" ");
  Serial.print(L3);
  Serial.print(" ");
  Serial.print(L4);
  Serial.print(" ");
  Serial.print(L5);
  Serial.print(" ");
  Serial.print(L6);
  Serial.print(" ");
  Serial.print(L7);
  Serial.print(" ");
  Serial.print(L8);
  Serial.print(" ");
  Serial.print(L9);
  Serial.print(" ");
  Serial.print(L10);
  Serial.print(" ");
  Serial.print(L11);
  Serial.print(" ");
  Serial.print(L12);
  Serial.print(" ");
  Serial.print(L13);
  Serial.print(" ");
  Serial.print(L14);
  Serial.print(" ");
  Serial.print(L15);
  Serial.print(" ");
  Serial.print(L16);
  Serial.print(" ");
  Serial.print(L17);
  Serial.print(" ");
  Serial.print(L18);
  Serial.print(" ");
  Serial.print(L19);
  Serial.print(" ");
  Serial.print(L20);
  Serial.print(" ");*/
  Serial.println(String(Xk * 10 / 2) + " cm");
  // Serial.print(" ");
  //Serial.println(Xk);
  Serial3.println(String(Xk * 10 / 2) + " cm");
  digitalWrite(LED_ST, 1);
  delay(50);
  digitalWrite(LED_ST, 0);
  delay(100);
  digitalWrite(LED_ST, 1);
  delay(50);
  digitalWrite(LED_ST, 0);
  delay(100);
  digitalWrite(LED_ST, 1);
  delay(500);
  digitalWrite(LED_ST, 0);
  delay(200);
  digitalWrite(LED_ST, 1);
  delay(50);
  digitalWrite(LED_ST, 0);
  delay(200);
}
void loop() {
  digitalWrite(FAN, 0);
  sensor();
}