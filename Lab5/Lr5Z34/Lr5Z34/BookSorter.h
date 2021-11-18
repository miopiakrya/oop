#include "Book.h"
#define AUTHOR (0)
#define TITLE (1)

class BookSorter 
{
private:
    size_t sortBy;
public:
    BookSorter();
    BookSorter(size_t sortBy);

    bool operator()(Book* b1, Book* b2) const;
};

