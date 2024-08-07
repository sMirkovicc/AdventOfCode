#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
    std::fstream myFile;
    std::string line;
    int sum = 0;
    char letter;
    std::string number;

    myFile.open("z1.txt", std::ios::in);
    if(myFile.is_open())
    {
        std::size_t firstDigit, secondDigit;
        int calVal = 0;

        while(getline(myFile, line))
        {
            for(int i = 0; i < line.size(); i++)
            {
                letter = line[i];
                switch(letter)
                {
                    case 'o':
                        if(line[i+1] == 'n' & line[i+2] == 'e')
                        {
                            number = "on";
                            line.replace(line.find(number), number.size(), "1");
                        }
                        break;
                    case 't':
                        if(line[i+1] == 'w' & line[i+2] == 'o')
                        {
                            number = "tw";
                            line.replace(line.find(number), number.size(), "2");
                        }
                        else if(line[i+1] == 'h' & line[i+2] == 'r' & line[i+3] == 'e' & line[i+4] == 'e')
                        {
                            number = "thre";
                            line.replace(line.find(number), number.size(), "3");
                        }
                        break;
                    case 'f':
                        if(line[i+1] == 'o' & line[i+2] == 'u' & line[i+3] == 'r')
                        {
                            number = "four";
                            line.replace(line.find(number), number.size(), "4");
                        }
                        else if(line[i+1] == 'i' & line[i+2] == 'v' & line[i+3] == 'e')
                        {
                            number = "fiv";
                            line.replace(line.find(number), number.size(), "5");
                        }
                        break;
                    case 's':
                        if(line[i+1] == 'i' & line[i+2] == 'x')
                        {
                            number = "six";
                            line.replace(line.find(number), number.size(), "6");
                        }
                        else if(line[i+1] == 'e' & line[i+2] == 'v' & line[i+3] == 'e' & line[i+4] == 'n')
                        {
                            number = "seve";
                            line.replace(line.find(number), number.size(), "7");
                        }
                        break;
                    case 'e':
                        if(line[i+1] == 'i' & line[i+2] == 'g' & line[i+3] == 'h' & line[i+4] == 't')
                        {
                            number = "eigh";
                            line.replace(line.find(number), number.size(), "8");
                        }
                        break;
                    case 'n':
                        if(line[i+1] == 'i' & line[i+2] == 'n' & line[i+3] == 'e')
                        {
                            number = "nin";
                            line.replace(line.find(number), number.size(), "9");
                        }
                        break;
                }
            }
            firstDigit = line.find_first_of("0123456789");
            secondDigit = line.find_last_of("0123456789");
            calVal = (line[firstDigit] - '0')*10 + (line[secondDigit] - '0');
            sum += calVal;
        }
        myFile.close();

        std::cout << "Sum of calibration values: " << sum << std::endl;
    }

    return 0;
}