int left_pwm = 5;
int left_state = 4;
int right_pwm = 3;
int right_state = 2;

int action_delay = 2000;

int currentSpeed = 210;

int rangeTrig = 8;
int rangeEcho = 7;

int stopRange = 25;

char currentAction = ' ';
char currentRoutine = ' ';

int enginesState = 0;

int state_led = 13;
int engines_switch = 12;

int prevButtonState = HIGH;
int currentButtonState = HIGH;

void setup() {
  
  // Engines
  pinMode(left_pwm, OUTPUT);
  pinMode(left_state, OUTPUT);
  pinMode(right_pwm, OUTPUT);
  pinMode(right_state, OUTPUT);
  
  // Engines switch
  pinMode(engines_switch, INPUT_PULLUP);
  
  pinMode(state_led, OUTPUT);
  digitalWrite(state_led,LOW);
  
  //Range meter
  pinMode(rangeTrig, OUTPUT);
  pinMode(rangeEcho, INPUT);
    
}

long getRange() {
  
  long duration, distance;
  digitalWrite(rangeTrig, LOW); 
  delayMicroseconds(2);
  digitalWrite(rangeTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(rangeTrig, LOW);
  duration = pulseIn(rangeEcho, HIGH);
  distance = (duration/2) / 29.1;
  
  return distance;
}


void forward() {
  
  currentAction = 'f';
  
  if (enginesState == 1) {
  
    analogWrite(left_pwm,currentSpeed);
    digitalWrite(left_state,0);
    analogWrite(right_pwm,currentSpeed);
    digitalWrite(right_state,0);
  
  }else {
    engine_stop();
  }
  
}

void back() {
  
  currentAction = 'b';
  
  if (enginesState == 1) {
  
    analogWrite(left_pwm,255-currentSpeed);
    digitalWrite(left_state,1);
    analogWrite(right_pwm,255-currentSpeed);
    digitalWrite(right_state,1);
  
  }else {
    engine_stop();
  }
}

void engine_stop() {
  
  currentAction = ' ';
  
  analogWrite(left_pwm,0);
  digitalWrite(left_state,0);
  analogWrite(right_pwm,0);
  digitalWrite(right_state,0);
}

void turn_left() {
  
  currentAction = 'l';
  
  if (enginesState == 1) {
  
    analogWrite(right_pwm,currentSpeed);
    digitalWrite(right_state,0);
    analogWrite(left_pwm,255-currentSpeed);
    digitalWrite(left_state,1);
  
  }
}

void turn_right() {
  
  currentAction = 'r';
  
  if (enginesState == 1) {
  
    analogWrite(right_pwm,255-currentSpeed);
    digitalWrite(right_state,1);
    analogWrite(left_pwm,currentSpeed);
    digitalWrite(left_state,0);
  
  }
  
}

long currentRange;
int actionDelay = 50;

void loop() {
  
  currentRange = getRange();
  
  currentButtonState = digitalRead(engines_switch);
  
  if (prevButtonState != currentButtonState && currentButtonState == LOW) {

    if (enginesState == 1) {
      enginesState = 0;
      digitalWrite(state_led,LOW);
    }else {
      enginesState = 1;
      digitalWrite(state_led,HIGH);
    }

    delay(100);
  }
  
  prevButtonState = currentButtonState;
  
  //Movement routines
  if (currentRange > stopRange) {
    forward();
    currentRoutine = 'd';
    actionDelay = 50;
  }else {
    
    if (currentRoutine != 'e') {
      engine_stop();
      delay(400);
      back();
      delay(random(3,6) * 100);
      engine_stop();
      delay(300);
    }
    
    currentRoutine = 'e';
    
    if (random(0,1) == 1) {
      turn_left();
    }else {
      turn_right();
    }
    actionDelay = random(4,7) * 100;
  }
  
  delay(actionDelay);
  
}
