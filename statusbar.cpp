#include <statusbar.hpp>

#define BLACK "\u001b[30m"
#define RED "\u001b[31m"
#define GREEN "\u001b[32m"
#define YELLOW "\u001b[33m"
#define BLUE "\u001b[34m"
#define MAGENTA "\u001b[35m"
#define CYAN "\u001b[36m"
#define WHITE "\u001b[37m"
#define RESET "\u001b[0m"

using std::ostream, std::string, std::cout, std::endl;
using std::chrono::duration, std::chrono::time_point, std::chrono::high_resolution_clock;
using std::chrono::seconds, std::chrono::milliseconds, std::chrono::duration_cast;
using std::thread, std::this_thread::sleep_for;
using std::unique_ptr;

Statusbar::Statusbar(const size_t& timerIntervalMill, const bool& progressBar, ostream& outputstream) : 
outputstream{outputstream},
progressBar{progressBar},
progress{0},
timerIntervalMill{timerIntervalMill >= 50 ? timerIntervalMill : 50},
runBar{true},
start{high_resolution_clock::now()} {
    outputProgress();
    //start thread with runTimer function
    threadPtr = unique_ptr<thread>(new thread(&Statusbar::runTimer, this));
}

Statusbar::~Statusbar() {
    //wait for timer to finish before terminating
    killBar();
    threadPtr->join();
}

void Statusbar::setProgress(const size_t& progress) {
    this->progress = progress;
}

void Statusbar::killBar() {
    runBar = false;
}

//function used by seperate thread to time output
void Statusbar::runTimer() {
    while(this->progress < 100 && runBar) {
        std::this_thread::sleep_for(milliseconds(timerIntervalMill));
        outputProgress();
    }
    outputProgress();
    outputstream << endl;
}

void Statusbar::outputProgress() {
    totalDuration = high_resolution_clock::now() - start;
    //create outputstring
    outputstream << std::fixed << std::setprecision(4);
    outputstream    << "\r" << GREEN << "Time Elapsed: " << BLUE << totalDuration.count() 
                    << GREEN << " Seconds";
    if(progressBar) outputstream << ", Progress: " << (progress < 100 ? RED : GREEN) << progress << "%";           
    outputstream << RESET << "\t";
    if(!runBar && progress < 100)
        outputstream << RED << "\nStatus Bar has been terminated!!!" << RESET;
    outputstream.flush();
}