#include "smc.h"
#include "smc/SerialPort.h"


/**
 * Initialize SMC
 * @param conn Reference to an open serial port
 */
SMC::SMC(SerialPort &conn)
  :_conn(conn),
   _buffer()
{
}

/**
 * Sends the exit safe start command to all devices
 * @return 1 if successfully sent
 */
int SMC::exitSafeStart(){

  //use compact format for broadcast
  _buffer[0] = (char)COMPACT_COM::EXIT_SS;

  return _conn.sendArray(_buffer, (int)COMPACT_COM_BYTES::EXIT_SS);
}

/**
 * Sends the exit safe start command to specified devices
 * @param uint8_t ID of device
 * @return 1 if successfully sent
 */
int SMC::exitSafeStart(uint8_t device){

  // use pololu format for single device
  // fill in first two bytes
  initPololuMsg(device);

  //start filling in _buffer at [2]
  _buffer[2] = (char)POLOLU_COM::EXIT_SS;

  return _conn.sendArray(_buffer, (int)POLOLU_COM_BYTES::EXIT_SS);
}

/**
 * Sends forward pwm value to all devices
 * @param pwm value between 0-3200 that maps to 0-100% duty cycle
 */
int SMC::motorForward(uint16_t pwm){

  // return instead of clamping to 3200 for safety
  if(pwm > 3200)
    return 0;

  // use compact format for broadcast
  _buffer[0] = (char)COMPACT_COM::MOTOR_FORWARD;

  // first byte is lower 5 bits of pwm
  _buffer[1] = pwm & 0x1F;
  // second byte is the remaining upper 7 bits
  _buffer[2] = pwm >> 5;

  return _conn.sendArray(_buffer, (int)COMPACT_COM_BYTES::MOTOR_FORWARD);
  
}

/**
 * Sends forward pwm value to specified device
 * @param uint8_t ID of device
 * @param pwm value between 0-3200
 */
int SMC::motorForward(uint8_t device, uint16_t pwm){

  // return instead of clamping to 3200 for safety
  if(pwm > 3200)
    return 0;

  // use pololu format for single device
  // fill in first two bytes
  initPololuMsg(device);

  // start filling in _buffer at [2]
  _buffer[2] = (char)POLOLU_COM::MOTOR_FORWARD;
  _buffer[3] = pwm & 0x1F;
  _buffer[4] = pwm >> 5;

  return _conn.sendArray(_buffer, (int)POLOLU_COM_BYTES::MOTOR_FORWARD);
}

/**
 * Sends reverse  pwm value to all devices
 * @param pwm value between 0-3200
 */
int SMC::motorReverse(uint16_t pwm){

  // return instead of clamping to 3200 for safety
  if(pwm > 3200)
    return 0;

  //use compact format for broadcast
  _buffer[0] = (int)COMPACT_COM::MOTOR_REVERSE;
  _buffer[1] = pwm & 0x1F;
  _buffer[2] = pwm >> 5;

  return _conn.sendArray(_buffer, (int)COMPACT_COM_BYTES::MOTOR_REVERSE);
}

/**
 * Sends reverse  pwm value to specified device
 * @param uint8_t ID of device
 * @param pwm value between 0-3200
 */
int SMC::motorReverse(uint8_t device, uint16_t pwm){

  // return instead of clamping to 3200 for safety
  if(pwm > 3200)
    return 0;

  // use pololu format for single device
  // fill in first two bytes
  initPololuMsg(device);

  _buffer[2] = (char)POLOLU_COM::MOTOR_REVERSE;
  _buffer[3] = pwm & 0x1F;
  _buffer[4] = pwm >> 5;

  return _conn.sendArray(_buffer, (int)POLOLU_COM_BYTES::MOTOR_REVERSE);

}

/**
 * Sends low resolution forward pwm value to all devices
 * @param pwm value between 0-127
 */
int SMC::motorForward_7Bit(uint8_t pwm ){

  // return instead of clamping to 3200 for safety
  if(pwm > 127)
    return 0;

  //use compact format for broadcast
  _buffer[0] = (int)COMPACT_COM::MOTOR_FORWARD_7BIT;
  _buffer[1] = pwm;

  return _conn.sendArray(_buffer, (int)COMPACT_COM_BYTES::MOTOR_FORWARD_7BIT);
}

/**
 * Sends low resolution forward pwm value to specified device
 * @param uint8_t ID of device
 * @param pwm value between 0-127
 */
int SMC::motorForward_7Bit(uint8_t device, uint8_t pwm){

    // return instead of clamping to 3200 for safety
  if(pwm > 127)
    return 0;

  // use pololu format for single device
  // fill in first two bytes
  initPololuMsg(device);

  _buffer[2] = (char)POLOLU_COM::MOTOR_FORWARD_7BIT;
  _buffer[3] = pwm;

  return _conn.sendArray(_buffer, (int)POLOLU_COM_BYTES::MOTOR_FORWARD_7BIT);
}

/**
 * Sends low resolution reverse  pwm value to all devices
 * @param pwm value between 0-127
 */
int SMC::motorReverse_7Bit(uint8_t pwm){

  // return instead of clamping to 3200 for safety
  if(pwm > 127)
    return 0;

  //use compact format for broadcast
  _buffer[0] = (int)COMPACT_COM::MOTOR_REVERSE_7BIT;
  _buffer[1] = pwm;

  return _conn.sendArray(_buffer, (int)COMPACT_COM_BYTES::MOTOR_REVERSE_7BIT);
}

