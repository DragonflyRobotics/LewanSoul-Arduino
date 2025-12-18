#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#define SERVO_ID_ALL 0xfe
#define SERVO_MOVE_TIME_WRITE 1
#define SERVO_MOVE_TIME_READ 2
#define SERVO_MOVE_TIME_WAIT_WRITE 7
#define SERVO_MOVE_TIME_WAIT_READ 8
#define SERVO_MOVE_START 11
#define SERVO_MOVE_STOP 12
#define SERVO_ID_WRITE 13
#define SERVO_ID_READ 14
#define SERVO_ANGLE_OFFSET_ADJUST 17
#define SERVO_ANGLE_OFFSET_WRITE 18
#define SERVO_ANGLE_OFFSET_READ 19
#define SERVO_ANGLE_LIMIT_WRITE 20
#define SERVO_ANGLE_LIMIT_READ 21
#define SERVO_VIN_LIMIT_WRITE 22
#define SERVO_VIN_LIMIT_READ 23
#define SERVO_TEMP_MAX_LIMIT_WRITE 24
#define SERVO_TEMP_MAX_LIMIT_READ 25
#define SERVO_TEMP_READ 26
#define SERVO_VIN_READ 27
#define SERVO_POS_READ 28
#define SERVO_OR_MOTOR_MODE_WRITE 29
#define SERVO_OR_MOTOR_MODE_READ 30
#define SERVO_LOAD_OR_UNLOAD_WRITE 31
#define SERVO_LOAD_OR_UNLOAD_READ 32
#define SERVO_LED_CTRL_WRITE 33
#define SERVO_LED_CTRL_READ 34
#define SERVO_LED_ERROR_WRITE 35
#define SERVO_LED_ERROR_READ 36
#define SERVO_ERROR_OVER_TEMPERATURE 1
#define SERVO_ERROR_OVER_VOLTAGE 2
#define SERVO_ERROR_LOCKED_ROTOR 4

class Utils {
public:
  static int lower_byte(int value) { return value & 0xff; }
  static int higher_byte(int value) { return (value >> 8) & 0xff; }
  static int word(int low_byte, int high_byte) {
    return (high_byte << 8) + low_byte;
  }
  static int clamp(int value, int min_value, int max_value) {
    return std::max(min_value, std::min(value, max_value));
  }
};

#endif // !UTILS_H
