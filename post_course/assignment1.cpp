/******************************************************
** Program: assignment1.cpp
** Author: Matthew McMahon
** Date: 10/15/2023
** Description: CS162 Basketball Assignment
** Input: User count, player names, money ball location, keep playing?
** Output: Required outputs
******************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

/*********************************************************************
** Function: player_count_func
** Description: Takes in the input and determines how many players are playing
** Parameters: Integer reference n
** Pre-Conditions: n, io, limits
** Post-Conditions: Asks player count, takes input for n, checks if n is an integer
*********************************************************************/
void player_count_func(int& n) {
  while (true) {
    cout << "Welcome to Basketball Game!\nHow many players? ";
    cin >> n;

    if (n > 0) {
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }

    cout << "Invalid input! Please try again.\n";
    
    cin.clear();  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

/*********************************************************************
** Function: rounds_one_thru_four
** Description: Runs the game for balls 1-4 on each rack, updating the player's score and game grid.
** Parameters: m, int reference player_score, rand_num, round, char grid, int reference round_points
** Pre-Conditions: Expects valid in;uts for m, round, and rand_num, grid[][] needs to be properly initialized, round_points needs to be set to 0
** Post-Conditions: Updates grid[][] with 'X', 'O', or 'M' if it's a money rack, the player score
*********************************************************************/
char rounds_one_thru_four(int m, int& player_score, int rand_num, int round, char grid[7][7], int& round_points) {
  int new_round = 0;
  for(int ball = 0; ball <= 3; ++ball) {
    rand_num = rand() % 2 + 1;
		
    if (rand_num == 1) {
      grid[round][ball] = 'X';
      round_points += 0;
    }
    else {
			if (m == 1 || m == 2) new_round = m;
			else if (m == 3) new_round = m + 1;
			else if (m == 4 || m == 5) new_round = m + 2;

			if (new_round == round) {
        round_points += 2;
        grid[round][ball] = 'M';
			}
			else {
				round_points += 1;
        grid[round][ball] = 'O';
			}
		}
	}

  return grid[round][3];
}

/*********************************************************************
** Function: rounds_five
** Description: Runs the game for the 5th ball on the rack, and updates the score and score card
** Parameters: int reference player_score, rand_num, round, char grid[][], int reference round_points
** Pre-Conditions: Expects valid inputs for round and rand_num, grid[][] needs to be properly initialized, round_points needs to be set to 0
** Post-Conditions: Updates grid[][] with 'X' or 'M' respectively and the players total score
*********************************************************************/
char rounds_five(int& player_score, int rand_num, int round, char grid[7][7], int& round_points) {
  for(int ball = 4; ball <= 4; ++ball) {
		rand_num = rand() % 2 + 1;
	
  	if (rand_num == 1) {
      grid[round][ball] = 'X';
      round_points += 0;
    }
		else {
			round_points += 2;
      grid[round][ball] = 'M';
		}
	}

  return grid[round][4];
}

/*********************************************************************
** Function: pos
** Description: Runs all of the rounds for the regular racks, and calculates the total score for the player after each rack
** Parameters: m, int reference player_score, rand_num, round, char grid[][]
** Pre-Conditions: Expects valid inputs for m, round and rand_num. grid[][] needs to be properly initialized, and player_score needs to be set to 0;
** Post-Conditions: Updates grid[][] within the nested functions and the player score
*********************************************************************/
char pos(int m, int& player_score, int rand_num, int round, char grid[7][7], int points) {
  rounds_one_thru_four(m, player_score, rand_num, round, grid, points);
  rounds_five(player_score, rand_num, round, grid, points);

  grid[round][5] = '|';
  player_score += points;
  grid[round][6] = points + 48;
  points = 0;

  return grid[round][4];
}

/*********************************************************************
** Function: starry
** Description: runs the starry rounds
** Parameters: int reference player_score, rand_num, ball, round, char grid[][]
** Pre-Conditions: Expects valid inputs for round, ball, and rand_num. grid[][] needs to be properly initialized.
** Post-Conditions: Updates grid[][] for the starry rounds and the players score
*********************************************************************/
char starry(int& player_score, int rand_num, int ball, int round, char grid[7][7], int round_points) {
  rand_num = rand() % 2 + 1;
	
  if (rand_num == 1) grid[round][ball] = 'X';
  else {
		round_points += 3;
    grid[round][ball] = 'W';
	}

  for (int i = 1; i < 5; ++i) grid[round][i] = ' ';

  grid[round][5] = '|';
  player_score += round_points;  
  grid[round][6] = round_points + 48;
  round_points = 0;

	return grid[round][0];
}

/*********************************************************************
** Function: the_game
** Description: Runs the game for a single player, updating their score and score card
** Parameters: m, int reference player_score, rand_num, char grid[][], string player_name[], player
** Pre-Conditions: Expects valid inputs for m, rand_num, round, ball, and player_name[]. grid[][] needs to be properly initialized
** Post-Conditions: Rund the game for whatever player it is on, updating grid[] and the player's score, and outputs what they get
*********************************************************************/
void the_game(int m, int& player_score, int& rand_num, char grid[7][7], string player_name[], int player) {
  int ball = 0;
  int round = 0;

  for (round = 1; round <= 7; ++round) {
    int points = 0;
  
    if (round == 3 || round == 5) {
      starry(player_score, rand_num, ball, round, grid, points);
      cout << "  *Starry! " << player_name[player] << " has " << player_score << " points!\n";
    }
    else {
      pos(m, player_score, rand_num, round, grid, points);

      if (round == 4) cout << "  Round " << round - 1 << "! " << player_name[player] << " has " << player_score << " points!\n";
      else if (round == 6 || round == 7) cout << "  Round " << round - 2 << "! " << player_name[player] << " has " << player_score << " points!\n";
      else cout << "  Round " << round << "! " << player_name[player] << " has " << player_score << " points!\n";
    }
  }
}

/*********************************************************************
** Function: keep_playing_func
** Description: Prompts the player to continue or quit the game
** Parameters: char reference keep playing
** Pre-Conditions: Expects a valid character 'y', 'Y', 'n', or 'N'
** Post-Conditions: Prompts the player to input a character, updates the value of keep_playing, will break the gameplay loop if 'n' or 'N' is entered, and will loop until a valid input is given
*********************************************************************/
void keep_playing_func(char& keep_playing) {
  while (true) {
    cout << "Keep playing? (y/n) ";  cin >> keep_playing;

    if (keep_playing == 'y' || keep_playing == 'Y') break;
    else if (keep_playing == 'n' || keep_playing == 'N') break;
    else cout << "Invalid input! Try again.\n" << endl;
  }
}

/*********************************************************************
** Function: print_grid
** Description: Displayed grid[][] with the results of the game
** Parameters: grid[][]
** Pre-Conditions: grid[][] needs to be properly initialized, and should be a 7x7 char grid
** Post-Conditions: Prints the game grid to the console, displays the results of each rack and type of rack
*********************************************************************/
void print_grid(char grid[7][7]) {
  cout << endl;
  for(int rack = 0; rack <= 6; ++rack) {
    if (rack <= 1) cout << "  Rack " << rack + 1 << ": ";
    else if (rack == 2 || rack == 4) cout << " *Starry: ";
    else if (rack == 3) cout << "  Rack 3: ";
    else cout << "  Rack " << rack - 1 << ": ";

    for(int ball = 0; ball <= 6; ++ball) {
      ++rack;
      cout << grid[rack][ball] << " ";
      --rack;
    }

    cout << endl;
  }
}

/*********************************************************************
** Function: start_of_the_game
** Description: runs the entirety of the code within it, and the nested functions
** Parameters: keep_playing, player, n, player_score, string player_name[], m, rand_num, grid[][], and player_scores[]
** Pre-Conditions: Expects all variables to have valid inputs and properly initialized
** Post-Conditions: Manages the loop for all players, keeps track of the player's scores and updates the array for it, displays the total points for each player at the end of the turn, and provides an option to keep playing
*********************************************************************/
void start_of_the_game(char keep_playing, int player, int n, int player_score, string player_name[], int m, int rand_num, char grid[7][7], int player_scores[]) {
  while (keep_playing == 'y' || keep_playing == 'Y') {
    for (player = 0; player < n; ++player) {

      player_score = 0;  int rack = 0;
      
      /* Money-Ball Rack Placement */
      while (true) {
        cout << endl << player_name[player] << ", where would you like to put your Money-Ball rack? (1-5): ";  cin >> m;  cout << endl;
        if (m >= 1 && m <= 5) break;
        cout << "Invalid input. Please try again.\n" << endl;
        cin.clear();  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      
      /* All 5 Rounds */
      the_game(m, player_score, rand_num, grid, player_name, player);
      
      /* Total Player Score Multi-Dim Array */
      print_grid(grid);
      
      /* Add To Player Score Card */
      cout << endl << "Total points for " << player_name[player] << " is " << player_score << endl;
      player_scores[player] += player_score;
    }	
    
    /* Keep Playing */
    keep_playing_func(keep_playing);
  }
}

/*********************************************************************
** Function: final_score_track
** Description: Displays the accumulated scores of all of the players at the end of the game
** Parameters: player_name[], player_scores[], n
** Pre-Conditions: The game needs to have ended
** Post-Conditions: Displays the final scores for each player in the order played, and provides a summary of each player's total points over all games
*********************************************************************/
void final_score_track(string player_name[], int player_scores[], int n) {
  for (int player = 0; player < n; ++player) cout << player_name[player] << " scored a total of " << player_scores[player] << " points!" << endl;
}

/*********************************************************************
** Function: high_score_track
** Description: Determines who has the high score
** Parameters: n, player_scores[], maximum, max_index
** Pre-Conditions: The game needs to have ended
** Post-Conditions: Identified the player with the highest score, and logs it in max_index, the maximum score achieved is stored in the variable maximum
*********************************************************************/
void high_score_track(int n, int player_scores[], int maximum, int& max_index) {
  for (int j = 0; j < n; ++j) {
    if (player_scores[j] > maximum) {
      maximum = player_scores[j];
      max_index = j;
    }
  }
}

/*********************************************************************
** Function: main
** Description: runs the code
** Parameters: none
** Pre-Conditions: the program is executed
** Post-Conditions: The game runs and finishes, finals scores are displayed for all players, winner is declared, memory allocated is deallocated for player names and scores
*********************************************************************/
int main() {
  
  /* Variable Declarations | Part 1 */
  int n = 0;
  
  /* RNG */
  srand((unsigned)time(0));
  
  /* Player Count */
  player_count_func(n);
  
  /* Variable Declarations | Part 2 */
  string* player_name = new string[n];
  int* player_scores = new int[n];
  int round, m, player = 1, player_score = 0, rand_num;
  char keep_playing = 'y';
  int maximum = 0, max_index = 0;  char grid[7][7];
  
  /* Set Player Scores to 0 */
  for (int k = 0; k < n; ++k) player_scores[k] = 0;
  
  /* Player Names */
  for (int player_count = 0; player_count < n; ++player_count) {
    cout << "Enter name for Player " << player_count + 1 << ": ";
    cin >> player_name[player_count];
  }

  /* Start of the Game */
  start_of_the_game(keep_playing, player, n, player_score, player_name, m, rand_num, grid, player_scores);
  
  /* Final Score Output */
  final_score_track(player_name, player_scores, n);
  
  /* Keeping Track of High Score */
  high_score_track(n, player_scores, maximum, max_index);

  cout << "The winner is " << player_name[max_index] << " with " << player_scores[max_index] << " points!" << endl;

  /* Prevent Memory Leaks */
  delete[] player_name;
  delete[] player_scores;

  return 0;
}