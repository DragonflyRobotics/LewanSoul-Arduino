#ifndef SERVO_H
#define SERVO_H

class Servo {

public:
  int id;
  Servo(int id) : id(id) {}
  int getId() const { return id; }
};

#endif // !SERVO_H
