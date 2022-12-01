#pragma once
#include <iostream>
#include <string>

/**
* @brief A progress bar to show whatever progress you want
*/
class ProgressBar {
private:
    int length_; // the length of the printed bar (not including ends)
    double progress_; // the proportion of progress made
public:
    /**
    * @brief Constructs the ProgressBar class starting at 0 progress
    *
    * @param length The bar's length
    */
    ProgressBar(int length = 70) : length_(70), progress_(0) {}
    /**
    * @brief Updates the progress level
    *
    * @param progress The new progress level
    */
    void updateProgress(double progress)  { progress_ = progress; }
    /**
    * @brief Gets a string representing the progress bar
    *
    * @return string The string
    */
    std::string toString() const;
};

/**
* @brief Overloads the << operator to output a progress bar
* Will overwrite the previous line
*
* @param out The output stream
* @param pb The progress bar
* @return ostream The output stream
*/
std::ostream & operator<<(std::ostream & out, const ProgressBar & pb);