/**
 * Sends low resolution reverse  pwm value to specified device
 * @param uint8_t ID of device
 * @param pwm value between 0-127
 */
int SMC::motorReverse_7Bit(uint8_t device, uint8_t pwm){

  // return instead of clamping to 3200 for safety
  if(pwm > 127)
    return 0;

  // use pololu format for single device
  // fill in first two bytes
  initPololuMsg(device);

  _buffer[2] = (char)POLOLU_COM::MOTOR_REVERSE_7BIT;
  _buffer[3] = pwm;

  return _conn.sendArray(_buffer, (int)POLOLU_COM_BYTES::MOTOR_REVERSE_7BIT);
}

/**
 * Sends motor brake duty cycle to all devices
 * @param Duty cycle value between 1-32
 */
int SMC::motorBrake(uint8_t duty){

  // return instead of clamping to 3200 for safety
  if(duty > 32)
    return 0;

  //use compact format for broadcast
  _buffer[0] = (int)COMPACT_COM::MOTOR_BRAKE;
  _buffer[1] = duty;

  return _conn.sendArray(_buffer, (int)COMPACT_COM_BYTES::MOTOR_BRAKE);
}

/**
 * Sends motor brake duty cycle to specified device
 * @param uint8_t ID of device
 * @param Duty cycle value between 1-32
 */
int SMC::motorBrake(uint8_t device, uint8_t duty){

  // return instead of clamping to 3200 for safety
  if(duty > 32)
    return 0;
  
  // use pololu format for single device
  // fill in first two bytes
  initPololuMsg(device);

  _buffer[2] = (char)POLOLU_COM::MOTOR_BRAKE;
  _buffer[3] = duty;

  return _conn.sendArray(_buffer, (int)POLOLU_COM_BYTES::MOTOR_BRAKE);
}

/**
 * Sends stop command to all devices
 * Enters safe start mode
 */
int SMC::motorStop(){

  //use compact format for broadcast
  _buffer[0] = (int)COMPACT_COM::MOTOR_STOP;

  return _conn.sendArray(_buffer, (int)COMPACT_COM_BYTES::MOTOR_STOP);
}
  
/**
 * Sends stop command to specified device
 * Enters safe start mode
 * @param uint8_t ID of device
 */
int SMC::motorStop(uint8_t device){

  // use pololu format for single device
  // fill in first two bytes
  initPololuMsg(device);

  _buffer[2] = (char)POLOLU_COM::MOTOR_STOP;

  return _conn.sendArray(_buffer, (int)POLOLU_COM_BYTES::MOTOR_STOP);
}

/**
 * Sends a set limit command to all devices
 * @param uint8_t ID of device
 * @param uint8_t ID of limit 
 * @param limit value
 * @param uint8_t ref response code
 * @return 1 if success, 0 if failed to send
 */
int SMC::setMotorLimit(uint8_t device, uint8_t limitID, uint16_t val, uint8_t &responseCode){

  // use pololu format for single device
  // fill in first two bytes
  initPololuMsg(device);

  _buffer[2] = (char)POLOLU_COM::SET_LIMIT;
  _buffer[3] = limitID;
  //byte 4 is low 7 bits of val
  _buffer[4] = val & 0x7F;
  //byte 5 is remaining 7 high bits of val
  _buffer[5] = val >> 7;

  int tmp = _conn.sendArray(_buffer, (int)POLOLU_COM_BYTES::SET_LIMIT);

  if(tmp){
    _conn.getArray(_buffer, (int)COM_RES_BYTES::SET_LIMIT);
    //get the last 3 bits for response code
    responseCode = _buffer[0] & 0x03;
  }
  return tmp;
}

/**
 * Reads the specified variable on a specific device 
 * @param uint8_t ID of device
 * @param uint8_t ID of variable
 */
 int SMC::getMotorVariable(uint8_t device, uint8_t variableID, uint16_t &variableVal){

  // use pololu format for single device
  // fill in first two bytes
  initPololuMsg(device);

  _buffer[2] = (char)POLOLU_COM::GET_SMC_VAR;

  _buffer[3] = variableID;
  int tmp = _conn.sendArray(_buffer, (int)POLOLU_COM_BYTES::GET_SMC_VAR);

  if(tmp){
    _conn.getArray(_buffer, (int)COM_RES_BYTES::GET_SMC_VAR);
    //combine two bytes to form 16 bit value
    variableVal = ((uint16_t)(_buffer[1]) << 8) | _buffer[0];
    //variableVal = _buffer[0] + 256*_buffer[1];
  }
  return tmp;
}

/**
 * Reads the firmware version of a specific device
 * @param uint8_t ID of device
 * @param uint16_t ref for product ID
 * @param uint8_t ref for major version number (BCD)
 * @param uint8_t ref for minor version number (BCD)
 * @return 1 if success
 */
int SMC::getFirmwareVersion(uint8_t device, uint16_t &productID, uint8_t &majorVersion, uint8_t &minorVersion){

  // use pololu format for single device
  // fill in first two bytes
  initPololuMsg(device);

  _buffer[2] = (char)POLOLU_COM::GET_FIRMWARE;

  int tmp = _conn.sendArray(_buffer, (int)POLOLU_COM_BYTES::GET_FIRMWARE);

  if(tmp){
    _conn.getArray(_buffer, (int)COM_RES_BYTES::GET_FIRMWARE);
    productID = ((uint16_t)(_buffer[1]) << 8) | _buffer[0];
    minorVersion = (uint8_t)_buffer[2];
    majorVersion = (uint8_t)_buffer[3];
  }
  return tmp;
}
