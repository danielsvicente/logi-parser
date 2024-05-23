#include <MessageParser.h>
#include <Printer.h>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "main: File missing\n" << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1; 
    }
    const std::string filename = argv[1];

    auto messages = Logi::MessageParser::parseMessages(filename);

    if (!messages) {
        std::cerr << "main: Failed to parse file " << filename << std::endl;
        return 1;
    }

    Logi::Printer::printMessages(messages.value());

    return 0;
}