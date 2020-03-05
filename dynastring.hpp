#include <stdlib.h>
using namespace std;

class Dynastring
{
private:
    int length;
    char *string;

public:
    const size_t size_type = sizeof(char);

    Dynastring();
    Dynastring(const char *, const size_t);
    Dynastring(const Dynastring &);
    Dynastring(Dynastring &&) noexcept;
    ~Dynastring();

    bool EqualsLexicographically(const Dynastring other) const
    {
        if (length != other.length)
        {
            return false;
        }
        else
        {
            for (size_t i = 0; i < length; i++)
            {
                if (tolower(string[i]) != tolower(other.string[i]))
                {
                    return false;
                }
            }
            return true;
        }
    }

    void Print()
    {
        for (size_t i = 0; i < length; i++)
        {
            cout << string[i];
        }
    }

    size_t Length()
    {
        return length;
    }

    const char Element(size_t index)
    {
        return string[index];
    }

    // Оператор приравнивания
    Dynastring operator=(const Dynastring &source)
    {
        if (this == &source)
        {
            return *this;
        }
        length = source.length;
        free(string);
        string = (char *)calloc(length, size_type);
        for (size_t i = 0; i < length; i++)
        {
            string[i] = source.string[i];
        };
        return *this;
    };

    // Оператор переноса значения
    Dynastring operator=(Dynastring &&source)
    {
        if (this == &source)
        {
            return *this;
        }
        free(string);
        length = source.length;
        string = source.string;
        source.length = 0;
        source.string = nullptr;
        return *this;
    };

    friend bool operator==(const Dynastring, const Dynastring);
    friend bool operator>(const Dynastring, const Dynastring);
    friend bool operator<(const Dynastring, const Dynastring);
    friend bool operator>=(const Dynastring, const Dynastring);
    friend bool operator<=(const Dynastring, const Dynastring);
    friend Dynastring operator+(Dynastring, Dynastring);
};

// Конструкторы

Dynastring::Dynastring()
{
    length = 0;
    string = (char *)calloc(1, size_type);
    string[0] = '\0';
}

// Конструктор копирования
Dynastring::Dynastring(const Dynastring &source)
{
    length = source.length;
    string = (char *)calloc(length + 1, size_type);
    for (size_t i = 0; i <= length; i++)
    {
        string[i] = source.string[i];
    }
}

// Конструктор перемещения
Dynastring::Dynastring(Dynastring &&source) noexcept
{
    length = source.length;
    string = source.string;
    source.length = 0;
    source.string = nullptr;
}

Dynastring::Dynastring(const char *inputArray, const size_t inputArraySize)
{
    length = inputArraySize;
    string = (char *)calloc(length + 1, size_type);
    for (size_t i = 0; i < length; i++)
    {
        string[i] = inputArray[i];
    }
    string[length] = '\0';
}

Dynastring::~Dynastring()
{
    free(string);
}

// Оператор сложения
Dynastring operator+(const Dynastring str1, const Dynastring str2)
{
    char string[str1.length + str2.length];
    for (size_t i = 0; i < str1.length; i++)
    {
        string[i] = str1.string[i];
    }
    for (size_t i = 0; i < str2.length; i++)
    {
        string[i + str1.length] = str2.string[i];
    }
    return Dynastring(string, str1.length + str2.length);
}

// Оператор сравнения
bool operator==(const Dynastring str1, const Dynastring str2)
{
    if (str1.length != str2.length)
    {
        return false;
    }
    else
        for (size_t i = 0; i < str1.length; i++)
        {
            if (str1.string[i] != str2.string[i])
            {
                return false;
            }
        }
    return true;
}

bool operator>(const Dynastring str1, const Dynastring str2)
{
    size_t maxLength;
    if (str1.length > str2.length)
    {
        maxLength = str1.length;
    }
    else
    {
        maxLength = str2.length;
    }
    for (size_t i = 0; i < maxLength; i++)
    {
        char lowercase1 = tolower(str1.string[i]);
        char lowercase2 = tolower(str2.string[i]);
        if (lowercase1 != lowercase2)
        {
            if (lowercase1 == '\0')
            {
                return false;
            }
            else if (lowercase2 == '\0')
            {
                return true;
            }
            else
            {
                return (lowercase1 > lowercase2);
            }
        }
    }
    return false;
}

bool operator>=(const Dynastring str1, const Dynastring str2)
{
    return (str1.EqualsLexicographically(str2) || str1 > str2);
}

bool operator<(const Dynastring str1, const Dynastring str2)
{
    return (str2 > str1);
}

bool operator<=(const Dynastring str1, const Dynastring str2)
{
    return str2 >= str1;
}