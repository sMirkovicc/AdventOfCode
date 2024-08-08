#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
    std::fstream myFile;
    std::string line;
    int max = 0;
    int min = 0;
    int gameId = 0;
    int sum = 0;
    int power = 1;
    int sumOfPower = 0;
    bool isPossible = true;

    myFile.open("z2.txt", std::ios::in);
    if (myFile.is_open())
    {
        std::string tempStr, color;
        std::size_t firstDigit;
        std::size_t found, tempFound;
        std::string Cubes;

        while (getline(myFile, line)) 
        { 
            for(int i = 0; i < 3; i++)
            {
                switch (i)
                {
                    case 0:
                        color = "red";
                        max = 12;
                        break;
                    case 1:
                        color = "green";
                        max = 13;
                        break;
                    case 2:
                        color = "blue";
                        max = 14;
                        break;
                }
                found = line.find(color);
                while (found != std::string::npos)
                {
                    tempFound = found;
                    while (isdigit(line[tempFound-2]))
                    {
                        tempStr = line[tempFound-2];
                        Cubes.insert(0, tempStr);
                        tempStr.clear();
                        tempFound--;
                    }
                    if (atoi(Cubes.c_str()) > max)
                    {
                        isPossible = false;
                    }

                    if (atoi(Cubes.c_str()) > min)
                    {
                        min = atoi(Cubes.c_str());
                    }

                    Cubes.clear();
                    found = line.find(color, found+1);
                }
                power *= min;
                min = 0;
            }

            if (isPossible)
            {
                firstDigit = line.find_first_of("0123456789");
                while (isdigit(line[firstDigit]))
                {
                    tempStr.push_back(line[firstDigit]);
                    firstDigit++;
                }
                gameId = atoi(tempStr.c_str());
                sum += gameId;
                tempStr.clear();
            }
            isPossible = true;

            sumOfPower += power;
            power = 1;
        }
        std::cout << "Sum of IDs: " << sum << std::endl;
        std::cout << "Sum of the power: " << sumOfPower << std::endl;
        myFile.close();
    }
    
    return 0;
}