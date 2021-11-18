#include <iostream>
#include <exception>
#include <fstream>
#include <any>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

struct CacheOutOfRangeException : public std::exception 
{
    const char* what() const throw () 
    {
        return "CacheOutOfRangeException";
    }
};

template <typename T>class Cache 
{
private:
    std::vector<T> values;
    size_t nums = 0;

public:
    void put(T elem) 
    {
        values.push_back(elem);
        nums++;
    }

    void operator+=(T elem) 
    {
        put(elem);
    }

    bool contains(T elem) 
    {
        for (int i = 0; i < nums; i++) 
        {
            if (values[i] == elem) return true;
        }
        return false;
    }
};

template <>class Cache<std::string> {
private:
    std::vector<std::string> values;
    size_t nums = 0;
    size_t max_values = 100;
public:
    void put(const std::string& elem)
    {
        if (nums >= max_values) throw CacheOutOfRangeException();
        values.push_back(elem);
        nums++;
    }

    void add(const std::string& elem)
    { 
        put(elem);
    }

    void operator+=(const std::string& elem) {
        put(elem);
    }

    bool contains(std::string elem) 
    {
        for (int i = 0; i < nums; i++) {
            if (values[i][0] == elem[0]) return true;
        }
        return false;
    }
};

int main() 
{
    Cache<std::string> voc;
    Cache<int> cache;
    
    cache.put(1);
    cache.put(2);
    cache.put(3);
    cache.put(4);
    cache += 5;

    voc.put("OK");

    std::cout << voc.contains("Only") << std::endl;
    std::cout << cache.contains(5) << std::endl;
}

