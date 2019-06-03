//  Copyright Cedric Lemaitre 2018

#ifndef SRC_COMMON_PASSAGER_READER_HPP_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <map>
#include "passager.hpp"

///   Class PassagerReader wich allows to read and store data from CSV file
///   titanic.sv
class PassagerReader
{
public:
    explicit PassagerReader(const std::string &);
    //  private:
    std::string filename;
    void parse_line(std::string);
    int nb_col_csv;
    std::vector<Passager> liste_passager;
    void sort(const std::string &);
    std::map<unsigned int, unsigned int> age_histogram;
    void compute_age_histogram();
    void export_age_histogram(const std::string &);
};
#define SRC_COMMON_PASSAGER_READER_HPP_
#endif //  SRC_COMMON_PASSAGER_READER_HPP_
