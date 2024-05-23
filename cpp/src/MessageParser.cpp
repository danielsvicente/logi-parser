#include "MessageParser.h"
#include <cstdint>
#include <iostream>
#include <fstream>

namespace Logi {

namespace {

std::uint32_t readLittleEndianUint32(const Buffer& buffer) {
    std::uint32_t number = 0;
    number |= static_cast<std::uint8_t>(buffer[0]);
    number |= static_cast<std::uint8_t>(buffer[1]) << 8;
    number |= static_cast<std::uint8_t>(buffer[2]) << 16;
    number |= static_cast<std::uint8_t>(buffer[3]) << 24;
    return number;
}

std::optional<Buffer> readFile(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        std::cerr << "MessageParser: Unable to open file " << filePath << std::endl;
        return {};
    }

    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    Buffer buffer(size);

    file.read(buffer.data(), size);
    file.close();

    return buffer;
}

}

std::optional<Messages> MessageParser::parseMessages(const std::string& file) {
    auto buffer = readFile(file);
    if (buffer) {
        Messages messages;
        auto bufferIndex = buffer.value().begin();
        while (bufferIndex != buffer.value().end()) {
            auto payloadSize = readLittleEndianUint32({bufferIndex, bufferIndex + 4});
            bufferIndex += 4;
            auto sequenceNumber = readLittleEndianUint32({bufferIndex, bufferIndex + 4});
            bufferIndex += 4;
            std::string message(bufferIndex, bufferIndex + payloadSize);
            messages.insert({sequenceNumber, message});
            bufferIndex += payloadSize;        
        }
        return messages;
    }
    return {};
}

}