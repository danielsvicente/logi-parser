#ifndef __TYPES_H__
#define __TYPES_H__

#include <vector>
#include <map>
#include <string>

namespace Logi {

using Buffer = std::vector<char>;
using Messages = std::map<int, std::string>;

}

#endif // __TYPES_H__