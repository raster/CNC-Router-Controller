/*
 * CheerLights.pde 
 *
 * You must select Keyboard from the "Tools > USB Type" menu
 *
 * Download and install the Bounce library: http://www.pjrc.com/teensy/td_libs_Bounce.html
 * 
 */

#include <Bounce.h>

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button0 = Bounce(0, 10);
Bounce button1 = Bounce(1, 10);  // 10 = 10 ms debounce time
Bounce button2 = Bounce(2, 10);  // which is appropriate for
Bounce button3 = Bounce(3, 10);  // most mechanical pushbuttons
Bounce button4 = Bounce(4, 10);
Bounce button5 = Bounce(5, 10);  // if a button is too "sensitive"
Bounce button6 = Bounce(6, 10);  // to rapid touch, you can
Bounce button7 = Bounce(7, 10);  // increase this time.
Bounce button8 = Bounce(8, 10);
Bounce button9 = Bounce(9, 10);


void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.  LOW for "on", and HIGH for "off" may seem
  // backwards, but using the on-chip pullup resistors is very
  // convenient.  The scheme is called "active low", and it's
  // very commonly used in electronics... so much that the chip
  // has built-in pullup resistors!
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);


  pinMode(20, INPUT_PULLUP);
  
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();

  // Check each button for "falling" edge.
  // Type a message on the Keyboard when each button presses
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  if (button0.fallingEdge()) {
    checkctrl();
    Keyboard.set_key1(KEY_RIGHT);
    Keyboard.send_now();
  }
  if (button0.risingEdge()) {
    checkctrl();
    releasekey();
  }
  
  if (button1.fallingEdge()) {
    checkctrl();
    Keyboard.set_key1(KEY_LEFT);
    Keyboard.send_now();
  }
  if (button1.risingEdge()) {
    checkctrl();
    releasekey();
  }
  
  if (button2.fallingEdge()) {
    checkctrl();
    Keyboard.set_key1(KEY_UP);
    Keyboard.send_now();
  }
  if (button2.risingEdge()) {
    checkctrl();
    releasekey();
  }
  
  if (button3.fallingEdge()) {
    checkctrl();
    Keyboard.set_key1(KEY_DOWN);
    Keyboard.send_now();
  }
  if (button3.risingEdge()) {
    checkctrl();
    releasekey();
  }
  
  if (button4.fallingEdge()) {
    checkctrl();
    Keyboard.set_key1(KEY_PAGE_UP);
    Keyboard.send_now();
  }
  if (button4.risingEdge()) {
    checkctrl();
    releasekey();
  }
  
  if (button5.fallingEdge()) {
    checkctrl();
    Keyboard.set_key1(KEY_PAGE_DOWN);
    Keyboard.send_now();
  }
  if (button5.risingEdge()) {
    checkctrl();
    releasekey();
  }
  
  if (button6.fallingEdge()) {
    Keyboard.set_modifier(MODIFIERKEY_ALT);
    Keyboard.set_key1(KEY_R);
    Keyboard.send_now();
    releasekey();
  }
  if (button6.risingEdge()) {
    releasekey();
  }
  
  if (button7.fallingEdge()) {
    Keyboard.set_modifier(MODIFIERKEY_ALT);
    Keyboard.set_key1(KEY_S);
    Keyboard.send_now();
    releasekey();
  }
  if (button7.risingEdge()) {
    releasekey();
  }
  
  
}

void checkctrl() {
  if (digitalRead(20) == HIGH) {
    Keyboard.set_modifier(0);
  }
  if (digitalRead(20) == LOW) {
    Keyboard.set_modifier(MODIFIERKEY_CTRL);
    // MODIFIERKEY_SHIFT <-- set to this for testing
  }
}


void releasekey() {
    Keyboard.set_key1(0);
    Keyboard.send_now();
}


//  

