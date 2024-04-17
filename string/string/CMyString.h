#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>
#include <cassert>
#include <cstring>
class CMyString 
{
public:
    CMyString();
    CMyString(const char* pString);
    CMyString(const char* pString, size_t length);
    CMyString(const CMyString& other);
    CMyString(CMyString&& other);
    CMyString(std::string const& stlString);
    ~CMyString();

    CMyString& operator=(const CMyString& other);
    CMyString& operator+=(const CMyString& other);
    friend CMyString operator+(const CMyString& lhs, const CMyString& rhs);
    bool operator==(const CMyString& other) const;
    bool operator!=(const CMyString& other) const;
    bool operator<(const CMyString& other) const;
    bool operator>(const CMyString& other) const;
    bool operator<=(const CMyString& other) const;
    bool operator>=(const CMyString& other) const;
    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    size_t GetLength() const;
    const char* GetStringData() const;
    CMyString SubString(size_t start, size_t length = SIZE_MAX) const;
    void Clear();

    using iterator = char*;
    using const_iterator = const char*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;

    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;

private:
    char* m_pData;
    size_t m_Length;

    void CopyFrom(const char* pString, size_t length);
};

std::ostream& operator<<(std::ostream& os, const CMyString& str);
std::istream& operator>>(std::istream& is, CMyString& str);

#endif
