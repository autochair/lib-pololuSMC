#ifndef SMC_DEFS_H_
#define SMC_DEFS_H_

#include <cstdint>

/**
 * Enumeration of all commands available to send to the pololu simple motor controller
 * Pololu Format
 * OR the command with 0x80 to produce the command byte for the Compact Format
 */
enum class POLOLU_COM: char {

    EXIT_SS                  = 0x03,            /**< Exits safe start mode */
    MOTOR_FORWARD            = 0x05,            /**< Power Motor in Forward Direction */
    MOTOR_REVERSE            = 0x06,            /**< Power Motor in Reverse Direction */
    MOTOR_FORWARD_7BIT       = 0X09,            /**< Power Motor in Forward Direction, 7-bit Speed */
    MOTOR_REVERSE_7BIT       = 0X0A,            /**< Power Motor in Reverse Direction 7-bit Speed */
    MOTOR_BRAKE              = 0x12,            /**< Brake Duty Cycle */
    MOTOR_STOP               = 0x60,            /**< Stop Motor and Enter Safe Start */
    SET_LIMIT                = 0x22,            /**< Set Temporary Limit for Motor */
    GET_SMC_VAR              = 0x21,            /**< Read 16 bit smc variable */
    GET_FIRMWARE             = 0x42,            /**< Get Firmware Version */
    HEADER                   = 0xAA             /**< Pololu Command Header */
};

/**
 * Enumeration of all commands available to send to the pololu simple motor controller
 * Compact Format
 * OR the command with 0x80 to produce the command byte for the Compact Format
 */
enum class COMPACT_COM: char {

    EXIT_SS                  = 0x83,            /**< Exits safe start mode */
    MOTOR_FORWARD            = 0x85,            /**< Power Motor in Forward Direction */
    MOTOR_REVERSE            = 0x86,            /**< Power Motor in Reverse Direction */
    MOTOR_FORWARD_7BIT       = 0X89,            /**< Power Motor in Forward Direction, 7-bit Speed */
    MOTOR_REVERSE_7BIT       = 0X8A,            /**< Power Motor in Reverse Direction 7-bit Speed */
    MOTOR_BRAKE              = 0x92,            /**< Brake Duty Cycle */
    MOTOR_STOP               = 0xE0,            /**< Stop Motor and Enter Safe Start */
    SET_LIMIT                = 0xA2,            /**< Set Temporary Limit for Motor */
    GET_SMC_VAR              = 0xA1,            /**< Read 16 bit smc variable */
    GET_FIRMWARE             = 0xC2             /**< Get Firmware Version */
};

/**
 * Enumeration of the number of bytes of data for each command.
 * Pololu Format
 * 
 */
enum class POLOLU_COM_BYTES: char {

    EXIT_SS                  = 2,               /**< No Data */
    MOTOR_FORWARD            = 4,               /**< Byte1: Low 5 bits of speed (Spd & 0x1F)
                                                     Byte2: Remaining bits of speed (Spd >> 5) */
    MOTOR_REVERSE            = 4,               /**< Byte1: Low 5 bits of speed (Spd & 0x1F)
                                                     Byte2: Remaining bits of speed (Spd >> 5) */
    MOTOR_FORWARD_7BIT       = 3,               /**< Byte1: Speed in increments 0-127 (mapped from 0-3200) */
    MOTOR_REVERSE_7BIT       = 3,               /**< Byte1: Speed in increments 0-127 (mapped from 0-3200) */
    MOTOR_BRAKE              = 3,               /**< Byte1: Braking Duty Cycle 1-32 */
    MOTOR_STOP               = 2,               /**< No Data */
    SET_LIMIT                = 5,               /**< Byte1: Limit ID
                                                     Byte2: Low 7 bits of limit val (Val & 0x7F)
                                                     Byte3: High 7 bits of limit val (Val >> 7) */
    GET_SMC_VAR              = 3,               /**< Byte1: Variable ID */
    GET_FIRMWARE             = 2                /**< No Data */
};

/**
 * Enumeration of the number of bytes of data for each command.
 * Compact Format
 * 
 */
enum class COMPACT_COM_BYTES: char {

    EXIT_SS                  = 0,               /**< No Data */
    MOTOR_FORWARD            = 2,               /**< Byte1: Low 5 bits of speed (Spd & 0x1F)
                                                     Byte2: Remaining bits of speed (Spd >> 5) */
    MOTOR_REVERSE            = 2,               /**< Byte1: Low 5 bits of speed (Spd & 0x1F)
                                                     Byte2: Remaining bits of speed (Spd >> 5) */
    MOTOR_FORWARD_7BIT       = 1,               /**< Byte1: Speed in increments 0-127 (mapped from 0-3200) */
    MOTOR_REVERSE_7BIT       = 1,               /**< Byte1: Speed in increments 0-127 (mapped from 0-3200) */
    MOTOR_BRAKE              = 1,               /**< Byte1: Braking Duty Cycle 1-32 */
    MOTOR_STOP               = 0,               /**< No Data */
    SET_LIMIT                = 3,               /**< Byte1: Limit ID
                                                     Byte2: Low 7 bits of limit val (Val & 0x7F)
                                                     Byte3: High 7 bits of limit val (Val >> 7) */
    GET_SMC_VAR              = 1,               /**< Byte1: Variable ID */
    GET_FIRMWARE             = 0                /**< No Data */
};

