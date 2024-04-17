#include "CMyString.h"

CMyString::CMyString() : m_pData(nullptr), m_Length(0) {}

CMyString::CMyString(const char* pString) : m_pData(nullptr), m_Length(0) 
{
    if (pString)
    {
        size_t length = strlen(pString);
        CopyFrom(pString, length);
    }
}

CMyString::CMyString(const char* pString, size_t length) : m_pData(nullptr), m_Length(0)
{
    if (pString) 
    {
        CopyFrom(pString, length);
    }
}

CMyString::CMyString(const CMyString& other) : m_pData(nullptr), m_Length(0) 
{
    CopyFrom(other.m_pData, other.m_Length);
}

CMyString::CMyString(CMyString&& other) : m_pData(nullptr), m_Length(0) 
{
    m_pData = other.m_pData;
    m_Length = other.m_Length;
    other.m_pData = nullptr;
    other.m_Length = 0;
}

CMyString::CMyString(std::string const& stlString) : m_pData(nullptr), m_Length(0)
{
    CopyFrom(stlString.c_str(), stlString.length());
}

// Destructor
CMyString::~CMyString() 
{
    delete[] m_pData;
}

// Copy assignment operator
CMyString& CMyString::operator=(const CMyString& other)
{
    if (this != &other) {
        delete[] m_pData;
        CopyFrom(other.m_pData, other.m_Length);
    }
    return *this;
}

// Concatenation operators
CMyString& CMyString::operator+=(const CMyString& other) 
{
    size_t newLength = m_Length + other.m_Length;
    char* newData = new char[newLength + 1];
    if (m_pData) 
    {
        memcpy(newData, m_pData, m_Length);
        delete[] m_pData;
    }
    memcpy(newData + m_Length, other.m_pData, other.m_Length);
    newData[newLength] = '\0'; // Устанавливаем завершающий нулевой символ
    m_pData = newData;
    m_Length = newLength;
    return *this;
}

CMyString operator+(const CMyString& lhs, const CMyString& rhs) 
{
    CMyString result(lhs);
    result += rhs;
    return result;
}

// Comparison operators
bool CMyString::operator==(const CMyString& other) const 
{
    return strcmp(m_pData, other.m_pData) == 0;
}

bool CMyString::operator!=(const CMyString& other) const 
{
    return !(*this == other);
}

bool CMyString::operator<(const CMyString& other) const
{
    return strcmp(m_pData, other.m_pData) < 0;
}

bool CMyString::operator>(const CMyString& other) const 
{
    return other < *this;
}

bool CMyString::operator<=(const CMyString& other) const
{
    return !(*this > other);
}

bool CMyString::operator>=(const CMyString& other) const
{
    return !(*this < other);
}

// Subscript operators
char& CMyString::operator[](size_t index)
{
    assert(index < m_Length);
    return m_pData[index];
}

const char& CMyString::operator[](size_t index) const
{
    assert(index < m_Length);
    return m_pData[index];
}

// Other methods
size_t CMyString::GetLength() const
{
    return m_Length;
}

const char* CMyString::GetStringData() const 
{
    return m_pData;
}

CMyString CMyString::SubString(size_t start, size_t length) const 
{
    if (start >= m_Length) return CMyString();
    if (length == SIZE_MAX || start + length > m_Length) length = m_Length - start;
    return CMyString(m_pData + start, length);
}

void CMyString::Clear()
{
    delete[] m_pData;
    m_pData = nullptr;
    m_Length = 0;
}

// Iterator methods
CMyString::iterator CMyString::begin() 
{
    return m_pData;
}

CMyString::iterator CMyString::end()
{
    return m_pData + m_Length;
}

CMyString::const_iterator CMyString::begin() const
{
    return m_pData;
}

CMyString::const_iterator CMyString::end() const 
{
    return m_pData + m_Length;
}

CMyString::const_iterator CMyString::cbegin() const 
{
    return m_pData;
}

CMyString::const_iterator CMyString::cend() const
{
    return m_pData + m_Length;
}

CMyString::reverse_iterator CMyString::rbegin() 
{
    return reverse_iterator(end());
}

CMyString::reverse_iterator CMyString::rend()
{
    return reverse_iterator(begin());
}

CMyString::const_reverse_iterator CMyString::rbegin() const
{
    return const_reverse_iterator(end());
}

CMyString::const_reverse_iterator CMyString::rend() const 
{
    return const_reverse_iterator(begin());
}

CMyString::const_reverse_iterator CMyString::crbegin() const 
{
    return const_reverse_iterator(cend());
}

CMyString::const_reverse_iterator CMyString::crend() const 
{
    return const_reverse_iterator(cbegin());
}

void CMyString::CopyFrom(const char* pString, size_t length) 
{
    m_Length = length;
    m_pData = new char[m_Length + 1];
    memcpy(m_pData, pString, m_Length);
    m_pData[m_Length] = '\0';
}

std::ostream& operator<<(std::ostream& os, const CMyString& str) 
{
    os << str.GetStringData();
    return os;
}

std::istream& operator>>(std::istream& is, CMyString& str)
{
    char buffer[4096];
    is >> buffer;
    str = CMyString(buffer);
    return is;
}
