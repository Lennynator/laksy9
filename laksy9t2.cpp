#include <iostream>
#include <fstream>
#include <string>

std::string readFile(const std::string& fileName) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        throw std::runtime_error("Tiedoston avaaminen epäonnistui.");
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    return content;
}

int main() {
    std::string fileName;

    while (true) {
        std::cout << "Anna tiedoston nimi: ";
        std::cin >> fileName;

        try {
            std::string content = readFile(fileName);

            std::cout << "Tiedoston sisältö:\n" << content << std::endl;

            break;  
        }
        catch (const std::exception& e) {
            std::cerr << "Virhe: " << e.what() << std::endl;
            std::cin.clear();   
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
        }
    }

    return 0;
}
