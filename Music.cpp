#include <iostream>
#include <cstring>
#include "Music.h"

using namespace std;

// Implementation of Music Functions

// Print details of the music
void Music::print() {
    cout << "Title: " << title << endl;
cout << "Creation year: " << year << endl;
cout << "Artist Name: " << artistName << endl;
     cout << "Length: " << duration << endl;}
// Destructor for cleanup
Music::~Music() {
delete[] artistName;  // Release memory allocated for the artist name
}
// Set the artist name for the music
void Music::addArtistName(char* newArtistName) {
    // Allocate memory for the artist name and copy the name
    artistName = new char[100];
    strcpy(artistName, newArtistName);
}

// Set the duration of the music
void Music::addDuration(int newDuration) {
    duration = newDuration;
}





