// pins
const short out_pins[] = {3, 5, 6, 9, 10, 11};
const short led_on[] = {32, 16, 8, 4, 2, 1};

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

unsigned short time = 0;

void loop() {
  Serial.println(time);
  for (short i=0; i < 6; ++i) {
    if ((time & led_on[i]) == led_on[i]) {
      analogWrite(out_pins[i], 255);
    } else {
      analogWrite(out_pins[i], 0);
    }
  }
  delay(1000);
  ++time;
}
