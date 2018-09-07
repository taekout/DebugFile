#include "DebugFile.hpp"

std::ifstream DebugFile::m_debugfile;
std::string DebugFile::filename = "C:\\Public\\debug.txt";

bool DebugFile::ParseLine(const std::string& line, const std::string& attribute, std::string& outValue)
{
    std::size_t found = line.find(attribute, 0);
    if (found == std::string::npos)
        return false;

    found += attribute.size();

    found = line.find('=', found);
    if (found == std::string::npos)
        return false;

    found++;
    while (found < line.size() && line[found] == ' ')
        found++;

    size_t start = found;
    if (start >= line.size())
        return false;

    while (found < line.size() && line[found] != ' ')
        found++;

    outValue = line.substr(start, found - start);
    return true;
}

std::string DebugFile::GetValue(const std::string& attribute)
{
    if (!m_debugfile.is_open()) {
        m_debugfile.open(DebugFile::filename, std::ifstream::in);
    }

    if (m_debugfile.is_open())
    {
        m_debugfile.clear();
        m_debugfile.seekg(0, std::ios::beg);
        std::string line;
        while (std::getline(m_debugfile, line))
        {
            std::string value;
            if (ParseLine(line, attribute, value)) {
                return value;
            }
        }
    }
    return "";
}

long long DebugFile::GetInt(const std::string& attribute)
{
    std::string value = GetValue(attribute);
    long long lValue;
    std::istringstream os(value);
    os >> lValue;
    return lValue;
}

double DebugFile::GetFloat(const std::string& attribute)
{
    std::string value = GetValue(attribute);
    double fValue;
    std::istringstream os(value);
    os >> fValue;
    return fValue;
}

bool DebugFile::GetBool(const std::string& attribute)
{
    std::string value = GetValue(attribute);
    bool bValue;
    std::istringstream os(value);
    os >> bValue;
    return bValue;
}

std::string DebugFile::GetString(const std::string& attribute)
{
    return GetValue(attribute);
}

