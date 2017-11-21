#ifndef SMC_DEFS_H_
#define SMC_DEFS_H_

#include <stdint.h>

/**
 * Enumeration of all commands available to send to the pololu simple motor controller
 * Pololu Format
 * OR the command with 0x80 to produce the command byte for the Compact Format
 */
enum class POLOLU_COM: uint8_t {

    EXIT_SS                  = 0x03,            /**< Exits safe start mode */
    MOTOR_FORWARD            = 0x05,            /**< Power Motor in Forward Direction */
    MOTOR_REVERSE            = 0x06,            /**< Power Motor in Reverse Direction */
    MOTOR_FORWARD_7BIT       = 0X09,            /**< Power Motor in Forward Direction, 7-bit Pwm */
    MOTOR_REVERSE_7BIT       = 0X0A,            /**< Power Motor in Reverse Direction 7-bit Pwm */
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
enum class COMPACT_COM: uint8_t {

    EXIT_SS                  = 0x83,            /**< Exits safe start mode */
    MOTOR_FORWARD            = 0x85,            /**< Power Motor in Forward Direction */
    MOTOR_REVERSE            = 0x86,            /**< Power Motor in Reverse Direction */
    MOTOR_FORWARD_7BIT       = 0X89,            /**< Power Motor in Forward Direction, 7-bit Pwm */
    MOTOR_REVERSE_7BIT       = 0X8A,            /**< Power Motor in Reverse Direction 7-bit Pwm */
    MOTOR_BRAKE              = 0x92,            /**< Brake Duty Cycle */
    MOTOR_STOP               = 0xE0,            /**< Stop Motor and Enter Safe Start */
    SET_LIMIT                = 0xA2,            /**< Set Temporary Limit for Motor */
    GET_SMC_VAR              = 0xA1,            /**< Read 16 bit smc variable */
    GET_FIRMWARE             = 0xC2             /**< Get Firmware Version */
};

/**
 * Enumeration of the number of bytes of data for each command.
 * Includes the command byte itself
 * Pololu Format
 * 
 */
enum class POLOLU_COM_BYTES: uint8_t {

    EXIT_SS                  = 3,               /**< No Data */
    MOTOR_FORWARD            = 5,               /**< Byte1: Low 5 bits of pwm (Spd & 0x1F)
                                                     Byte2: Remaining bits of pwm (Spd >> 5) */
    MOTOR_REVERSE            = 5,               /**< Byte1: Low 5 bits of pwm (Spd & 0x1F)
                                                     Byte2: Remaining bits of pwm (Spd >> 5) */
    MOTOR_FORWARD_7BIT       = 4,               /**< Byte1: Pwm in increments 0-127 (mapped from 0-3200) */
    MOTOR_REVERSE_7BIT       = 4,               /**< Byte1: Pwm in increments 0-127 (mapped from 0-3200) */
    MOTOR_BRAKE              = 4,               /**< Byte1: Braking Duty Cycle 1-32 */
    MOTOR_STOP               = 3,               /**< No Data */
    SET_LIMIT                = 6,               /**< Byte1: Limit ID
                                                     Byte2: Low 7 bits of limit val (Val & 0x7F)
                                                     Byte3: High 7 bits of limit val (Val >> 7) */
    GET_SMC_VAR              = 4,               /**< Byte1: Variable ID */
    GET_FIRMWARE             = 3                /**< No Data */
};

/**
 * Enumeration of the number of bytes of data for each command.
 * Includes teh command byte itself
 * Compact Format
 * 
 */
enum class COMPACT_COM_BYTES: uint8_t {

