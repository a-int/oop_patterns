#pragma once

#include <iostream>

struct DocInterface {
  virtual void open(const std::string &fName) = 0;
  virtual void save() = 0;
  virtual void close() = 0;
  virtual void read() = 0;
};

class PdfDoc : public DocInterface {
public:
  void open(const std::string &fName) override {
    std::cout << "Open pdf...\n";
  };
  void save() override { std::cout << "Save pdf...\n"; };
  void close() override { std::cout << "Close pdf...\n"; };
  void read() override { std::cout << "read pdf...\n"; };
};

class WordDoc : public DocInterface {
public:
  void open(const std::string &fName) override {
    std::cout << "Open word...\n";
  };
  void save() override { std::cout << "Save word...\n"; };
  void close() override { std::cout << "Close word...\n"; };
  void read() override { std::cout << "read word...\n"; };
};

class AbstractParser {
public:
  virtual ~AbstractParser() {}

  void parse(const std::string &fName);

protected:
  virtual DocInterface *createDoc() = 0;
  virtual void doAnalyze() {} // hook

private:
  DocInterface *doc;
};

class PdfParser : public AbstractParser {
protected:
  DocInterface *createDoc() override { return new PdfDoc; }
  void doAnalyze() override { std::cout << "Analyze pdf...\n"; }
};

class WordParser : public AbstractParser {
protected:
  DocInterface *createDoc() override { return new WordDoc; }
};

void AbstractParser::parse(const std::string &fName) {
  doc = createDoc();

  doc->open(fName);
  doc->read();
  doc->close();
  doAnalyze();
}