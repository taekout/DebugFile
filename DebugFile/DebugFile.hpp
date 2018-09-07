#pragma once
#include <string>
#include <mutex>
#include <fstream>
#include <sstream>

class DebugFile
{
protected:
    static std::ifstream m_debugfile;
    static std::string filename;

    static bool ParseLine(const std::string& line, const std::string& attribute, std::string& outValue);

public:
    DebugFile() = delete;
    virtual ~DebugFile() = delete;

    static std::string GetValue(const std::string& attribute);

    static long long GetInt(const std::string& attribute);
    static double GetFloat(const std::string& attribute);
    static bool GetBool(const std::string& attribute);
    static std::string GetString(const std::string& attribute);
};
