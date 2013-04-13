int engines_switch = 13;

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

void setup() {
  
  // Engines
  pinMode(left_pwm, OUTPUT);
  pinMode(left_state, OUTPUT);
  pinMode(right_pwm, OUTPUT);
  pinMode(right_state, OUTPUT);
  
  // Engines switch
  pinMode(engines_switch, INPUT_PULLUP);
  
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
  
  if (digitalRead(engines_switch) == LOW) {
  
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
  
  if (digitalRead(engines_switch) == LOW) {
  
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
  
  if (digitalRead(engines_switch) == LOW) {
  
    analogWrite(left_pwm,currentSpeed);
    digitalWrite(left_state,0);
    analogWrite(right_pwm,255-currentSpeed);
    digitalWrite(right_state,1);
  
  }
}

void turn_right() {
  
  currentAction = 'r';
  
  if (digitalRead(engines_switch) == LOW) {
  
    analogWrite(left_pwm,255-currentSpeed);
    digitalWrite(left_state,1);
    analogWrite(right_pwm,currentSpeed);
    digitalWrite(right_state,0);
  
  }
  
}

long currentRange;
int actionDelay = 50;

void loop() {
  
  currentRange = getRange();
  
  if (currentRange > stopRange) {
    forward(); 
    actionDelay = 50;
  }else {
    
    if (currentAction != 'l') {
      engine_stop();
      delay(500);
    }
    
    turn_left();
    actionDelay = 800;
  }
  
  delay(actionDelay);
  
}
