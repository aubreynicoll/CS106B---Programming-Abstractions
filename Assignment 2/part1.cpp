/* Assignment 2, Part A: Random Writing and Markov Models of Language
 *
 * Written by Aubrey Nicoll as part of Stanford Engineering's CS106B course.
 *
 * This program prompts the user for a text file and the depth of the Markov
 * model, which in this particular implementation shall be arbitrarily limited
 * to 1 to 10. If the input file has less characters than the model depth, no
 * model will be created;
 *
 * The program then reads the input file character by character, mapping each
 * seed to a vector of characters that appeared after the seed in the text.
 * Duplicate characters in the vector represent a higher probability that the
 * character appeared after a given seed.
 *
 * Finally, the program builds a randomly generated text from the model. It
 * begins with the most common seed, and adds characters one at a time by
 * randomly accessing each seed's vector. Hilarity ensues.
 * */

#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

#define DEPTH_MIN 1
#define DEPTH_MAX 10
#define OUTPUT_LENGTH 2000

using namespace std;

void getUserInput(ifstream &file, int &k);
void buildModel(ifstream &input, map<string, vector<char> > &model, int k);
void generateText(map<string, vector<char> > &model, int k);
void printModel(map<string, vector<char> > &model);

int main() {
  srand(time(0));

  ifstream input;
  int k = 0;
  map<string, vector<char> > model;

  getUserInput(input, k);
  buildModel(input, model, k);
  generateText(model, k);
  return 0;
}

void getUserInput(ifstream &file, int &k) {
  do {
    string filename;
    cout << "Enter filename: ";
    getline(cin, filename);
    file.open(filename);
  } while (file.fail());

  do {
    string depth;
    cout << "Enter depth (1 to 10): ";
    getline(cin, depth);
    try {
      k = stoi(depth);
    } catch (exception &error) {
      continue;
    }
  } while (k < DEPTH_MIN || k > DEPTH_MAX);

  return;
}

void buildModel(ifstream &input, map<string, vector<char> > &model, int k) {
  string seed;
  char c = '\0';

  while (seed.length() < k) {
    c = input.get();
    seed += c;
  }

  while ((c = input.get()) != EOF) {
    model[seed].push_back(c);
    seed.erase(0, 1);
    seed += c;
  }

  return;
}

void generateText(map<string, vector<char> > &model, int k) {
  string seed;
  char c = '\0';

  for (map<string, vector<char> >::iterator it = model.begin();
       it != model.end(); it++) {
    if (seed == "") {
      seed = it->first;
    } else {
      if (model.at(seed).size() < it->second.size()) {
        seed = it->first;
      }
    }
  }

  cout << seed;
  for (int i = 0; i < OUTPUT_LENGTH - k; i++) {
    try {
      c = model.at(seed).at(rand() % model.at(seed).size());
      cout << c;
      seed.erase(0, 1);
      seed += c;
    } catch (exception e) {
      break;
    }
  }

  return;
}

void printModel(map<string, vector<char> > &model) {
  for (map<string, vector<char> >::iterator it = model.begin();
       it != model.end(); it++) {
    cout << it->first << " : ";
    for (int i = 0; i < it->second.size(); i++) {
      cout << it->second[i] << ", ";
    }
    cout << endl;
  }
  return;
}