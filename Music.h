#ifndef MUSICHEADER
#define MUSICHEADER

#include <iostream>
#include "Media.h"

using namespace std;

// Header for Music class
class Music : public Media {
public:
    virtual void print();                // Print details of the music
    ~Music();// Destructor for cleanup
   virtual void addArtistName(char*);  // Set the artist name for the music
    virtual void addDuration(int);       // Set the duration of the music


private:
    char* artistName;  // Artist name of the music
    int duration;      // Duration of the music in minutes
};

#endif
