#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <cstdint>
#include <ctime>
#include <fstream>

#include "Binary.hpp"

namespace Pex {

/**
 * @brief Binary structure file reading.
 *
 * The FileReader class provides a function to read a PEX file into a Binary structure.
 * The filename is provided as a parameter of the constructor.
 */
class FileReader
{
public:
    FileReader(const std::string& fileName);
    ~FileReader();

    void read(Binary& binary);

protected:

    void readHeader(Header& header);
    void read(StringTable& stringTable);
    void read(DebugInfo& debugInfo);
    void read(UserFlags& userFlags);
    void read(Objects& objects);
    void read(StructInfos& structInfos);
    void read(Variables& variables);
    void read(Properties& properties);
    void read(States& states);
    void read(Functions& functions);
    void read(Function& function);
    void read(TypedNames& typednames);
    void read(Instructions& instructions);


    std::uint8_t getUint8();
    std::uint16_t getSUint16();
    std::uint16_t getUint16();
    std::uint32_t getSUint32();
    std::uint32_t getUint32();
    StringTable::Index getStringIndex();
    StringTable::Index getSStringIndex();

    std::int16_t getInt16();
    std::int16_t getSInt16();
    float getFloat();
    float getSFloat();
    std::time_t getTime();
    std::time_t getSTime();
    std::string getString();
    std::string getSString();
    Value getValue();

    const StringTable* m_StringTable;

private:
    std::ifstream m_File;
};
}
#endif // FILEREADER_HPP
