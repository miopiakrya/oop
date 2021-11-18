#include <exception>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <iostream>

struct EmptyManagerException : public std::exception 
{
    const char* what() const throw () 
    {
        return "EmptyManagerException";
    }
};

template <typename T>class DataManager
{
private:
    static const int maxElements = 64;
    const std::string dumpFile = "dump.dat";
    T values[maxElements];
    int nums = 0;
public:
    void iterate(std::ostream_iterator<T> iter) 
    {
        for (int i = 0; i < nums; i++) 
        {
            iter = values[i];
        }
    }
    void push(T elem) 
    {
        if (nums == maxElements) 
        {
            std::ofstream data(dumpFile);
            data << (*this);
            data.close();
            nums = 0;
        }
        T temp;
        
        values[nums] = elem;
        nums++;
    }

    friend std::ostream& operator<<(std::ostream& out, const DataManager<T> t) 
    {
        for (int i = 0; i < t.nums; ++i)
        {
            out << t.values[i] << std::endl;
        }
        return out;
    }

    void push(T elem[], int n) 
    {
        for (int i = 0; i < n; i++) 
        {
            push(elem[i]);
        }
    }

    T peek() 
    {
        if (nums % 2 == 0) return 0;
        else return values[nums / 2];
    }

    T pop() 
    {
        if (nums == 0) throw EmptyManagerException();
        T output = values[0];

        if (nums == 1) 
        {
            for (int i = 0; i < maxElements; i++) 
            {
                std::ifstream data(dumpFile);
                std::string temp;

                while (std::getline(data, temp) && nums < maxElements) 
                {
                    std::istringstream ss(temp);
                    ss >> values[nums - 1];
                    nums++;
                }

                data.close();
                return output;
            }
        }

        for (int i = 0; i < nums; i++) 
        {
            values[i] = values[i + 1];
        }

        nums--;
        return output;
    }
};

template <>class DataManager<char>
{
private:
    static const int maxElements = 64;
    char values[maxElements];
    int nums = 0;
    const std::string dumpFile = "dump.dat";

public:
    void iterate(std::ostream_iterator<char> iter) 
    {
        for (int i = 0; i < nums; i++) 
        {
            iter = values[i];
        }
    }

    void push(char elem) 
    {
        if (nums == maxElements) 
        {
            std::ofstream data("dump.dat");
            data << (*this);
            data.close();
            nums = 0;
        }

        char temp;

        values[nums] = elem;
        nums++;
    }

    friend std::ostream& operator<<(std::ostream& out, const DataManager<char> t) 
    {
        for (int i = 0; i < t.nums; ++i) 
        {
            out << t.values[i] << std::endl;
        }
        return out;
    }

    void push(char elem[], int n) 
    {
        for (int i = 0; i < n; i++) 
        {
            push(elem[i]);
        }
    }

    char peek() 
    {
        if (nums >= 2) return values[2];
        else return 0;
    }

    char pop() 
    {
        if (nums == 0) throw EmptyManagerException();
        char output = values[0];
        if (nums == 1) {
            for (int i = 0; i < maxElements; i++) 
            {
                std::ifstream data(dumpFile);
                std::string temp;
                while (std::getline(data, temp) && nums < maxElements) 
                {
                    std::istringstream ss(temp);
                    ss >> values[nums - 1];
                    nums++;
                }
                data.close();
                return output;
            }
        }

        for (int i = 0; i < nums; i++) 
        {
            values[i] = values[i + 1];
        }
        nums--;

        return output;
    }

    char popUpper() 
    {
        if (nums == 0) throw EmptyManagerException();
        char output = toupper(values[0]);
        if (nums == 1) {
            for (int i = 0; i < maxElements; i++) 
            {
                std::ifstream data(dumpFile);
                std::string temp;
                while (std::getline(data, temp) && nums < maxElements)
                {
                    std::istringstream ss(temp);
                    ss >> values[nums - 1];
                    nums++;
                }
                data.close();
                return output;
            }
        }

        for (int i = 0; i < nums; i++) 
        {
            values[i] = values[i + 1];
        }
        nums--;

        return output;
    }

    char popLower() 
    {
        if (nums == 0) throw EmptyManagerException();
        char output = tolower(values[0]);

        if (nums == 1) 
        {
            for (int i = 0; i < maxElements; i++) 
            {
                std::ifstream data(dumpFile);
                std::string temp;
                while (std::getline(data, temp) && nums < maxElements) 
                {
                    std::istringstream ss(temp);
                    ss >> values[nums - 1];
                    nums++;
                }
                data.close();
                return output;
            }
        }

        for (int i = 0; i < nums; i++) 
        {
            values[i] = values[i + 1];
        }
        nums--;

        return output;
    }
};

int main()
{
    DataManager<int> dmInt = DataManager<int>();
    dmInt.push(1);
    dmInt.push(2);
    dmInt.push(3);
    dmInt.push(4);
    dmInt.pop();

    std::ostream_iterator<int> out_int(std::cout, "\n");
    dmInt.iterate(out_int);

    DataManager<double> dmDouble = DataManager<double>();
    double doubleArr[] = { 1.33, 66.66, 0.33 };

    dmDouble.push(doubleArr, 3);

    std::ostream_iterator<double> out_double(std::cout, "\n");
    dmDouble.iterate(out_double);

    DataManager<char> dmChar = DataManager<char>();
    char charArr[] = { 'h', 'i' };

    dmChar.push(charArr, 2);

    std::ostream_iterator<char> out_char(std::cout, "");
    dmChar.iterate(out_char);

    char ch = dmChar.popUpper();
    std::cout << "\n" << ch << std::endl;
}
