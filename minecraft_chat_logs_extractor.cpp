#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <zlib.h>

using namespace std;
namespace fs = std::filesystem;

int main() {
    string main_path = "C:\\Users\\User\\AppData\\Roaming\\.minecraft\\logs"; // minecraft logs path
    string path_file;
    ifstream main_file(main_path);
    ofstream gz_names("gz_names.txt");
    if (gz_names.is_open()) {
        for (const auto& entry : fs::directory_iterator(main_path)) {
            if (fs::is_regular_file(entry.path())) {
                if (entry.path().filename() != "latest.log") {
                    string log_name = entry.path().filename().string();
                    string type = ".txt";
                    string slash = "\\";
                    string file_name = log_name;
                    string file_name_long = entry.path().string();
                    log_name.erase(log_name.end() - 7, log_name.end());
                    log_name += type;
                    string log_path = entry.path().string() + slash + log_name;
                    gz_names << log_path << endl;
                }
            }
        }
        gz_names.close();
        cout << "Ended";
    }
    else {
        std::cerr << "Error: Unable to create or open the file.\n";
    }

    return 0;
}
