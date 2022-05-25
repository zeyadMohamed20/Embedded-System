#                  <u>Microwave Oven Controller</u> 

### <u>Aim</u>

This project simulates the embedded controller in a microwave oven

------

###  <u>Project Description</u>

The project is implemented using Tiva TM4C123GH6PM microcontroller depending on the      state machine diagram attached on the github repository
At the beginning, you need to enter a choice on the keypad to begin:

1) If A is pushed on the keypad (for popcorn), the LCD should show “Popcorn” and then
​    cook for 1 minute while the remaining cook time counts down (in seconds) on the LCD,
​    then clear the LCD after cooking completes.

2) If B (for Beef) or C (for chicken) is pushed on the keypad, the words “Beef weight?” or
​    “Chicken weight?” (respectively) should appear on the LCD. After that, the user must 
​     enter an integer value between 1 and 9 on the keypad to indicate how many kilos are
​     there to be defrosted,After a valid number is entered
​     the LCD display is cleared and show the value of the weight on the LCD for 2 seconds then
​    start cooking while the remaining cook time counts down (in seconds) on the LCD
o Beef is defrosted at a rate of 0.5 minutes per kilo.
o Chicken is defrosted at a rate of 0.2 minutes per kilo.
o If an illegal number is entered, then the LCD should show “Err” for 2 seconds,
​    then show previous message to set kilo again

3) If D is pushed on the keypad, the words “Cooking Time?” should appear on the LCD.
​    After that the user can enter a value between 1 sec. and 30 min. to indicate the cooking time
​    required in minutes and seconds. This value is displayed on the LCD as it is entered, right
​    to left.
​    For example, pressing 1 displays 00:01, then pressing 2 displays 00:12, then pressing 4
   displays 01:24, then pressing 5 displays 12:45. Press push button SW1 to clear the LCD
   display and show 00:00 and press SW2 to start cooking (if valid time) and counting down 

   But, if the time entered is invalid, display "invalid time" on LCD for 2 sec then enter time again

4) Switch SW3 (external push button), position 1, will simulate the microwave oven door
​    latch, where the switch being down would be simulating the open-door situation and the
​    switch being up would be simulating the door closed situation. Only when the latch is
   closed should the oven be able to be started.
o When SW2 is pressed, the oven starts operation.
o When SW1 (external push button) is pressed for first time, the oven operation
​    pauses (keeping remaining time on the display).
o When SW1 is pushed for second time after pressing it for first time, the time is
   cleared and the cooking stops.
o If SW2 is pushed after the oven is paused and the door is closed, then cooking
   must resume from the time it was paused.
• If it is cooking, opening the door should pause the cooking and keep the remaining time
  on display.
• When the microwave is running, the array of LEDs should be on. When it is stopped,
  they should go off. If paused, the array of LEDs should blink
 till the cooking is resumed or stopped.
 When the microwave completes its function and timer has counted down to zero (regular
 timed cooking or defrosting), the array of LEDs should flash 3 times 
 and the buzzer should produce an audible tone/alarm during these 3 seconds

------

### <u>Snapshots</u>

![1](https://github.com/zeyadMohamed20/Embedded-System/blob/81faaffd82df053523447e2eb5eda6c6bcca78d0/Images/1.jpeg)





![2](https://github.com/zeyadMohamed20/Embedded-System/blob/a993c3cddb31e85b62509401ba6870e9e5e0bcd9/Images/2.jpeg)

![3](https://github.com/zeyadMohamed20/Embedded-System/blob/766bd3743133c125c03f12eeba293f8e9ac69298/Images/3.jpeg)

![4](https://github.com/zeyadMohamed20/Embedded-System/blob/a993c3cddb31e85b62509401ba6870e9e5e0bcd9/Images/4.jpeg)

![5](https://github.com/zeyadMohamed20/Embedded-System/blob/a993c3cddb31e85b62509401ba6870e9e5e0bcd9/Images/5.jpeg)

![6](https://github.com/zeyadMohamed20/Embedded-System/blob/a993c3cddb31e85b62509401ba6870e9e5e0bcd9/Images/6.jpeg)

![7](https://github.com/zeyadMohamed20/Embedded-System/blob/a993c3cddb31e85b62509401ba6870e9e5e0bcd9/Images/7.jpeg)

![8](https://github.com/zeyadMohamed20/Embedded-System/blob/a993c3cddb31e85b62509401ba6870e9e5e0bcd9/Images/8.jpeg)

![9](https://github.com/zeyadMohamed20/Embedded-System/blob/a993c3cddb31e85b62509401ba6870e9e5e0bcd9/Images/9.jpeg)

![10](https://github.com/zeyadMohamed20/Embedded-System/blob/a993c3cddb31e85b62509401ba6870e9e5e0bcd9/Images/10.jpeg)

![11](https://github.com/zeyadMohamed20/Embedded-System/blob/a993c3cddb31e85b62509401ba6870e9e5e0bcd9/Images/11.jpeg)

![12](https://github.com/zeyadMohamed20/Embedded-System/blob/a993c3cddb31e85b62509401ba6870e9e5e0bcd9/Images/12.jpeg)

![13](https://github.com/zeyadMohamed20/Embedded-System/blob/a993c3cddb31e85b62509401ba6870e9e5e0bcd9/Images/13.jpeg)

![14](https://github.com/zeyadMohamed20/Embedded-System/blob/a993c3cddb31e85b62509401ba6870e9e5e0bcd9/Images/14.jpeg)

------

### <u>Setup</u>

To run this project, you need to intsall keil version 4 -embedded system platform-<u></u>

------

### <u>Live Demo</u> 

To see live demo for project, follow this link:



------



## <u>Contributors</u>

<u></u>Zeyad Mohamed     <zeyadmohamedasu@gmail.com>

Bishoy Yousry          <1900733@eng.asu.edu.eg>

Hassan Khaled        <Hassankhaled006@gmail.com>

Yusuf Ebrahim         <yabrahim500@gmail.com>

Andrw Adel              <andrewadel3322@gmail.com>

Basel Khaled            <zoulsmsm@gmail.com>

------

## <u>License & Copyright</u>

© Embedded Software Team ,Faculty Of Engineering Ain Shams University Cairo

​    Licensed under the [MIT License](LICENSE) 

------

