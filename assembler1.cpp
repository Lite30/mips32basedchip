#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

/*
    Here is a sample mips instruction: add $t0, $s1, $s2
    there is a blankspace between add and $t0
    and (;) as a delimeter between operands

*/

using namespace std;

int main()
{
    

    ifstream in_file("mipsinstruction.txt");//read from file
    
    if(!in_file.is_open())
    {
        cerr<< "Unable to file!"<< endl;
        return 1;
    }

    string readString;

    while(getline(in_file, readString)) //read from inputstream in_file and store into string readString
    {
        istringstream iss(readString); //treat string as an input stream

        string command, operand1, operand2, operand3;
        if(getline(iss, command,' ')&&getline(iss, operand1, ',')&&getline(iss, operand2, ',')&&getline(iss, operand3))
            {
                //do something

                std::cout << "Command: " << command << ", Operand1: " << operand1
                      << ", Operand2: " << operand2 << ", Operand3: " << operand3
                      << std::endl;
            }
            else{
                cerr<<"Error parsing line" << readString <<endl;
            }
    }

    in_file.close();

    return 0;
}