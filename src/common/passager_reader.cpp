//  Copyright Cedric Lemaitre 2018
#include <algorithm>
#include <iostream>
#include <fstream>

#include "passager_reader.hpp"

PassagerReader::PassagerReader(const std::string &file_name)
{
    nb_col_csv = 15;
    filename = file_name;
    std::ifstream if_file(file_name);
    if (if_file.is_open())
    {
        std::string val_line;
        while (if_file.good())
        {
            getline(if_file, val_line);
            parse_line(val_line);
        } //  while if_file.good()
    }
    else
    {
        std::cout << "Can't open file";
    } // if open file
} // end PassagerReader

void PassagerReader::parse_line(std::string line)
{
    bool survived;
    int pclass;
    bool sex;
    int age;
    int slbsp;
    int parch;
    int fare;
    std::string embarked;
    std::string type_class;
    std::string who;
    bool adult_male;
    std::string deck;
    std::string embark_town;
    bool alive;
    bool alone;
    std::stringstream line_stream(line);
    std::string cell;
    int count = 0;
    while (std::getline(line_stream, cell, ','))
    {
        switch (count)
        {
        case 0:
            if (cell == "1")
                survived = true;
            else
                survived = false;
            count++;
            break;
        case 1:
            pclass = atoi(cell.c_str());
            count++;
            break;
        case 2:
            if (cell == "male")
                sex = true;
            else
                sex = false;
            count++;
            break;
        case 3:
            if (cell == "")
                age = -1;
            else
                age = atoi(cell.c_str());
            count++;
            break;
        case 4:
            slbsp = atoi(cell.c_str());
            count++;
            break;
        case 5:
            parch = atoi(cell.c_str());
            count++;
            break;
        case 6:
            fare = atoi(cell.c_str());
            count++;
            break;
        case 7:
            embarked = cell;
            count++;
            break;
        case 8:
            type_class = cell;
            count++;
            break;
        case 9:
            who = cell;
            count++;
            break;
        case 10:
            if (cell == "True")
                adult_male = true;
            else
                adult_male = false;
            count++;
            break;
        case 11:
            deck = cell;
            count++;
            break;
        case 12:
            embark_town = cell;
            count++;
            break;
        case 13:
            if (cell == "yes")
                alive = true;
            else
                alive = false;
            count++;
            break;
        case 14:
            if (cell == "True" || cell == "true")
                alone = true;
            else
                alone = false;
            count++;
            break;
        default:
            std::cout << "Warning : value of count in [0, 14]\n";
        } //  switch case
    }     //  while end line
    Passager temp_passager(survived, pclass, sex, age, slbsp, parch, fare,
                           embarked, type_class, who, adult_male, deck, embark_town, alive,
                           alone);
    liste_passager.push_back(temp_passager);
}

void PassagerReader::sort(const std::string &member)
{
    std::sort(liste_passager.begin(), liste_passager.end(),
              [=](Passager const &a, Passager const &b) -> bool {
                  if (member == "survived")
                  {
                      return a.survived < b.survived;
                  }
                  else if (member == "pclass")
                  {
                      return a.pclass < b.pclass;
                  }
                  else if (member == "sex")
                  {
                      return a.sex < b.sex;
                  }
                  else if (member == "age")
                  {
                      return a.age < b.age;
                  }
                  else if (member == "slbsp")
                  {
                      return a.slbsp < b.slbsp;
                  }
                  else if (member == "parch")
                  {
                      return a.parch < b.parch;
                  }
                  else if (member == "fare")
                  {
                      return a.fare < b.fare;
                  }
                  else if (member == "embarked")
                  {
                      return a.embarked < b.embarked;
                  }
                  else if (member == "type_class")
                  {
                      return a.type_class < b.type_class;
                  }
                  else if (member == "who")
                  {
                      return a.who < b.who;
                  }
                  else if (member == "adult_male")
                  {
                      return a.adult_male < b.adult_male;
                  }
                  else if (member == "deck")
                  {
                      return a.deck < b.deck;
                  }
                  else if (member == "embark_town")
                  {
                      return a.embark_town < b.embark_town;
                  }
                  else if (member == "alive")
                  {
                      return a.alive < b.alive;
                  }
                  else if (member == "alone")
                  {
                      return a.alone < b.alone;
                  }
                  return true;
              });
}

void PassagerReader::compute_age_histogram()
{
    for (std::vector<int>::size_type i = 0, size = liste_passager.size(); i < size; i++)
    {
        if (!(liste_passager[i].age == -1))
        {
            if (age_histogram.find(liste_passager[i].age) == age_histogram.end())
                age_histogram[liste_passager[i].age] = 1;
            else
                age_histogram[liste_passager[i].age]++;
        }
    }
}

void PassagerReader::export_age_histogram(const std::string &export_file)
{
    std::ofstream outfile(export_file);
    std::map<unsigned int, unsigned int>::iterator it = age_histogram.begin();

    if (outfile.good())
        outfile << "age,frequency" << std::endl;

    while (outfile.good() && it != age_histogram.end())
    {
        outfile << it->first << "," << it->second << std::endl;
        it++;
    }

    outfile.close();
}
