#include <iostream>
#include "Control.h" //This header file is to separate IO methods from data structure class

using namespace std;

int main()
{
    string filelist = "met_index.txt";
    Control programControl;
    programControl.Run(filelist);

    return 0;
}

