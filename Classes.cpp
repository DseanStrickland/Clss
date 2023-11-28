/*

Arjun Pai
Credits: Jazveer Kaler, Ramachandra Pai (Dad), Taaha Khan, Ashank Shah
Most Help goes to Jazveer Kaler he helped me a lot with the header files and helped a lot with logic. 
Project Description: Digital Media Database

 */
#include <iostream>
#include <typeinfo>
#include <vector>
#include "Media.h"
#include <limits>
#include "Videogames.h"
#include "Music.h"
#include "Movies.h"
#include <cstring>

using namespace std;

// Function prototypes
void searchMedia(vector<Media*> &);
void addMedia(vector<Media*> &);
void deleteMedia(vector<Media*> &);

int main() {
  int option;
  vector<Media*> v;

  // Main menu loop
  while (option != 4) {
    cout << "\nMenu:\n1. Add media\n2. Search media\n3. Delete media\n4. Exit\nChoose an option: ";
    cin >> option;
    cin.ignore();

    // Execute the corresponding option based on the user's input
    if (option == 1) {
      addMedia(v); // Call function to add media
    } else if (option == 2) {
      searchMedia(v); // Call function to search media
    } else if (option == 3) {
      deleteMedia(v); // Call function to delete media
    } else if (option == 4) {
      cout << "Exiting...\n";
    } else {
      cout << "Invalid choice!\n";
    }
  }
}

// Function to search for media based on title or year
void searchMedia(vector<Media*> &newv) {
  char choice;
  cout << "Search by (T)itle or (Y)ear?: ";
  cin >> choice;
  cin.ignore();

  if (toupper(choice) == 'T') {
    char searchQuery[10];
    cout << "Enter search query: " << endl;
    cin.get(searchQuery, 11);

    // Iterate through the vector and print media with matching titles
    for (vector<Media*>::iterator it = newv.begin(); it < newv.end(); ++it) {
      if (strcmp((*it)->getTitle(), searchQuery) == 0) {
        (*it)->print(); // Call print function for matching media
      }
    }
  } else if (toupper(choice) == 'Y') {
    int searchQuery;
    cin >> searchQuery;

    // Iterate through the vector and print media with matching years
    for (vector<Media*>::iterator it = newv.begin(); it != newv.end(); ++it) {
      if ((*it)->getYear() == searchQuery) {
        (*it)->print(); // Call print function for matching media
      }
    }
  } else {
    cout << "Invalid choice. Please enter T for Title or Y for Year.\n";
  }
}

// Function to delete media based on title or year
void deleteMedia(vector<Media*> &newv) {
  char confirm[100];
  Media* temp;
  char choice;

  cout << "Delete by (T)itle or (Y)ear?: ";
  cin >> choice;
  cin.ignore();

  if (toupper(choice) == 'T') {
    char searchQuery[50];
    cout << "Enter the title of the media that you want to delete: " << endl;
    cin.get(searchQuery, 100);

    // Iterate through the vector, print matching media, and ask for confirmation to delete
    for (int i = 0; i < newv.size(); i++) {
      if (strcmp(newv[i]->getTitle(), searchQuery) == 0) {
        newv[i]->print(); // Call print function for matching media
        cout << "Are you sure you want to delete this media? Enter (Y)es or (N)o";
        cin >> confirm;

        // If confirmed, delete the media and remove it from the vector
        if (strcmp(confirm, "Y") == 0) {
          delete newv[i];
          newv.erase(newv.begin() + i);
          cout << "deleted" << endl;
        } else {
          cout << "Media was not deleted" << endl;
        }
      }
    }
  }

  if (toupper(choice) == 'Y') {
    int searchQuery;
    cout << "Enter the year of the media that you want to delete: " << endl;
    cin >> searchQuery;

    // Iterate through the vector, print matching media, and ask for confirmation to delete
    for (int i = 0; i < newv.size(); i++) {
      if (newv[i]->getYear() == searchQuery) {
        newv[i]->print(); // Call print function for matching media
        cout << "Are you sure you want to delete this media? Enter (Y)es or (N)o";
        cin >> confirm;

        // If confirmed, delete the media and remove it from the vector
        if (strcmp(confirm, "Y") == 0) {
          delete newv[i];
          newv.erase(newv.begin() + i);
          cout << "deleted" << endl;
        } else {
          cout << "Media was not deleted" << endl;
        }
      }
    }
  }
}

// Function to add new media to the vector
void addMedia(vector<Media*> &newv) {
  char name[100];
  int publishYear;
  int mediaType;
  char maker[100];
  int length;
  float rating;

  cout << "Please enter the type of media that you are adding to the database. Enter 1 for music, 2 for videogames, and 3 for a movie" << endl;
  cin >> mediaType;

  // Add music to the vector
  if (mediaType == 1) {
    Music* newmusic = new Music();

    // Get information from the user and set the attributes of the new music object
    cout << "Enter the name of the music: " << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get(name, 100);
    newmusic->Title(name);

    cout << "Enter the creation year of the music: " << endl;
    cin >> publishYear;
    newmusic->Year(publishYear);

    cout << "Enter the artist name: " << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get(maker, 100);
    newmusic->addArtistName(maker);

    cout << "Enter the length of the music in minutes: " << endl;
    cin >> length;
    newmusic->addDuration(length);

    // Add the new music object to the vector
    newv.push_back(newmusic);
  }

  // Add videogame to the vector
  if (mediaType == 2) {
    VideoGames* newvg = new VideoGames();

    // Get information from the user and set the attributes of the new videogame object
    cout << "Enter the name of the game: " << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get(name, 100);
    newvg->Title(name);

    cout << "Enter the creation year of the game: " << endl;
    cin >> publishYear;
    newvg->Year(publishYear);

    cout << "Enter the publisher of the game: " << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get(maker, 100);
    newvg->addPublisherName(maker);

    cout << "Enter the rating of the game out of 10: " << endl;
    cin >> rating;
    cin.clear();
    newvg->addRating(rating);

    // Add the new videogame object to the vector
    newv.push_back(newvg);
  }

  // Add movie to the vector
  if (mediaType == 3) {
    Movies* newmovie = new Movies();

    // Get information from the user and set the attributes of the new movie object
    cout << "Enter the name of the movie: " << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get(name, 100);
    newmovie->Title(name);

    cout << "Enter the year: " << endl;
    cin >> publishYear;
    newmovie->Year(publishYear);

    cout << "Enter the director: " << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get(maker, 100);
    newmovie->addDirector(maker);

    cout << "Enter the length : " << endl;
    cin >> length;
    newmovie->addDuration(length);

    cout << "Enter the rating ?/10: " << endl;
    cin >> rating;
    cin.clear();
    newmovie->addRating(rating);

    // Add the new movie object to the vector
    newv.push_back(newmovie);
  }
}
