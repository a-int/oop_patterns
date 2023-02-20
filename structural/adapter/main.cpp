#include <iostream>
#include "adapter.hpp"
int main(){
	XML xml = XML("XML data");
	xml.print();

	XMLtoJSON adapter = XMLtoJSON(xml);

	JSON json = adapter.parseXML();
	json.print();
	
	return 0;
}