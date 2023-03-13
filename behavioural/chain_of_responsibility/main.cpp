#include "chain.hpp"

int main(){
	//Use window as default handler for button if cannot process the request from event
	Button* bttn = new Button;
	Window* win = new Window;
	bttn->setHandler(win);
	bttn->handleEvent(new ButtonEvent);
	bttn->handleEvent(new WindowEvent);

	delete bttn;
	delete win;
	return 0;
}