    EXIT_SS                  = 1,               /**< No Data */
    MOTOR_FORWARD            = 3,               /**< Byte1: Low 5 bits of pwm (Spd & 0x1F)
                                                     Byte2: Remaining bits of pwm (Spd >> 5) */
    MOTOR_REVERSE            = 4,               /**< Byte1: Low 5 bits of pwm (Spd & 0x1F)
                                                     Byte2: Remaining bits of pwm (Spd >> 5) */
    MOTOR_FORWARD_7BIT       = 2,               /**< Byte1: Pwm in increments 0-127 (mapped from 0-3200) */
    MOTOR_REVERSE_7BIT       = 2,               /**< Byte1: Pwm in increments 0-127 (mapped from 0-3200) */
    MOTOR_BRAKE              = 2,               /**< Byte1: Braking Duty Cycle 1-32 */
    MOTOR_STOP               = 1,               /**< No Data */
    SET_LIMIT                = 4,               /**< Byte1: Limit ID
                                                     Byte2: Low 7 bits of limit val (Val & 0x7F)
                                                     Byte3: High 7 bits of limit val (Val >> 7) */
    GET_SMC_VAR              = 2,               /**< Byte1: Variable ID */
    GET_FIRMWARE             = 1                /**< No Data */
};

/**
 * The number of bytes returned for a command
 * Indepent of command format
 */
enum class COM_RES_BYTES: uint8_t {

    EXIT_SS                  = 0,               /**< No Response */
    MOTOR_FORWARD            = 0,               /**< No Response */
    MOTOR_REVERSE            = 0,               /**< No Response */
    MOTOR_FORWARD_7BIT       = 0,               /**< No Response */
    MOTOR_REVERSE_7BIT       = 0,               /**< No Response */
    MOTOR_BRAKE              = 0,               /**< No Response */
    MOTOR_STOP               = 0,               /**< No Response */
    PWM                      = 0,               /**< No Response */
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

enum class SSC_COM: uint8_t {
  SSC_PWM                    = 0XFF             /**< Set Motor Pwm, Direction Based On Value */
};

enum class SSC_COM_BYTES: uint8_t {
  SSC_PWM                    = 2                /**< Byte1: device ID
                                                     Byte2: Pwm, 0-Full Reverse, 127-Still, 254-Full Forward */
};

enum class SMC_VAR: uint8_t {

  //status flag registers
  ERROR_STATUS               = 0x00,            /**< Errors that are currently stopping the motor */
  ERRORS                     = 0x01,            /**< Errors that have occurred since this was last read */
  SERIAL_ERRORS              = 0x02,            /**< Serial Errors that have occurred since this was last read */
  LIMIT_STATUS               = 0x03,            /**< Set bits indicate things currently limiting motor */
  RESET_FLAGS                = 0x7F,            /**< Flags indicating soruce of last board reset */

  // RC Channel Inputs
  RC1_UNLIMITED_RAW          = 0x04,            /**< Positive Pulse Width on RC1.
                                                     Type: unsigned 16-bit
                                                     Units: 0.25 us
                                                     0xFFFF if no valid signal is detected */
  RC1_RAW                    = 0x05,            /**< Positive Pulse Width on RC1
                                                     Type: unsigned 16-bit
                                                     Units: 0.25 us
                                                     0xFFFF if no valid signal or outside of error settings */
  RC1_SCALED                 = 0x06,            /**< Scaled RC1 Raw Value 
                                                     Type: signed 16-bit
                                                     Units: internal units
                                                     0 if raw is 0xFFFF
                                                     -3200 to +3200 otherwise */
  RC2_UNLIMITED_RAW          = 0x08,            /**< See RC1_UNLIMITED_RAW */
  RC2_RAW                    = 0x09,            /**< See RC1_RAW */
  RC2_SCALED                 = 0x0A,            /**< See RC1_SCALED */

  // Analog Channel Inputs
  AN1_UNLIMITED_RAW          = 0x0C,            /**< 12-bit ADC reading on analog channel 1
                                                     Type: unsigned 16-bit
                                                     Units: counts, 0.0008059 volts/count
                                                     0xFFFF if the controller detects the input is disconnected */
  AN1_RAW                    = 0x0D,            /**< 12-bit ADC reading on analog channel 1
                                                     Type: unsigned 16-bit
                                                     Units: counts, 0.0008059 volts/count
                                                     0xFFFF if disconnected or signal outside of error settings */
  AN1_SCALED                 = 0x0E,            /**< Scaled AN1 Raw Value
                                                     Type: signed 16-bit
                                                     Units: internal units
                                                     0 if disconnected
                                                     -3200 to +3200 otherwise */
  AN2_UNLIMITED_RAW          = 0x10,            /**< See AN1_UNLIMITED_RAW */
  AN2_RAW                    = 0x11,            /**< See AN1_RAW */
  AN2_SCALED                 = 0x12,            /**< See AN1_SCALED */

