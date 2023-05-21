//************************************************************************************************************ 
// Project Header files 
//************************************************************************************************************
#include <iostream>
#include<string>
#include <string.h> 
#include<vector>
#include "Accounts.h"
#include ""


void setupProgram();
void createAccount(int& userInput, std::vector<Accounts*>& accContainer);
void showMenu(int& userInput, std::vector<Accounts*>& accContainer);

//show accounts belong to account class 
void showAccDetails(int accNum, std::vector<Accounts*>& accContainer);
void deposit(int& userInput, std::vector<Accounts*>& accContainer);
void withdraw(int& userInput, std::vector<Accounts*>& accContainer);
void showBalance(int& userInput, std::vector<Accounts*>& accContainer);
void showAccList(int& userInput, std::vector<Accounts*>& accContainer);
void deleteAcc();
void modAcc();
void exitProgram();
int cleanUserInputInt(int& userIn);
std::string cleanUserInputString(std::string userIn);



int main()
{
	int userInput = 0;
	std::vector<Accounts*> accContainer(100);
	for (std::vector<Accounts*>::iterator accIter = accContainer.begin(); accIter != accContainer.end(); ++accIter) {

		*accIter = new Accounts();
	}
	showMenu(userInput, accContainer);
}


//creates and then stores Accounts inside Account container 
void createAccount(int& userInputRef, std::vector<Accounts*>& accContainer)
{
	int accountNum = 0;
	char accountType = ' ';
	std::string accName = " ";
	std::string userInput = " ";
	std::string balanceS = " ";
	char userInputChar = ' ';
	int balance = 0;
	bool isAdmin = false;
	bool endCreateAcc = false;
	bool userInputError = false;

	//go through account container until you rech the end 
	for (std::vector<Accounts*>::iterator accIter = accContainer.begin(); accIter != accContainer.end(); ++accIter) {



		do
		{


			///prompt user to enter Account Number
			std::cout << "Enter Account Number\n";
			std::cin >> accountNum;

			//check userInput meets requirments for correct inpuit 
			accountNum = cleanUserInputInt(accountNum);

			//clear the \n caused by pressing enter from the stream 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			//prompt user to enter Account Name 
			std::cout << "Enter Account Holder Name\n";
			std::getline(std::cin, accName);
			accName = cleanUserInputString(accName);



			do
			{

				//Prompt user to Enter  account Type 
				std::cout << "Enter Type of account S:Savings/C:checkings\n";
				std::cin >> accountType;

				//clear the \n caused by pressing enter from the stream 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				/*check to see user input meets our guidline for clean input

				 P = userinput is S, Q = user input is C , r = userInput is True
				if user input eqauls S or C  it is True otherwise it is false

				 r != p v r != Q -> !r
				*/
				if (!(::toupper(accountType) == 'S' || ::toupper(accountType) == 'C'))
				{
					std::cout << "Invalid Input please choose S for savings or C for checkings \n";
				}

				/*the loop is not to end until userIput is True

				 P = userinput is S, Q = user input is C , r = userInput is True
					if user input eqauls S or C  it is True otherwise it is false

					 r != p v r != Q -> !r
				*/

			} while (!(::toupper(accountType) == 'S' || ::toupper(accountType) == 'C'));


			do
			{


				//Prompt user to make inital Deposit 
				std::cout << "Enter initial Amount \n";
				std::getline(std::cin, balanceS);

				// check to see the user has entred Interger values only
				for (size_t i = 0; i < balanceS.size(); i++)
				{
					/*User can not enter a value this not a number i.e alphabet or symbol
					P = user Input is an Interger
					Q = user Input is Valid

				Modus Ponens
				 if p -> q.
				 p
				 thefire q

				 user input is an Interger -> userInput is Valid
				 userInput is an Interger
				 therefore User Input is valid
					*/
					if (balanceS[i] > 57 || balanceS[i] < 48)
					{
						std::cout << "ERROR INVALID INPUT MUST BE A INTERGER\n\n";
						userInputError = true;
						break;
					}
					else
					{
						//convert correct userInput value to integer 
						userInputError = false;
						balance = std::stoi(balanceS);

					}

				}
				// do this while the user Input is not valid 
			} while (userInputError);
			userInputError = false;



			do
			{
				//Prompt user to enter Admin Privilege
				std::cout << "Do you require Admin privilege (Y/N) \n";
				std::cin >> userInputChar;

				/*if user input is not eqaul to Y and not eqaul to N then input is invalid
				*/
				if (::toupper(userInputChar) != 'Y' && ::toupper(userInputChar) != 'N')
				{
					std::cout << "Invalid input Value Must be Y or N\n\n";
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				/**/
			} while ((::toupper(userInputChar) != 'Y' && ::toupper(userInputChar) != 'N'));

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();

			std::cout << "Type E if you would like to exit\n";
			std::cin >> userInputChar;
			endCreateAcc = ::toupper(userInputChar) == 'E' ? true : false;

			//creates account and stores it in new allocated memory slot at which the moemory location is stored in container of pointers  
			*accIter = new Accounts(accountNum, accName, accountType, balance, isAdmin);


		} while (!endCreateAcc);

		if (!endCreateAcc == false)
		{
			break;
		}

	}


	//print accounts 
	for (std::vector<Accounts*>::iterator accIter = accContainer.begin(); accIter != accContainer.end(); ++accIter) {

		std::cout << "The account stored at memory value :" << *accIter << "\n";
		std::cout << "The account holders Name:" << (*accIter)->getAccountName() << "\n";

	}

	showMenu(userInputRef, accContainer);
}



void showMenu(int& userInput, std::vector<Accounts*>& accContainer)
{

	std::cout << "Please select an option \n\n";
	std::cout << "1: Create Account\n";
	std::cout << "2: Deposit\n";
	std::cout << "3: Withdraw\n";
	std::cout << "4: View Balance\n";
	std::cout << "5: Show all accounts\n";
	std::cout << "6: Delte Acccount \n";
	std::cout << "7: Modify Account\n";
	std::cout << "8: Exit\n";

	std::cin >> userInput;
	switch (userInput)
	{
	case 1:
		createAccount(userInput, accContainer);
		break;

	case 2:
		deposit(userInput, accContainer);
		break;

	case 3:
		withdraw(userInput, accContainer);
		break;

	case 4:
		showBalance(userInput, accContainer);
		break;

	case 5:
		showAccList(userInput, accContainer);
		break;

	case 6:
		deleteAcc();
		break;

	case 7:
		modAcc();
		break;

	case 8:
		exitProgram();
		break;

	default:
		break;
	}

}

void showAccDetails(int accNum)
{
}

void deposit(int& userInput, std::vector<Accounts*>& accContainer)
{
	do
	{
		std::cout << "Type in your account Number\n";

		/*Read userInput if the userInput is an interger the cin fail function will return
		false if not it will return true telling us the data the use has entered
		does not match the one we requested*/
		std::cin >> userInput;

		if (std::cin.fail())
		{
			std::cout << "Error Invalid input Try again\n";
			//clear any error flags then prompt user to enter Account number in Interger form
			std::cin.clear();
			// Discard any input in stream  before taking new  input
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> userInput;

		}

		//Discard any input that might have been left in the stream 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (std::cin.fail());

	//retreive users account by using account number
	for (std::vector<Accounts*>::iterator accIter = accContainer.begin(); accIter != accContainer.end(); ++accIter) {

		if (userInput == (*accIter)->getAccountNum())
		{
			int deposit = 0;
			do
			{

				//prompt user to deposit amount 
				std::cout << "How much would you like to deposit\n";
				std::cin >> deposit;

				if (std::cin.fail())
				{
					std::cout << "Error Invalid input Try again\n";
					//clear any error flags then prompt user to enter Account number in Interger form
					std::cin.clear();
					// Discard any input in stream  before taking new  input
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> deposit;

				}

				//Discard any input that might have been left in the stream 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			} while (std::cin.fail());

			//store deposit in users account and out put thier new balance 
			(*accIter)->deposit(deposit);
			std::cout << "your new balance is" << (*accIter)->getBalance() << "\n";
		}
	}
	showMenu(userInput, accContainer);


}

//allows user to make withdrws from thier account 
void withdraw(int& userInput, std::vector<Accounts*>& accContainer)
{
	int withdraw = 0;
	std::string accNum("");
	char accNumTemp[256];
	bool accExists = false;
	bool inputisValid = false;
	int accNumInt;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	do
	{
		

		//prompt user to enter account number 
		std::cout << "Type in your account Number\n";
		std::getline(std::cin, accNum);

		//Convert string input into Char array 
		for (size_t i = 0; i < accNum.length(); i++)
		{
			//fill char array elements with the string values until each value in the string exists in a element in the char array 
			accNumTemp[i] = accNum[i];
		}

		//check to see if the input is valid
		for (size_t i = 0; i < accNum.length(); i++)
		{
			//check to see if user input is a number between 0-9
			if (accNumTemp[i] >= '0' && accNumTemp[i] <= '9')
			{

				//std::cout << "The value is a number \n\n";
				inputisValid = true;
				std::cout << "Input valid\n";
				//convert the string version of account number into the interger version 
				accNumInt = std::stoi(accNum);

				for (std::vector<Accounts*>::iterator accIter = accContainer.begin(); accIter != accContainer.end(); ++accIter) {

					if (accNumInt == (*accIter)->getAccountNum())
					{
						std::cout << "Account Exists\n";
						inputisValid = true;
					}
					else
					{
						std::cout << "Account Does Not Exist\n";
						inputisValid = false;
						break;
					}
				}
			}
			else
			{
				/*output error message if input is not a numer
				and end loop since the input is not clean */
				std::cout << "Invalid Input please make sure the input is a number consiting of the follwing characters 0-9\n\n";
				inputisValid = false;
				break;
			}
		}

		//extracts charecters from the input sequence and discards them until the \n(Enter Button) char has been entred 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (!inputisValid);



	//this loops checks to see if the user has entered valid input and if the account number exist 
	/*do
	{
		//if the user has entred invalid data or the accounot does not exist out put error message
		while (std::cin.fail() || !accExists)
		{
			//
			if (!accExists) std::cout << "Account does not exist\n";
			std::cout << "Error Input is invalid please enter an Interger value \n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> userInput;
			if (std::cin.fail()) std::cout << "FAIL\n";

			for (std::vector<Accounts*>::iterator accIter = accContainer.begin(); accIter != accContainer.end(); ++accIter) {

				if (userInput == (*accIter)->getAccountNum())
				{
					accExists = true;
					break;
				}
				else
				{
					accExists = false;
				}
			}
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (!accExists);
	*/


	for (std::vector<Accounts*>::iterator accIter = accContainer.begin(); accIter != accContainer.end(); ++accIter) {

		if (userInput == (*accIter)->getAccountNum())
		{
			std::cout << "How much would you like to Withdraw\n";
			std::cin >> withdraw;

			do
			{



				if (std::cin.fail())
				{
					std::cout << "Error Input is invalid please enter an Interger value \n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> withdraw;
				}

			} while (std::cin.fail());

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			(*accIter)->withdraw(withdraw);
			std::cout << "your new balance is" << (*accIter)->getBalance() << "\n";
		}


	}
	showMenu(userInput, accContainer);
}

void showBalance(int& userInput, std::vector<Accounts*>& accContainer)
{
	std::cout << "Type in your account Number\n";
	std::cin >> userInput;
	userInput = cleanUserInputInt(userInput);
	for (std::vector<Accounts*>::iterator accIter = accContainer.begin(); accIter != accContainer.end(); ++accIter) {

		if (userInput == (*accIter)->getAccountNum())
		{
			std::cout << "Your balance is " << (*accIter)->getBalance() << "\n";
		}
	}
	showMenu(userInput, accContainer);
}

void showAccList(int& userInput, std::vector<Accounts*>& accContainer)
{
	std::cout << "Type in your account Number\n";
	std::cin >> userInput;
	userInput = cleanUserInputInt(userInput);
	for (std::vector<Accounts*>::iterator accIter = accContainer.begin(); accIter != accContainer.end(); ++accIter) {

		std::cout << "AccountNum: " << (*accIter)->getAccountNum() << "AccountName:" << (*accIter)->getAccountName() << "\n";
	}
	showMenu(userInput, accContainer);
}

void deleteAcc()
{
}

void modAcc()
{
}

void exitProgram()
{
	system("pause");
}

//function cleanUserInputint needs to be rectified use accept value as string for error checking then return clean input as converted string to int value.
//function makes sure the input user has entred is of interger type 
int cleanUserInputInt(int& userIn)
{

	// this codition checks to see if the  cin stream has failed which is what it does when user enters non integer type input
	if (std::cin.fail())
	{
		do
		{
			//using clear we get rid of the fail flag ans using ignore we to throw away anthing in the inputStream 
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Incorrect Input Please Try again input  has to be an interger value\n";
			std::cin >> userIn;

			//loop makes sure we do it until input is correct 
		} while (!std::cin);

	}
	//returns clean userinput 
	return userIn;
}


std::string cleanUserInputString(std::string userIn)
{
	bool inputIsValid = false;
	do
	{
		for (size_t i = 0; i < userIn.size(); i++)
		{

			if (!(std::isalpha(userIn[i])))
			{
				inputIsValid = false;
				std::cout << "Incorrect Input, Input can only contain Alphabetical letters\n";
				std::getline(std::cin, userIn);
				break;
			}
			else
			{
				inputIsValid = true;
			}
		}


	} while (!inputIsValid);
	return userIn;
}
