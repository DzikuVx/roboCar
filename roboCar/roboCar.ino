int engines_switch = 13;

int left_pwm = 5;
int left_state = 4;
int right_pwm = 3;
int right_state = 2;

int action_delay = 2000;

int currentSpeed = 255;

void setup() {
  
  pinMode(led, OUTPUT);
  pinMode(left_pwm, OUTPUT);
  pinMode(left_state, OUTPUT);
  pinMode(right_pwm, OUTPUT);
  pinMode(right_state, OUTPUT);
  
}

void forward() {
  analogWrite(left_pwm,currentSpeed);
  digitalWrite(left_state,0);
  analogWrite(right_pwm,currentSpeed);
  digitalWrite(right_state,0);
}

void back() {
  analogWrite(left_pwm,255-currentSpeed);
  digitalWrite(left_state,1);
  analogWrite(right_pwm,255-currentSpeed);
  digitalWrite(right_state,1);
}

void engine_stop() {
  analogWrite(left_pwm,0);
  digitalWrite(left_state,0);
  analogWrite(right_pwm,0);
  digitalWrite(right_state,0);
}

void turn_l-eft() {
  analogWrite(left_pwm,currentSpeed);
  digitalWrite(left_state,0);
  analogWrite(right_pwm,255-currentSpeed);
  digitalWrite(right_state,1);
}

void turn_right() {
  analogWrite(left_pwm,255-currentSpeed);
  digitalWrite(left_state,1);
  analogWrite(right_pwm,currentSpeed);
  digitalWrite(right_state,0);
}

/*
void loop() {
  
  
}
*/

Demo version
void loop() {
  
  forward();
  delay(2000);
  engine_stop();
  delay(500);
  back();
  delay(2000);
  engine_stop();
  delay(500);
  turn_left();
  delay(1000);
  engine_stop();
  delay(500);
  turn_right();
  delay(1000);
  engine_stop();
  delay(500);
  
}

