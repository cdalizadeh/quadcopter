/* LIBRARIES */

#include <Servo.h>
#include <PID_v1.h>

/* CONSTANTS */

#define NUM_ESCS 4

#define ESC1_PIN 3
#define ESC2_PIN 9
#define ESC2_PIN 10
#define ESC2_PIN 11

#define X_KP 0
#define X_KD 0
#define X_KI 0

#define Y_KP 0
#define Y_KD 0
#define Y_KI 0

#define Z_KP 0
#define Z_KD 0
#define Z_KI 0

/* GLOBALS */

Servo esc[NUM_ESCS];

double x_angle;
double x_control;
PID x_pid(&x_angle, &x_control, X_KP, X_KD, X_KI, DIRECT);

double y_angle;
double y_control;
PID y_pid(&y_angle, &y_control, Y_KP, Y_KD, Y_KI, DIRECT);

double z_acceleration;
double z_control;
PID z_pid(&z_acceleration, &z_control, Z_KP, Z_KD, Z_KI, DIRECT);

/* SETUP */

void setup()
{
  initializePID();
  
  esc[0].attach(ESC1_PIN);
  esc[1].attach(ESC2_PIN);
  esc[2].attach(ESC3_PIN);
  esc[3].attach(ESC4_PIN);
  initializeMotor(esc);
}

/* LOOP */

void loop()
{
  x_angle = getXAngle();
  y_angle = getYAngle();
  z_acceleration = getZAcceleration();
  
  x_pid.compute();
  y_pid.compute();
  z_pid.compute();

  
}

/* FUNCTIONS */

void initializeMotor(Servo esc[]){
  for (int i = 0; i < NUM_ESCS; i++){
    esc[i].write(0);
  }
  delay(3000);
  for (int i = 0; i < NUM_ESCS; i++){
    esc[i].write(50);
  }
  delay(3000);
  for (int i = 0; i < NUM_ESCS; i++){
    esc[i].write(0);
  }
  delay(3000);
  for (int i = 0; i < NUM_ESCS; i++){
    esc[i].write(50);
  }
  delay(3000);
  for (int i = 0; i < NUM_ESCS; i++){
    esc[i].write(85);
  }
  delay(5000);
  for (int i = 0; i < NUM_ESCS; i++){
    esc[i].write(0);
  }
}

void initializePID(){
  //x_pid.SetOutputLimits(-100, 100);
  x_pid.SetMode(AUTOMATIC);
  y_pid.SetMode(AUTOMATIC);
  z_pid.SetMode(AUTOMATIC);
}
