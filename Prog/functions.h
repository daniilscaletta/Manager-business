#pragma once

#include <string>
#include <vector>

using namespace std;

void show_menu();

void add_note(const string& str);

void see_all_notes();

vector<string> find_one_note(const string& note_to_find);