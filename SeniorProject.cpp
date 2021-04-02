
#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

#include "olcConsoleGameEngine.h"


class MatthewYanzer_SeniorProject : public olcConsoleGameEngine
{
public:

	MatthewYanzer_SeniorProject()
	{
		m_sAppName = L"Senior Project";
	}

	virtual bool OnUserCreate()
	{
		//the map of the level
		map += L"#############F#############";//1
		map += L"#4............G..........1#";//2  1 1
		map += L"#.############.##########.#";//3
		map += L"#G...1##4...1#.#4...G..1#.#";//4
		map += L"#.###.##.###.#.#.#H#.##.#.#";//5
		map += L"#.###.##.###.#.#.###.##.#.#";//6
		map += L"#.###.##.###.#.#.###.##.#.#";//7
		map += L"#.##A.##.###.#G.G###.##.#.#";//8
		map += L"#.###.##.###.#.#.##B.##.#.#";//9
		map += L"#.###.##.#H#.#.#.###.##.#.#";//10
		map += L"#G...2##3...G#.#3...G..2#.#";//11
		map += L"#.##########.#.##########.#";//12
		map += L"#G..........2#3..........G#";//13
		map += L"#.#######################.E";//14
		map += L"#G..........1#4..........G#";//15
		map += L"#.##########.#.##########.#";//16
		map += L"#.#4..G...1#.#G...1##4...G#";//17
		map += L"#.#.##.###.#.#.###.##.###.#";//18
		map += L"#.#.##.###.#.#.###.##.###.#";//19
		map += L"#.#.##.H##.#.#.###.##.S.#.#";//20
		map += L"#.#.##.###G.G#.###.##.###.#";//21
		map += L"#.#.#C.###.#.#.##D.##.###.#";//22
		map += L"#.#.##.###.#.#.###.##.#H#.#";//23
		map += L"#.#3..G...2#.#G...2##3...G#";//24
		map += L"#.##########.#.##########.#";//25
		map += L"#3..........G.G..........2#";//26
		map += L"###########################";//27
		

		//assigning sprite variables to their cooresponding sprites. The wstring in parenthesis is the location of the sprite in your computer's files
		spriteWall = new olcSprite(L"../ConsoleApplication2/fps_wall.spr");
		spriteLamp = new olcSprite(L"../ConsoleApplication2/fps_lamp.spr");
		spriteFireBall = new olcSprite(L"../ConsoleApplication2/fps_fireball.spr");
		spriteExit = new olcSprite(L"../ConsoleApplication2/fps_exit.spr");
		spriteVending = new olcSprite(L"../ConsoleApplication2/fps_vending.spr");
		spriteAlarm = new olcSprite(L"../ConsoleApplication2/fps_alarm.spr");
		spriteVending2 = new olcSprite(L"../ConsoleApplication2/fps_vending2.spr");
		spriteThreat = new olcSprite(L"../ConsoleApplication2/fps_threat.spr");
		spriteHide = new olcSprite(L"../ConsoleApplication2/fps_hide.spr");
		spriteSecret = new olcSprite(L"../ConsoleApplication2/fps_secret.spr");
		spriteKey = new olcSprite(L"../ConsoleApplication2/fps_key.spr");
		spriteSword = new olcSprite(L"../ConsoleApplication2/fps_sword.spr");
		fDepthBuffer = new float[ScreenWidth()];

		return true;
	}

virtual bool OnUserUpdate(float fElapsedTime)
{	
	//This represents the GAME OVER screen and displays it whenever the player is caught by the threat.
	srand(time(NULL));
	if (isTutorialing == true)
	{
		while (isTutorialing == true)
		{
			for (int x = 0; x < ScreenWidth(); x++)
			{
				for (int y = 0; y < ScreenHeight(); y++)
				{
					Draw(x, y, PIXEL_SOLID, FG_CYAN);
				}
			}

			wstring a = L"Hold the F key while playing to turn on your flashlight.";
			wstring b = L"Releasing the F key turns your flashlight off.";
			wstring c = L"Press E while in front of a vending machine to look for change.";
			wstring d = L"Press E while on top of an emergency pole to ward off the threat if he is near.";
			wstring e = L"You can also press E to pick up floating keys, open the blue wall, and pick up the sword.";
			wstring f = L"Run into walls labeled HIDE to hide from the threat.";
			wstring g = L"Press M to open up your map and keep track of how much change you've found.";
			wstring h = L"The green moving dot on the map is you.";
			wstring i = L"The blue moving dot is the key.";
			wstring j = L"The red moving dot is the threat.";
			wstring k = L"Press N to put your map away.";
			wstring l = L"Press B to return to the main menu.";
			
			DrawString(25, 20, a);
			DrawString(25, 22, b);
			DrawString(25, 24, c);
			DrawString(25, 26, d);
			DrawString(25, 28, e);
			DrawString(25, 30, f);
			DrawString(25, 32, g);
			DrawString(25, 34, h);
			DrawString(25, 36, i);
			DrawString(25, 38, j);
			DrawString(25, 40, k);
			DrawString(25, 42, l);
			if (m_keys[L'B'].bHeld)
			{
				isTutorialing = false;
				isStarting = true;
			}

			return true;
		}
	}
	
	if (isLosing == true)
	{
		while (isLosing == true)
		{
			//Sets the background of the screen to plain red.
			for (int x = 0; x < ScreenWidth(); x++)
			{
				for (int y = 0; y < ScreenHeight(); y++)
				{
					Draw(x, y, PIXEL_SOLID, FG_RED);
				}
			}

			//Strings to be displayed
			wstring title = L"You were caught!";
			wstring instA = L"You Lost!";
			wstring instB = L"Press R to exit to main menu";

			//Displaying the above strings
			DrawString(50, 50, title);
			DrawString(50, 51, instA);
			DrawString(50, 52, instB);

			//If the R key is pushed, the game's variables are reset and the Main Menu screen displays.
			if (m_keys[L'R'].bHeld)
			{
				isLosing = false;
				isStarting = true;
				fPlayerX = 1.5f;
				fPlayerY = 1.5;
				fPlayerA = 0.0f;

				fThreatX = 25.5f;
				fThreatY = 25.5f;
				fKeyX = 25.5f;
				fKeyY = 25.5f;
				north = false;
				south = false;
				east = true;
				west = false;
				if (map[535] == 'Q')
				{
					map[535] = 'S';
				}
				moneyCollected = 0.00;
				hasSoda = false;
				hasKey = false;
				hasSword = false;
				first = true;
				second = true;
				third = true;
				fourth = true;
				one = true;
				two = true;
				three = true;
				four = true;
				isPatrolling = true;
				change = true;
			}

			return true;
		}
	}

	//This represents the Victory screen and displays it when the player accomplishes the goal of the game without getting caught.
	if (isWinning == true)
	{
		while (isWinning == true)
		{
			//The screen's background displays a plain yellow color.
			for (int x = 0; x < ScreenWidth(); x++)
			{
				for (int y = 0; y < ScreenHeight(); y++)
				{
					Draw(x, y, PIXEL_SOLID, FG_YELLOW);
				}
			}
			
			//The strings to be displayed to the screen
			wstring title = L"Congratulations!";
			wstring instA = L"You Won!";
			wstring secret = L"You slayed the abomination!";
			wstring instB = L"Press R to exit to main menu";

			//Displaying the above three strings on the screen
			if (hasSword == false)
			{
				DrawString(50, 50, title);
				DrawString(50, 51, instA);
				DrawString(50, 52, instB);
			}
			else
			{
				DrawString(50, 50, title);
				DrawString(50, 51, secret);
				DrawString(50, 52, instB);
			}
			

			//If the R key is pushed, the game's variables are reset and the Main Menu screen displays.
			if (m_keys[L'R'].bHeld)
			{
				isWinning = false;
				isStarting = true;
				fPlayerX = 1.5f;
				fPlayerY = 1.5f;
				fPlayerA = 0.0f;

				fThreatX = 25.5f;
				fThreatY = 25.5f;
				fKeyX = 25.5f;
				fKeyY = 25.5f;
				north = false;
				south = false;
				east = true;
				west = false;
				if (map[535] == 'Q')
				{
					map[535] = 'S';
				}
				moneyCollected = 0.00;
				hasSoda = false;
				hasKey = false;
				hasSword = false;
				first = true;
				second = true;
				third = true;
				fourth = true;
				one = true;
				two = true;
				three = true;
				four = true;
				isPatrolling = true;
				change = true;
			}

			return true;
		}
	}

	//This represents the Main Menu screen and displays it whenever the player starts the game or restarts the game.
	if (isStarting == true)
	{
		while (isStarting == true)
		{
			//The background of this screen displays a plain blue color.
			for (int x = 0; x < ScreenWidth(); x++)
			{
				for (int y = 0; y < ScreenHeight(); y++)
				{
					Draw(x, y, PIXEL_SOLID, FG_BLUE);
				}
			}

			//The strings to be displayed
			wstring title = L"Late Night Snack";
			wstring instA = L"Press E to begin";
			wstring instB = L"Press H to read the controls";
			//Displaying the above three strings
			DrawString(50, 50, title);
			DrawString(50, 51, instA);
			DrawString(50, 52, instB);
			//If the E key is pressed, the game begins
			if (m_keys[L'E'].bHeld)
			{
				isStarting = false;
				isPlaying = true;
			}
			if (m_keys[L'H'].bHeld)
			{
				isStarting = false;
				isTutorialing = true;
			}

			return true;
		}
	}
	
	//This represents the Pause screen and displays it whenever the player pauses the game by pushing the P key
	if (isPaused == true)
	{
		while (isPaused == true)
		{
			//The background of this screen displays a plain green color
			for (int x = 0; x < ScreenWidth(); x++)
			{
				for (int y = 0; y < ScreenHeight(); y++)
				{
					Draw(x, y, PIXEL_SOLID, FG_GREEN);
				}
			}

			//The strings to be displayed
			wstring paused = L"Paused";
			wstring instA = L"Press E to Resume";
			wstring instB = L"Press R to exit to Main Menu";

			//Displaying the above three strings
			DrawString(50, 50, paused);
			DrawString(50, 51, instA);
			DrawString(50, 52, instB);

			//If the E key is pressed, the game resumes play
			if (m_keys[L'E'].bHeld)
			{
				isPaused = false;
				isPlaying = true;
			}

			//If the R key is pushed, the game's variables are reset and the Main Menu screen displays.
			if (m_keys[L'R'].bHeld)
			{
				isPaused = false;
				isStarting = true;
				fPlayerX = 1.5f;
				fPlayerY = 1.5f;
				fPlayerA = 0.0f;

				fThreatX = 25.5f;
				fThreatY = 25.5f;
				fKeyX = 25.5f;
				fKeyY = 25.5f;
				east = true;
				south = false;
				west = false;
				north = false;
				if (map[535] == 'Q')
				{
					map[535] = 'S';
				}
				moneyCollected = 0.00;
				hasSoda = false;
				hasKey = false;
				hasSword = false;
				first = true;
				second = true;
				third = true;
				fourth = true;
				one = true;
				two = true;
				three = true;
				four = true;
				isPatrolling = true;
				change = true;
			}

			return true;
		}
	}

	//This represents the game itself, giving the player a character to control, a map to move around in, an objective to complete, and a threat to avoid
	if (isPlaying == true)
	{
		while (isPlaying == true)
		{
			//This variable displays all objects within the game, including the threat, lamp posts, key, and alarm poles
			if(!hasSword && !hasKey)
			{
				listObjects = {
							{1.5f, 1.5f, 0.0f, 0.0f, false, spriteAlarm},
							{25.5f, 1.5f, 0.0f, 0.0f, false, spriteAlarm},
							{1.5f, 25.5f, 0.0f, 0.0f, false, spriteAlarm},
							{25.5f, 25.5f, 0.0f, 0.0f, false, spriteAlarm},
							{fThreatX, fThreatY, 0.0f, 0.0f, false, spriteThreat},
							{fKeyX, fKeyY, 0.0f, 0.0f, false, spriteKey},
							{fSwordX, fSwordY, 0.0f, 0.0f, false, spriteSword},
							};
			}

			else if (hasKey && !hasSword)
			{
				listObjects = {
							{1.5f, 1.5f, 0.0f, 0.0f, false, spriteAlarm},
							{25.5f, 1.5f, 0.0f, 0.0f, false, spriteAlarm},
							{1.5f, 25.5f, 0.0f, 0.0f, false, spriteAlarm},
							{25.5f, 25.5f, 0.0f, 0.0f, false, spriteAlarm},
							{fThreatX, fThreatY, 0.0f, 0.0f, false, spriteThreat},
							{fKeyX, fKeyY, 0.0f, 0.0f, true, spriteKey},
							{fSwordX, fSwordY, 0.0f, 0.0f, false, spriteSword},
				};
			}
			else
			{
							listObjects = {
							{1.5f, 1.5f, 0.0f, 0.0f, false, spriteAlarm},
							{25.5f, 1.5f, 0.0f, 0.0f, false, spriteAlarm},
							{1.5f, 25.5f, 0.0f, 0.0f, false, spriteAlarm},
							{25.5f, 25.5f, 0.0f, 0.0f, false, spriteAlarm},
							{fThreatX, fThreatY, 0.0f, 0.0f, false, spriteThreat},
							{fKeyX, fKeyY, 0.0f, 0.0f, true, spriteKey},
							{fSwordX, fSwordY, 0.0f, 0.0f, true, spriteSword},
							};
			}
			
			//If the threat and the player are occupying the same space, a GAME OVER is triggered, and the GAME OVER screen displays
			if ((int)fThreatY == (int)fPlayerY && (int)fThreatX == (int)fPlayerX && hasSword == true)
			{
				isPlaying = false;
				isWinning = true;
			}

			else if ((int)fThreatY == (int)fPlayerY && (int)fThreatX == (int)fPlayerX)
			{
				isPlaying = false;
				isLosing = true;
			}
			
			//This will determine the key's movement through the map. It's identical to the threat's patrolling behavior
			if(!hasKey)
			{
				if (map[(int)fKeyY * nMapWidth + (int)fKeyX] == '.')
				{
					if (knorth == true)
					{
						fKeyY -= .5 * 5.0f * fElapsedTime;
					}

					else if (ksouth == true)
					{
						fKeyY += .5 * 5.0f * fElapsedTime;
					}

					else if (keast == true)
					{
						fKeyX += .5 * 5.0f * fElapsedTime;
					}

					else if (kwest == true)
					{
						fKeyX -= .5 * 5.0f * fElapsedTime;
					}
				}

				//If the threat stands on a 1, this represents a corner with an entrance facing west and an entrance facing south
				else if (map[(int)fKeyY * nMapWidth + (int)fKeyX] == '1')
				{
					if (keast == true)
					{
						fKeyX = (int)fKeyX + .5;
						fKeyY += .5 * 5.0f * fElapsedTime;
						keast = false;
						ksouth = true;
					}

					else if (ksouth == true)
					{
						fKeyY += .5 * 5.0f * fElapsedTime;
					}

					else if (knorth == true)
					{
						fKeyY = (int)fKeyY + .5;
						fKeyX -= .5 * 5.0f * fElapsedTime;
						knorth = false;
						kwest = true;
					}

					else if (kwest == true)
					{
						fKeyX -= .5 * 5.0f * fElapsedTime;
					}
				}
				//If the threat stands on a 2, this represents a corner with an entrance facing west and an entrance facing north
				else if (map[(int)fKeyY * nMapWidth + (int)fKeyX] == '2')
				{
					if (ksouth == true)
					{
						fKeyY = (int)fKeyY + .5;
						fKeyX -= .5 * 5.0f * fElapsedTime;
						ksouth = false;
						kwest = true;
					}

					else if (keast == true)
					{
						fKeyX = (int)fKeyX + .5;
						fKeyY -= .5 * 5.0f * fElapsedTime;
						keast = false;
						knorth = true;
					}

					else if (knorth == true)
					{
						fKeyY -= .5 * 5.0f * fElapsedTime;
					}

					else if (kwest == true)
					{
						fKeyX -= .5 * 5.0f * fElapsedTime;
					}
				}
				//If the threat stands on a 3, this represents a corner with an entrance facing east and an entrance facing north
				else if (map[(int)fKeyY * nMapWidth + (int)fKeyX] == '3')
				{
					if (kwest == true)
					{
						fKeyX = (int)fKeyX + .5;
						fKeyY -= .5 * 5.0f * fElapsedTime;
						kwest = false;
						knorth = true;
					}

					else if (knorth == true)
					{
						fKeyY -= .5 * 5.0f * fElapsedTime;
					}

					else if (ksouth == true)
					{
						fKeyY = (int)fKeyY + .5;
						fKeyX += .5 * 5.0f * fElapsedTime;
						ksouth = false;
						keast = true;
					}
					else if (keast == true)
					{
						fKeyX += .5 * 5.0f * fElapsedTime;
					}
				}
				//If the threat stands on a 4, this represents a corner with an entrance facing east and an entrance facing south
				else if (map[(int)fKeyY * nMapWidth + (int)fKeyX] == '4')
				{
					if (kwest == true)
					{
						fKeyX = (int)fKeyX + .5;
						fKeyY += .5 * 5.0f * fElapsedTime;
						kwest = false;
						ksouth = true;
					}

					else if (ksouth == true)
					{
						fKeyY += .5 * 5.0f * fElapsedTime;
					}
					else if (knorth == true)
					{
						fKeyY = (int)fKeyY + .5;
						fKeyX += .5 * 5.0f * fElapsedTime;
						knorth = false;
						keast = true;
					}
					else if (keast == true)
					{
						fKeyX += .5 * 5.0f * fElapsedTime;
					}
				}
				//If the threat stands on a G, this represents a three point intersection in any orthogonal orientation
				else if (map[(int)fKeyY * nMapWidth + (int)fKeyX] == 'G')
				{
					//This represents an intersection with the wall facing north
					if (map[((int)fKeyY - 1) * nMapWidth + (int)fKeyX] == '#')
					{
						if (kisDeciding == true && knorth == true)
						{
							fKeyY = (int)fKeyY + .5;

							int kresult = rand() % 2 + 1;

							if (kresult == 1)
							{
								fKeyX += .5 * 5.0f * fElapsedTime;
								keast = true;
								knorth = false;
								kisDeciding = false;
							}
							else if (kresult == 2)
							{
								fKeyX -= .5 * 5.0f * fElapsedTime;
								kwest = true;
								knorth = false;
								kisDeciding = false;
							}
						}

						else if (kisDeciding == true && keast == true)
						{
							fKeyX = (int)fKeyX + .5;

							int kresult = rand() % 2 + 1;

							if (kresult == 1)
							{
								fKeyY += .5 * 5.0f * fElapsedTime;
								ksouth = true;
								keast = false;
								kisDeciding = false;
							}
							else if (kresult == 2)
							{
								fKeyX += .5 * 5.0f * fElapsedTime;
								kisDeciding = false;
							}
						}
						else if (kisDeciding == true && kwest == true)
						{
							fKeyX = (int)fKeyX + .5;

							int kresult = rand() % 2 + 1;

							if (kresult == 1)
							{
								fKeyY += .5 * 5.0f * fElapsedTime;
								ksouth = true;
								kwest = false;
								kisDeciding = false;
							}
							else if (kresult == 2)
							{
								fKeyX -= .5 * 5.0f * fElapsedTime;
								kisDeciding = false;
							}
						}
						else
						{
							if (ksouth == true)
							{
								fKeyY += .5 * 5.0f * fElapsedTime;
							}
							else if (keast == true)
							{
								fKeyX += .5 * 5.0f * fElapsedTime;
							}
							else if (kwest == true)
							{
								fKeyX -= .5 * 5.0f * fElapsedTime;
							}
						}

					}
					//This represents an intersection with the wall facing east
					else if (map[(int)fKeyY * nMapWidth + ((int)fKeyX + 1)] == '#')
					{
						if (kisDeciding == true && keast == true)
						{
							fKeyX = (int)fKeyX + .5;

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fKeyY -= .5 * 5.0f * fElapsedTime;
								knorth = true;
								keast = false;
								kisDeciding = false;
							}
							else if (result == 2)
							{
								fKeyY += .5 * 5.0f * fElapsedTime;
								ksouth = true;
								keast = false;
								kisDeciding = false;
							}
						}

						else if (kisDeciding == true && ksouth == true)
						{
							fKeyY = (int)fKeyY + .5;

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fKeyX -= .5 * 5.0f * fElapsedTime;
								kwest = true;
								ksouth = false;
								kisDeciding = false;
							}
							else if (result == 2)
							{
								fKeyY += .5 * 5.0f * fElapsedTime;
								kisDeciding = false;
							}
						}
						else if (kisDeciding == true && knorth == true)
						{
							fKeyY = (int)fKeyY + .5;

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fKeyX -= .5 * 5.0f * fElapsedTime;
								kwest = true;
								knorth = false;
								kisDeciding = false;
							}
							else if (result == 2)
							{
								fKeyY -= .5 * 5.0f * fElapsedTime;
								kisDeciding = false;
							}
						}
						else
						{
							if (knorth == true)
							{
								fKeyY -= .5 * 5.0f * fElapsedTime;
							}
							else if (ksouth == true)
							{
								fKeyY += .5 * 5.0f * fElapsedTime;
							}
							else if (kwest == true)
							{
								fKeyX -= .5 * 5.0f * fElapsedTime;
							}
						}
					}
					//This represents an intersection with the wall facing south
					else if (map[((int)fKeyY + 1) * nMapWidth + (int)fKeyX] == '#')
					{
						if (kisDeciding == true && ksouth == true)
						{
							fKeyY = (int)fKeyY + .5;

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fKeyX += .5 * 5.0f * fElapsedTime;
								keast = true;
								ksouth = false;
								kisDeciding = false;
							}
							else if (result == 2)
							{
								fKeyX -= .5 * 5.0f * fElapsedTime;
								kwest = true;
								ksouth = false;
								kisDeciding = false;
							}
						}

						else if (kisDeciding == true && keast == true)
						{
							fKeyX = (int)fKeyX + .5;

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fKeyY -= .5 * 5.0f * fElapsedTime;
								knorth = true;
								keast = false;
								kisDeciding = false;
							}
							else if (result == 2)
							{
								fKeyX += .5 * 5.0f * fElapsedTime;
								kisDeciding = false;
							}
						}

						else if (kisDeciding == true && kwest == true)
						{
							fKeyX = (int)fKeyX + .5;

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fKeyY -= .5 * 5.0f * fElapsedTime;
								knorth = true;
								kwest = false;
								kisDeciding = false;
							}
							else if (result == 2)
							{
								fKeyX -= .5 * 5.0f * fElapsedTime;
								kisDeciding = false;
							}
						}

