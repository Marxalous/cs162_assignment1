# cs162_assignment1
Oregon State University CS162 Fall 2023 Assignment 1

/* PLEASE VIEW IN CODE MODE */

+----------------+
| Score: 113/100 |
+----------------+------------------+------------+---+----------+---+-------+
| Rubric:        |                  | Full Marks |   | No Marks |   | Pts   |
+-----------------------------------+------------+---+----------+---+-------+
| Supports a game of 2 players      | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| Supports a game with 5 racks      | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| Supports a game with 5 balls on   |            |   |          |   |       |
| each rack                         | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| Supports a game with 2 starry     |            |   |          |   |       |
| balls                             | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| Correctly alternames players      | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| For each rack other than the      |            |   |          |   |       |
| money ball rack, there are 4      |            |   |          |   |       |
| 1-pt regular balls and 1 2-pt     |            |   |          |   |       |
| money ball                        | 4pt        |   | 0pt      |   | 4     |
+-----------------------------------+------------+---+----------+---+-------+
| The player is prompted to choose  |            |   |          |   |       |
| the money ball rack's position    | 4pt        |   | 0pt      |   | 4     |
+-----------------------------------+------------+---+----------+---+-------+
| The game allows the user to play  |            |   |          |   |       |
| again                             | 4pt        |   | 0pt      |   | 4     |
+-----------------------------------+------------+---+----------+---+-------+
| The score of each position / rack |            |   |          |   |       |
| is calculated correctly           | 6pt        |   | 0pt      |   | 6     |
+-----------------------------------+------------+---+----------+---+-------+
| The score of the money ball rack  |            |   |          |   |       |
| is calculated correctly           | 6pt        |   | 0pt      |   | 6     |
+-----------------------------------+------------+---+----------+---+-------+
| The total score is calculated     |            |   |          |   |       |
| correctly as the sum of all 5     |            |   |          |   |       |
| rack scores plus the scores of    |            |   |          |   |       |
| the 2 starry balls                | 6pt        |   | 0pt      |   | 6     |
+-----------------------------------+------------+---+----------+---+-------+
| Random numbers are seeded         |            |   |          |   |       |
| correctly                         | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| Correctly calculates 50% chance   |            |   |          |   |       |
| of making each shot               | 6pt        |   | 0pt      |   | 6     |
+-----------------------------------+------------+---+----------+---+-------+
| For each player, use an array to  |            |   |          |   |       |
| track the shooting result         | 10pt       |   | 0pt      |   | 10    |
+-----------------------------------+------------+---+----------+---+-------+
| Appropriate error handling        |            |   |          |   |       |
| (correct type, invalid value)     |            |   |          |   |       |
| for each user input, and          |            |   |          |   |       |
| appropriate error messages        | 4pt        |   | 0pt      |   | 4     |
+-----------------------------------+------------+---+----------+---+-------+
| Reprompts the user whenever they  |            |   |          |   |       |
| supply an invalid input           | 4pt        |   | 0pt      |   | 4     |
+-----------------------------------+------------+---+----------+---+-------+
| Displays the game scoresheet      |            |   |          |   |       |
| after each player's turn          | 4pt        |   | 0pt      |   | 4     |
+-----------------------------------+------------+---+----------+---+-------+
| Game scoresheet contains rack     |            |   |          |   |       |
| info (shots made / missed within  |            |   |          |   |       |
| each position---e.g., "XOOXM")    | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| Game scoresheet contains rack     |            |   |          |   |       |
| scores                            | 4pt        |   | 0pt      |   | 4     |
+-----------------------------------+------------+---+----------+---+-------+
| Game scoresheet contains total    |            |   |          |   |       |
| score                             | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| Shots in the scoresheet rack      |            |   |          |   |       |
| info are denoted correctly:       |            |   |          |   |       |
| "X" for miss, "O" for one point   |            |   |          |   |       |
| (regular ball), "M" for two       |            |   |          |   |       |
| points (money ball), "W" for      |            |   |          |   |       |
| three points (starry ball)        | 8pt        |   | 0pt      |   | 8     |
+-----------------------------------+------------+---+----------+---+-------+
| At the end of the game, the       |            |   |          |   |       |
| winner is correctly determined    | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| At the end of the game, the       |            |   |          |   |       |
| game prints out the winning       | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| player                            |            |   |          |   |       |
| Style: Program header that        |            |   |          |   |       |
| contains author's name,           |            |   |          |   |       |
| description, etc                  | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| Function header for each          |            |   |          |   |       |
| function, containing function's   |            |   |          |   |       |
| name, description, etc            | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| Consistent and proper spacing     |            |   |          |   |       |
| / indentation                     | 4pt        |   | 0pt      |   | 4     |
+-----------------------------------+------------+---+----------+---+-------+
| Proper use of in-line comments    | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
|                                   |            |   |          | = | 98    |
|                                   |            |   |          | / | 100   |
+-----------------------------------+------------+---+----------+---+-------+
| Extra credit:                     | Full Marks |   | No Marks |   | Pts   |
+-----------------------------------+------------+---+----------+---+-------+
| Error handling for N and          |            |   |          |   |       |
| reprompt until valid              | 3pt        |   | 0pt      |   | 3     |
+-----------------------------------+------------+---+----------+---+-------+
| The game supports N players,      |            |   |          |   |       |
| where N is determined by a user   |            |   |          |   |       |
| input, and correctly uses dynamic |            |   |          |   |       |
| arrays to keep track of players'  |            |   |          |   |       |
| shooting results / scores for all |            |   |          |   |       |
| N players                         | 12pt       |   | 0pt      |   | 12    |
+-----------------------------------+------------+---+----------+---+-------+
|                                   |            |   |          | = | 15    |
|                                   |            |   |          | / | 15    |
+-----------------------------------+------------+---+----------+---+-------+
|                                   |            |   |          | = | 113   |
|                                   |            |   |          | / | 115   |
+-----------------------------------+------------+---+----------+---+-------+
