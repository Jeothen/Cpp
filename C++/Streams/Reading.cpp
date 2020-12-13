#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(){
    // Output divided by space or tab
    std::ifstream ifs("test.txt");
    std::string s;
    while (ifs >> s){
        std::cout << s << std::endl;
    }

    std::cout << std::endl;
    std::cout <<"getline " << std::endl;
    // output divided by line

    std::ifstream ifs2("test_copy.txt");
    std::string ss;
    while (std::getline(ifs2,ss))
    {
        std::cout << ss << std::endl;
    }

    std::cout << std::endl;
    std::cout << "copy" << std::endl;
    std::ifstream ifs3("test_copy.txt");
    std::string s2 = "aa";
    s2.resize(100);
    // copy string
//  std::copy(std::istreambuf_iterator<char>(ifs3), std::istreambuf_iterator<char>(), s2.begin());  // initial and write
    std::copy(std::istreambuf_iterator<char>(ifs3), std::istreambuf_iterator<char>(), std::back_inserter(s2)); // write after last char 
    std::cout << s2 << std::endl;

    std::cout << std::endl;
    std::cout << "binary test" << std::endl;
    // binary file  write
    std::ofstream bin("test.bin",std::ios::binary);
    std::string bin_test = "text_test";
    bin.write(bin_test.c_str(),sizeof(bin_test));
    bin.close();
    
    // binary file read
    std::ifstream read_bin("test.bin",std::ios::binary);
    char output_str[22];
    read_bin.read(output_str,sizeof(output_str));
    std::cout << output_str << std::endl;
    read_bin.close();

    // copy stream
    std::ofstream ofs("test_out.txt");
    std::ifstream ifs4("test_copy.txt");
    std::copy(std::istreambuf_iterator<char>(ifs4), std::istreambuf_iterator<char>(), std::ostream_iterator<char>(ofs));
    ofs.close();
    
    // register on array
    std::cout << std::endl;
    std::cout <<"array test" << std::endl;
    char arr[100];
    std::ifstream ifs5("test.txt");
    std::copy(std::istreambuf_iterator<char>(ifs5), std::istreambuf_iterator<char>(), arr);
    for (int i=0; i<20; i++) std::cout << arr[i] <<":";
}