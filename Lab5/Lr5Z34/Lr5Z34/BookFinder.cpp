#include "BookFinder.h"

BookFinder::BookFinder(size_t _startYear, size_t _endYear) 
{
    startYear = _startYear;
    endYear = _endYear;
}

bool BookFinder::operator()(Book* b) const 
{
    return b->getYear() >= startYear && b->getYear() <= endYear;
}
