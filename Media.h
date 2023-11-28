#ifndef MEDIAHEADER
#define MEDIAHEADER

#include <iostream>
#include <cstring>

using namespace std;

// Header for Media class
class Media {
public:
      // Get the year of creation for the media
    virtual int getYear();

    // Print basic information about the media
    virtual void print();

    // Destructor for cleanup
    virtual ~Media();

    // Set the title of the media
    virtual void Title(char*);

    // Set the year of creation for the media
    virtual void Year(int);

    // Get the title of the media
    virtual char* getTitle();
protected:
    // Title of the media
    char* title;

    // Year of creation for the media
    int year;
};

#endif
