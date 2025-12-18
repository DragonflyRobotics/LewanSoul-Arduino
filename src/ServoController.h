#ifndef SERVOCONTROLLER_H
#define SERVOCONTROLLER_H

#include "Servo.h"
#include "Utils.h"

class ServoController {
public:
  Serial serialPort;
  ServoController(Serial serial) : serialPort(serial) {}

  void command(int servoId, int command) {
    int length = 3;
    int checksum = 255 - ((servoId + length + command) % 256);
    serialPort.write(0x55);
    serialPort.write(0x55);
    serialPort.write(servoId);
    serialPort.write(length);
    serialPort.write(command);
    serialPort.write(checksum);
  }

  void command(int servoId, int command, int param1) {
    int length = 4;
    int checksum = 255 - ((servoId + length + command + param1) % 256);
    serialPort.write(0x55);
    serialPort.write(0x55);
    serialPort.write(servoId);
    serialPort.write(length);
    serialPort.write(command);
    serialPort.write(param1);
    serialPort.write(checksum);
  }

  void command(int servoId, int command, int param1, int param2) {
    int length = 5;
    int checksum = 255 - ((servoId + length + command + param1 + param2) % 256);
    serialPort.write(0x55);
    serialPort.write(0x55);
    serialPort.write(servoId);
    serialPort.write(length);
    serialPort.write(command);
    serialPort.write(param1);
    serialPort.write(param2);
    serialPort.write(checksum);
  }

  void command(int servoId, int command, int param1, int param2, int param3) {
    int length = 6;
    int checksum =
        255 - ((servoId + length + command + param1 + param2 + param3) % 256);
    serialPort.write(0x55);
    serialPort.write(0x55);
    serialPort.write(servoId);
    serialPort.write(length);
    serialPort.write(command);
    serialPort.write(param1);
    serialPort.write(param2);
    serialPort.write(param3);
    serialPort.write(checksum);
  }

  void command(int servoId, int command, int param1, int param2, int param3,
               int param4) {
    int length = 7;
    int checksum =
        255 -
        ((servoId + length + command + param1 + param2 + param3 + param4) %
         256);
    serialPort.write(0x55);
    serialPort.write(0x55);
    serialPort.write(servoId);
    serialPort.write(length);
    serialPort.write(command);
    serialPort.write(param1);
    serialPort.write(param2);
    serialPort.write(param3);
    serialPort.write(param4);
    serialPort.write(checksum);
  }

  void query() {}
  void get_servo_id(int servoId) {
    command(servoId, SERVO_ID_READ);
    query();
  }
  void set_servo_id(int servoId, int newId) {
    command(servoId, SERVO_ID_WRITE, newId);
  }

  void move_servo(int servoId, int position, int time) {
    position = Utils::clamp(position, 0, 1000);
    time = Utils::clamp(time, 0, 30000);

    command(servoId, SERVO_MOVE_TIME_WRITE, Utils::lower_byte(position),
            Utils::higher_byte(position), Utils::lower_byte(time),
            Utils::higher_byte(time));
  }
};

#endif // !SERVOCONTROLLER_H
