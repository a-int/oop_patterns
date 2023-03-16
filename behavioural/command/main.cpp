#include "command.hpp"
#include <vector>
int main() {
  Window *app = new Window;

  Button bttn(new WindowRequestHide(app));
  bttn.clicked();

  bttn.setRequest(new WindowRequestClose(app));
  bttn.clicked();

  bttn.setRequest(new NoComand);
  bttn.clicked();

  return 0;
}