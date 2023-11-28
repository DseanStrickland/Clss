#include <iostream>
#include <cstring>
#include <iomanip>
#include "VideoGames.h"

using namespace std;

// Implementation of VideoGames Functions

// Set the publisher name for the video game
void VideoGames::addPublisherName(char* newPublisherName) {
    // Allocate memory for the publisher name and copy the name
    publisherName = new char[100];
    strcpy(publisherName, newPublisherName);
}

// Set the rating for the video game
void VideoGames::addRating(float newRating) {
    rating = newRating;
}
// Print details of the video game
void VideoGames::print() {
    cout << "Game Title: " << title << endl;
    cout << "Creation Year: " << year << endl;
    cout << "Publisher Name: " << publisherName << endl;
    cout << "Game Rating: " << fixed << setprecision(2) << rating << endl;
}

// Destructor for cleanup
VideoGames::~VideoGames() {
    delete[] publisherName;  // Release memory allocated for the publisher name
}
