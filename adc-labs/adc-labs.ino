// Include the heartbeat module
#include "src/hrtbt/hrtbt.h"

// This function is used to initialize the various hardware that will be used
// in the code. It is only called once.
void setup() {
  // Set the heartbeat module
  hrtbt_cfg();
}

// This function is where the actual application code resides. It will run thru
// the code to the bottom and then start back over from the top forever.
void loop() {
  // Perform any action that the heartbeat module needs to do
  hrtbt_action();
}