  // Diagnostic Variables
  TARGET_PWM                 = 0x14,            /**< Motor Target Pwm requested by controlling interface 
                                                     Type: signed 16-bit
                                                     Units: internal units
                                                     -3200 to +3200 */
  CURRENT_PWM                = 0x15,            /**< Current pwm of motor
                                                     Type: signed 16-bit
                                                     Units: internal units
                                                     -3200 to +3200 */
  BRAKE_AMOUNT               = 0x16,            /**< How hard controller is braking when pwm = 0 
                                                     Type: unsigned 16-bit
                                                     0-32 mapped to 0-100% duty cycle
                                                     0 - Full coast (motor leads open)
                                                     32 - Full brake (motor leads fully shorted) */
  INPUT_VOLTAGE              = 0x17,            /**< Measured voltage on the VIN pin
                                                     Type: unsigned 16-bit
                                                     Units: mV */
  TEMPERATURE                = 0x18,            /**< Board temperature as measured by sensor near motor driver.
                                                     Type: unsigned 16-bit
                                                     Units: 0.1 C
                                                     Temperatures below freezing reported as 0. */
  RC_PERIOD                  = 0x1A,            /**< RC1 period if a valid signal is available.
                                                     Type: unsigned 16-bit
                                                     0 otherwise */
  BAUD_RATE_REGISTER         = 0x1B,            /**< Value of the controller's Baud Rate Register (BRR)
                                                     Type: unsigned 16-bit
                                                     Units: seconds per bits
                                                     bps = 72,000,000/BRR */
  SYSTEM_TIME_LOW            = 0x1C,            /**< Number of milliseconds since last reset or power cycle
                                                     Type: unsigned 16-bit
                                                     Lowest two bytes */
  SYSTEM_TIME_HIGH           = 0x1D,            /**< Number of milliseconds since last reset or power cycle
                                                     Type: unsigned 16-bit
                                                     Highest two bytes */

  // Temporary Motor Limits
  MAX_PWM_FORWARD            = 0x1E,            /**< Maximum allowed motor pwm in the forward direction
                                                     Type: unsigned 16-bit
                                                     Units: internal units
                                                     0-3200 */
  MAX_ACCELERATION_FORWARD   = 0x1F,            /**< Maximum allowed motor acceleration in the forward direction
                                                     Type: unsigned 16-bit
                                                     Units: delta(pwm) per update period
                                                     0 to 3200, 0 means no limit */
  MAX_DECELERATION_FORWARD   = 0x20,            /**< Maximum allowed motor deceleration in the forward direction
                                                     Type: unsigned 16-bit
                                                     Units: delta(pwm) per update period
                                                     0 to 3200, 0 means no limit */
  BRAKE_DURATION_FORWARD     = 0x21,            /**< Time spent braking (at pwm = 0) when transitioning from forward to reverse
                                                     Type: unsigned 16-bit
                                                     Units: ms */
  MAX_PWM_REVERSE            = 0x24,            /**< Same as MAX_PWM_FORWARD in reverse direction */
  MAX_ACCELERATION_REVERSE   = 0x25,            /**< Same as MAX_ACCELERATION_FORWARD in reverse direction */
  MAX_DECELERATION_REVERSE   = 0x26,            /**< Same as MAX_DECELERATION_FORWARD in reverse direction */
  BRAKE_DURATION_REVERSE     = 0x27             /**< Time spent brakin (at pwm = 0) when transitioning from reverse to forward */
};

/**
 * Soft Limit IDs
 */
enum class SOFT_LIMIT: uint8_t {
  MAX_PWM_BOTH             = 0x00,            /**< Sets both forward and backward max speed */
  MAX_ACCELERATION_BOTH      = 0x01,            /**< Sets both forward and backward max accel */
  MAX_DECELERATION_BOTH      = 0x02,            /**< Sets both forward and backward max decel */
  BRAKE_DURATION_BOTH        = 0x03,            /**< Sets both forward and backward brake duration */
  MAX_PWM_FORWARD          = 0x04,            /**< Sets forward max speed */
  MAX_ACCELERATION_FORWARD   = 0x05,            /**< Sets forward max accel */
  MAX_DECELERATION_FORWARD   = 0x06,            /**< Sets forward max decel */
  BRAKE_DURATION_FORWARD     = 0x07,            /**< Sets forward brake duration */
  MAX_PWM_REVERSE          = 0x08,            /**< Sets backward max speed */
  MAX_ACCELERATION_REVERSE   = 0x09,            /**< Sets backward max accel */
  MAX_DECELERATION_REVERSE   = 0x0A,            /**< Sets backward max decel */
  BRAKE_DURATION_REVERSE     = 0x0B,            /**< Sets backward brake duration */
  
};


/**
 * Bitmask for errors in SMC_VAR::ERROR_SATUS
 */
enum class ERROR_STATUS: int16_t {

