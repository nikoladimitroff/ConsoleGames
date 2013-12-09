ConsoleGames
============

Basic projects to be used by SE students @ FMI, SU.

# Tasks

## General

*	Create a repo @ github.com. Send me a mail with a list of all team members and the link to the repo
*	Choose / Invent your own  naming convention and explicitly write in the README.md file of your project
*	Fix all bugs currently in the game. Implement missing functionality.
*	Add a simple menu that allows the player to:
	**	Start a game
	**	See instructions about the game
	**	Show the highest score the player has achieved in this session
	**	Change settings (controls, graphics, audio) [BONUS]
	**	Exit the game
	
	The menu shall be the first thing a player sees and the player MUST have the option to return to the main menu at ANYTIME.
	
*	Add aesthetics to your game. Choose appropriate colours, ASCII art and audio.
*	Actually implement an Audio system using either `cout << '\a';` or the Windows function Beep (google it). [BONUS]
*	Implement save / load functionality. Use file streams (google them) [BONUS]
*	Do all the above adhering to the naming convention of your choice!

## Snake

*	Add different fruit for the snake to eat. Differ the fruit by their colours or symbols.
*	Add power-ups that give the snake speed / invulnerability / whatever you thing of that DON'T increase the snake's length.
*	Add different poisonous fruit that reduce the snake's size.
*	Add unpassable obstacles.
*	Fix the bug that allows the snake to cross itself.
*	Add the ability to move trough walls
*	Implement an RPG-like skill system. Have the snake gain abilities like moving trough obstacles, eliminating poisons from poisonous fruit, gaining speed,
crossing itself with no penalty and whatever else you can come up with.  [BONUS]

## Tetris

*	Add all the usual figures found in Tetris.
*	Implement collision detection.
*	Clear the floor whenever the whole row has been filled up with figures.
*	Show a ghost-like figure at the place where the currently falling figure will hit the floor
*	Implement a two-player tetris like (this one)[http://www.tetrisfriends.com/games/Battle2P/game.php] [BONUS]
*	Implement a colourized tetris. In a colourized tetris a row is cleared only if either
	**	The whole row is the same colour
	**	There is a path of the same colour that connects the pieces of the row
	
	[BONUS]

## Falling Rocks

*	Add rocks of different sizes and colours
*	Add dwarfs of different sizes and colours
*	Implement collision detection
*	Add falling power-ups - bonuses that help the player like shrinking the dwarf or speeding him up
*	Add levels to the game - it may be something as simple as increasing the speed at which rocks fall, decreasing the interval during which they spawn or slowing down the player
*	Implement an RPG-like skill system. Have the dwarf gain abilities like moving trough rocks, gaining speed, the ability to shoot down rocks, etc.  [BONUS]

## Asteroids

*	Add asteroids of different sizes and colours
*	Add space ships of different sizes and colours
*	Implement collision detection
*	Give the space ship the ability to shoot down asteroids
*	Add bosses to the game - other space ships that have their own personal arsenal and don't die on first hit.
*	Give the player health / lives, allow him to survive more than a single hit with an asteroid
*	Add power-ups - bonuses that help the player like improving his fire power or speeding him up
*	Add levels to the game - it may be something as simple as increasing the speed at which asteroids come at the player, decreasing the interval during which they spawn or slowing down the player
*	Implement an RPG-like skill system. Have the space-ship gain abilities like moving trough rocks, gaining speed, etc.  [BONUS]

## Pong

*	Implement collision detection and make the movement more realistic - let the ball move in the Y direction as well.
*	Implement an artificial intelligence smart enough to play the game. It should have 2 modes:
	**	"Ralph Wiggum mode" - the AI randomly chooses a direction to follow
	**	"Lisa Simpsons mode" - the AI always follows the balls movement and cannot ever miss the ball
*	Add points to both player for scoring
*	Add obstacles in between the two players. The obstacles should have different materials that the ball bounces differently upon contact with. For instance,
hitting a stone wall may cause the ball to move in a direction opposite of the current, while hitting an wood wall opposite to the current on only one axis and
nevertheless a half-mirror may allow the ball to pass trough it when the ball is coming from the left and not when it's coming from the right.
*	Add multiplayer support
*	Add multiple paddles to the game (more players) - 3, 4 or 8. Add multiplayer support and AI for the new paddles. [BONUS]

## The "Platform kills things" game

*	Implement collision detection. Destroy blocks upon hit. Have the player lose whenever he misses the ball.
*	Create different blocks. Some blocks should be destroyed on a single hit, others may survive longer, third may be invulnerable.
*	Give the player abilities like shooting a second ball or increasing the length of his platform whenever he successfully destroys a special kind of a block.
*	Add levels to the game - it may be something as simple as increasing the speed of the ball, spawning new blocks or slowing down the player
*	Add multiplayer support for 2, 3 or 4 players to simultaneously control more platforms each having a different ball. Show ranking. [BONUS]

