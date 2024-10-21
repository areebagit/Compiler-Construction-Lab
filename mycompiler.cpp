#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "No file provided. Please specify a file to read." << endl;
        return 1;
    }

    ifstream file(argv[1]); // Open the file passed as the second argument
    if (!file)
    {
        cout << "Could not open the file: " << argv[1] << endl;
        return 1;
    }

    string line;
    int argCount = 0;
    while (getline(file, line))
    {
        stringstream ss(line); // Create a stringstream from the line
        string word;

        while (ss >> word)
        {
            argCount++;
            for (int i = 0; i < word.length(); i++)
            {
                if (word[i] == '(' || word[i] == ')' || word[i] == '[' || word[i] == ']' || word[i] == '{' || word[i] == '}')
                {
                    argCount++;
                    cout << "Argument " << argCount << ": " << word[i] << endl;
                }
            }
            cout << "Argument " << argCount << ": " << word << endl;
        }
    }

    file.close();
    return 0;
}