  SAFE_START                 = 0x0001,            /**< Bit0: Safe start violation error */
  CHANNEL_INVALID            = 0x0002,            /**< Bit1: Required Channel Invalid */
  SERIAL_ERROR               = 0x0004,            /**< Bit2: Serial Error */
  COMMAND_TIMEOUT            = 0x0008,            /**< Bit3: Command Timeout */
  LIMIT_KILL_SWITCH          = 0x0010,            /**< Bit4: Limit/Kill Switch */
  LOW_VIN                    = 0x0020,            /**< Bit5: Low Input Voltage */
  HIGH_VIN                   = 0x0040,            /**< Bit6: High Input Voltage */
  OVER_TEMPERATURE           = 0x0080,            /**< Bit7: Over Temperature */
  MOTOR_DRIVE_ERROR          = 0x0100,            /**< Bit8: Motor Drive Error */
  ERR_LINE                   = 0x0200             /**< Bit9: Error Line High */
};


/**
 * Bitmask for serial errors in SMC_VAR::SERIAL_ERRORS
 */
enum class SERIAL_ERROR: int16_t {

  FRAME                      = 0x0002,            /**< Bit1: Frame */
  NOISE                      = 0x0004,            /**< Bit2: Noise */
  RX_OVERRUN                 = 0x0008,            /**< Bit3: RX Overrun */
  FORMAT                     = 0x0010,            /**< Bit4: Format */
  CRC                        = 0x0020             /**< Bit5: CRC */
};

/*
 * Bitmask for limit statuses in SMC_VAR::LIMIT_STATUS
 */
enum class LIMIT_STATUS: int16_t {

  SAFE_START                 = 0x0001,            /**< Bit0: Safe Start violation */
  OVER_TEMPERATURE           = 0x0002,            /**< Bit1: Temperature is actively reducing pwm */
  MAX_PWM                    = 0x0004,            /**< Bit2: Max pwm limit is actively reducing pwm 
                                                             taret pwm > max pwm */
  STARTING_PWM               = 0x0008,            /**< Bit3: Starting pwm limit is actively reducing pwm to zero
                                                             target pwm < starting pwm */
  ACCEL_BRAKE                = 0x0010,            /**< Bit4: Motor pwm is not equal to target pwm because of accleration or brake limits */
  RC1_KILL                   = 0x0020,            /**< Bit5: RC1 is configured as kill switch and is active */
  RC2_KILL                   = 0x0040,            /**< Bit6: RC2 is configured as kill switch and is active */
  AN1_KILL                   = 0x0080,            /**< Bit7: AN1 is configured as kill switch and is active */
  AN2_KILL                   = 0x0100,            /**< Bit8: AN2 is configured as kill switch and is active */
  USB_KILL                   = 0x0200             /**< Bit9: USB kill switch is active */
};

/**
 * Bitmask for reset flags in SMC_VAR::RESET_FLAGS
 */
enum class RESET_FLAGS: int16_t {

  RST                        = 0x0004,            /**< RST pin pulled low by external source */
  PWR                        = 0x000C,            /**< Power reset (VIN got too low or was disconnected) */
  SOFTWARE                   = 0x0014,            /**< Software reset by firmware upgrade process */
  WATCHDOG                   = 0x0024             /**< Watchdog timer reset */   
};

#endif /* SMC_DEFS_H_ */
