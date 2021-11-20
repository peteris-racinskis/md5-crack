#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>

using namespace std;
const string answer = "61a60170273e74a5be90355ffe8e86ad";

// Produce md5 hash of string
void hash_and_print(string str){
    unsigned char result[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)str.c_str(), str.size(), result);
    std::ostringstream sout;
    sout<<std::hex<<std::setfill('0');
    for(long long c: result)
    {
        sout<<std::setw(2)<<(long long)c;
    }
    if (answer.compare(sout.str()) == 0) {
        cout << "string: " << str << " hash: " << sout.str() << endl;
    }
}

// Iterate over every string of length {1, 2, ... , n}
void length_iter(int remaining, string so_far, string charset){
    if (remaining == 0){
        hash_and_print(so_far);
    } else {
        for (char c : charset){
            length_iter(remaining-1, so_far + c, charset);
        }
    }
}

// Iterate over a preallocated range of starting characters
void init_iter(int remaining, string start_chars, string charset){
    for (int i = 0; i < start_chars.length(); i++){
        length_iter(remaining-1, start_chars.substr(i,1), charset);
    }
}


int main() {
    string alphabet = "abc";
    int w
    int symbols_per_block = alphabet.length()/world_size;
    string charblocks [alphabet.length()/symbols_per_block];
    for (int i = charblocks.length()-1; i > 0; i--){
        charblocks[i] = alphabet.substr(alphabet.length()-symbols_per_block-1, symbols_per_block);
        alphabet = alphabet.substr(0, alphabet.length()-symbols_per_block);
    }
    init_iter(6, alphabet, alphabet);
    return 0;
}