						else
						{
							if (knorth == true)
							{
								fKeyY -= .5 * 5.0f * fElapsedTime;
							}
							else if (keast == true)
							{
								fKeyX += .5 * 5.0f * fElapsedTime;
							}
							else if (kwest == true)
							{
								fKeyX -= .5 * 5.0f * fElapsedTime;
							}
						}
					}
					//This represents an intersection with the wall facing west
					else if (map[(int)fKeyY * nMapWidth + ((int)fKeyX - 1)] == '#')
					{
						if (kisDeciding == true && kwest == true)
						{
							fKeyX = (int)fKeyX + .5;

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fKeyY -= .5 * 5.0f * fElapsedTime;
								knorth = true;
								kwest = false;
								kisDeciding = false;
							}
							else if (result == 2)
							{
								fKeyY += .5 * 5.0f * fElapsedTime;
								ksouth = true;
								kwest = false;
								kisDeciding = false;
							}
						}

						else if (kisDeciding == true && ksouth == true)
						{
							fKeyY = (int)fKeyY + .5;

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fKeyX += .5 * 5.0f * fElapsedTime;
								keast = true;
								ksouth = false;
								kisDeciding = false;
							}
							else if (result == 2)
							{
								fKeyY += .5 * 5.0f * fElapsedTime;
								kisDeciding = false;
							}
						}

						else if (kisDeciding == true && knorth == true)
						{
							fKeyY = (int)fKeyY + .5;

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fKeyX += .5 * 5.0f * fElapsedTime;
								keast = true;
								knorth = false;
								kisDeciding = false;
							}
							else if (result == 2)
							{
								fKeyY -= .5 * 5.0f * fElapsedTime;
								kisDeciding = false;
							}
						}

						else
						{
							if (knorth == true)
							{
								fKeyY -= .5 * 5.0f * fElapsedTime;
							}
							else if (ksouth == true)
							{
								fKeyY += .5 * 5.0f * fElapsedTime;
							}
							else if (keast == true)
							{
								fKeyX += .5 * 5.0f * fElapsedTime;
							}
						}
					}
				}
				//If the threat leaves a three point intersection, it is ready to make a decision when encountering another three point intersection
				if (map[(int)fKeyY * nMapWidth + (int)fKeyX] != 'G')
				{
					kisDeciding = true;
				}

			}
			//If the Player walks into the Threat's field of view, the Threat enters chase mode
			for (int i = 1; i <= 6; i++)
			{
				if (canSee == true)
				{
					if (north == true)
					{
						if (map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == '#' ||
							map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'A' ||
							map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'B' ||
							map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'C' ||
							map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'D' ||
							map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'E' ||
							map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'F' ||
							map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'H' ||
							map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'S' ||
							map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'Q')
						{
							canSee = false;
						}
						if (((int)fThreatY - i) == (int)fPlayerY && (int)fThreatX == (int)fPlayerX && canSee == true)
						{
							isPatrolling = false;
							isChasing = true;
							fChaseX = (int)fPlayerX;
							fChaseY = (int)fPlayerY;
						}
					
					}
					else if (south == true)
					{
						if (map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == '#' ||
							map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'A' ||
							map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'B' ||
							map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'C' ||
							map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'D' ||
							map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'E' ||
							map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'F' ||
							map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'H' ||
							map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'S' ||
							map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'Q')
						{
							canSee = false;
						}

						if (((int)fThreatY + i) == (int)fPlayerY && (int)fThreatX == (int)fPlayerX && canSee == true)
						{
							isPatrolling = false;
							isChasing = true;
							fChaseX = (int)fPlayerX;
							fChaseY = (int)fPlayerY;
						}
					}
					else if (east == true)
					{
						if (map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == '#' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'A' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'B' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'C' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'D' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'E' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'F' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'H' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'S' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'Q')
						{
							canSee = false;
						}

						if ((int)fThreatY == (int)fPlayerY && ((int)fThreatX + i) == (int)fPlayerX && canSee == true)
						{
							isPatrolling = false;
							isChasing = true;
							fChaseX = (int)fPlayerX;
							fChaseY = (int)fPlayerY;
						}
					}
					else if (west == true)
					{
						if (map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == '#' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'A' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'B' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'C' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'D' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'E' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'F' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'H' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'S' ||
							map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'Q')
						{
							canSee = false;
						}

						if ((int)fThreatY == (int)fPlayerY && ((int)fThreatX - i) == (int)fPlayerX && canSee == true)
						{
							isPatrolling = false;
							isChasing = true;
							fChaseX = (int)fPlayerX;
							fChaseY = (int)fPlayerY;
						}
					}
				}
				
			}

			canSee = true;

			//This represents the threat's movement habits while it sees the player, aka, while it's chasing
			if (isChasing == true)
			{
				if ((int)fChaseX != (int)fThreatX || (int)fChaseY != (int)fThreatY)
				{
					if (north == true)
					{
						fThreatY -= .5 * 5.0f * fElapsedTime;
					}
					else if (south == true)
					{
						fThreatY += .5 * 5.0f * fElapsedTime;
					}
					else if (east == true)
					{
						fThreatX += .5 * 5.0f * fElapsedTime;
					}
					else if (west == true)
					{
						fThreatX -= .5 * 5.0f * fElapsedTime;
					}
				}
				
				//Once the Threat is standing where it last saw the Player, it "looks around" to see if it can spot the Player again. If it can, it continues pursuit.
				else if ((int)fChaseX == (int)fThreatX && (int)fChaseY == (int)fThreatY)
				{
					fCheckX = fChaseX;
					fCheckY = fChaseY;
					if (north == true || south == true)
					{
						fThreatY = (int)fThreatY + .5;
					}
					else if (east == true || west == true)
					{
						fThreatX = (int)fThreatX + .5;
					}
					int check = 0;
					for (int i = 1; i <= 6; i++)
					{
						//east
						if ((int)fPlayerX > (int)fChaseX)
						{
							if ((int)fThreatY == (int)fPlayerY && ((int)fThreatX + i) == (int)fPlayerX && canSee == true)
							{
								if (map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == '#' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'A' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'B' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'C' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'D' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'E' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'F' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'H' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'S' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX + i)] == 'Q')
								{
									canSee = false;
								}

								if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] != 'H')
								{
									isPatrolling = false;
									isChasing = true;
									fChaseX = (int)fPlayerX;
									fChaseY = (int)fPlayerY;
									east = true;
									west = false;
									north = false;
									south = false;
								}
							}
						}
						//west
						else if ((int)fPlayerX < (int)fChaseX)
						{
							if ((int)fThreatY == (int)fPlayerY && ((int)fThreatX - i) == (int)fPlayerX && canSee == true)
							{
								if (map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == '#' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'A' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'B' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'C' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'D' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'E' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'F' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'H' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'S' ||
									map[(int)fThreatY * nMapWidth + ((int)fThreatX - i)] == 'Q')
									{
										canSee = false;
									}

								if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] != 'H')
								{
									isPatrolling = false;
									isChasing = true;
									fChaseX = (int)fPlayerX;
									fChaseY = (int)fPlayerY;
									east = false;
									north = false;
									south = false;
									west = true;
								}
							}
						}
						//south
						else if ((int)fPlayerY > (int)fChaseY)
						{
							if (((int)fThreatY + i) == (int)fPlayerY && (int)fThreatX == (int)fPlayerX && canSee == true)
							{
								if (map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == '#' ||
									map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'A' ||
									map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'B' ||
									map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'C' ||
									map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'D' ||
									map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'E' ||
									map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'F' ||
									map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'H' ||
									map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'S' ||
									map[((int)fThreatY + i) * nMapWidth + (int)fThreatX] == 'Q')
								{
									canSee = false;
								}

								if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] != 'H')
								{
									isPatrolling = false;
									isChasing = true;
									fChaseX = (int)fPlayerX;
									fChaseY = (int)fPlayerY;
									north = false;
									south = true;
									east = false;
									west = false;
								}
							}
						}
						//north
						else if ((int)fPlayerY < (int)fChaseY)
						{
							if (((int)fThreatY - i) == (int)fPlayerY && (int)fThreatX == (int)fPlayerX && canSee == true)
							{
								if (map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == '#' ||
									map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'A' ||
									map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'B' ||
									map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'C' ||
									map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'D' ||
									map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'E' ||
									map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'F' ||
									map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'H' ||
									map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'S' ||
									map[((int)fThreatY - i) * nMapWidth + (int)fThreatX] == 'Q')
								{
									canSee = false;
								}
								if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] != 'H')
								{
									isPatrolling = false;
									isChasing = true;
									fChaseX = (int)fPlayerX;
									fChaseY = (int)fPlayerY;
									north = true;
									south = false;
									east = false;
									west = false;
								}
							}
						}
					}
					if (fCheckX == fChaseX && fCheckY == fChaseY)
					{
						isChasing = false;
						isPatrolling = true;
					}
				}
			}
			
			//This represents the threat's movement habits while it does not see the player, aka, while it's patrolling
			if (isPatrolling == true)
			{					
				
				//If the threat is not standing on an intersection, it continues to move in the same direction that it did on the previous frame
				if (map[(int)fThreatY * nMapWidth + (int)fThreatX] == '.')
				{
					if (north == true)
					{
						fThreatY -= .5 * 5.0f * fElapsedTime;
					}

					else if (south == true)
					{
						fThreatY += .5 * 5.0f * fElapsedTime;
					}

					else if (east == true)
					{
						fThreatX += .5 * 5.0f * fElapsedTime;
					}

					else if (west == true)
					{
						fThreatX -= .5 * 5.0f * fElapsedTime;
					}
				}

				//If the threat stands on a 1, this represents a corner with an entrance facing west and an entrance facing south
				else if (map[(int)fThreatY * nMapWidth + (int)fThreatX] == '1')
				{
					if (east == true)
					{
						fThreatX = (int)fThreatX + .5;
						fThreatY += .5 * 5.0f * fElapsedTime;
						east = false;
						south = true;
					}

					else if (south == true)
					{
						fThreatY += .5 * 5.0f * fElapsedTime;
					}

					else if (north == true)
					{
						fThreatY = (int)fThreatY + .5;
						fThreatX -= .5 * 5.0f * fElapsedTime;
						north = false;
						west = true;
					}

					else if (west == true)
					{
						fThreatX -= .5 * 5.0f * fElapsedTime;
					}
				}
				//If the threat stands on a 2, this represents a corner with an entrance facing west and an entrance facing north
				else if (map[(int)fThreatY * nMapWidth + (int)fThreatX] == '2')
				{
					if (south == true)
					{
						fThreatY = (int)fThreatY + .5;
						fThreatX -= .5 * 5.0f * fElapsedTime;
						south = false;
						west = true;
					}

					else if (east == true)
					{
						fThreatX = (int)fThreatX + .5;
						fThreatY -= .5 * 5.0f * fElapsedTime;
						east = false;
						north = true;
					}

					else if (north == true)
					{
						fThreatY -= .5 * 5.0f * fElapsedTime;
					}

					else if (west == true)
					{
						fThreatX -= .5 * 5.0f * fElapsedTime;
					}
				}
				//If the threat stands on a 3, this represents a corner with an entrance facing east and an entrance facing north
				else if (map[(int)fThreatY * nMapWidth + (int)fThreatX] == '3')
				{
					if (west == true)
					{
						fThreatX = (int)fThreatX + .5;
						fThreatY -= .5 * 5.0f * fElapsedTime;
						west = false;
						north = true;
					}

					else if (north == true)
					{
						fThreatY -= .5 * 5.0f * fElapsedTime;
					}

					else if (south == true)
					{
						fThreatY = (int)fThreatY + .5;
						fThreatX += .5 * 5.0f * fElapsedTime;
						south = false;
						east = true;
					}
					else if (east == true)
					{
						fThreatX += .5 * 5.0f * fElapsedTime;
					}
				}
				//If the threat stands on a 4, this represents a corner with an entrance facing east and an entrance facing south
				else if (map[(int)fThreatY * nMapWidth + (int)fThreatX] == '4')
				{
					if (west == true)
					{
						fThreatX = (int)fThreatX + .5;
						fThreatY += .5 * 5.0f * fElapsedTime;
						west = false;
						south = true;
					}

					else if (south == true)
					{
						fThreatY += .5 * 5.0f * fElapsedTime;
					}
					else if (north == true)
					{
						fThreatY = (int)fThreatY + .5;
						fThreatX += .5 * 5.0f * fElapsedTime;
						north = false;
						east = true;
					}
					else if (east == true)
					{
						fThreatX += .5 * 5.0f * fElapsedTime;
					}
				}
				//If the threat stands on a G, this represents a three point intersection in any orthogonal orientation
				else if (map[(int)fThreatY * nMapWidth + (int)fThreatX] == 'G')
				{
					//This represents an intersection with the wall facing north
					if (map[((int)fThreatY - 1) * nMapWidth + (int)fThreatX] == '#')
					{
						if (isDeciding == true && north == true)
						{
							fThreatY = (int)fThreatY + .5;
							
							
							int result = rand() % 2 + 1;
							
							if (result == 1)
							{
								fThreatX += .5 * 5.0f * fElapsedTime;
								east = true;
								north = false;
								isDeciding = false;
							}
							else if (result == 2)
							{
								fThreatX -= .5 * 5.0f * fElapsedTime;
								west = true;
								north = false;
								isDeciding = false;
							}
						}

						else if (isDeciding == true && east == true)
						{
							fThreatX = (int)fThreatX + .5;
							

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fThreatY += .5 * 5.0f * fElapsedTime;
								south = true;
								east = false;
								isDeciding = false;
							}
							else if (result == 2)
							{
								fThreatX += .5 * 5.0f * fElapsedTime;
								isDeciding = false;
							}
						}
						else if (isDeciding == true && west == true)
						{
							fThreatX = (int)fThreatX + .5;
							

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fThreatY += .5 * 5.0f * fElapsedTime;
								south = true;
								west = false;
								isDeciding = false;
							}
							else if (result == 2)
							{
								fThreatX -= .5 * 5.0f * fElapsedTime;
								isDeciding = false;
							}
						}
						else
						{
							if (south == true)
							{
								fThreatY += .5 * 5.0f * fElapsedTime;
							}
							else if (east == true)
							{
								fThreatX += .5 * 5.0f * fElapsedTime;
							}
							else if (west == true)
							{
								fThreatX -= .5 * 5.0f * fElapsedTime;
							}
						}

					}
					//This represents an intersection with the wall facing east
					else if (map[(int)fThreatY * nMapWidth + ((int)fThreatX + 1)] == '#')
					{
						if (isDeciding == true && east == true)
						{
							fThreatX = (int)fThreatX + .5;
							

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fThreatY -= .5 * 5.0f * fElapsedTime;
								north = true;
								east = false;
								isDeciding = false;
							}
							else if (result == 2)
							{
								fThreatY += .5 * 5.0f * fElapsedTime;
								south = true;
								east = false;
								isDeciding = false;
							}
						}

						else if (isDeciding == true && south == true)
						{
							fThreatY = (int)fThreatY + .5;
							

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fThreatX -= .5 * 5.0f * fElapsedTime;
								west = true;
								south = false;
								isDeciding = false;
							}
							else if (result == 2)
							{
								fThreatY += .5 * 5.0f * fElapsedTime;
								isDeciding = false;
							}
						}
						else if (isDeciding == true && north == true)
						{
							fThreatY = (int)fThreatY + .5;
							

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fThreatX -= .5 * 5.0f * fElapsedTime;
								west = true;
								north = false;
								isDeciding = false;
							}
							else if (result == 2)
							{
								fThreatY -= .5 * 5.0f * fElapsedTime;
								isDeciding = false;
							}
						}
						else
						{
							if (north == true)
							{
								fThreatY -= .5 * 5.0f * fElapsedTime;
							}
							else if (south == true)
							{
								fThreatY += .5 * 5.0f * fElapsedTime;
							}
							else if (west == true)
							{
								fThreatX -= .5 * 5.0f * fElapsedTime;
							}
						}
					}
					//This represents an intersection with the wall facing south
					else if (map[((int)fThreatY + 1) * nMapWidth + (int)fThreatX] == '#')
					{
						if (isDeciding == true && south == true)
						{
							fThreatY = (int)fThreatY + .5;
							

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fThreatX += .5 * 5.0f * fElapsedTime;
								east = true;
								south = false;
								isDeciding = false;
							}
							else if (result == 2)
							{
								fThreatX -= .5 * 5.0f * fElapsedTime;
								west = true;
								south = false;
								isDeciding = false;
							}
						}

						else if (isDeciding == true && east == true)
						{
							fThreatX = (int)fThreatX + .5;
							

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fThreatY -= .5 * 5.0f * fElapsedTime;
								north = true;
								east = false;
								isDeciding = false;
							}
							else if (result == 2)
							{
								fThreatX += .5 * 5.0f * fElapsedTime;
								isDeciding = false;
							}
						}
						
						else if (isDeciding == true && west == true)
						{
							fThreatX = (int)fThreatX + .5;
							

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fThreatY -= .5 * 5.0f * fElapsedTime;
								north = true;
								west = false;
								isDeciding = false;
							}
							else if (result == 2)
							{
								fThreatX -= .5 * 5.0f * fElapsedTime;
								isDeciding = false;
							}
						}
						
						else
						{
							if (north == true)
							{
								fThreatY -= .5 * 5.0f * fElapsedTime;
							}
							else if (east == true)
							{
								fThreatX += .5 * 5.0f * fElapsedTime;
							}
							else if (west == true)
							{
								fThreatX -= .5 * 5.0f * fElapsedTime;
							}
						}
					}
					//This represents an intersection with the wall facing west
					else if (map[(int)fThreatY * nMapWidth + ((int)fThreatX - 1)] == '#')
					{
						if (isDeciding == true && west == true)
						{
							fThreatX = (int)fThreatX + .5;
							

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fThreatY -= .5 * 5.0f * fElapsedTime;
								north = true;
								west = false;
								isDeciding = false;
							}
							else if (result == 2)
							{
								fThreatY += .5 * 5.0f * fElapsedTime;
								south = true;
								west = false;
								isDeciding = false;
							}
						}

						else if (isDeciding == true && south == true)
						{
							fThreatY = (int)fThreatY + .5;
							

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fThreatX += .5 * 5.0f * fElapsedTime;
								east = true;
								south = false;
								isDeciding = false;
							}
							else if (result == 2)
							{
								fThreatY += .5 * 5.0f * fElapsedTime;
								isDeciding = false;
							}
						}
						
						else if (isDeciding == true && north == true)
						{
							fThreatY = (int)fThreatY + .5;
							

							int result = rand() % 2 + 1;

							if (result == 1)
							{
								fThreatX += .5 * 5.0f * fElapsedTime;
								east = true;
								north = false;
								isDeciding = false;
							}
							else if (result == 2)
							{
								fThreatY -= .5 * 5.0f * fElapsedTime;
								isDeciding = false;
							}
						}
						
						else
						{
							if (north == true)
							{
								fThreatY -= .5 * 5.0f * fElapsedTime;
							}
							else if (south == true)
							{
								fThreatY += .5 * 5.0f * fElapsedTime;
							}
							else if (east == true)
							{
								fThreatX += .5 * 5.0f * fElapsedTime;
							}
						}
					}
				}
				//If the threat leaves a three point intersection, it is ready to make a decision when encountering another three point intersection
				if (map[(int)fThreatY * nMapWidth + (int)fThreatX] != 'G')
				{
					isDeciding = true;
				}
			
			}

			//If the P key is pressed, the game is paused and the Pause screen displays
			if (m_keys[L'P'].bHeld && isPaused == false)
			{
				isPaused = true;
				isPlaying = false;
			}
			
			//If the A key is pressed, the player rotates counterclockwise
			if (m_keys[L'A'].bHeld)
				fPlayerA -= (2.0f) * fElapsedTime;

			//If the D key is pressed, the player rotates clockwise
			if (m_keys[L'D'].bHeld)
				fPlayerA += (2.0f) * fElapsedTime;

			//If the W key is pressed, the player moves forward
			if (m_keys[L'W'].bHeld)
			{
				fPlayerX += sinf(fPlayerA) * 5.0f * fElapsedTime;
				fPlayerY += cosf(fPlayerA) * 5.0f * fElapsedTime;

				if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#' ||
					map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == 'A' ||
					map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == 'B' ||
					map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == 'C' ||
					map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == 'D' ||
					map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == 'E' ||
					map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == 'F' ||
					map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == 'S')
				{
					fPlayerX -= sinf(fPlayerA) * 5.0f * fElapsedTime;
					fPlayerY -= cosf(fPlayerA) * 5.0f * fElapsedTime;
				}
			}

			//If the S key is pressed, the player moves backward
			if (m_keys[L'S'].bHeld)
			{
				fPlayerX -= sinf(fPlayerA) * 5.0f * fElapsedTime;
				fPlayerY -= cosf(fPlayerA) * 5.0f * fElapsedTime;

				if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#' ||
					map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == 'A' ||
					map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == 'B' ||
					map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == 'C' ||
					map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == 'D' ||
					map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == 'E' ||
					map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == 'F' ||
					map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == 'S')
				{
					fPlayerX += sinf(fPlayerA) * 5.0f * fElapsedTime;
					fPlayerY += cosf(fPlayerA) * 5.0f * fElapsedTime;
				}
			}

			//If the M key is pressed, the map displays if it is not displaying already
			if (m_keys[L'M'].bPressed)
			{
				displayMap = true;
			}

			//If the N key is pressed, the map stops displaying if it is displaying already
			if (m_keys[L'N'].bPressed)
			{
				displayMap = false;
			}

			//If the E key is pressed, the player can interact with different things in the game
			if (m_keys[L'E'].bHeld)
			{
				//If the player is standing adjacent to a blue vending machine and presses E, 25 cents is added to the player's money count
				//If the vending machine has already been searched by the player, nothing happens
				if (map[((int)fPlayerY + 1) * nMapWidth + (int)fPlayerX] == 'A' ||
					map[((int)fPlayerY - 1) * nMapWidth + (int)fPlayerX] == 'A' || 
					map[(int)fPlayerY * nMapWidth + ((int)fPlayerX + 1)] == 'A' || 
					map[(int)fPlayerY * nMapWidth + ((int)fPlayerX - 1)] == 'A')
				{
					if (first == true)
					{
						moneyCollected = moneyCollected + .25;
						first = false;
					}
				}
				
				if (map[((int)fPlayerY + 1) * nMapWidth + (int)fPlayerX] == 'B' ||
					map[((int)fPlayerY - 1) * nMapWidth + (int)fPlayerX] == 'B' ||
					map[(int)fPlayerY * nMapWidth + ((int)fPlayerX + 1)] == 'B' ||
					map[(int)fPlayerY * nMapWidth + ((int)fPlayerX - 1)] == 'B')
				{
					if (second == true)
					{
						moneyCollected = moneyCollected + .25;
						second = false;
					}
				}

				if (map[((int)fPlayerY + 1) * nMapWidth + (int)fPlayerX] == 'C' ||
					map[((int)fPlayerY - 1) * nMapWidth + (int)fPlayerX] == 'C' ||
					map[(int)fPlayerY * nMapWidth + ((int)fPlayerX + 1)] == 'C' ||
					map[(int)fPlayerY * nMapWidth + ((int)fPlayerX - 1)] == 'C')
				{
					if (third == true)
					{
						moneyCollected = moneyCollected + .25;
						third = false;
					}
				}

				if (map[((int)fPlayerY + 1) * nMapWidth + (int)fPlayerX] == 'D' ||
					map[((int)fPlayerY - 1) * nMapWidth + (int)fPlayerX] == 'D' ||
					map[(int)fPlayerY * nMapWidth + ((int)fPlayerX + 1)] == 'D' ||
					map[(int)fPlayerY * nMapWidth + ((int)fPlayerX - 1)] == 'D')
				{
					if (fourth == true)
					{
						moneyCollected = moneyCollected + .25;
						fourth = false;
					}
				}

				//If the player has collected at least $1.00 and has a soda in their inventory and presses E while adjacent to the exit, they win the game and the Victory screen displays
				if (map[((int)fPlayerY + 1) * nMapWidth + (int)fPlayerX] == 'E' ||
					map[((int)fPlayerY - 1) * nMapWidth + (int)fPlayerX] == 'E' ||
					map[(int)fPlayerY * nMapWidth + ((int)fPlayerX + 1)] == 'E' ||
					map[(int)fPlayerY * nMapWidth + ((int)fPlayerX - 1)] == 'E')
				{
					if (moneyCollected >= 1.00 && hasSoda == true)
					{
						isPlaying = false;
						isWinning = true;

					}
				}

				//If the player is standing adjacent to a green vending machine and presses E, a soda is added to the player's inventory
				//If the vending machine has already been searched by the player, nothing happens
				if (map[((int)fPlayerY + 1) * nMapWidth + (int)fPlayerX] == 'F' ||
					map[((int)fPlayerY - 1) * nMapWidth + (int)fPlayerX] == 'F' ||
					map[(int)fPlayerY * nMapWidth + ((int)fPlayerX + 1)] == 'F' ||
					map[(int)fPlayerY * nMapWidth + ((int)fPlayerX - 1)] == 'F')
				{
					if (moneyCollected >= 1.00)
					{
						hasSoda = true;
					}
				}

				//If the player presses E on the same space as the key, the player picks up the key
				if ((int)fPlayerX == (int)fKeyX && (int)fPlayerY == (int)fKeyY)
				{
					hasKey = true;
				}

				//If the player presses E on the same space as the sword, the player picks the sword
				if ((int)fPlayerX == (int)fSwordX && (int)fPlayerY == (int)fSwordY)
				{
					hasSword = true;
				}
				//If the plaeyr is standing adjacent to the magic field and presses E with the key, the barrier closes
				if (map[((int)fPlayerY + 1) * nMapWidth + (int)fPlayerX] == 'S' && hasKey == true)
				{
					map[((int)fPlayerY + 1) * nMapWidth + (int)fPlayerX] = 'Q';
				}
				if (map[((int)fPlayerY - 1) * nMapWidth + (int)fPlayerX] == 'S' && hasKey == true)
				{
					map[((int)fPlayerY - 1) * nMapWidth + (int)fPlayerX] = 'Q';
				}
				if (map[(int)fPlayerY * nMapWidth + ((int)fPlayerX + 1)] == 'S' && hasKey == true)
				{
					map[(int)fPlayerY * nMapWidth + ((int)fPlayerX + 1)] = 'Q';
				}
				if (map[(int)fPlayerY * nMapWidth + ((int)fPlayerX - 1)] == 'S' && hasKey == true)
				{
					map[(int)fPlayerY * nMapWidth + ((int)fPlayerX - 1)] = 'Q';
				}
			
			}

			//If the player presses the F key, their range of view increases, acting as a sort of flashlight for the player
			if (m_keys[L'F'].bHeld)
			{
				fDepth = 33;
			}
			else
			{
				fDepth = 10;
			}

			if (m_keys[L'G'].bHeld)
			{
				// If the player is standing on an alarm and the threat is six tiles away, the threat flees to the opposite corner of the map. Can only be used once per game.
				if ((int)fPlayerY == 1.0f && (int)fPlayerX == 1.0f && one == true)
				{
					for (int i = 1; i <= 6; i++)
					{
						if ((1.0f + i) == (int)fThreatY || (1.0f + i) == (int)fThreatX)
						{
							fThreatY = 25.0f;
							fThreatX = 25.0f;
							north = true;
						}
					}
					one = false;
					isChasing = false;
					isPatrolling = true;
				}

				if ((int)fPlayerY == 25.0f && (int)fPlayerX == 1.0f && two == true)
				{
					for (int i = 1; i <= 6; i++)
					{
						if ((25.0f - i) == (int)fThreatY || (1.0f + i) == (int)fThreatX)
						{
							fThreatY = 1.0f;
							fThreatX = 25.0f;
							south = true;
						}
					}
					two = false;
					isChasing = false;
					isPatrolling = true;
				}

				if ((int)fPlayerY == 1.0f && (int)fPlayerX == 25.0f && three == true)
				{
					for (int i = 1; i <= 6; i++)
					{
						if ((1.0f + i) == (int)fThreatY || (25.0f - i) == (int)fThreatX)
						{
							fThreatY = 25.0f;
							fThreatX = 1.0f;
							east = true;
						}
					}
					three = false;
					isChasing = false;
					isPatrolling = true;
				}

				if ((int)fPlayerY == 25.0f && (int)fPlayerX == 25.0f && four == true)
				{
					for (int i = 1; i <= 6; i++)
					{
						if ((25.0f - i) == (int)fThreatY || (25.0f - i) == (int)fThreatX)
						{
							fThreatY = 1.0f;
							fThreatX = 1.0f;
							west = true;
						}
					}
					one = false;
					isChasing = false;
					isPatrolling = true;
				}
			}
			
			//Displaying to the screen
			for (int x = 0; x < ScreenWidth(); x++)
			{
				// For each column, calculate the projected ray angle into world space
				float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)ScreenWidth()) * fFOV;

				float fStepSize = 0.01f;
				float fDistanceToWall = 0.0f;
				bool bHitWall = false;
				bool bBoundary = false;

				float fEyeX = sinf(fRayAngle);
				float fEyeY = cosf(fRayAngle);

				float fSampleX = 0.0f;

				while (!bHitWall && fDistanceToWall < fDepth)
				{

					fDistanceToWall += fStepSize;

					int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
					int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

					//Test if ray is out of bounds
					if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight)
					{
						bHitWall = true; //Set distance to maximum depth
						fDistanceToWall = fDepth;
					}
					else
					{
						//Ray is inbounds so test to see if the ray cell is a wall block
						if (map.c_str()[nTestY * nMapWidth + nTestX] == '#' || 
							map.c_str()[nTestY * nMapWidth + nTestX] == 'A' || 
							map.c_str()[nTestY * nMapWidth + nTestX] == 'B' ||
							map.c_str()[nTestY * nMapWidth + nTestX] == 'C' ||
							map.c_str()[nTestY * nMapWidth + nTestX] == 'D' ||
							map.c_str()[nTestY * nMapWidth + nTestX] == 'E' ||
							map.c_str()[nTestY * nMapWidth + nTestX] == 'F' ||
							map.c_str()[nTestY * nMapWidth + nTestX] == 'H' ||
							map.c_str()[nTestY * nMapWidth + nTestX] == 'S')
						{
							bHitWall = true;

							float fBlockMidX = (float)nTestX + 0.5f;
							float fBlockMidY = (float)nTestY + 0.5f;

							float fTestPointX = fPlayerX + fEyeX * fDistanceToWall;
							float fTestPointY = fPlayerY + fEyeY * fDistanceToWall;

							float fTestAngle = atan2f((fTestPointY - fBlockMidY), (fTestPointX - fBlockMidX));

							if (fTestAngle >= -3.14159f * 0.25f && fTestAngle < 3.14159f * 0.25f)
								fSampleX = fTestPointY - (float)nTestY;
							if (fTestAngle >= 3.14159f * 0.25f && fTestAngle < 3.14159f * 0.75f)
								fSampleX = fTestPointX - (float)nTestX;
							if (fTestAngle < -3.14159f * 0.25f && fTestAngle >= -3.14159f * 0.75f)
								fSampleX = fTestPointX - (float)nTestX;
							if (fTestAngle >= 3.14159f * 0.75f || fTestAngle < -3.14159f * 0.75f)
								fSampleX = fTestPointY - (float)nTestY;
						}
					}
				}

				//Calculate distance to ceiling and floor
				int nCeiling = (float)(ScreenHeight() / 2.0) - ScreenHeight() / ((float)fDistanceToWall);
				int nFloor = ScreenHeight() - nCeiling;

				fDepthBuffer[x] = fDistanceToWall;

				for (int y = 0; y < ScreenHeight(); y++)
				{
					//Displaying the ceiling
					if (y <= nCeiling)
						Draw(x, y, L' ');
					//Displaying the walls, exit, hiding spots, and vending machines
					else if (y > nCeiling && y <= nFloor)
					{
						int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
						int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);
						
						if (fDistanceToWall < fDepth && map.c_str()[nTestY * nMapWidth + nTestX] == '#')
						{
							float fSampleY = ((float)y - (float)nCeiling) / ((float)nFloor - (float)nCeiling);
							Draw(x, y, spriteWall->SampleGlyph(fSampleX, fSampleY), spriteWall->SampleColour(fSampleX, fSampleY));
						}
						else if (fDistanceToWall < fDepth && map.c_str()[nTestY * nMapWidth + nTestX] == 'E')
						{
							float fSampleY = ((float)y - (float)nCeiling) / ((float)nFloor - (float)nCeiling);
							Draw(x, y, spriteExit->SampleGlyph(fSampleX, fSampleY), spriteExit->SampleColour(fSampleX, fSampleY));
						}
						else if (fDistanceToWall < fDepth && map.c_str()[nTestY * nMapWidth + nTestX] == 'A')
						{
							float fSampleY = ((float)y - (float)nCeiling) / ((float)nFloor - (float)nCeiling);
							Draw(x, y, spriteVending->SampleGlyph(fSampleX, fSampleY), spriteVending->SampleColour(fSampleX, fSampleY));
						}
						else if (fDistanceToWall < fDepth && map.c_str()[nTestY * nMapWidth + nTestX] == 'B')
						{
							float fSampleY = ((float)y - (float)nCeiling) / ((float)nFloor - (float)nCeiling);
							Draw(x, y, spriteVending->SampleGlyph(fSampleX, fSampleY), spriteVending->SampleColour(fSampleX, fSampleY));
						}
						else if (fDistanceToWall < fDepth && map.c_str()[nTestY * nMapWidth + nTestX] == 'C')
						{
							float fSampleY = ((float)y - (float)nCeiling) / ((float)nFloor - (float)nCeiling);
							Draw(x, y, spriteVending->SampleGlyph(fSampleX, fSampleY), spriteVending->SampleColour(fSampleX, fSampleY));
						}
						else if (fDistanceToWall < fDepth && map.c_str()[nTestY * nMapWidth + nTestX] == 'D')
						{
							float fSampleY = ((float)y - (float)nCeiling) / ((float)nFloor - (float)nCeiling);
							Draw(x, y, spriteVending->SampleGlyph(fSampleX, fSampleY), spriteVending->SampleColour(fSampleX, fSampleY));
						}
						else if (fDistanceToWall < fDepth && map.c_str()[nTestY * nMapWidth + nTestX] == 'F')
						{
							float fSampleY = ((float)y - (float)nCeiling) / ((float)nFloor - (float)nCeiling);
							Draw(x, y, spriteVending2->SampleGlyph(fSampleX, fSampleY), spriteVending2->SampleColour(fSampleX, fSampleY));
						}
						else if (fDistanceToWall < fDepth && map.c_str()[nTestY * nMapWidth + nTestX] == 'H')
						{
							float fSampleY = ((float)y - (float)nCeiling) / ((float)nFloor - (float)nCeiling);
							Draw(x, y, spriteHide->SampleGlyph(fSampleX, fSampleY), spriteHide->SampleColour(fSampleX, fSampleY));
						}
						else if (fDistanceToWall < fDepth && map.c_str()[nTestY * nMapWidth + nTestX] == 'S')
						{
							float fSampleY = ((float)y - (float)nCeiling) / ((float)nFloor - (float)nCeiling);
							Draw(x, y, spriteSecret->SampleGlyph(fSampleX, fSampleY), spriteSecret->SampleColour(fSampleX, fSampleY));
						}
						else
							Draw(x, y, PIXEL_SOLID, 0);

					}
					//Displaying the floor
					else 
						Draw(x, y, PIXEL_SOLID, FG_DARK_GREEN);
				}
			}

			for (auto &object : listObjects)
			{
				//Update object physics
				object.x += object.vx * fElapsedTime;
				object.y += object.vy * fElapsedTime;

				//Check if object is inside wall - set flag for removal
				if (map.c_str()[(int)object.y * nMapWidth + (int)object.x] == '#')
					object.bRemove = true;
				//Can object be seen?
				float fVecX = object.x - fPlayerX;
				float fVecY = object.y - fPlayerY;
				float fDistanceFromPlayer = sqrt(fVecX*fVecX + fVecY * fVecY);

				//Calculate angle between objects and player's feet
				//to determine if the object is in the player's field of view

				float fEyeX = sinf(fPlayerA);
				float fEyeY = cosf(fPlayerA);
				float fObjectAngle = atan2f(fEyeY, fEyeX) - atan2f(fVecY, fVecX);
				if (fObjectAngle < -3.14159f)
					fObjectAngle += 2.0f * 3.14159f;
				if (fObjectAngle > 3.14159f)
					fObjectAngle -= 2.0f * 3.14159f;
				bool bInPlayerFOV = fabs(fObjectAngle) < fFOV / 2.0f;

				if (bInPlayerFOV && fDistanceFromPlayer >= 0.5f && fDistanceFromPlayer < fDepth && !object.bRemove)
				{
					float fObjectCeiling = (float)(ScreenHeight() / 2.0) - ScreenHeight() / ((float)fDistanceFromPlayer);
					float fObjectFloor = ScreenHeight() - fObjectCeiling;
					float fObjectHeight = fObjectFloor - fObjectCeiling;
					float fObjectAspectRatio = (float)object.sprite->nHeight / (float)object.sprite->nWidth;
					float fObjectWidth = fObjectHeight / fObjectAspectRatio;
					float fMiddleOfObject = (0.5f * (fObjectAngle / (fFOV / 2.0f)) + 0.5f) * (float)ScreenWidth();

					for (float lx = 0; lx < fObjectWidth; lx++)
					{
						for (float ly = 0; ly < fObjectHeight; ly++)
						{
							float fSampleX = lx / fObjectWidth;
							float fSampleY = ly / fObjectHeight;
							wchar_t c = object.sprite->SampleGlyph(fSampleX, fSampleY);
							int nObjectColumn = (int)(fMiddleOfObject + lx - (fObjectWidth / 2.0f));
							if (nObjectColumn >= 0 && nObjectColumn < ScreenWidth())
							{
								if (c != L' ' && fDepthBuffer[nObjectColumn] >= fDistanceFromPlayer)
								{
									Draw(nObjectColumn, fObjectCeiling + ly, c, object.sprite->SampleColour(fSampleX, fSampleY));
									fDepthBuffer[nObjectColumn] = fDistanceFromPlayer;
								}

							}
						}
					}
				}
			}

			//The string that contains the amount of money that the player has collected
			wstring money = to_wstring(moneyCollected);
			money.pop_back();
			money.pop_back();
			money.pop_back();
			money.pop_back();

			//Remove dead objects from the object list
			listObjects.remove_if([](sObject &o) { return o.bRemove; });

			//Display Map
			int otherX = 0, otherY = 0;
			if (displayMap == true)
			{
				for (int nx = 0; nx < nMapWidth; nx++)
					for (int ny = 0; ny < nMapHeight; ny++)
					{
						//If the tile is floor, display Black
						if (map[ny * nMapHeight + nx] == 'G' ||
							map[ny * nMapHeight + nx] == '1' ||
							map[ny * nMapHeight + nx] == '2' ||
							map[ny * nMapHeight + nx] == '3' ||
							map[ny * nMapHeight + nx] == '4' ||
							map[ny * nMapHeight + nx] == '.' ||
							map[ny * nMapHeight + nx] == 'Q')
						{
							Draw(ny + 1, nx + 1, PIXEL_SOLID, FG_BLACK);
						}
						//If the tile is blue vending machine, display Blue
						else if (map[ny * nMapHeight + nx] == 'A' ||
							map[ny * nMapHeight + nx] == 'B' ||
							map[ny * nMapHeight + nx] == 'C' ||
							map[ny * nMapHeight + nx] == 'D')
						{
							Draw(ny + 1, nx + 1, PIXEL_SOLID, FG_BLUE);
						}
						//If the tile is green vending machine, display Green
						else if (map[ny * nMapHeight + nx] == 'F')
						{
							Draw(ny + 1, nx + 1, PIXEL_SOLID, FG_GREEN);
						}
						//If the tile is exit, display Yellow
						else if (map[ny * nMapHeight + nx] == 'E')
						{
							Draw(ny + 1, nx + 1, PIXEL_SOLID, FG_YELLOW);
						}
						//If the tile is hiding spot, display dark blue
						else if (map[ny * nMapHeight + nx] == 'H')
						{
							Draw(ny + 1, nx + 1, PIXEL_SOLID, FG_DARK_BLUE);
						}
						//If the tile is wall, display White
						else
						{
							Draw(ny + 1, nx + 1, PIXEL_SOLID, FG_WHITE);
						}
						
						otherX = nx;
						otherY = ny;
					}
				//If the tile is Player, display Green
				Draw(1 + (int)fPlayerY, 1 + (int)fPlayerX, PIXEL_SOLID, FG_GREEN);
				//If the tile is Threat, display Red
				Draw(1 + (int)fThreatY, 1 + (int)fThreatX, PIXEL_SOLID, FG_RED);
				
				//If the tile is Key, display Cyan
				if (!hasKey)
				{
					Draw(1 + (int)fKeyY, 1 + (int)fKeyX, PIXEL_SOLID, FG_CYAN);
				}
				
				Draw(1 + (int)fSwordY, 1 + (int)fSwordX, PIXEL_SOLID, FG_CYAN);
				DrawString(otherX - 25, otherY + 3, c);
				
				Draw(otherX - 9, otherY + 3, L'$');

				DrawString(otherX - 8, otherY + 3, money);

				if (hasKey && change == true)
				{
					DrawString(otherX - 25, otherY + 5, L"You have a key!");
				}

				if (hasKey && hasSword)
				{
					DrawString(otherX - 25, otherY + 5, L"You have the Mourn Blade! Go slay the abomination!");
					change = false;
				}
				
				if (hasSoda == true)
				{
					DrawString(otherX - 25, otherY + 4, win);
				}
			}

			return true;
		}
	}
	
}
private:
	//Variables for determining the state of the game
	bool isPlaying = false;
	bool isPaused = false;
	bool isStarting = true;
	bool isWinning = false;
	bool isLosing = false;
	bool isTutorialing = false;

	//Variable for determining if the player has a soda
	bool hasSoda = false;

	//Variable for determining if the player has the key
	bool hasKey = false;

	//Variable for determining if the player has the key
	bool hasSword = false;

	//Variables for keeping track of which vending machines have been searched
	bool first = true;
	bool second = true;
	bool third = true;
	bool fourth = true;

	//Variables for keeping track of which alarm poles the Player has used
	bool one = true;
	bool two = true;
	bool three = true;
	bool four = true;

	//Variables for determining which way the Threat is facing
	bool north = false;
	bool south = false;
	bool east = true;
	bool west = false;

	//Variables for determining which way the Key is facing
	bool knorth = false;
	bool ksouth = false;
	bool keast = true;
	bool kwest = false;
	
	//Variable for determining if the Threat has decided which way to go in a three point intersection
	bool isDeciding = true;
	
	//Variable for determining if the Key has decided which way to go in a three point intersection
	bool kisDeciding = true;

	//Variable for checking if the Threat is patrolling
	bool isPatrolling = true;

	//Variable for checking if the Threat is chasing the player
	bool isChasing = false;
	
	//Variable for determining if the AI is looking at a wall
	bool canSee = true;

	//Variables for the player's coordinates and direction
	float fPlayerX = 1.5f;
	float fPlayerY = 1.5f;
	float fPlayerA = 0.0f;

	//Threat's coordinates
	float fThreatX = 25.5f;
	float fThreatY = 25.5f;

	//Key's coordinates
	float fKeyX = 25.5f;
	float fKeyY = 25.5f;

	//Sword's coordinates
	float fSwordX = 23.5f;
	float fSwordY = 19.5f;

	//Coordinates where the Threat last saw the Player
	float fChaseX = 0;
	float fChaseY = 0;

	//Coordinates for when the Threat seeks the Player
	float fCheckX = 0;
	float fCheckY = 0;

	//Varaibles for the size of the map
	int nMapHeight = 27;
	int nMapWidth = 27;

	//Variable for checking if the map is displayed to the screen
	bool displayMap;

	//Variable for changing player instructions
	bool change = true;

	float fFOV = 3.14159 / 4.0;
	
	//Variable that determines how far the player can see
	float fDepth = 15;

	//Variable that represents the map
	wstring map;
	
	//Variable that represents the amount of money that the player has
	float moneyCollected = 0.00;
	
	//displays that appear when applicable
	wstring c = L"Money Collected";
	wstring win = L"You got the soda! Now escape!";
	
	//sprites used
	olcSprite *spriteWall;
	olcSprite *spriteLamp;
	olcSprite *spriteFireBall;
	olcSprite *spriteExit;
	olcSprite *spriteVending;
	olcSprite *spriteAlarm;
	olcSprite *spriteVending2;
	olcSprite *spriteThreat;
	olcSprite *spriteHide;
	olcSprite *spriteSecret;
	olcSprite *spriteKey;
	olcSprite *spriteSword;

	float *fDepthBuffer = nullptr;

	//struct that applies to all objects in the game
	struct sObject
	{
		float x;
		float y;
		float vx;
		float vy;
		bool bRemove;
		olcSprite *sprite;
	};

	//list of the objects
	list<sObject> listObjects;
};

int main() {
	//instantiating, displaying, and running the game
	MatthewYanzer_SeniorProject game;
	game.ConstructConsole(120, 80, 8, 8);
	game.Start();
	
	return 0;
}