#include <iostream>
#include "functions.h"
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

 string path = "C:/Users/daniilscaletta/Desktop/ToDoList/Resources/DataBase.txt";

void show_menu()
{
    cout << endl;
    cout << "[1] Add Notes " << endl;
    cout << "[2] Show All Notes " << endl;
    cout << "[3] Find Note " << endl;
    cout << "[4] Remove Note " << endl;
    cout << "[5] Remove All Notes " << endl;
    cout << "[6] Exit " << endl;
}

void add_note(const string& new_note)
{
    cout << new_note << endl;

    ofstream file;

    file.open(path, ofstream::app);
    if(!file.is_open())
    {
        cout << "file is NOT opened" << endl;
        exit(EXIT_FAILURE);
    }
    file << new_note << endl;

    file.close();

    cout << "Note Added !" << endl;
}

void see_all_notes()
{
    ifstream file;

    file.open(path);

    if(!file.is_open())
    {
        cout << "file is NOT opened" << endl;
        exit(EXIT_FAILURE);
    }

    string one_note;
    int i = 1;
    while(getline(file, one_note))
    {
        cout << "[" << i++ << "] " << one_note << endl; 
        if(file.eof()) break;
    }

    file.close();
}

vector<string> find_one_note(const string& note_to_find)
{
    ifstream file;

    file.open(path);

    if(!file.is_open())
    {
        cout << "File is empty! Add notes" << endl;
        exit(EXIT_FAILURE);
    }
    
    string one_note;
    vector<string> found_notes;
    int count = 0;

    while(getline(file, one_note))
    {
        if(one_note.find(note_to_find) != -1) 
        {
            count++;
            found_notes.push_back(one_note);
        }    
        if(file.eof()) break;
    }
    file.close();

    return found_notes;
}

void remove_note(int number_of_note)
{
    ifstream fin;
    fin.open(path);

    if(!fin.is_open())
    {
        cout << "file is NOT opened" << endl;
        exit(EXIT_FAILURE);
    }

    vector<string> notes;
    string one_note;
    while(getline(fin, one_note))
    {
        notes.push_back(one_note);
        if(fin.eof()) break;
    }
    notes.erase(notes.begin() + number_of_note - 1);
    fin.close();

    ofstream fout;
    fout.open(path, ofstream::out);

    if(!fout.is_open())
    {
        cout << "file is NOT opened" << endl;
        exit(EXIT_FAILURE);
    }

    for(auto& a : notes) fout << a << endl;
    fout.close();
    cout << "Note deleted! " << endl;
}

void remove_all_notes()
{
    ofstream file;

    file.open(path, ofstream::out);
    if(!file.is_open())
    {
        cout << "file is NOT opened" << endl;
        exit(EXIT_FAILURE);
    }

    file.close();
    cout << "All notes are deleted!" << endl;
}

