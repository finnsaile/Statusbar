#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <iostream>
#include <ostream>
#include <string>
#include <chrono>
#include <thread>
#include <iomanip>

class Statusbar {
private:
    //for calculating time
    std::chrono::duration<double> totalDuration;
    const std::chrono::time_point<std::chrono::high_resolution_clock> start;
    //for string output
    bool runBar;
    size_t progress;
    const bool progressBar;
    const size_t timerIntervalMill;
    std::ostream& outputstream;
    void outputProgress();
    //for running function in seperate thread
    std::unique_ptr<std::thread> threadPtr;
    void runTimer();

public:
    //set time interval in milliseconds and output stream
    Statusbar(const size_t& timerIntervalMill = 100, const bool& progressBar = true,std::ostream& output = std::cout);
    ~Statusbar();
    //user interaction
    void setProgress(const size_t& percent);
    void killBar();
};

#endif