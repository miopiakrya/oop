#include <string>
#include "Book.h"

class BookFinder 
{
private:
    size_t startYear;
    size_t endYear;
public:
    BookFinder(size_t _startYear, size_t _endYear);
    bool operator()(Book* b) const;
};

