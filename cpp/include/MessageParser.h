#ifndef __MESSAGEPARSER_H__
#define __MESSAGEPARSER_H__

#include "Types.h"
#include <string>
#include <optional>

namespace Logi {

class MessageParser
{
    
public:
    static std::optional<Messages> parseMessages(const std::string& file);
};

}

#endif // __MESSAGEPARSER_H__
