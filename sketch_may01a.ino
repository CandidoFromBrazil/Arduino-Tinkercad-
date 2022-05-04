void setup() {
  pinMode(13,OUTPUT); //pinMode() = porta 
  //OUTPUT=SAÍDA. - INPUT=ENTRADA

}

void loop() {
 digitalWrite(13,HIGH); //HIGH=LIGADA(5V) - LOW=DESLIGADA(0)
 //digitalWrite=porta digital
 delay(2000);
 digitalWrite(13,LOW);
 delay(2000);
}
