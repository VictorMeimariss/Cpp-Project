#include<iostream>
#include<mkl.h>

int main()
{
    MKLVersion version;
    mkl_get_version(&version);

    std::cout << "MKL Version: " 
              << version.MajorVersion << "."
              << version.MinorVersion << "."
              << version.UpdateVersion << std::endl;

              
    return 0;
}