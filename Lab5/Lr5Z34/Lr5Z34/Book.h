#pragma once

#include <string>

class Book 
{
private:
    std::string title;
    std::string author;
    size_t year;
public:
    Book();
    Book(std::string _title, std::string _author, size_t _year);
    std::string getAuthor();
    std::string getTitle();
    size_t getYear();
};