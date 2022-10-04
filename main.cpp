#include <iostream>
#include "statusbar.hpp"
#include <fstream>

int main() {
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    Statusbar bar(10);
    for(int i = 0; i < 101; i++) {
        start = std::chrono::high_resolution_clock::now();
        while((std::chrono::high_resolution_clock::now() - start).count() / 1e9 < 0.1);
        bar.setProgress(i);
    }
    bar.killBar();
}