/**
 * The number of bytes returned for a command
 * Indepent of command format
 */
enum class COM_RES_BYTES: char {

    EXIT_SS                  = 0,               /**< No Response */
    MOTOR_FORWARD            = 0,               /**< No Response */
    MOTOR_REVERSE            = 0,               /**< No Response */
    MOTOR_FORWARD_7BIT       = 0,               /**< No Response */
    MOTOR_REVERSE_7BIT       = 0,               /**< No Response */
    MOTOR_BRAKE              = 0,               /**< No Response */
    MOTOR_STOP               = 0,               /**< No Response */
    SPEED                    = 0,               /**< No Response */
    SET_LIMIT                = 1,               /**< Byte1: Limit Code: 0 - Okay
                                                                        1 - Hard Forward Limit Conflict
                                                                        2 - Hard Reverse Limit Conflict
                                                                        3 - Hard For/Rev Limit Conflict */
    GET_SMC_VAR              = 2,               /**< Byte1: Low byte of 16-bit variable
                                                     Byte2: High significant byte of 16-bit variable */
    GET_FIRMWARE             = 4                /**< Byte1: Low byte of Product ID
                                                     Byte2: High byte of Product ID
                                                     Byte3: Minor Firmware Version (BCD)
                                                     Byte4: Major Firmware Version (BDC) */
};

enum class SSC_COM: char {
  SPEED                      = 0XFF             /**< Set Motor Speed, Direction Based On Value */
};

enum class SSC_COM_BYTES: char {
  SPEED                      = 2                /**< Byte1: device ID
                                                     Byte2: Speed, 0-Full Reverse, 127-Still, 254-Full Forward */
};

enum class SMC_VAR: char {

  //status flag registers
  ERROR_STATUS               = 0x00,            /**< Errors that are currently stopping the motor */
  ERRORS_OCCURRED            = 0x01,            /**< Errors that have occurred since this was last read */
  SERIAL_ERRORS_OCCURRED     = 0x02,            /**< Serial Errors that have occurred since this was last read */
  LIMIT_STATUS               = 0x03,            /**< Set bits indicate things currently limiting motor */
  RESET_FLAGS                = 0x7F,            /**< Flags indicating soruce of last board reset */

  // RC Channel Inputs
  RC1_UNLIMITED_RAW          = 0x04,            /**< Positive Pulse Width on RC1.
                                                     Units: 0.25 us
                                                     0xFFFF if no valid signal is detected */
  RC1_RAW                    = 0x05,            /**< Positive Pulse Width on RC1
                                                     Units: 0.25 us
                                                     0xFFFF if no valid signal or outside of error settings */
  RC1_SCALED                 = 0x06,            /**< Scaled RC1 Raw Value 
                                                     0 if raw is 0xFFFF
                                                     -3200 to +3200 otherwise */
  RC2_UNLIMITED_RAW          = 0x08,            /**< See RC1_UNLIMITED_RAW */
  RC2_RAW                    = 0x09,            /**< See RC1_RAW */
  RC2_SCALED                 = 0x0A,            /**< See RC1_SCALED */

  // Analog Channel Inputs
  AN1_UNLIMITED_RAW          = 0x0C,            /**< 12-bit ADC reading on analog channel 1
                                                     Units: counts, 0.0008059 volts/count
                                                     0xFFFF if the controller detects the input is disconnected */
  AN1_RAW                    = 0x0D,            /**< 12-bit ADC reading on analog channel 1
                                                     Units: counts, 0.0008059 volts/count
                                                     0xFFFF if disconnected or signal outside of error settings */
  AN1_SCALED                 = 0x0E,            /**< Scaled AN1 Raw Value
                                                     0 if disconnected
                                                     -3200 to +3200 otherwise */
  AN2_UNLIMITED_RAW          = 0x10,            /**< See AN1_UNLIMITED_RAW */
  AN2_RAW                    = 0x11,            /**< See AN1_RAW */
  AN2_SCALED                 = 0x12,            /**< See AN1_SCALED */

  // Diagnostic Variables
  TARGET_SPEED               = 0x14,            /**< Motor Target Speed requested by controlling interface 
                                                     -3200 to +3200 */
  CURRENT_SPEED              = 0x15,            /**< Current speed of motor
                                                     -3200 to +3200 */
  BRAKE_AMOUNT               = 0x16,            /**< How hard controller is braking when speed = 0 
                                                     0-32 mapped to 0-100% duty cycle
                                                     0 - Full coast (motor leads open)
                                                     32 - Full brake (motor leads fully shorted) */
  INPUT_VOLTAGE              = 0x17,            /**< 
  
  
};
#endif /* SMC_DEFS_H_ */
