int A = 8;
int B = 9;

void setup() {
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);  
}
 
void loop() {
  digitalWrite(A,HIGH); //팬모터가 A방향으로 회전
  digitalWrite(B,LOW);
  delay(2000); //2초 후
 
  digitalWrite(A,LOW); // 전체 정지
  digitalWrite(B,LOW);
  delay(5000); //5초 후
  
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH); //팬모터가 B방향으로 회전
  delay(2000); //2초 후
 
  digitalWrite(A,LOW); // 전체 정지
  digitalWrite(B,LOW);
  delay(5000); //5초 후
 
}
