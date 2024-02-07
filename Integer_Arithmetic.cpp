#include <iostream>

using namespace std;

void twoComplementAddition();

void twoComplementNegation();



int main() {

    bool currentlyRunning = true;


    while (currentlyRunning) {

        cout << "Welcome to the Integer Arithmetic Program!";

        cout << endl;
        cout << endl;

        cout << "Press 1 for Two's Complement Addition.";

        cout << endl;
        cout << endl;

        cout << "Press 2 for Two's Complement Negation.";

        cout << endl;
        cout << endl;

        cout << "Press 3 for Two's Complement Multiplication.";

        cout << endl;
        cout << endl;

        cout << "Press 4 for Two's Complement Division.";

        cout << endl;
        cout << endl;
        cout << endl;

        cout << "If you would like to exit the program, enter 0.";

        cout << endl;
        cout << endl;

        cout << endl;

        cout << "Enter here: ";

        int userInput;

        if (!(cin >> userInput)) {

            cout << endl;

            cin.clear();

            cin.ignore(100, '\n');

            cout << endl << endl;

            cout << "Invalid entry.  Please try again." << "\n\n\n\n";


            continue;
        }


        if (userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4) {

            cout << endl;

            cout << "Invalid entry. Please enter 1, 2, 3, or 4 to access a menu option.";

            cout << endl;

            cout << endl;

            cout << endl;

            cout << endl;

            continue;

        }

        /**** BEGINNING of Two's Complement Addition ****/


        if (userInput == 1) {



			cout << endl;
			cout << "_______________";

			cout << endl;
			cout << endl;

			cout << "You have selected Two's Complement Addition.";

			cout << endl;
			cout << endl;


			twoComplementAddition();



        }



        /**** END of Two's Complement Addition ****/



        

        else if (userInput == 0) {

            currentlyRunning = false;

            cout << endl;

            cout << "Thank you for using the program.";

            cout << endl;
            cout << endl;

        }








    } // End of while loop -> while(currentlyRunning)

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

} // int main()






void twoComplementAddition() {


	bool runAddition = true;

	char runAgain;



	while (runAddition) {


		cout << "Enter a Decimal Number (Negative, 0 or Positive): ";

		int decimalInput1;


		if (!(cin >> decimalInput1)) {

			cout << endl;

			cin.clear();

			cin.ignore(100, '\n');

			cout << "\n\n" << "Invalid entry. Please try again.";

			cout << endl << endl << endl;

			continue;

		}


		cout << endl;



		cout << "Enter Another Decimal Number to Add (Negative, 0, or Positive): ";

		int decimalInput2;



		if (!(cin >> decimalInput2)) {

			cout << endl;

			cin.clear();

			cin.ignore(100, '\n');

			cout << "\n\n" << "Invalid entry. Please try again.";

			cout << endl << endl << endl;

			continue;

		}


		cout << endl;


		cout << "Enter a word size (in bits): ";

		int wordSize;

		cin >> wordSize;

		cout << endl;

		/** ERROR CHECKING: Checking for invalid word size


		**/





		/**** Two's Complement Addition Algorithm ****/



		// Calculating Minimum and Maximum of Two's Compliment (TMinw and TMaxw)


		int TMin = pow(2, wordSize - 1) * (-1);

		int TMax = pow(2, wordSize - 1) - 1;


		// Storage for addition result that will be printed 

		int additionResult = 0;



		// Seeing if both decimal inputs are in the range of TMin and TMax (the range of a two's complement number)

		bool inTwoComplementRange;

		if ((decimalInput1 >= TMin && decimalInput1 <= TMax) && (decimalInput2 >= TMin && decimalInput2 <= TMax)) {

			inTwoComplementRange = true;

		}

		// Throwing error message if both decimal inputs are not in the range


		else {

			inTwoComplementRange = false;

			cout << "Sorry, the number you entered is not within the range of a Two's Complement number.  Please try again." << endl;

			cout << endl;
			cout << endl;
			cout << endl;

			continue;

		}


		if (inTwoComplementRange) {

			additionResult = decimalInput1 + decimalInput2; // Adding both numbers, then checking to see if it is normal, has positive overflow, or negative overflow

			


			// Checking for Negative Overflow

			if (additionResult < TMin) {

				additionResult += pow(2, wordSize); // Adding 2^W to the result if Negative Overflow occurs (to get back into the correct range)

			}




			// Checking for Positive Overflow

			else if (additionResult >= pow(2, wordSize - 1)) {

				additionResult -= pow(2, wordSize); // Subtracting 2^W to the result if Positive Overflow occurs (to get back into the correct range)


			}

	}


		/**** End of Algorithm ****/

		cout << endl << endl;

		cout << "Here is your resulting Two's Complement number after Addition: " << additionResult << endl;

		cout << endl;
		cout << endl;





		cout << "Would you like to enter another number? (Y/N): ";

		cin >> runAgain;

		cout << endl;
		cout << endl;

		if (toupper(runAgain) == 'Y') {
			runAddition = true;
		}

		else if (toupper(runAgain) == 'N') {
			runAddition = false;
		}


	}


} // end of twoComplementAddition()



void twoComplementNegation() {


	bool runNegation = true;

	char runAgain;

	while (runNegation) {


		cout << "Enter a Decimal Number to Negate: ";

		int decimalInput;


		if (!(cin >> decimalInput)) {

			cout << endl;

			cin.clear();

			cin.ignore(100, '\n');

			cout << "\n\n" << "Invalid entry. Please try again.";

			cout << endl << endl << endl;

			continue;

		}


		cout << endl;


		cout << "Enter a word size (in bits): ";

		int wordSize;


		cin >> wordSize;


		cout << endl;



		// Calculating Minimum and Maximum of Two's Compliment (TMinw and TMaxw)


		int TMin = pow(2, wordSize - 1) * (-1);

		int TMax = pow(2, wordSize - 1) - 1;



		// Storage for negation result that will be printed 


		int negationResult;





		/**** Two's Complement Negation Algorithm ****/






		/**** End of Algorithm ****/


		cout << "Here is your resulting Two's Complement number after Negation: " /* << negationResult << endl */ ;


		cout << endl;
		cout << endl;





		cout << "Would you like to enter another number? (Y/N): ";

		cin >> runAgain;

		cout << endl;
		cout << endl;

		if (toupper(runAgain) == 'Y') {
			runNegation = true;
		}

		else if (toupper(runAgain) == 'N') {
			runNegation = false;

		}

	}

}






