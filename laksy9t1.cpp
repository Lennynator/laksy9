#include <iostream>
#include <new>
#include <cstdlib>

void testNewOperator() {
    const size_t blockSize = 1024;
    size_t totalMemory = 0;

    try {
        while (true) {
            int* ptr = new int[blockSize];
            totalMemory += blockSize * sizeof(int);
            std::cout << "Varattu muistia (new): " << totalMemory << " tavua\n";
        }
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Muistinvaraus (new) epäonnistui: " << e.what() << std::endl;
    }
}

void testMallocFunction() {
    const size_t blockSize = 1024;
    size_t totalMemory = 0;

    while (true) {
        int* ptr = static_cast<int*>(malloc(blockSize * sizeof(int)));

        if (ptr != nullptr) {
            totalMemory += blockSize * sizeof(int);
            std::cout << "Varattu muistia (malloc): " << totalMemory << " tavua\n";
        }
        else {
            std::cerr << "Muistinvaraus (malloc) epäonnistui.\n";
            break;
        }
    }
}

int main() {
    std::cout << "Testataan new-operaattoria:\n";
    testNewOperator();

    std::cout << "\nTestataan malloc-funktiota:\n";
    testMallocFunction();

    return 0;
}