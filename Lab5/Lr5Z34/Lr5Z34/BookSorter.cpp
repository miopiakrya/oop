#include "BookSorter.h"

BookSorter::BookSorter() 
{
    sortBy = TITLE;
}

BookSorter::BookSorter(size_t _sortBy) 
{
    sortBy = _sortBy;
}

bool BookSorter::operator()(Book* b1, Book* b2) const
{
    if (sortBy == AUTHOR) return b1->getAuthor() < b2->getAuthor();
    return b1->getTitle() < b2->getTitle();
}
