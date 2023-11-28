#ifndef VIDEOGAMEHEADER
#define VIDEOGAMEHEADER

#include <iostream>
#include "Media.h"

using namespace std;

// Header for VideoGames class
class VideoGames : public Media {
public:

    // Destructor for cleanup
    virtual ~VideoGames();
    // Set the publisher name for the video game
    virtual void addPublisherName(char*);

    // Set the rating for the video game
    virtual void addRating(float);

    // Print details of the video game
    virtual void print();


private:
     // Rating of the video game
    float rating;

    // Publisher name of the video game
    char* publisherName;

   
};

#endif
