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
    ASSERT_EQ(first.alone, true);
    ASSERT_EQ(first.adult_male, true);
    ASSERT_EQ(first.sex, true);
    ASSERT_EQ(first.fare, 30);
    ASSERT_EQ(first.embark_town, "Southampton");
    ASSERT_EQ(first.type_class, "First");
    ASSERT_EQ(first.survived, true);
    ASSERT_EQ(first.deck, "C");

    ASSERT_EQ(last.age, 80);
    ASSERT_EQ(last.survived, true);
    ASSERT_EQ(last.alone, true);
    ASSERT_EQ(last.adult_male, true);
    ASSERT_EQ(last.type_class, "First");
    ASSERT_EQ(last.sex, true);
    ASSERT_EQ(last.fare, 30);
    ASSERT_EQ(last.embark_town, "Southampton");
    ASSERT_EQ(last.deck, "A");

    my_passager_reader.sort("survived");
    ASSERT_EQ(first.survived, false);
    ASSERT_EQ(last.survived, true);
    my_passager_reader.sort("pclass");
    ASSERT_EQ(first.pclass, 1);
    ASSERT_EQ(last.pclass, 3);
    my_passager_reader.sort("sex");
    ASSERT_EQ(first.sex, false);
    ASSERT_EQ(last.sex, true);
    my_passager_reader.sort("age");
    ASSERT_EQ(first.age, -1);
    ASSERT_EQ(last.age, 80);
    my_passager_reader.sort("slbsp");
    ASSERT_EQ(first.slbsp, 0);
    ASSERT_EQ(last.slbsp, 8);
    my_passager_reader.sort("parch");
    ASSERT_EQ(first.parch, 0);
    ASSERT_EQ(last.parch, 6);
    my_passager_reader.sort("fare");
    ASSERT_EQ(first.fare, 0);
    ASSERT_EQ(last.fare, 512);
    my_passager_reader.sort("embarked");
    ASSERT_EQ(first.embarked, "");
    ASSERT_EQ(last.embarked, "S");
    my_passager_reader.sort("type_class");
    ASSERT_EQ(first.type_class, "");
    ASSERT_EQ(last.type_class, "Third");
    my_passager_reader.sort("who");
    ASSERT_EQ(first.who, "");
    ASSERT_EQ(last.who, "woman");
    my_passager_reader.sort("adult_male");
    ASSERT_EQ(first.adult_male, false);
    ASSERT_EQ(last.adult_male, true);
    my_passager_reader.sort("deck");
    ASSERT_EQ(first.deck, "");
    ASSERT_EQ(last.deck, "G");
    my_passager_reader.sort("embark_town");
    ASSERT_EQ(first.embark_town, "");
    ASSERT_EQ(last.embark_town, "Southampton");
    my_passager_reader.sort("alive");
    ASSERT_EQ(first.alive, false);
    ASSERT_EQ(last.alive, true);
    my_passager_reader.sort("alone");
    ASSERT_EQ(first.alone, false);
    ASSERT_EQ(last.alone, true);
}

TEST(TestPassager, TestStreamOut)
{
    std::string f_name = "../data/titanic.csv";
    PassagerReader my_passager_reader(f_name);
    Passager &first = my_passager_reader.liste_passager.front();
    Passager &last = my_passager_reader.liste_passager.back();
    std::string output = "survived : false, pclass : 3, sex : true, age : 32, slbsp : 0, parch : 0, fare : 7, embarked : , type_class : , who : , adult_male : true, deck : , embark_town : , alive : false, alone : true";
    std::stringstream out;
    out << last;
    ASSERT_STREQ(out.str().c_str(), output.c_str());

    out.str(std::string());
    output = "survived : false, pclass : 3, sex : true, age : 22, slbsp : 1, parch : 0, fare : 7, embarked : S, type_class : Third, who : man, adult_male : true, deck : , embark_town : Southampton, alive : false, alone : false";
    out << first;
    ASSERT_STREQ(out.str().c_str(), output.c_str());
}

TEST(TestPassager, TestHistogram)
{
    std::string f_name = "../data/titanic.csv";
    PassagerReader my_passager_reader(f_name);
    my_passager_reader.compute_age_histogram();

    ASSERT_EQ(my_passager_reader.age_histogram[0], 7);
    ASSERT_EQ(my_passager_reader.age_histogram[10], 2);
    ASSERT_EQ(my_passager_reader.age_histogram[50], 10);
    ASSERT_EQ(my_passager_reader.age_histogram[80], 1);
}
