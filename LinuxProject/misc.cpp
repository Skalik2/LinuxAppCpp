#include "misc.h"

// QString getConsoleOutput(char* input){
//     std::array<char, 128> buffer;
//     QString result;
//     std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(input, "r"), pclose);
//     if (!pipe) {
//         throw std::runtime_error("popen() failed!");
//     }
//     while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr) {
//         result += buffer.data();
//     }
//     return QString(result);
// }
