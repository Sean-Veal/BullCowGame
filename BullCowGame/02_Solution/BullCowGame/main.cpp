/*
Console executable. Uses BullCowGame class
Acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame; //New Game Instance
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		//TODO add a game summarize
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}
void PrintIntro()
{
	// Introduce the game
	constexpr int32 WORD_LENGHT = 666; // Apofygh "magic numbers", eukolh allagh metavliths se olo to programma.
	std::cout << "Welcome to BullCowGame game!\n"
		<< "Can you guess the " << WORD_LENGHT
		<< "th letter isogram I'm thinking of? \n";
	return;
}
void PlayGame()
{
	BCGame.Reset();
	FBullCowGame BCGame; //New Game Instance
	int32 MaxTries = BCGame.GetMaxTries();
	// loop for the number of turns asking for quesses
	// TODO change from FOR to WHILE loop ince we are validating tries
	std::cout << "The Maximum number of tries is: " << MaxTries << std::endl;
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess(); // TODO make loop checking valid guesses
		// Submit valid guess to the game
		// Print numer of Bulls and Cows
		std::cout <<"Your Guess Is: "<< Guess << std::endl;
	}
}
FText GetGuess()
{
	int32 ThisCurrentTry = BCGame.GetCurrentTry();
	std::cout << "The current try is: " << ThisCurrentTry << std::endl;
	// Get a guess from the player.
	std::cout << "Please enter your Guess: ";
	FText Guess = "";
	getline(std::cin, Guess);
	return Guess;
}
bool AskToPlayAgain()
{
	std::cout << "Do You Want To Play Again? (y,n)\n";
	FText Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');


}
