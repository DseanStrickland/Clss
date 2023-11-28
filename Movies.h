
#ifndef MOVIESHEADER
#define MOVIESHEADER

#include <iostream>
#include "Media.h"

// Header for Movie class
class Movies : public Media {
public:
    virtual void addRating(float);      // Set the rating of the movie
    virtual void print();               // Print details of the movie
    ~Movies();                          // Destructor for cleanup
    virtual void addDirector(char*);  // Set the director of the movie
    virtual void addDuration(int);     // Set the duration of the movie

private:
    char* director;  // Director of the movie
    int duration;    // Duration of the movie in minutes
    float rating;    // Rating of the movie
};

#endif












