/*
*  testSuite
*
*  Created by Jean-Matthieu VERMOSEN on 23/03/2015
*  Copyright 2015. All rights reserved.
*
*/

#include <string>
#include <boost/lexical_cast.hpp>

int main(int argc, char** argv) {

	int exit;														// exit code

	try {

		bool end = false;											// main exit indicator 
		int test = 0;												// optional test

		for (int i = 1; i < argc; i++) {							// deals with optional arguments

			std::string arg(argv[i]);								// current std::string

			if (arg.substr(1, 4) == "test") {						// arg 1: expects -test=n

				std::string str(arg.substr(6, arg.length() - 6));	// the value
				test = boost::lexical_cast<int>(str);				// runs the selected test automatically	
				end = true;											// for later use: only one attempt

			}
		}

		do {														// manual selection - loop over the choices

			int res = test;											// for manual definition

			if (test == 0) {

				std::cout											// message
					<< std::endl << "Please select an activity: "
					<< std::endl
					<< std::endl << "######## tests ########"
					<< std::endl << "1 - bla"
					<< std::endl
					<< std::endl << "#### Miscellaneous ####"
					<< std::endl << "0 - exit"
					<< std::endl
					<< std::endl;

				std::cin >> res;									// user defined test

			}

			switch (res) {											// switch over the available tests

			case 1:

				//bla
				break;

			case 0:

				end = true;											// stop the server
				break;

			default:												// unknown, invalid

				std::cout
					<< "invalid selection, please try again"
					<< std::endl;

				break;

			}

		} while (end == false);										// loop until exit

		exit = 0;

	}
	catch (std::exception & e) {									// exception management

		std::cout
			<< "an error occured: "
			<< e.what()
			<< std::endl;

		exit = 1; system("pause");

	}
	catch (...) {													// unknown error

		std::cout
			<< "an unknown error occured..."
			<< std::endl;

		exit = 1; system("pause");

	}

	return exit;

}