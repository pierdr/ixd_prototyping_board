# IxD Prototyping Board

This board was designed for the Prototyping class at the California College of the Arts and it is designed to help lower the barrier of exploring physical inputs and physical computing. 

The custom board is designed to make physical computing more accessible to students and beginners by easing them into complexity a little bit at a time. The board functions as a keyboard (HID device) at first, allowing students to interact with the computer without writing any firmware. Next, the board can be talked to as a serial device, enabling more complex interactions. Finally, students can use the board as a regular Arduino, adding complexity gradually as they learn more about physical computing.

### Anatomy of the board

![](./_other/board2.jpg)
The prototyping board includes analog sensors, an encoder, and multiple buttons that can be used to send keyboard inputs to a computer. The analog sensors are connected to pins A4 and A5, while the encoder is connected to pins 4 and 12 with a switch on pin 6. The buttons are connected to pins A0, A1, A2, A3, 13, and 6, and each button is mapped to a corresponding keyboard key.

| Pin           | Description                                                                                                    |
|---------------|----------------------------------------------------------------------------------------------------------------|
| A4            | Analog sensor input                                                                                            |
| A5            | Light sensor input                                                                                             |
| 4             | Encoder channel A                                                                                              |
| 12            | Encoder channel B                                                                                              |
| 6             | Encoder switch                                                                                                 |
| A0            | Button input mapped to 's'                                                                                     |
| A1            | Button input mapped to 'w'                                                                                     |
| A2            | Button input mapped to 'd'                                                                                     |
| A3            | Button input mapped to 'a'                                                                                     |
| 13            | Button input mapped to spacebar                                                                                |

On the bottom of the board there is an explanation of the hardware components that are connected to the board. 
![](./_other/board_bottom.png).

### Hardware Setup

1. ![](./_other/encoder_board.jpg)Install female headers into the sockets for the rotary encoder.
2. ![](./_other/screwterminal_board.jpg)Install screw terminals at the end of the board. 


### Advanced features

The custom prototyping board includes some advanced features such as a haptic controller, audio output on pin 9, and an optocoupler (pin 8). It also offers pins 7 and 10 for additional inputs/outputs, and SCL and SDA for I2C communication.

| Pin  | Description                              |
|------|------------------------------------------|
| 11   | Haptic controller trigger (PB7)           |
| 3    | Haptic controller SCL (PD0)               |
| 2    | Haptic controller SDA (PD1)               |
| 9    | Audio output (PB5)                        |
| 8    | Optocoupler (PB4)                         |
| 7    | Free for additional input/output (PD2)   |
| 10   | Free for additional input/output (PB6)   |
| A4/SDA | Free for I2C communication (SDA)         |
| A5/SCL | Free for I2C communication (SCL)         |

### Arduino compatibility
The prototyping board is built around an ATmega 32u4 microcontroller, which is the same as the Arduino Micro. This means that the board can be programmed using the Arduino software, just like any other Arduino.

To add software to an Arduino Micro, you will need to use the Arduino IDE. Connect the board to the computer using a USB cable, select the board type "Arduino Micro" and the serial port, then write your code in the IDE and click on the "Upload" button to transfer the code to the board. 

### Credits

This effort would not be possible without the help of [Romy Aboudarham](https://github.com/romyaa), [Matt Visco](https://github.com/mattvisco) and [Hiroshi Mendoza](https://github.com/hiromendo). Special thanks to the [Hybrid Lab at CCA](https://github.com/HybridLabCCA).  




