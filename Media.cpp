#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

// Implementation of Media Functions


// Get the title of the media
char* Media::getTitle() {
    return title;
}

// Get the year of creation for the media
int Media::getYear() {
    return year;
}
// Set the year of creation for the media
void Media::Year(int newYear) {
    year = newYear;
}


// Print basic information about the media
void Media::print() {
    cout << "Year: " << year << endl;
    cout << "Title: " << title << endl;
}

// Destructor for cleanup
Media::~Media() {
    delete[] title;  // Release memory allocated for the title
}

// Set the title of the media
void Media::Title(char* newTitle) {
    // Allocate memory for the title and copy the name
    title = new char[100];
    strcpy(title, newTitle);
}

