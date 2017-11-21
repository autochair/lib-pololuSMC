#ifndef SMC_H_
#define SMC_H_

#include "SerialPort.h"
#include "defs.h"
#include <string>

class SMC {
private:

  SerialPort* _conn; /**< Serial Port for SMC communication */
  char _buffer[6];

  void initPololuMsg(uint8_t device){
    _buffer[0] = (char)POLOLU_COM::HEADER;
    _buffer[1] = device;
  };

public:

  /**
   *Default ctor
   */
  SMC();
  
  /**
   * Initialize SMC
   * @param conn Reference to an open serial port
   */
  SMC(SerialPort* conn);

  /**
   * Add a serial port reference
   * @param conn reference to an open serial port
   */
  void setPort(SerialPort* conn);

  /**
   * Sends the exit safe start command to all devices
   * @return 1 if successfully sent
   */
  int exitSafeStart();
  
  /**
   * Sends the exit safe start command to specified devices
   * @param uint8_t ID of device
   * @return 1 if successfully sent
   */
  int exitSafeStart(uint8_t device);

  /**
   * Sends forward pwm value to all devices
   * @param pwm value between 0-3200
   */
  int motorForward(uint16_t pwm );

  /**
   * Sends forward pwm value to specified device
   * @param uint8_t ID of device
   * @param pwm value between 0-3200
   */
  int motorForward(uint8_t device, uint16_t pwm);

  /**
   * Sends reverse  pwm value to all devices
   * @param pwm value between 0-3200
   */
  int motorReverse(uint16_t pwm);

  /**
   * Sends reverse  pwm value to specified device
   * @param uint8_t ID of device
   * @param pwm value between 0-3200
   */
  int motorReverse(uint8_t device, uint16_t pwm);

  /**
   * Sends low resolution forward pwm value to all devices
   * @param pwm value between 0-127
   */
  int motorForward_7Bit(uint8_t pwm );

  /**
   * Sends low resolution forward pwm value to specified device
   * @param uint8_t ID of device
   * @param pwm value between 0-127
   */
  int motorForward_7Bit(uint8_t device, uint8_t pwm);

  /**
   * Sends low resolution reverse  pwm value to all devices
   * @param pwm value between 0-127
   */
  int motorReverse_7Bit(uint8_t pwm);

  /**
   * Sends low resolution reverse  pwm value to specified device
   * @param uint8_t ID of device
   * @param pwm value between 0-127
   */
  int motorReverse_7Bit(uint8_t device, uint8_t pwm);

  /**
   * Sends motor brake duty cycle to all devices
   * @param Duty cycle value between 1-32
   */
  int motorBrake(uint8_t duty);

  /**
   * Sends motor brake duty cycle to specified device
   * @param uint8_t ID of device
   * @param Duty cycle value between 1-32
   */
  int motorBrake(uint8_t device, uint8_t duty);

  /**
   * Sends stop command to all devices
   * Enters safe start mode
   */
  int motorStop();
  
  /**
   * Sends stop command to specified device
   * Enters safe start mode
   * @param uint8_t ID of device
   */
  int motorStop(uint8_t device);

  /**
   * Sends a set limit command to all devices
   * @param uint8_t ID of device
   * @param uint8_t ID of limit 
   * @param limit value
   * @param uint8_t ref response code
   * @return 1 if success, 0 if failed to send
   */
  int setMotorLimit(uint8_t device, uint8_t limitID, uint16_t val, uint8_t &responseCode);

  /**
   * Reads the specified variable on a specific device 
   * @param uint8_t ID of device
   * @param uint8_t ID of variable
   */
  int getMotorVariable(uint8_t device, uint8_t variableID, uint16_t &variableVal);

  /**
   * Reads the firmware version of a specific device
   * @param uint8_t ID of device
   * @param uint16_t ref for product ID
   * @param uint8_t ref for major version number (BCD)
   * @param uint8_t ref for minor version number (BCD)
   * @return 1 if success
   */
  int getFirmwareVersion(uint8_t device, uint16_t &productID, uint8_t &majorVersion, uint8_t &minorVersion);
  
};

#endif /* SMC_H_ */
