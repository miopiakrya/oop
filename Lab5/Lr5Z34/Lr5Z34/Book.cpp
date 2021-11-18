#include "Book.h"

Book::Book(std::string _title, std::string _author, size_t _year) 
{
    title = _title;
    author = _author;
    year = _year;
}

Book::Book() {}

std::string Book::getAuthor()
{
    return author;
}

std::string Book::getTitle() 
{
    return title;
}

size_t Book::getYear() 
{
    return year;
}