#ifndef SMC_H_
#define SMC_H_

#include "SerialPort.h"
#include <string>

#define MAX_NUM_SMC_DEVICES 127

class SMC {
private:
    /* TODO
     serial connection (private) 
     serial port
     baud rate
     motor list (public get, public set) - list of motor id's that are supposed to be on the com port
     motor state (public get, private set) - current state of the motor (on, off, error)
     motor direction (public get, private set) - forward or backwards
   */

  /*serial port*/
  int _baudrate;
  std::string _port;
  SerialPort _conn;

  /*smc*/
  int _smcs[MAX_NUM_SMC_DEVICES];
  

public:
  /*TODO

    ctors
    serial setup
    

    enums:

    Status Flags:
     Error Status
     Errors Occurred
     Serial Errors Occurred
     Limit Status
     Reset Flags

    RC Channel Inputs:
     RC1 Unlimited Raw Value
     RC1 Raw Value
     RC1 Scaled Value
     RC2 Unlimited Raw Value
     RC2 Raw Value
     RC2 Scaled Value

    Analog Channel Inputs:
     AN1 Unlimited Raw
     AN1 Raw Value
     AN1 Scaled Value
     AN2 Unlimited Raw Value
     AN2 Raw Value
     AN2 Scaled Value

    Diaganotic Variables:
     Target Speed
     Speed
     Brake Amount
     Input Voltage
     Temperature
     RC Period
     Baud Rate Register
     System Time (low)
     System Time (high)

     Temporary Motor Limits:
      Max Speed Forward
      Max Acceleration Forward
      Max Deceleration Forward
      Brake Duration Forward
      Max Speed Reverse
      Max Acceleration Reverse
      Max Deceleration Reverse
      Brake Duration Reverse

    Bitmasks:

     Error Status
      Safe Start Violation
      Required Channel Invalid
      Serial Error
      Command Timeout
      Limit/Kill Switch
      Low VIN
      High VIN
      Over Temperature
      Motor Driver Error
      ERR Line High
      
     Serial Error
      Frame
      Noise
      RX Overrun
      Format
      CRC
      
     Limit Status
      Error/SafeStart
      Temperature
      Max Speed
      Starting Speed
      Motor Speed not equal to target due to accel/brake limits
      RC1 configured as kill switch and is active
      RC2 limit active
      AN1 limit active
      AN2 limit active
      USB kill switch active

     Reset Flags
      RST pin pulled low by external source
      Power reset 
      Software Reset
      Watchdog Timer Reset

    commands:

    Exit Safe-Start
    Motor Forward
    Motor Reverse
    Fast Set Speed (mini ssc)
    Motor Brake
    Get Variable
    Set Motor Limit
    Get Firmware Version
    Stop Motor

    

   */


}

#endif /* SMC_H_ */
