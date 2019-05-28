// Copyright 2018 Cdric Lemaitre

#include <gtest/gtest.h>

#include <string>
#include <sstream>
#include <common/passager_reader.hpp>

// Create our own test to check the different function of our class
// This function will take two arguments:
// * The test case name
// * The test name
TEST(TestPassagerReader, TestConstructorOneParamFileName)
{
    //  first line in csv file
    //  0,3,male,22.0,1,0,7.25,S,Third,man,True,,Southampton,no,False
    std::string f_name = "../data/titanic.csv";
    PassagerReader my_passager_reader(f_name);
    ASSERT_FALSE(my_passager_reader.liste_passager[0].survived);
    ASSERT_EQ(my_passager_reader.liste_passager[0].pclass, 3);
    ASSERT_TRUE(my_passager_reader.liste_passager[0].sex);
    ASSERT_EQ(my_passager_reader.liste_passager[0].age, 22);
    std::string chaine_deck = "";
    ASSERT_STREQ(
        my_passager_reader.liste_passager[0].deck.c_str(),
        chaine_deck.c_str());
    ASSERT_FALSE(my_passager_reader.liste_passager[0].alone);
    // line number 4
    // 1,1,female,35.0,1,0,53.1,S,First,woman,False,C,Southampton,yes,False
    ASSERT_TRUE(my_passager_reader.liste_passager[3].survived);
    ASSERT_EQ(my_passager_reader.liste_passager[3].pclass, 1);
    ASSERT_FALSE(my_passager_reader.liste_passager[3].sex);
    ASSERT_EQ(my_passager_reader.liste_passager[3].age, 35);
    chaine_deck = "C";
    ASSERT_STREQ(
        my_passager_reader.liste_passager[3].deck.c_str(),
        chaine_deck.c_str());
    ASSERT_FALSE(my_passager_reader.liste_passager[3].alone);
    //  line number 6
    //  0,3,male,,0,0,8.4583,Q,Third,man,True,,Queenstown,no,True
    ASSERT_FALSE(my_passager_reader.liste_passager[5].survived);
    ASSERT_EQ(my_passager_reader.liste_passager[5].pclass, 3);
    ASSERT_TRUE(my_passager_reader.liste_passager[5].sex);
    ASSERT_EQ(my_passager_reader.liste_passager[5].age, -1);
    chaine_deck = "";
    ASSERT_STREQ(
        my_passager_reader.liste_passager[5].deck.c_str(),
        chaine_deck.c_str());
    ASSERT_TRUE(my_passager_reader.liste_passager[5].alone);
}

TEST(TestPassagerReader, TestSort)
{
    //  first line in csv file
    //  0,3,male,22.0,1,0,7.25,S,Third,man,True,,Southampton,no,False
    std::string f_name = "../data/titanic.csv";
    PassagerReader my_passager_reader(f_name);
    Passager &first = my_passager_reader.liste_passager.front();
    Passager &last = my_passager_reader.liste_passager.back();

    ASSERT_EQ(first.age, 22);
    ASSERT_EQ(last.age, 32);
    my_passager_reader.sort("age");
    ASSERT_EQ(first.age, -1);
    ASSERT_EQ(last.age, 80);
}

TEST(TestPassager, TestStreamOut)
{
    std::string f_name = "../data/titanic.csv";
    PassagerReader my_passager_reader(f_name);
    Passager &first = my_passager_reader.liste_passager.front();
    Passager &last = my_passager_reader.liste_passager.back();
    std::string output = "survived : false, pclass : 3, sex : true, age : 32, slbsp : 0, parch : 0, fare : 7, embarked : , type_class : , who : , adult_male : false, deck : , embark_town : , alive : false, alone : true";
    std::stringstream out;
    out << last;
    ASSERT_STREQ(out.str().c_str(), output.c_str());

    out.str(std::string());
    output = "survived : false, pclass : 3, sex : true, age : 22, slbsp : 1, parch : 0, fare : 7, embarked : S, type_class : Third, who : man, adult_male : false, deck : , embark_town : Southampton, alive : false, alone : false";
    out << first;
    ASSERT_STREQ(out.str().c_str(), output.c_str());
}
