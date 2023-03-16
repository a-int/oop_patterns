#include "mediator.hpp"

int main(){
	ChatMediator cm;

	Person jack("Jack", cm);
	Person nick("Nick", cm);

	cm.addParticipant(jack).addParticipant(nick);
	jack.sendMessgae(nick, "Test message");

	return 0;
}