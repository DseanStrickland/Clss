#include <iostream>
#include <cstring>
#include <iomanip>
#include "Movies.h"

using namespace std;

// Implementation of Movie Functions

// Print details of the movie
void Movies::print() {
    cout << "Movie Title: " << title << endl;
    cout << "Creation Year: " << year << endl;
    cout << "Director: " << director << endl;
    cout << "Duration: " << duration << " minutes" << endl;
    cout << "Rating: " << fixed << setprecision(2) << rating << endl;
}


// Set the rating of the movie
void Movies::addRating(float newRating) {
    rating = newRating;
}

// Destructor for cleanup
Movies::~Movies() {
    delete[] director;  // Release memory allocated for the director
}
// Set the director of the movie
void Movies::addDirector(char* newDirector) {
    // Allocate memory for the director and copy the name
    director = new char[100];
    strcpy(director, newDirector);
}

// Set the duration of the movie
void Movies::addDuration(int newDuration) {
    duration = newDuration;
}


