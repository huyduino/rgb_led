#define delayTime 10
int rgb_pins [3] = {3, 5, 6}; // RED at 3, GREEN at 5, BLUE at 6
int rgb_values [3] = {0, 0, 0};

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(rgb_pins[i], OUTPUT);
    digitalWrite(rgb_pins[i], HIGH);
  }
}

void loop() {
  run(0); // running RED
  run(1); // running GREEN
  run(2); // running BLUE

  off_led();
  delay(1000);
}

void run(int index) {
  // init value
  memset(rgb_values, 0, sizeof(rgb_values));
  rgb_values[index] = 255;

  analogWrite(rgb_pins[index], 0);

  // running index color
  int next_index = (index == 2) ? 0 : index + 1;
  for (int i = 0; i < 255; i += 1) {
    rgb_values[index] -= 1;
    rgb_values[next_index] += 1;
    analogWrite(rgb_pins[index], 255 - rgb_values[index]);
    analogWrite(rgb_pins[next_index], 255 - rgb_values[next_index]);
    delay(delayTime);
  }
}

void off_led() {
  analogWrite(rgb_pins[0], 0);
  analogWrite(rgb_pins[1], 0);
  analogWrite(rgb_pins[2], 0);
}

