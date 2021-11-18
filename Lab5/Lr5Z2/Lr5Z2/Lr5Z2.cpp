#pragma warning(disable : 4996)

#include <map>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    const char* dividers = ".,:!;?- ";
    const size_t MAXLEN = 1000, MINLETTERS = 3, MINOCCURANCES = 7;

    string fileText = "text.txt";
    map<std::string, int> map;
    ifstream file(fileText);

    if (file.is_open())
    {
        while (file.peek() != EOF)
        {
            char text[MAXLEN];
            file.getline(text, MAXLEN);
            char* substr = strtok(text, dividers);
            while (substr != nullptr)
            {
                string word = substr;
                transform(word.begin(), word.end(), word.begin(), tolower);

                auto mapIterator = map.find(word);

                if (mapIterator == map.end()) map.insert(make_pair(word, 1));
                else map[word]++;
                substr = strtok(nullptr, dividers);
            }
        }
    }

    file.close();
    auto mapIterator = map.begin();
    multimap<int, string, greater<>> sorted_map;

    for (int i = 0; mapIterator != map.end(); mapIterator++, i++)
        if (mapIterator->first.length() > MINLETTERS && mapIterator->second >= MINOCCURANCES)
            sorted_map.insert(make_pair(mapIterator->second, mapIterator->first));

    for (auto const& entry : sorted_map)
    {
        cout << entry.second << " " << entry.first << std::endl;
    }
}