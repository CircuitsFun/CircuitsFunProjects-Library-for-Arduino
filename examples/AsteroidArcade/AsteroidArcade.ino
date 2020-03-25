#include <CircuitsFunProjects.h>

Button button(6);

void setup() {
  Serial.begin(9600);
  button.begin();
}

void loop() {
  if (button.isPressed()) {
    Serial.println("Shoot!");
  }
}
