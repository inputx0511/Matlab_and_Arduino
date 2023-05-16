#define echoPin 2
#define trigPin 3
int x=0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}
int val;
static int led = 0;
void loop() {
//  Serial.print("\n");
//  Serial.print(13);
//  while (Serial.available() > 0)
//  {
//    val = Serial.read();
//    if (val == 'a')
//    {
//      Serial.print("ok high");
//      Serial.print(read_sr04(2, 3));
//      Serial.print("\n");
//      digitalWrite(13, HIGH);
////      delay(5000);
//    }
//    else if (val == 'b') 
//    {
//      Serial.print("ok low");
//      Serial.print("\n");
//      digitalWrite(13, LOW);
//      delay(500);
//    }
//  }

//      Serial.print(x);
      val = Serial.parseInt();
      Serial.print(read_sr04(2, 3));
      Serial.print("/////////");
      Serial.print(val+3);
      Serial.print("\n");
//      x++;
}


float read_sr04(int echo, int trig)
{

    unsigned long duration;
    int distance;
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);  // phát xung từ chân trig
    delayMicroseconds(15);    //datasheet cua srf04 thi trigger pulse min = 10us
    digitalWrite(trig, LOW);
    
    duration = pulseIn(echo, HIGH);
    distance = duration/2/2.9;    //datasheet noi ve viec tinh toan khoang cach
    return distance;
}
