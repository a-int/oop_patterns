#include "template.hpp"

int main(){

	AbstractParser* parser = new PdfParser;
	parser->parse("test.pdf");

	std::cout<<"\n\n";
	delete parser;

	parser = new WordParser;
	parser->parse("test.docx");

	return 0;
}