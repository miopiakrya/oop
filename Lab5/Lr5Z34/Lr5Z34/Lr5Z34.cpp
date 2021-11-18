#include "Book.h"
#include <clocale>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include "BookSorter.h"
#include "BookFinder.h"

int main() 
{
    setlocale(LC_ALL, "Russian");

    std::vector<Book*> books;

    books.push_back(new Book("����� � ���", "������� �.�.", 2010));
    books.push_back(new Book("���������", "����������� �.�.", 2004));
    books.push_back(new Book("�����", "�������� �.�.", 2010));
    books.push_back(new Book("���� ��������", "������� �.�.", 1999));
    books.push_back(new Book("������������ �������", "�������� �.�.", 2011));
    books.push_back(new Book("���������� �������", "������� �.", 2009));
    books.push_back(new Book("������ �����", "������� �.", 2001));
    books.push_back(new Book("�����", "ø�� �.�.", 2010));
    books.push_back(new Book("����� ������", "������� �.", 1998));

    std::cout << "\n����� � ���������� �������:\n\n";
    BookSorter book_sorter;

    std::sort(books.begin(), books.end(), book_sorter);
    std::vector<Book*>::iterator i;

    for (i = books.begin(); i != books.end(); ++i)
    {
        std::cout << (*i)->getAuthor() << " \""
            << (*i)->getTitle() << "\"" << std::endl;
    }

    BookFinder book_finder(2005, 2014);
    auto finder = std::find_if(books.begin(), books.end(), book_finder);
    std::cout << "\n����� � ��������� ���� ������� 2005 - 2014:\n\n";

    while (finder != books.end())
    {
        std::cout << (*finder)->getAuthor() << " \""
            << (*finder)->getTitle() << "\"" << std::endl;
        finder = std::find_if(++finder, books.end(), book_finder);
    }

    std::vector<int> years;
    for (auto& i : books) {
        years.push_back(i->getYear());
    }

    std::cout << "\n����� ����� 2009 ����: " << std::count_if(years.begin(), years.end(), std::bind2nd(std::greater<int>(), 2009)) << std::endl;

    for (i = books.begin(); i != books.end(); ++i)
    {
        delete (*i);
    }
}