

/**
 * Initialize SMC
 * @param conn Reference to an open serial port
 */
SMC::SMC(const SerialPort &conn)
  :_conn(conn),
   buffer()
{
}

/**
 * Sends the exit safe start command to all devices
 * @return 1 if successfully sent
 */
int SMC::exitSafeStart(){

  //use compact format for broadcast
  buffer[0] = (int)COMPACT_COM::EXIT_SS;

  return _conn.sendArray(buffer, (int)COMPACT_COM_BYTES::EXIT_SS;
}

/**
 * Sends the exit safe start command to specified devices
 * @param uint8_t ID of device
 * @return 1 if successfully sent
 */
int SMC::exitSafeStart(uint8_t device){

  // use pololu format for single device
  initPololuMsg(device);

  //start filling in buffer at [2]
  buffer[2] = POLOLU_COM::EXIT_SS;

  return _conn.sendArray(buffer, (int)POLOLU_COM_BYTES::EXIT_SS);
}

/**
 * Sends forward pwm value to all devices
 * @param pwm value between 0-3200
 */
int SMC::motorForward(uint16_t pwm){

  //use compact format for broadcast
  buffer[0] = (int)COMPACT_COM::MOTOR_FORWARD;
}

/**
 * Sends forward pwm value to specified device
 * @param uint8_t ID of device
 * @param pwm value between 0-3200
 */
int SMC::motorForward(uint8_t device, uint16_t pwm){
  
}

/**
 * Sends reverse  pwm value to all devices
 * @param pwm value between 0-3200
 */
int SMC::motorReverse(uint16_t pwm){

  //use compact format for broadcast
  buffer[0] = (int)COMPACT_COM::MOTOR_REVERSE;
}

/**
 * Sends reverse  pwm value to specified device
 * @param uint8_t ID of device
 * @param pwm value between 0-3200
 */
int SMC::motorReverse(uint8_t device, uint16_t pwm){
  
}

/**
 * Sends low resolution forward pwm value to all devices
 * @param pwm value between 0-127
 */
int SMC::motorForward_7Bit(uint8_t pwm ){

  //use compact format for broadcast
  buffer[0] = (int)COMPACT_COM::MOTOR_FORWARD_7BIT;
}

/**
 * Sends low resolution forward pwm value to specified device
 * @param uint8_t ID of device
 * @param pwm value between 0-127
 */
int SMC::motorForward_7Bit(uint8_t device, uint8_t pwm){
  
}

/**
 * Sends low resolution reverse  pwm value to all devices
 * @param pwm value between 0-127
 */
int SMC::motorReverse_7Bit(uint8_t pwm){

  //use compact format for broadcast
  buffer[0] = (int)COMPACT_COM::MOTOR_REVERSE_7BIT;
}

/**
 * Sends low resolution reverse  pwm value to specified device
 * @param uint8_t ID of device
 * @param pwm value between 0-127
 */
int SMC::motorReverse_7Bit(uint8_t device, uint8_t pwm){
  
}

/**
 * Sends motor brake duty cycle to all devices
 * @param Duty cycle value between 1-32
 */
int SMC::motorBrake(uint8_t duty){

  //use compact format for broadcast
  buffer[0] = (int)COMPACT_COM::MOTOR_BRAKE;
}

/**
 * Sends motor brake duty cycle to specified device
 * @param uint8_t ID of device
 * @param Duty cycle value between 1-32
 */
int SMC::motorBrake(uint8_t device, uint8_t duty){
  
}

/**
 * Sends stop command to all devices
 * Enters safe start mode
 */
int SMC::motorStop(){

  //use compact format for broadcast
  buffer[0] = (int)COMPACT_COM::MOTOR_STOP;
}
  
/**
 * Sends stop command to specified device
 * Enters safe start mode
 * @param uint8_t ID of device
 */
int SMC::motorStop(uint8_t device){
  
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
  
}

/**
 * Reads the specified variable on a specific device 
 * @param uint8_t ID of device
 * @param uint8_t ID of variable
 */
int SMC::getMotorVariable(uint8_t device, uint8_t variableID){
  
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
  
}
