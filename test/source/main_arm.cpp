#include <fstream>
#include <iostream>
#include <string>

#include <disasm/disassembler.hpp>
#include <disasm/ARM/instructions.hpp>

int main() {

    constexpr std::array<uint8_t, 96> data = { 
        0x80, 0xb5, 0x82, 0xb0, 0x00, 0xaf, 0x00, 0xf0, 0x6e, 0xf9, 0x00, 0xf0, 0x29, 0xf8, 0x00, 0xf0, 
        0x77, 0xf8, 0x4f, 0xf0, 0x80, 0x53, 0x7b, 0x60, 0xfa, 0x20, 0x00, 0xf0, 0xd9, 0xf9, 0x01, 0x21, 
        0x4f, 0xf0, 0x90, 0x40, 0x00, 0xf0, 0xf2, 0xfe, 0x03, 0x46, 0x00, 0x2b, 0x03, 0xd0, 0x7b, 0x68, 
        0x1b, 0x78, 0xaa, 0x2b, 0x0b, 0xd1, 0x7b, 0x68, 0x00, 0x22, 0x1a, 0x70, 0x01, 0x22, 0x4f, 0xf4, 
        0x00, 0x51, 0x06, 0x48, 0x00, 0xf0, 0xfa, 0xfe, 0x07, 0xf0, 0x24, 0xfe, 0x04, 0xe0, 0x7b, 0x68, 
        0x00, 0x22, 0x1a, 0x70, 0xff, 0xf7, 0xba, 0xff, 0xfe, 0xe7, 0x00, 0xbf, 0x00, 0x08, 0x00, 0x48 
    };
    auto span = std::span<const dc::u8>(data.data(), data.size());

    fmt::print("Disassembly:\n");
    for (const auto &line : dc::disasm::disassemble<dc::disasm::arm::v7::thumb::Architecture>(span)) {
        printf("%s\n", line.c_str());
    }
    return 0;
}
