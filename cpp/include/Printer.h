#ifndef __PRINTER_H__
#define __PRINTER_H__

#include "Types.h"
#include <string>

namespace Logi {

class Printer
{
public:
    static void printMessages(const Messages& Messages);

private:
    static void printTableHeader();
    static void printMessageRow(int sequenceNumber, std::string& message);
};
}

#endif // __PRINTER_H__
