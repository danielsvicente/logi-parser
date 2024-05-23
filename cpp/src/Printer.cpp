#include "Printer.h"
#include <iostream>

namespace Logi {

namespace {

void formatBreakline(std::string& str) {
    size_t pos = 0;
    std::string currentText = "\n";
    std::string newText = "\n                  | ";
    while ((pos = str.find(currentText, pos)) != std::string::npos) {
        str.replace(pos, currentText.length(), newText);
        pos += newText.length();
    }
}

}

void Printer::printMessages(const Messages& messages) {
    printTableHeader();
    for (auto message : messages) {
        printMessageRow(message.first, message.second);
    }
}

void Printer::printTableHeader() {
    std::cout << "+-----------------+--------------------------------------+" << std::endl;
    std::cout << "| Sequence Number | Message                              |" << std::endl;
    std::cout << "+-----------------+--------------------------------------+" << std::endl;
}

void Printer::printMessageRow(int sequenceNumber, std::string& message) {
    formatBreakline(message);
    std::cout << "  " << sequenceNumber << "               | " << message << std::endl;
    std::cout << "+-----------------+--------------------------------------+" << std::endl;
}

}