#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
    std::fstream myFile;
    std::string line;
    float points = 0.5;
    int sum = 0;
    int copies[208] = {0};
    int cards = 0;
    int i = 0;
    int j = 0;

    myFile.open("z4.txt", std::ios::in);
    if (myFile.is_open())
    {
        std::size_t colon, vBar, pos, check;
        std::string winningNumber = "";

        while (getline(myFile, line))
        {
            copies[i] += 1;
            i++;

            colon = line.find(':');
            vBar = line.find('|');
            pos = colon + 2;
            while (line[pos] != line[vBar])
            {
                if (isdigit(line[pos]))
                {
                    winningNumber.push_back(line[pos]);
                }
                else if (winningNumber != "")
                {
                    check = line.find(winningNumber, vBar);
                    while(check != std::string::npos)
                    {
                        if (!isdigit(line[check+winningNumber.size()]) && !isdigit(line[check-1]))
                        {
                            points *= 2;
                            copies[i+j] += 1 * copies[i-1]; 
                            j++;
                        }
                        check++;
                        check = line.find(winningNumber, check);
                    }
                    winningNumber.clear();
                }
                pos++;
            }
            sum += int(points);
            points = 0.5;
            j = 0;
        }
        for(int k = 0; k < 208; k++)
        {
            cards += copies[k];
        }
        std::cout << "Total points: " << sum << std::endl;
        std::cout << "Total scratchcards: " << cards << std::endl;
        myFile.close();
    }
    
    return 0;
}