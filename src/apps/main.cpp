// Copyright 2016 Guillaume Lemaitre, Cedric Lemaitre

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "../common/complex.hpp"
#include "../common/phone.hpp"
#include "../common/smartphone.hpp"
#include "../common/point.hpp"
#include "../common/ex_template.hpp"
#include "../common/passager_reader.hpp"
#include "../common/process_passager.hpp"
#include "../common/polymorphism.hpp"
#include "../common/functor.hpp"
#include <common/passager.hpp>
#include <common/passager_reader.hpp>

int main()
{

    std::string f_name = "../data/titanic.csv";
    PassagerReader my_passager_reader(f_name);

    for (Passager const &my_passenger : my_passager_reader.liste_passager)
    {
        std::cout << my_passenger << std::endl;
    }

    my_passager_reader.sort("age");

    for (Passager const &my_passenger : my_passager_reader.liste_passager)
    {
        std::cout << my_passenger << std::endl;
    }

    // my_passager_reader.sort("survived");
    // std::cout << "survived" << std::endl;
    // std::cout << my_passager_reader.liste_passager.front() << std::endl;
    // std::cout << my_passager_reader.liste_passager.back() << std::endl;
    // my_passager_reader.sort("pclass");
    // std::cout << "pclass" << std::endl;
    // std::cout << my_passager_reader.liste_passager.front() << std::endl;
    // std::cout << my_passager_reader.liste_passager.back() << std::endl;
    // my_passager_reader.sort("sex");
    // std::cout << "sex" << std::endl;
    // std::cout << my_passager_reader.liste_passager.front() << std::endl;
    // std::cout << my_passager_reader.liste_passager.back() << std::endl;
    // my_passager_reader.sort("age");
    // std::cout << "age" << std::endl;
    // std::cout << my_passager_reader.liste_passager.front() << std::endl;
    // std::cout << my_passager_reader.liste_passager.back() << std::endl;
    // my_passager_reader.sort("slbsp");
    // std::cout << "slbsp" << std::endl;
    // std::cout << my_passager_reader.liste_passager.front() << std::endl;
    // std::cout << my_passager_reader.liste_passager.back() << std::endl;
    // my_passager_reader.sort("parch");
    // std::cout << "parch" << std::endl;
    // std::cout << my_passager_reader.liste_passager.front() << std::endl;
    // std::cout << my_passager_reader.liste_passager.back() << std::endl;
    // my_passager_reader.sort("fare");
    // std::cout << "fare" << std::endl;
    // std::cout << my_passager_reader.liste_passager.front() << std::endl;
    // std::cout << my_passager_reader.liste_passager.back() << std::endl;
    // my_passager_reader.sort("embarked");
    // std::cout << "embarked" << std::endl;
    // std::cout << my_passager_reader.liste_passager.front() << std::endl;
    // std::cout << my_passager_reader.liste_passager.back() << std::endl;
    // my_passager_reader.sort("type_class");
    // std::cout << "type_class" << std::endl;
    // std::cout << my_passager_reader.liste_passager.front() << std::endl;
    // std::cout << my_passager_reader.liste_passager.back() << std::endl;
    // my_passager_reader.sort("who");
    // std::cout << "who" << std::endl;
    // std::cout << my_passager_reader.liste_passager.front() << std::endl;
    // std::cout << my_passager_reader.liste_passager.back() << std::endl;
    // my_passager_reader.sort("adult_male");
    // std::cout << "adult_male" << std::endl;
    // std::cout << my_passager_reader.liste_passager.front() << std::endl;
    // std::cout << my_passager_reader.liste_passager.back() << std::endl;
    // my_passager_reader.sort("deck");
    // std::cout << "deck" << std::endl;
    // std::cout << my_passager_reader.liste_passager.front() << std::endl;
    // std::cout << my_passager_reader.liste_passager.back() << std::endl;
    // my_passager_reader.sort("embark_town");
    // std::cout << "embark_town" << std::endl;
    // std::cout << my_passager_reader.liste_passager.front() << std::endl;
    // std::cout << my_passager_reader.liste_passager.back() << std::endl;
    // my_passager_reader.sort("alive");
    // std::cout << "alive" << std::endl;
    // std::cout << my_passager_reader.liste_passager.front() << std::endl;
    // std::cout << my_passager_reader.liste_passager.back() << std::endl;
    // my_passager_reader.sort("alone");
    // std::cout << "alone" << std::endl;
    // std::cout << my_passager_reader.liste_passager.front() << std::endl;
    // std::cout << my_passager_reader.liste_passager.back() << std::endl;
    //  demobscv::polymorph::Car c(1000, 4);
    //  demobscv::polymorph::Moto m(1000, 250);
    //
    //  c.display();
    //  m.display();
    //
    //  introduice(c);
    //  introduice(m);
    //
    //  demobscv::polymorph::Vehicule * ptr_v(0);
    //   ptr_v = & c;
    //
    //   std::cout << "Nb wheels of ptr_v : " << ptr_v->nb_wheels() << std::endl;
    //      std::string f_name = "../data/titanic.csv";
    //      PassagerReader my_passager_reader(f_name);
    //      ProcessPassager my_process_passager(my_passager_reader.liste_passager);
    //      std::cout << "Age moyenne des passagers : "
    //          << my_process_passager.p_mean_age() << "\n";
    //      StatSurvived stat_survived = my_process_passager.p_survived();
    //      std::cout << "Nombre de survivant : "
    //          << stat_survived.nb_survived << "\n";
    //      std::cout << "Pourcentage de survivant : "
    //          << stat_survived.percentage_survived << "\n";
    //      std::map<std::string, int> histo = my_process_passager.p_hist_emabarked();
    //      std::string clef = "";
    //      for (auto const & x : histo) {
    //          if (x.first == "") {
    //              clef = "No information";
    //          } else {
    //              clef = x.first;
    //          }
    //          std::cout << clef
    //              << ":"
    //              << x.second
    //              << "\n";
    //      }  //  for all element of the map

    // Point my_point(12, 0);
    // float ar = 1.27;
    // float ai = 2.0;
    // complex a(ar, ai);

    // float br = 1.45;
    // float bi = 2.18;
    // complex b(br, bi);

    // complex cres;

    // cres = a + b;

    // std::cout << cres.get_real() << " \n \n";

    // int i = 12;
    // double d = 12.4;
    // std::string s = "Test";

    // print_data(i);
    // print_data(d);
    // print_data(s);

    // double t1_i = 5.0;
    // double t2_j = 6.13;
    // double res = Add_T(t1_i, t2_j);
    // std::cout << res << "\n";

    // float ar = 3.0;
    // float ai = 2.7;
    // float br = 4.0;
    // float bi = 9.6;

    // complex a(ar, ai);
    // complex b(br, bi);
    // complex c;

    // c = Add_T(a, b);

    // std::cout << c.get_real() << "\n";
    // std::cout << c.get_imag() << "\n";
    /*	phone my_phone;

	my_phone.set_value(150);
	std::cout << my_phone.get_value() << "\n";


	Smartphone my_smartphone;
	my_smartphone.set_os("Android");
	std::cout << my_smartphone.get_os() << "\n";

	my_smartphone.set_year(2012);
	std::cout << my_smartphone.get_year() << "\n";




	// create, instanciate a complex object
	complex my_complex;
	my_complex.set_imag(1.2789);

	std::cout << "real : " << my_complex.get_real() << "\n";
	std::cout << "imag : "<< my_complex.get_imag()<< "\n";

	// custon corstructor

	float c = 2.9;
	float d = 1.34;

	float a  = 2;
	float b = 2;
	complex res_add;

	complex my_complex2(c, d);
	complex my_complex3(a, b);

	res_add = my_complex2 + my_complex3;

	std::cout << "real : " << res_add.get_real()<< "\n";
	std::cout << "imag : "<< res_add.get_imag()<< "\n";

	float m = my_complex2.get_mod();
	std::cout << "Modulus of my_compex2 obj : " << m << "\n";

	float n = my_complex2.get_arg();
	std::cout << "Arg of my_compex2 obj : " << n << "\n";*/
    return 0;
}
