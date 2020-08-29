const short SER_pin = 2;
const short SRCLK_pin = 4;
const short RCLK_pin = 3;


void setup() {
  // put your setup code here, to run once:
  pinMode(SER_pin, OUTPUT);
  pinMode(RCLK_pin, OUTPUT);
  pinMode(SRCLK_pin, OUTPUT);
}

const short led_arr[] = {1, 2, 4};

void write_one() {
  digitalWrite(SER_pin, HIGH);
  digitalWrite(SRCLK_pin, LOW);
  digitalWrite(SRCLK_pin, HIGH);
}

void write_zero() {
  digitalWrite(SER_pin, LOW);
  digitalWrite(SRCLK_pin, LOW);
  digitalWrite(SRCLK_pin, HIGH);
}

void load_register() {
  digitalWrite(RCLK_pin, LOW);
  digitalWrite(RCLK_pin, HIGH);
}

void put_num(short num) {
  for (int i=0; i<3; i++) {
    if (num & led_arr[i]) {
      write_one();
    } else {
      write_zero();
    }
  }
  load_register();
}

unsigned short time;

void loop() {
  put_num(time);
  delay(1000);
  ++time;
}
