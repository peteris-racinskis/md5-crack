#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>

using namespace std;

void hash_and_print(string str){
    unsigned char result[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)str.c_str(), str.size(), result);
    std::ostringstream sout;
    sout<<std::hex<<std::setfill('0');
    for(long long c: result)
    {
        sout<<std::setw(2)<<(long long)c;
    }
    cout << sout.str() << endl;
}


int main() {
    hash_and_print("aabbcc");
    return 0;
}