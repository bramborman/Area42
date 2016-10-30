#define nafurt const
#define nic NULL
#define vytvorimedatovytyp typedef
#define vypis enum
#define hromada struct
#define velikost sizeof
#define prazdnota void
#define anone bool
#define pismeno char
#define celecislo int
#define souradnice COORD
#define zavorka (
#define opacnazavorka )
#define hranatazavorka [
#define opacnahranatazavorka ]
#define chlupatazavorka {
#define opacnachlupatazavorka }
#define pokud if
#define jinak else
#define dokud while
#define delej do
#define zatim for
#define pravda true
#define nepravda false
#define prepinac switch
#define moznost case
#define pokracovat continue
#define zastavit break
#define vratitse return
#define strednik ;
#define tecka .
#define carka ,
#define sipka -> 
#define otaznik ?
#define dvojtecka :
#define plus +
#define minus -
#define procento %
#define zvetsime ++
#define zmensime --
#define plusrovnase +=
#define minusrovnase -=
#define lomitko /
#define hvezdicka *
#define vykricnik !
#define divnya &
#define rovnase =
#define vetsi >
#define mensi <
#define vetsineborovnase >=
#define mensineborovnase <=
#define je ==
#define neni !=
#define aji &&
#define nebo ||
#define vytisknemepismeno putchar
#define vytisknemesikovne printf
#define hlavni main

//#define DEBUG
#define BUFFER_NORESIZE

#define CHANGELOG_COLUMNS 50
nafurt pismeno CHANGELOG_GAME hranatazavorka  opacnahranatazavorka  hranatazavorka CHANGELOG_COLUMNS opacnahranatazavorka  rovnase
 chlupatazavorka 
	 chlupatazavorka "1 tecka 7 'A better way':" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Rewrited game engine" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Score in title" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Added new cheats" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Fixed bug with right bottom corner" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Fully removed screen flashing" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Some bugs were fixed" opacnachlupatazavorka  carka 
	 chlupatazavorka "1 tecka 6 'FISA is your hero':" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Added a little secret" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Changed controls" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Fixed screen flashing" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Improved game perzatimmance" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Some bugs were fixed" opacnachlupatazavorka  carka 
	 chlupatazavorka "1 tecka 5 'Make a way vykricnik ':" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Added borderless mode" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Better game perzatimmance" opacnachlupatazavorka  carka 
	 chlupatazavorka "1 tecka 4 'It grows':" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Game is now responsive designed" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Code were optimized" opacnachlupatazavorka  carka 
	 chlupatazavorka "1 tecka 3 'Let me pokracovat':" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Hotseat pokracovats pokud one player dies" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Added changelog" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Some bugs were fixed" opacnachlupatazavorka  carka 
	 chlupatazavorka "1 tecka 2 'Do it twice':" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Added multiplayer" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Code is more effective" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Some bugs were fixed" opacnachlupatazavorka  carka 
	 chlupatazavorka "1 tecka 1 'When meowside flies':" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Added menus" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Some bugs were fixed" opacnachlupatazavorka  carka 
	 chlupatazavorka "1 tecka 0 'First release':" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Only singleplayer" opacnachlupatazavorka  carka 
	 chlupatazavorka "- Without menus" opacnachlupatazavorka 
 opacnachlupatazavorka  strednik 

#include "unigfcs.h"

#define LENGHT_START 3
#define LENGHT_MAX LENGHT_START  plus  100

#define SLEEP_EASY 200
#define SLEEP_MEDIUM 50
#define SLEEP_HARD 30

#define SPECIAL_SPAWN rand zavorka  opacnazavorka  procento 1000000 je 53
#define SPECIAL_BONUS 3

#define NEUTRAL  minus 5
#define FULL 219

vytvorimedatovytyp vypis
 chlupatazavorka 
	BONUS carka 
	MINE
 opacnachlupatazavorka  SPECIAL strednik 

vytvorimedatovytyp hromada
 chlupatazavorka 
	pismeno direction strednik 
	souradnice position strednik 
 opacnachlupatazavorka  VECTOR strednik 

vytvorimedatovytyp hromada
 chlupatazavorka 
	celecislo active strednik 
	celecislo lastAssigned strednik 
	VECTOR vector hranatazavorka LENGHT_MAX opacnahranatazavorka  strednik 
 opacnachlupatazavorka  BEND strednik 

vytvorimedatovytyp hromada
 chlupatazavorka 
	souradnice position strednik 
	VISUAL visual strednik 
 opacnachlupatazavorka  BERRY strednik 

vytvorimedatovytyp hromada
 chlupatazavorka 
	anone collision strednik 
	celecislo active strednik 
	celecislo shown strednik 
	VECTOR first strednik 
	VECTOR last strednik 
	BEND bend strednik 
	VISUAL visual strednik 
 opacnachlupatazavorka  SNAKE strednik 

anone isSpecialShown rovnase nepravda strednik 
pismeno consoleColor hranatazavorka  opacnahranatazavorka  rovnase "color 0F" strednik 
pismeno liveTitle hranatazavorka 35 opacnahranatazavorka  rovnase  chlupatazavorka 0 opacnachlupatazavorka  strednik 
BERRY specials hranatazavorka  opacnahranatazavorka  rovnase 
 chlupatazavorka 
	 chlupatazavorka 
		 chlupatazavorka  opacnachlupatazavorka  carka   chlupatazavorka '+' carka  LightGreen opacnachlupatazavorka 
	 opacnachlupatazavorka  carka 
	
	 chlupatazavorka 
		 chlupatazavorka  opacnachlupatazavorka  carka   chlupatazavorka 207 carka  LightRed opacnachlupatazavorka 
	 opacnachlupatazavorka 
 opacnachlupatazavorka  strednik 

celecislo main zavorka  opacnazavorka  strednik 
celecislo customdpokudficulty zavorka  opacnazavorka  strednik 
anone creator zavorka nafurt celecislo SLEEP carka  nafurt anone HOTSEAT carka  nafurt anone BORDERS opacnazavorka  strednik 
prazdnota randomcolors zavorka  opacnazavorka  strednik 
prazdnota newberry zavorka BERRY  hvezdicka berry carka  nafurt anone  hvezdicka GAMEBOARD opacnazavorka  strednik 
prazdnota livetitle zavorka nafurt celecislo SCORE opacnazavorka  strednik 
prazdnota livetitle zavorka nafurt celecislo SCORE1 carka  nafurt celecislo SCORE2 opacnazavorka  strednik 
prazdnota snake zavorka nafurt celecislo SLEEP carka  nafurt anone BORDERS carka  nafurt VISUAL SNAKEVISUAL opacnazavorka  strednik 
prazdnota hotseat zavorka nafurt celecislo SLEEP carka  nafurt anone BORDERS carka  nafurt VISUAL SNAKEVISUAL opacnazavorka  strednik 

celecislo main zavorka  opacnazavorka 
 chlupatazavorka 
	initialize zavorka "Snake" carka  "v1.7 'A better way'" carka  "beta 3" carka  79 carka  24 opacnazavorka  strednik 
	mainmenu zavorka LIGHTGREEN opacnazavorka  strednik 
	
	system zavorka "cls" opacnazavorka  strednik 
	puts zavorka "Internal error has occured\nPress any key to close the game  tecka   tecka   tecka " opacnazavorka  strednik 
	getch zavorka  opacnazavorka  strednik 
	
	system zavorka "cls" opacnazavorka  strednik 
	exit zavorka 1 opacnazavorka  strednik 
 opacnachlupatazavorka 

prazdnota controls zavorka  opacnazavorka 
 chlupatazavorka 
#define CENTERING 35

	checkconsolesize zavorka  opacnazavorka  strednik 
	
	dokud zavorka pravda opacnazavorka 
	 chlupatazavorka 
		system zavorka "cls" opacnazavorka  strednik 
		
#ifdef DEBUG
	verticalcenter zavorka 9 opacnazavorka  strednik 
#else
	verticalcenter zavorka 8 opacnazavorka  strednik 
#endif
		
		center zavorka "CONTROLS" opacnazavorka  strednik 
		vytisknemesikovne zavorka "\n\n" opacnazavorka  strednik 
		
		center zavorka CENTERING carka  "Player 1:          Arrow keys\n" opacnazavorka  strednik 
		center zavorka CENTERING carka  "Player 2:          WASD\n" opacnazavorka  strednik 
		center zavorka CENTERING carka  "Pause game:        ESC\n" opacnazavorka  strednik 
		
#ifdef DEBUG
	center zavorka CENTERING carka  "Freeze:            SPACE\n" opacnazavorka  strednik 
#endif
		
		center zavorka CENTERING carka  "Menus navigation:  Arrow keys carka  ENTER carka  ESC" opacnazavorka  strednik 
		vytisknemesikovne zavorka "\n\n" opacnazavorka  strednik 
		
		center zavorka "> Back  " opacnazavorka  strednik 
		
		dokud zavorka pravda opacnazavorka 
		 chlupatazavorka 
#ifdef DEBUG
	CURSOR_RESET strednik 
	DEBUG_CHEATS strednik 
#endif
			
			temp rovnase getcheat zavorka getch zavorka  opacnazavorka  opacnazavorka  strednik 
			
			pokud zavorka temp je ENTER nebo temp je ESC opacnazavorka 
			 chlupatazavorka 
				vratitse strednik 
			 opacnachlupatazavorka 
			
			pokud zavorka checkconsolesize zavorka  opacnazavorka  opacnazavorka 
			 chlupatazavorka 
				zastavit strednik 
			 opacnachlupatazavorka 
		 opacnachlupatazavorka 
	 opacnachlupatazavorka 

#undef CENTERING
 opacnachlupatazavorka 

anone game zavorka nafurt DIFFICULTY DIFFIFULTY1 carka  nafurt anone HOTSEAT opacnazavorka 
 chlupatazavorka 
#define CENTERING 6

	checkconsolesize zavorka  opacnazavorka  strednik 
	
	celecislo dpokudficulty carka  selection rovnase 0 strednik 
	souradnice cursorPosition strednik 
	
	pokud zavorka DIFFIFULTY1 je CUSTOM opacnazavorka 
	 chlupatazavorka 
		dpokudficulty rovnase customdpokudficulty zavorka  opacnazavorka  strednik 
		
		pokud zavorka dpokudficulty je 0 opacnazavorka 
		 chlupatazavorka 
			vratitse nepravda strednik 
		 opacnachlupatazavorka 
	 opacnachlupatazavorka 
	jinak
	 chlupatazavorka 
		dpokudficulty rovnase  zavorka DIFFIFULTY1 je EASY  otaznik  SLEEP_EASY  dvojtecka   zavorka DIFFIFULTY1 je MEDIUM  otaznik  SLEEP_MEDIUM  dvojtecka  SLEEP_HARD opacnazavorka  opacnazavorka  strednik 
	 opacnachlupatazavorka 
	
	dokud zavorka pravda opacnazavorka 
	 chlupatazavorka 
		system zavorka "cls" opacnazavorka  strednik 
		
		verticalcenter zavorka 5 opacnazavorka  strednik 
		center zavorka "CHOOSE GAME MODE" opacnazavorka  strednik 
		vytisknemesikovne zavorka "\n\n" opacnazavorka  strednik 
		
		center zavorka CENTERING carka  "Normal\n" opacnazavorka  strednik 
		
		cursorPosition rovnase commonCursorPosition strednik 
		cursorPosition tecka X   minusrovnase  2 strednik 
		
		center zavorka CENTERING carka  "Borderless\n" opacnazavorka  strednik 
		vytisknemepismeno zavorka '\n' opacnazavorka  strednik 
		center zavorka CENTERING carka  "Back" opacnazavorka  strednik 
		
		dokud zavorka pravda opacnazavorka 
		 chlupatazavorka 
			
#ifdef DEBUG
	DEBUG_MAIN strednik 
#endif
			
			movecursor zavorka cursorPosition tecka X carka  cursorPosition tecka Y  plus  selection  plus   zavorka selection je 2  otaznik  1  dvojtecka  0 opacnazavorka  opacnazavorka  strednik 
			vytisknemepismeno zavorka '>' opacnazavorka  strednik 
			
			temp rovnase getarrow zavorka getcheat zavorka getch zavorka  opacnazavorka  opacnazavorka  opacnazavorka  strednik 
			
			movecursor zavorka cursorPosition tecka X carka  cursorPosition tecka Y  plus  selection  plus   zavorka selection je 2  otaznik  1  dvojtecka  0 opacnazavorka  opacnazavorka  strednik 
			vytisknemepismeno zavorka ' ' opacnazavorka  strednik 
			
			pokud zavorka  zavorka temp je ENTER aji selection je 2 opacnazavorka  nebo temp je ESC opacnazavorka 
			 chlupatazavorka 
				vratitse nepravda strednik 
			 opacnachlupatazavorka 
			jinak pokud zavorka temp je ENTER opacnazavorka 
			 chlupatazavorka 
				pokud zavorka creator zavorka dpokudficulty carka  HOTSEAT carka  selection je 0  otaznik  pravda  dvojtecka  nepravda opacnazavorka  opacnazavorka 
				 chlupatazavorka 
					vratitse pravda strednik 
				 opacnachlupatazavorka 
				
				zastavit strednik 
			 opacnachlupatazavorka 
			jinak pokud zavorka temp je UP aji selection neni 0 opacnazavorka 
			 chlupatazavorka 
				selection zmensime  strednik 
			 opacnachlupatazavorka 
			jinak pokud zavorka temp je DOWN aji selection neni 2 opacnazavorka 
			 chlupatazavorka 
				selection zvetsime  strednik 
			 opacnachlupatazavorka 
			
			pokud zavorka checkconsolesize zavorka  opacnazavorka  opacnazavorka 
			 chlupatazavorka 
				zastavit strednik 
			 opacnachlupatazavorka 
		 opacnachlupatazavorka 
	 opacnachlupatazavorka 

#undef CENTERING
 opacnachlupatazavorka 

celecislo customdpokudficulty zavorka  opacnazavorka 
 chlupatazavorka 
#define CENTERING 7
#define MIN 10
#define MAX 300
#define STEP 5

	checkconsolesize zavorka  opacnazavorka  strednik 
	
	celecislo selection rovnase 0 strednik 
	celecislo wheelSelection rovnase MIN strednik 
	souradnice wheelCursorPosition carka  cursorPosition strednik 
	
	dokud zavorka pravda opacnazavorka 
	 chlupatazavorka 
		system zavorka "cls" opacnazavorka  strednik 
		
		verticalcenter zavorka 7 opacnazavorka  strednik 
		center zavorka "CHOOSE CUSTOM DELAY" opacnazavorka  strednik 
		vytisknemesikovne zavorka "\n\n" opacnazavorka  strednik 
		
		getcurrentcursorposition zavorka  divnya wheelCursorPosition opacnazavorka  strednik 
		
		vytisknemesikovne zavorka "\n\n\n" opacnazavorka  strednik 
		center zavorka CENTERING carka  "Confirm\n" opacnazavorka  strednik 
		
		cursorPosition rovnase commonCursorPosition strednik 
		cursorPosition tecka X   minusrovnase  2 strednik 
		
		center zavorka CENTERING carka  "Back" opacnazavorka  strednik 
		
		dokud zavorka pravda opacnazavorka 
		 chlupatazavorka 
			
#ifdef DEBUG
	DEBUG_MAIN strednik 
	vytisknemesikovne zavorka "\nwheelSelection dvojtecka  %3d | " carka  wheelSelection opacnazavorka  strednik 
	vytisknemesikovne zavorka consoleSize tecka X mensi 100  otaznik  "wheelCursorPosition dvojtecka  %2d %2d"  dvojtecka  "wheelCursorPosition dvojtecka  %3d %3d" carka  wheelCursorPosition tecka X carka  wheelCursorPosition tecka Y opacnazavorka  strednik 
#endif
			
			wheelselection zavorka wheelCursorPosition carka  wheelSelection carka  MIN carka  MAX carka  STEP opacnazavorka  strednik 
			
			movecursor zavorka cursorPosition tecka X carka  cursorPosition tecka Y  plus  selection opacnazavorka  strednik 
			vytisknemepismeno zavorka '>' opacnazavorka  strednik 
			
			temp rovnase getarrow zavorka getcheat zavorka getch zavorka  opacnazavorka  opacnazavorka  opacnazavorka  strednik 
			
			movecursor zavorka cursorPosition tecka X carka  cursorPosition tecka Y  plus  selection opacnazavorka  strednik 
			vytisknemepismeno zavorka ' ' opacnazavorka  strednik 
			
			pokud zavorka  zavorka temp je ENTER aji selection je 1 opacnazavorka  nebo temp je ESC opacnazavorka 
			 chlupatazavorka 
				vratitse 0 strednik 
			 opacnachlupatazavorka 
			jinak pokud zavorka temp je ENTER opacnazavorka 
			 chlupatazavorka 
				vratitse wheelSelection strednik 
			 opacnachlupatazavorka 
			jinak pokud zavorka temp je UP aji selection neni 0 opacnazavorka 
			 chlupatazavorka 
				selection zmensime  strednik 
			 opacnachlupatazavorka 
			jinak pokud zavorka temp je DOWN aji selection neni 1 opacnazavorka 
			 chlupatazavorka 
				selection zvetsime  strednik 
			 opacnachlupatazavorka 
			jinak pokud zavorka temp je LEFT opacnazavorka 
			 chlupatazavorka 
				wheelSelection   minusrovnase  STEP strednik 
				
				pokud zavorka wheelSelection je MIN  minus  STEP opacnazavorka 
				 chlupatazavorka 
					wheelSelection rovnase MAX strednik 
				 opacnachlupatazavorka 
			 opacnachlupatazavorka 
			jinak pokud zavorka temp je RIGHT opacnazavorka 
			 chlupatazavorka 
				wheelSelection  plusrovnase  STEP strednik 
				
				pokud zavorka wheelSelection je MAX  plus  STEP opacnazavorka 
				 chlupatazavorka 
					wheelSelection rovnase MIN strednik 
				 opacnachlupatazavorka 
			 opacnachlupatazavorka 
			
			pokud zavorka checkconsolesize zavorka  opacnazavorka  opacnazavorka 
			 chlupatazavorka 
				zastavit strednik 
			 opacnachlupatazavorka 
		 opacnachlupatazavorka 
	 opacnachlupatazavorka 

#undef CENTERING
#undef MIN
#undef MAX
#undef STEP
 opacnachlupatazavorka 

anone creator zavorka nafurt celecislo SLEEP carka  nafurt anone HOTSEAT carka  nafurt anone BORDERS opacnazavorka 
 chlupatazavorka 
#define CENTERING 7
#define COLOR_CHAR 254
#define COLOR_MIN 9
#define COLOR_MAX 15

	checkconsolesize zavorka  opacnazavorka  strednik 
	
	nafurt pismeno BODIES hranatazavorka  opacnahranatazavorka  rovnase  chlupatazavorka 'O' carka  'X' carka  176 carka  177 carka  219 carka  '\0' opacnachlupatazavorka  strednik 
	
	anone changing rovnase nepravda carka  mainSelectionRendered strednik 
	celecislo bodySelection rovnase 0 carka  colorSelection rovnase WHITE carka  selection rovnase 0 strednik 
	souradnice bodyCursorPosition carka  colorCursorPosition carka  snakeCursorPosition carka  cursorPosition strednik 
	VISUAL snakeVisual strednik 
	
	snakeVisual tecka body rovnase BODIES hranatazavorka bodySelection opacnahranatazavorka  strednik 
	snakeVisual tecka color rovnase  zavorka COLOR opacnazavorka colorSelection strednik 
	
	dokud zavorka pravda opacnazavorka 
	 chlupatazavorka 
		system zavorka "cls" opacnazavorka  strednik 
		
		verticalcenter zavorka 15 opacnazavorka  strednik 
		center zavorka "CREATE YOUR OWN SNAKE" opacnazavorka  strednik 
		vytisknemesikovne zavorka "\n\n" opacnazavorka  strednik 
		
		center zavorka 1 opacnazavorka  strednik 
		bodyCursorPosition rovnase colorCursorPosition rovnase snakeCursorPosition rovnase commonCursorPosition strednik 
		
		snakeCursorPosition tecka Y  plusrovnase  2 strednik 
		
		bodyCursorPosition tecka X rovnase 0 strednik 
		bodyCursorPosition tecka Y  plusrovnase  8 strednik 
		
		movecursor zavorka bodyCursorPosition opacnazavorka  strednik 
		center zavorka 9 opacnazavorka  strednik 
		bodyCursorPosition rovnase commonCursorPosition strednik 
		
		colorCursorPosition tecka X  plusrovnase  10 strednik 
		
		zatim zavorka celecislo i rovnase 0 strednik  i mensineborovnase COLOR_MAX  minus  COLOR_MIN strednik  i zvetsime  opacnazavorka 
		 chlupatazavorka 
			movecursor zavorka colorCursorPosition tecka X carka  colorCursorPosition tecka Y  plus  i opacnazavorka  strednik 
			
			setforeground zavorka  zavorka COLOR opacnazavorka  zavorka COLOR_MAX  minus  i opacnazavorka  opacnazavorka  strednik 
			vytisknemepismeno zavorka COLOR_CHAR opacnazavorka  strednik 
		 opacnachlupatazavorka 
		
		colorCursorPosition tecka X  plusrovnase  2 strednik 
		
		vytisknemepismeno zavorka '\n' opacnazavorka  strednik 
		center zavorka CENTERING opacnazavorka  strednik 
		
		cursorPosition rovnase commonCursorPosition strednik 
		cursorPosition tecka X   minusrovnase  2 strednik 
		cursorPosition tecka Y  plusrovnase  3  plus  selection strednik 
		
		mainSelectionRendered rovnase nepravda strednik 
		
		dokud zavorka pravda opacnazavorka 
		 chlupatazavorka 
			
#ifdef DEBUG
	setforeground zavorka WHITE opacnazavorka  strednik 
	DEBUG_MAIN strednik 
	movecursor zavorka 0 carka  1 opacnazavorka  strednik 
	vytisknemesikovne zavorka consoleSize tecka X mensi 100  otaznik  "bodyCursor:  %2d %2d | "  dvojtecka  "bodyCursor: %3d %3d | " carka  bodyCursorPosition tecka X carka  bodyCursorPosition tecka Y opacnazavorka  strednik 
	vytisknemesikovne zavorka consoleSize tecka X mensi 100  otaznik  "colorCursor: %2d %2d | "  dvojtecka  "colorCursor: %3d %3d | " carka  colorCursorPosition tecka X carka  colorCursorPosition tecka Y opacnazavorka  strednik 
	vytisknemesikovne zavorka consoleSize tecka X mensi 100  otaznik  "snakeCursor: %2d %2d\n"  dvojtecka  "snakeCursor: %3d %3d\n" carka  snakeCursorPosition tecka X carka  snakeCursorPosition tecka Y opacnazavorka  strednik 
	vytisknemesikovne zavorka "bodySelection: %2d | " carka  bodySelection opacnazavorka  strednik 
	vytisknemesikovne zavorka "colorSelection: %2d | " carka  colorSelection opacnazavorka  strednik 
	vytisknemesikovne zavorka "changing: %d | " carka  changing opacnazavorka  strednik 
	vytisknemesikovne zavorka "mainSelectionRendered: %d\n" carka  mainSelectionRendered opacnazavorka  strednik 
	vytisknemesikovne zavorka "snakeVisual.body: %c | " carka  snakeVisual tecka body opacnazavorka  strednik 
	vytisknemesikovne zavorka "snakeVisual.color: %2d" carka  snakeVisual tecka color opacnazavorka  strednik 
#endif
			setforeground zavorka  zavorka COLOR opacnazavorka colorSelection opacnazavorka  strednik 
			
			zatim zavorka celecislo i rovnase 0 strednik  i mensi 3 strednik  i zvetsime  opacnazavorka 
			 chlupatazavorka 
				movecursor zavorka snakeCursorPosition tecka X carka  snakeCursorPosition tecka Y  plus  i opacnazavorka  strednik 
				vytisknemepismeno zavorka BODIES hranatazavorka bodySelection opacnahranatazavorka  opacnazavorka  strednik 
			 opacnachlupatazavorka 
			
			setforeground zavorka WHITE opacnazavorka  strednik 
			
			movecursor zavorka bodyCursorPosition opacnazavorka  strednik 
			
			setforeground zavorka DARKGRAY opacnazavorka  strednik 
			vytisknemesikovne zavorka "%c " carka   zavorka bodySelection je 1  otaznik  BODIES hranatazavorka strlen zavorka BODIES opacnazavorka   minus  1 opacnahranatazavorka   dvojtecka   zavorka bodySelection je 0  otaznik  BODIES hranatazavorka strlen zavorka BODIES opacnazavorka   minus  2 opacnahranatazavorka   dvojtecka  BODIES hranatazavorka bodySelection  minus  2 opacnahranatazavorka  opacnazavorka  opacnazavorka  opacnazavorka  strednik 
			
			setforeground zavorka LIGHTGRAY opacnazavorka  strednik 
			vytisknemesikovne zavorka "%c " carka   zavorka bodySelection je 0  otaznik  BODIES hranatazavorka strlen zavorka BODIES opacnazavorka   minus  1 opacnahranatazavorka   dvojtecka  BODIES hranatazavorka bodySelection  minus  1 opacnahranatazavorka  opacnazavorka  opacnazavorka  strednik 
			
			setforeground zavorka WHITE opacnazavorka  strednik 
			vytisknemesikovne zavorka "%c " carka  BODIES hranatazavorka bodySelection opacnahranatazavorka  opacnazavorka  strednik 
			
			setforeground zavorka LIGHTGRAY opacnazavorka  strednik 
			vytisknemesikovne zavorka "%c " carka   zavorka bodySelection je strlen zavorka BODIES opacnazavorka   minus  1  otaznik  BODIES hranatazavorka 0 opacnahranatazavorka   dvojtecka  BODIES hranatazavorka bodySelection  plus  1 opacnahranatazavorka  opacnazavorka  opacnazavorka  strednik 
			
			setforeground zavorka DARKGRAY opacnazavorka  strednik 
			vytisknemesikovne zavorka "%c" carka   zavorka bodySelection je strlen zavorka BODIES opacnazavorka   minus  2  otaznik  BODIES hranatazavorka 0 opacnahranatazavorka   dvojtecka   zavorka bodySelection je strlen zavorka BODIES opacnazavorka   minus  1  otaznik  BODIES hranatazavorka 1 opacnahranatazavorka   dvojtecka  BODIES hranatazavorka bodySelection  plus  2 opacnahranatazavorka  opacnazavorka  opacnazavorka  opacnazavorka  strednik 
			
			setforeground zavorka WHITE opacnazavorka  strednik 
			
			pokud zavorka changing opacnazavorka 
			 chlupatazavorka 
				movecursor zavorka colorCursorPosition opacnazavorka  strednik 
				vytisknemepismeno zavorka '<' opacnazavorka  strednik 
				
				setforeground zavorka DARKGRAY opacnazavorka  strednik 
			 opacnachlupatazavorka 
			
			pokud zavorka  vykricnik changing nebo  vykricnik mainSelectionRendered opacnazavorka 
			 chlupatazavorka 
				pokud zavorka  vykricnik mainSelectionRendered opacnazavorka 
				 chlupatazavorka 
					movecursor zavorka 0 carka  cursorPosition tecka Y  minus  selection opacnazavorka  strednik 
					center zavorka CENTERING carka  "Confirm\n" opacnazavorka  strednik 
					center zavorka CENTERING carka  "Change\n" opacnazavorka  strednik 
					center zavorka CENTERING carka  "Back" opacnazavorka  strednik 
					
					mainSelectionRendered rovnase pravda strednik 
				 opacnachlupatazavorka 
				
				movecursor zavorka cursorPosition opacnazavorka  strednik 
				vytisknemepismeno zavorka '>' opacnazavorka  strednik 
			 opacnachlupatazavorka 
			
			setforeground zavorka WHITE opacnazavorka  strednik 
			
			temp rovnase getarrow zavorka getcheat zavorka getch zavorka  opacnazavorka  opacnazavorka  opacnazavorka  strednik 
			
			pokud zavorka changing opacnazavorka 
			 chlupatazavorka 
				movecursor zavorka colorCursorPosition opacnazavorka  strednik 
				vytisknemepismeno zavorka ' ' opacnazavorka  strednik 
				movecursor zavorka colorCursorPosition tecka X  plus  4 carka  colorCursorPosition tecka Y opacnazavorka  strednik 
				vytisknemepismeno zavorka ' ' opacnazavorka  strednik 
			 opacnachlupatazavorka 
			jinak
			 chlupatazavorka 
				movecursor zavorka cursorPosition opacnazavorka  strednik 
				vytisknemepismeno zavorka ' ' opacnazavorka  strednik 
			 opacnachlupatazavorka 
			
			pokud zavorka changing opacnazavorka 
			 chlupatazavorka 
				pokud zavorka temp je ENTER opacnazavorka 
				 chlupatazavorka 
					changing rovnase nepravda strednik 
					mainSelectionRendered rovnase nepravda strednik 
					
					snakeVisual tecka body rovnase BODIES hranatazavorka bodySelection opacnahranatazavorka  strednik 
					snakeVisual tecka color rovnase  zavorka COLOR opacnazavorka colorSelection strednik 
				 opacnachlupatazavorka 
				jinak pokud zavorka temp je ESC opacnazavorka 
				 chlupatazavorka 
					changing rovnase nepravda strednik 
					mainSelectionRendered rovnase nepravda strednik 
					
					colorCursorPosition tecka Y  plusrovnase  colorSelection  minus  COLOR_MAX strednik 
					
					bodySelection rovnase 0 strednik 
					colorSelection rovnase  zavorka celecislo opacnazavorka snakeVisual tecka color strednik 
				 opacnachlupatazavorka 
				jinak pokud zavorka temp je UP aji colorSelection neni COLOR_MAX opacnazavorka 
				 chlupatazavorka 
					colorSelection zvetsime  strednik 
					colorCursorPosition tecka Y zmensime  strednik 
				 opacnachlupatazavorka 
				jinak pokud zavorka temp je DOWN aji colorSelection neni COLOR_MIN opacnazavorka 
				 chlupatazavorka 
					colorSelection zmensime  strednik 
					colorCursorPosition tecka Y zvetsime  strednik 
				 opacnachlupatazavorka 
				jinak pokud zavorka temp je LEFT opacnazavorka 
				 chlupatazavorka 
					pokud zavorka bodySelection je 0 opacnazavorka 
					 chlupatazavorka 
						bodySelection rovnase strlen zavorka BODIES opacnazavorka   minus  1 strednik 
					 opacnachlupatazavorka 
					jinak
					 chlupatazavorka 
						bodySelection zmensime  strednik 
					 opacnachlupatazavorka 
				 opacnachlupatazavorka 
				jinak pokud zavorka temp je RIGHT opacnazavorka 
				 chlupatazavorka 
					pokud zavorka bodySelection je strlen zavorka BODIES opacnazavorka   minus  1 opacnazavorka 
					 chlupatazavorka 
						bodySelection rovnase 0 strednik 
					 opacnachlupatazavorka 
					jinak
					 chlupatazavorka 
						bodySelection zvetsime  strednik 
					 opacnachlupatazavorka 
				 opacnachlupatazavorka 
			 opacnachlupatazavorka 
			jinak
			 chlupatazavorka 
				pokud zavorka  zavorka temp je ENTER aji selection je 2 opacnazavorka  nebo temp je ESC opacnazavorka 
				 chlupatazavorka 
					vratitse nepravda strednik 
				 opacnachlupatazavorka 
				jinak pokud zavorka temp je ENTER opacnazavorka 
				 chlupatazavorka 
					pokud zavorka selection je 1 opacnazavorka 
					 chlupatazavorka 
						changing rovnase pravda strednik 
						mainSelectionRendered rovnase nepravda strednik 
					 opacnachlupatazavorka 
					jinak
					 chlupatazavorka 
						pokud zavorka  vykricnik HOTSEAT opacnazavorka 
						 chlupatazavorka 
							snake zavorka SLEEP carka  BORDERS carka  snakeVisual opacnazavorka  strednik 
						 opacnachlupatazavorka 
						jinak
						 chlupatazavorka 
							hotseat zavorka SLEEP carka  BORDERS carka  snakeVisual opacnazavorka  strednik 
						 opacnachlupatazavorka 
						
						vratitse pravda strednik 
					 opacnachlupatazavorka 
				 opacnachlupatazavorka 
				jinak pokud zavorka temp je UP aji selection neni 0 opacnazavorka 
				 chlupatazavorka 
					selection zmensime  strednik 
					cursorPosition tecka Y zmensime  strednik 
				 opacnachlupatazavorka 
				jinak pokud zavorka temp je DOWN aji selection neni 2 opacnazavorka 
				 chlupatazavorka 
					selection zvetsime  strednik 
					cursorPosition tecka Y zvetsime  strednik 
				 opacnachlupatazavorka 
			 opacnachlupatazavorka 
			
			pokud zavorka checkconsolesize zavorka  opacnazavorka  opacnazavorka 
			 chlupatazavorka 
				zastavit strednik 
			 opacnachlupatazavorka 
		 opacnachlupatazavorka 
	 opacnachlupatazavorka 

#undef CENTERING
#undef COLOR_CHAR
#undef COLOR_MIN
#undef COLOR_MAX
 opacnachlupatazavorka 

prazdnota randomcolors zavorka  opacnazavorka 
 chlupatazavorka 
    delej
     chlupatazavorka 
        consoleColor hranatazavorka 6 opacnahranatazavorka  rovnase rand zavorka  opacnazavorka  procento 16 strednik 
        consoleColor hranatazavorka 7 opacnahranatazavorka  rovnase rand zavorka  opacnazavorka  procento 16 strednik 
     opacnachlupatazavorka  dokud zavorka consoleColor hranatazavorka 6 opacnahranatazavorka  je consoleColor hranatazavorka 7 opacnahranatazavorka  opacnazavorka  strednik 
    
    pokud zavorka consoleColor hranatazavorka 6 opacnahranatazavorka  vetsineborovnase 10 opacnazavorka 
     chlupatazavorka 
        consoleColor hranatazavorka 6 opacnahranatazavorka   plusrovnase  'A'  minus  10 strednik 
     opacnachlupatazavorka 
    jinak
     chlupatazavorka 
        consoleColor hranatazavorka 6 opacnahranatazavorka   plusrovnase  '0' strednik 
     opacnachlupatazavorka 
    
    pokud zavorka consoleColor hranatazavorka 7 opacnahranatazavorka  vetsineborovnase 10 opacnazavorka 
     chlupatazavorka 
        consoleColor hranatazavorka 7 opacnahranatazavorka   plusrovnase  'A'  minus  10 strednik 
     opacnachlupatazavorka 
    jinak
     chlupatazavorka 
        consoleColor hranatazavorka 7 opacnahranatazavorka   plusrovnase  '0' strednik 
     opacnachlupatazavorka 
    
    system zavorka consoleColor opacnazavorka  strednik 
    vratitse strednik 
 opacnachlupatazavorka 

prazdnota newberry zavorka BERRY  hvezdicka berry carka  nafurt anone  hvezdicka GAMEBOARD opacnazavorka 
 chlupatazavorka 
	anone collision strednik 
	
	delej
	 chlupatazavorka 
		collision rovnase nepravda strednik 
		
		berry  sipka position tecka X rovnase rand zavorka  opacnazavorka  procento  zavorka forcedConsoleSize tecka X  plus  1 opacnazavorka  strednik 
		berry  sipka position tecka Y rovnase rand zavorka  opacnazavorka  procento  zavorka forcedConsoleSize tecka Y  plus  1 opacnazavorka  strednik 
		
		zatim zavorka celecislo y rovnase  minus 1 strednik  y mensineborovnase 1 strednik  y zvetsime  opacnazavorka 
		 chlupatazavorka 
			pokud zavorka  zavorka berry  sipka position tecka Y je 0 aji y je  minus 1 opacnazavorka  nebo  zavorka berry  sipka position tecka Y je forcedConsoleSize tecka Y aji y je 1 opacnazavorka  opacnazavorka 
			 chlupatazavorka 
				pokracovat strednik 
			 opacnachlupatazavorka 
			
			zatim zavorka celecislo x rovnase  minus 1 strednik  x mensineborovnase 1 strednik  x zvetsime  opacnazavorka 
			 chlupatazavorka 
				pokud zavorka  zavorka berry  sipka position tecka X je 0 aji x je  minus 1 opacnazavorka  nebo  zavorka berry  sipka position tecka X je forcedConsoleSize tecka X aji x je 1 opacnazavorka  opacnazavorka 
				 chlupatazavorka 
					pokracovat strednik 
				 opacnachlupatazavorka 
				
				pokud zavorka  hvezdicka  zavorka GAMEBOARD  plus   zavorka  zavorka berry  sipka position tecka Y  plus  y opacnazavorka   hvezdicka  forcedConsoleSize tecka X opacnazavorka   plus   zavorka berry  sipka position tecka X  plus  x opacnazavorka  opacnazavorka  opacnazavorka 
				 chlupatazavorka 
					collision rovnase pravda strednik 
					zastavit strednik 
				 opacnachlupatazavorka 
			 opacnachlupatazavorka 
			
			pokud zavorka collision opacnazavorka 
			 chlupatazavorka 
				zastavit strednik 
			 opacnachlupatazavorka 
		 opacnachlupatazavorka 
	 opacnachlupatazavorka  dokud zavorka collision opacnazavorka  strednik 
	
	movecursor zavorka berry  sipka position opacnazavorka  strednik 
	printvisual zavorka berry  sipka visual opacnazavorka  strednik 
	
	vratitse strednik 
 opacnachlupatazavorka 

prazdnota livetitle zavorka nafurt celecislo SCORE opacnazavorka 
 chlupatazavorka 
	sprintf zavorka liveTitle carka  "%s  minus  score dvojtecka  %d" carka  GAMENAME carka  SCORE  minus  LENGHT_START opacnazavorka  strednik 
	SetConsoleTitle zavorka liveTitle opacnazavorka  strednik 
	
	vratitse strednik 
 opacnachlupatazavorka 

prazdnota livetitle zavorka nafurt celecislo SCORE1 carka  nafurt celecislo SCORE2 opacnazavorka 
 chlupatazavorka 
	sprintf zavorka liveTitle carka  "%s  minus  player 1 dvojtecka  %d player 2 dvojtecka  %d" carka  GAMENAME carka  SCORE1  minus  LENGHT_START carka  SCORE2  minus  LENGHT_START opacnazavorka  strednik 
	SetConsoleTitle zavorka liveTitle opacnazavorka  strednik 
	
	vratitse strednik 
 opacnachlupatazavorka 

prazdnota snake zavorka nafurt celecislo SLEEP carka  nafurt anone BORDERS carka  nafurt VISUAL SNAKEVISUAL opacnazavorka 
 chlupatazavorka 
	checkconsolesize zavorka  opacnazavorka  strednik 
	forcedConsoleSize rovnase consoleSize strednik 
	
	anone gameBoard hranatazavorka forcedConsoleSize tecka Y  plus  1 opacnahranatazavorka  hranatazavorka forcedConsoleSize tecka X  plus  1 opacnahranatazavorka  strednik 
	celecislo shownSpecial rovnase 0 strednik 
	BERRY berry strednik 
	SNAKE snake strednik 
	
	berry tecka visual tecka body rovnase 'X' strednik 
	berry tecka visual tecka color rovnase WHITE strednik 
	
	snake tecka collision rovnase nepravda strednik 
	snake tecka active rovnase LENGHT_START strednik 
	snake tecka shown rovnase snake tecka bend tecka active rovnase snake tecka bend tecka lastAssigned rovnase 0 strednik 
	snake tecka first tecka position tecka X rovnase snake tecka last tecka position tecka X rovnase forcedConsoleSize tecka X  lomitko  2 strednik 
	snake tecka first tecka position tecka Y rovnase snake tecka last tecka position tecka Y rovnase forcedConsoleSize tecka Y  lomitko  2 strednik 
	snake tecka first tecka direction rovnase snake tecka last tecka direction rovnase UP strednik 
	snake tecka visual tecka body rovnase SNAKEVISUAL tecka body strednik 
	snake tecka visual tecka color rovnase SNAKEVISUAL tecka color strednik 
	
	zatim zavorka celecislo i rovnase 0 strednik  i mensi forcedConsoleSize tecka Y  plus  1 strednik  i zvetsime  opacnazavorka 
	 chlupatazavorka 
		zatim zavorka celecislo j rovnase 0 strednik  j mensi forcedConsoleSize tecka X  plus  1 strednik  j zvetsime  opacnazavorka 
		 chlupatazavorka 
			gameBoard hranatazavorka i opacnahranatazavorka  hranatazavorka j opacnahranatazavorka  rovnase nepravda strednik 
		 opacnachlupatazavorka 
	 opacnachlupatazavorka 
	
	gameBoard hranatazavorka snake tecka first tecka position tecka Y opacnahranatazavorka  hranatazavorka snake tecka first tecka position tecka X opacnahranatazavorka  rovnase pravda strednik 
	
	zatim zavorka celecislo i rovnase 0 strednik  i mensi LENGHT_MAX strednik  i zvetsime  opacnazavorka 
	 chlupatazavorka 
		snake tecka bend tecka vector hranatazavorka i opacnahranatazavorka  tecka position tecka X rovnase snake tecka bend tecka vector hranatazavorka i opacnahranatazavorka  tecka position tecka Y rovnase snake tecka bend tecka vector hranatazavorka i opacnahranatazavorka  tecka direction rovnase NEUTRAL strednik 
	 opacnachlupatazavorka 
	
#ifndef DEBUG
	timer zavorka pravda opacnazavorka  strednik 
#endif
	
	livetitle zavorka snake tecka active opacnazavorka  strednik 
	system zavorka "cls" opacnazavorka  strednik 
	
	newberry zavorka  divnya berry carka  gameBoard hranatazavorka 0 opacnahranatazavorka  opacnazavorka  strednik 
	
	dokud zavorka pravda opacnazavorka 
	 chlupatazavorka 
		forceconsolesize zavorka  opacnazavorka  strednik 
		
		pokud zavorka cheats hranatazavorka FISA opacnahranatazavorka  opacnazavorka 
		 chlupatazavorka 
			randomcolors zavorka  opacnazavorka  strednik 
		 opacnachlupatazavorka 
		
		gameBoard hranatazavorka snake tecka first tecka position tecka Y opacnahranatazavorka  hranatazavorka snake tecka first tecka position tecka X opacnahranatazavorka  rovnase pravda strednik 
		movecursor zavorka snake tecka first tecka position opacnazavorka  strednik 
		
		pokud zavorka  vykricnik cheats hranatazavorka FISA opacnahranatazavorka  opacnazavorka 
		 chlupatazavorka 
			printvisual zavorka snake tecka visual opacnazavorka  strednik 
		 opacnachlupatazavorka 
		jinak
		 chlupatazavorka 
			vytisknemepismeno zavorka FULL opacnazavorka  strednik 
		 opacnachlupatazavorka 
		
		pokud zavorka snake tecka shown neni snake tecka active opacnazavorka 
		 chlupatazavorka 
			snake tecka shown zvetsime  strednik 
		 opacnachlupatazavorka 
		jinak
		 chlupatazavorka 
			gameBoard hranatazavorka snake tecka last tecka position tecka Y opacnahranatazavorka  hranatazavorka snake tecka last tecka position tecka X opacnahranatazavorka  rovnase nepravda strednik 
			movecursor zavorka snake tecka last tecka position opacnazavorka  strednik 
			
			pokud zavorka  vykricnik cheats hranatazavorka FISA opacnahranatazavorka  opacnazavorka 
			 chlupatazavorka 
				setforeground zavorka BLACK opacnazavorka  strednik 
				vytisknemepismeno zavorka snake tecka visual tecka body opacnazavorka  strednik 
				setforeground zavorka WHITE opacnazavorka  strednik 
			 opacnachlupatazavorka 
			jinak
			 chlupatazavorka 
				vytisknemepismeno zavorka ' ' opacnazavorka  strednik 
			 opacnachlupatazavorka 
			
			pokud zavorka snake tecka last tecka position je snake tecka bend tecka vector hranatazavorka snake tecka bend tecka active opacnahranatazavorka  tecka position opacnazavorka 
			 chlupatazavorka 
				snake tecka last tecka direction rovnase snake tecka bend tecka vector hranatazavorka snake tecka bend tecka active opacnahranatazavorka  tecka direction strednik 
				snake tecka bend tecka active zvetsime  strednik 
				
				pokud zavorka snake tecka bend tecka active je LENGHT_MAX opacnazavorka 
				 chlupatazavorka 
					snake tecka bend tecka active rovnase 0 strednik 
				 opacnachlupatazavorka 
			 opacnachlupatazavorka 
			
			pokud zavorka snake tecka last tecka direction je UP opacnazavorka 
			 chlupatazavorka 
				snake tecka last tecka position tecka Y zmensime  strednik 
			 opacnachlupatazavorka 
			jinak pokud zavorka snake tecka last tecka direction je DOWN opacnazavorka 
			 chlupatazavorka 
				snake tecka last tecka position tecka Y zvetsime  strednik 
			 opacnachlupatazavorka 
			jinak pokud zavorka snake tecka last tecka direction je LEFT opacnazavorka 
			 chlupatazavorka 
				snake tecka last tecka position tecka X zmensime  strednik 
			 opacnachlupatazavorka 
			jinak pokud zavorka snake tecka last tecka direction je RIGHT opacnazavorka 
			 chlupatazavorka 
				snake tecka last tecka position tecka X zvetsime  strednik 
			 opacnachlupatazavorka 
			
			pokud zavorka  vykricnik BORDERS opacnazavorka 
			 chlupatazavorka 
				pokud zavorka snake tecka last tecka position tecka X mensi 0 opacnazavorka 
				 chlupatazavorka 
					snake tecka last tecka position tecka X rovnase forcedConsoleSize tecka X strednik 
				 opacnachlupatazavorka 
				jinak pokud zavorka snake tecka last tecka position tecka X vetsi forcedConsoleSize tecka X opacnazavorka 
				 chlupatazavorka 
					snake tecka last tecka position tecka X rovnase 0 strednik 
				 opacnachlupatazavorka 
				jinak pokud zavorka snake tecka last tecka position tecka Y mensi 0 opacnazavorka 
				 chlupatazavorka 
					snake tecka last tecka position tecka Y rovnase forcedConsoleSize tecka Y strednik 
				 opacnachlupatazavorka 
				jinak pokud zavorka snake tecka last tecka position tecka Y vetsi forcedConsoleSize tecka Y opacnazavorka 
				 chlupatazavorka 
					snake tecka last tecka position tecka Y rovnase 0 strednik 
				 opacnachlupatazavorka 
			 opacnachlupatazavorka 
		 opacnachlupatazavorka 
	
		CURSOR_RESET strednik 
	
#ifdef DEBUG
	vytisknemesikovne zavorka consoleSize tecka X mensi 100  otaznik  "first: %2d %2d %c | "  dvojtecka  "first: %3d %3d %c | " carka  snake tecka first tecka position tecka X carka  snake tecka first tecka position tecka Y carka  printarrow zavorka snake tecka first tecka direction opacnazavorka  opacnazavorka  strednik 
	vytisknemesikovne zavorka consoleSize tecka X mensi 100  otaznik  "bend[%3d]:% 3d% 3d %c | "  dvojtecka  "bend[%3d]:% 4d% 4d %c | " carka snake tecka bend tecka active carka  snake tecka bend tecka vector hranatazavorka snake tecka bend tecka active opacnahranatazavorka  tecka position tecka X carka  snake tecka bend tecka vector hranatazavorka snake tecka bend tecka active opacnahranatazavorka  tecka position tecka Y carka 
		printarrow zavorka snake tecka bend tecka vector hranatazavorka snake tecka bend tecka active opacnahranatazavorka  tecka direction opacnazavorka  opacnazavorka  strednik 
	vytisknemesikovne zavorka "active: %3d | " carka  snake tecka active opacnazavorka  strednik 
	vytisknemesikovne zavorka consoleSize tecka X mensi 100  otaznik  "berry: %2d %2d | "  dvojtecka  "berry: %3d %3d | " carka  berry tecka position tecka X carka  berry tecka position tecka Y opacnazavorka  strednik 
	vytisknemesikovne zavorka "%s" carka  consoleColor opacnazavorka  strednik 
		
	vytisknemesikovne zavorka consoleSize tecka X mensi 100  otaznik  "\nlast:  %2d %2d %c | "  dvojtecka  "\nlast:  %3d %3d %c | " carka  snake tecka last tecka position tecka X carka  snake tecka last tecka position tecka Y carka  printarrow zavorka snake tecka last tecka direction opacnazavorka  opacnazavorka  strednik 
	vytisknemesikovne zavorka consoleSize tecka X mensi 100  otaznik   zavorka snake tecka bend tecka lastAssigned vetsi 0  otaznik  "bend[%3d]: %2d %2d %c | " dvojtecka  "bend[%3d]: -- -- - | " opacnazavorka   dvojtecka   zavorka snake tecka bend tecka lastAssigned vetsi 0  otaznik  "bend[%3d]: %3d %3d %c | " dvojtecka  "bend[%3d]: --- --- - | " opacnazavorka  carka 
		snake tecka bend tecka lastAssigned carka  snake tecka bend tecka vector hranatazavorka snake tecka bend tecka lastAssigned  minus  1 opacnahranatazavorka  tecka position tecka X carka  snake tecka bend tecka vector hranatazavorka snake tecka bend tecka lastAssigned  minus  1 opacnahranatazavorka  tecka position tecka Y carka 
		printarrow zavorka snake tecka bend tecka vector hranatazavorka snake tecka bend tecka lastAssigned  minus  1 opacnahranatazavorka  tecka direction opacnazavorka  opacnazavorka  strednik 
	vytisknemesikovne zavorka "shown:  %3d | " carka  snake tecka shown opacnazavorka  strednik 
	vytisknemesikovne zavorka "SLEEP: %3d   |" carka  SLEEP opacnazavorka  strednik 
	vytisknemesikovne zavorka "" opacnazavorka  strednik 
	DEBUG_CHEATS strednik 
#endif
		
		Sleep zavorka SLEEP opacnazavorka  strednik 
		
		pokud zavorka kbhit zavorka  opacnazavorka  opacnazavorka 
		 chlupatazavorka 
			temp rovnase getch zavorka  opacnazavorka  strednik 
			
			pokud zavorka IF_ARROW(temp) opacnazavorka 
			 chlupatazavorka 
				temp rovnase getch zavorka  opacnazavorka  strednik 
				
				pokud zavorka IF_ARROWS(temp)  aji temp neni snake tecka first tecka direction aji temp neni  zavorka snake tecka first tecka direction je UP  otaznik  DOWN  dvojtecka   zavorka snake tecka first tecka direction je DOWN  otaznik  UP  dvojtecka   zavorka snake tecka first tecka direction je LEFT  otaznik  RIGHT  dvojtecka  LEFT opacnazavorka  opacnazavorka  opacnazavorka  opacnazavorka 
				 chlupatazavorka 
					snake tecka first tecka direction rovnase snake tecka bend tecka vector hranatazavorka snake tecka bend tecka lastAssigned opacnahranatazavorka  tecka direction rovnase temp strednik 
					snake tecka bend tecka vector hranatazavorka snake tecka bend tecka lastAssigned opacnahranatazavorka  tecka position rovnase snake tecka first tecka position strednik 
					snake tecka bend tecka lastAssigned zvetsime  strednik 
					
					pokud zavorka snake tecka bend tecka lastAssigned je LENGHT_MAX opacnazavorka 
					 chlupatazavorka 
						snake tecka bend tecka lastAssigned rovnase 0 strednik 
					 opacnachlupatazavorka 
				 opacnachlupatazavorka 
			 opacnachlupatazavorka 
			jinak pokud zavorka temp je ESC opacnazavorka 
			 chlupatazavorka 
				SetConsoleTitle zavorka GAMENAME opacnazavorka  strednik 
				
				pokud zavorka pausemenu zavorka nepravda opacnazavorka  opacnazavorka 
				 chlupatazavorka 
					vratitse strednik 
				 opacnachlupatazavorka 
				
				livetitle zavorka snake tecka active opacnazavorka  strednik 
				
				pokud zavorka cheats hranatazavorka FISA opacnahranatazavorka  opacnazavorka 
				 chlupatazavorka 
					randomcolors zavorka  opacnazavorka  strednik 
				 opacnachlupatazavorka 
			 opacnachlupatazavorka 
			
#ifdef DEBUG
	jinak pokud zavorka temp je SPACE opacnazavorka 
	 chlupatazavorka 
		dokud zavorka getch zavorka  opacnazavorka  neni SPACE opacnazavorka  strednik 
	 opacnachlupatazavorka 
#endif
		
		 opacnachlupatazavorka 
		
		pokud zavorka snake tecka first tecka direction je UP opacnazavorka 
		 chlupatazavorka 
			snake tecka first tecka position tecka Y zmensime  strednik 
		 opacnachlupatazavorka 
		jinak pokud zavorka snake tecka first tecka direction je DOWN opacnazavorka 
		 chlupatazavorka 
			snake tecka first tecka position tecka Y zvetsime  strednik 
		 opacnachlupatazavorka 
		jinak pokud zavorka snake tecka first tecka direction je LEFT opacnazavorka 
		 chlupatazavorka 
			snake tecka first tecka position tecka X zmensime  strednik 
		 opacnachlupatazavorka 
		jinak pokud zavorka snake tecka first tecka direction je RIGHT opacnazavorka 
		 chlupatazavorka 
			snake tecka first tecka position tecka X zvetsime  strednik 
		 opacnachlupatazavorka 
		
		pokud zavorka BORDERS opacnazavorka 
		 chlupatazavorka 
			pokud zavorka  vykricnik  zavorka snake tecka first tecka position vetsineborovnase ORIGIN opacnazavorka  nebo  vykricnik  zavorka snake tecka first tecka position mensineborovnase forcedConsoleSize opacnazavorka  opacnazavorka 
			 chlupatazavorka 
				snake tecka collision rovnase pravda strednik 
			 opacnachlupatazavorka 
		 opacnachlupatazavorka 
		jinak
		 chlupatazavorka 
			pokud zavorka snake tecka first tecka position tecka X mensi 0 opacnazavorka 
			 chlupatazavorka 
				snake tecka first tecka position tecka X rovnase forcedConsoleSize tecka X strednik 
			 opacnachlupatazavorka 
			jinak pokud zavorka snake tecka first tecka position tecka X vetsi forcedConsoleSize tecka X opacnazavorka 
			 chlupatazavorka 
				snake tecka first tecka position tecka X rovnase 0 strednik 
			 opacnachlupatazavorka 
			jinak pokud zavorka snake tecka first tecka position tecka Y mensi 0 opacnazavorka 
			 chlupatazavorka 
				snake tecka first tecka position tecka Y rovnase forcedConsoleSize tecka Y strednik 
			 opacnachlupatazavorka 
			jinak pokud zavorka snake tecka first tecka position tecka Y vetsi forcedConsoleSize tecka Y opacnazavorka 
			 chlupatazavorka 
				snake tecka first tecka position tecka Y rovnase 0 strednik 
			 opacnachlupatazavorka 
		 opacnachlupatazavorka 
		
		pokud zavorka snake tecka first tecka position je berry tecka position opacnazavorka 
		 chlupatazavorka 
			snake tecka active zvetsime  strednik 
			
			pokud zavorka cheats hranatazavorka HAMSTER opacnahranatazavorka  opacnazavorka 
			 chlupatazavorka 
				snake tecka active  plusrovnase  2 strednik 
			 opacnachlupatazavorka 
			
			livetitle zavorka snake tecka active opacnazavorka  strednik 
			
			newberry zavorka  divnya berry carka  gameBoard hranatazavorka 0 opacnahranatazavorka  opacnazavorka  strednik 
		 opacnachlupatazavorka 
		
		pokud zavorka  vykricnik isSpecialShown aji SPECIAL_SPAWN opacnazavorka 
		 chlupatazavorka 
			shownSpecial rovnase rand zavorka  opacnazavorka  procento  zavorka velikost zavorka specials opacnazavorka   lomitko  velikost zavorka specials hranatazavorka 0 opacnahranatazavorka  opacnazavorka  opacnazavorka  strednik 
			
			newberry zavorka  divnya specials hranatazavorka shownSpecial opacnahranatazavorka  carka  gameBoard hranatazavorka 0 opacnahranatazavorka  opacnazavorka  strednik 
			isSpecialShown rovnase pravda strednik 
		 opacnachlupatazavorka 
		jinak pokud zavorka isSpecialShown opacnazavorka 
		 chlupatazavorka 
			pokud zavorka snake tecka first tecka position je specials hranatazavorka shownSpecial opacnahranatazavorka  tecka position opacnazavorka 
			 chlupatazavorka 
				prepinac zavorka shownSpecial opacnazavorka 
				 chlupatazavorka 
					moznost MINE dvojtecka 
						snake tecka collision rovnase pravda strednik 
						zastavit strednik 
					
					moznost BONUS dvojtecka 
						snake tecka active  plusrovnase  SPECIAL_BONUS strednik 
						livetitle zavorka snake tecka active opacnazavorka  strednik 
						zastavit strednik 
				 opacnachlupatazavorka 
				
				isSpecialShown rovnase nepravda strednik 
			 opacnachlupatazavorka 
			jinak pokud zavorka SPECIAL_SPAWN opacnazavorka 
			 chlupatazavorka 
				movecursor zavorka specials hranatazavorka shownSpecial opacnahranatazavorka  tecka position opacnazavorka  strednik 
				vytisknemepismeno zavorka ' ' opacnazavorka  strednik 
				
				isSpecialShown rovnase nepravda strednik 
			 opacnachlupatazavorka 
		 opacnachlupatazavorka 
		
		pokud zavorka gameBoard hranatazavorka snake tecka first tecka position tecka Y opacnahranatazavorka  hranatazavorka snake tecka first tecka position tecka X opacnahranatazavorka  opacnazavorka 
		 chlupatazavorka 
			snake tecka collision rovnase pravda strednik 
		 opacnachlupatazavorka 
		
		pokud zavorka snake tecka collision nebo snake tecka active je LENGHT_MAX opacnazavorka 
		 chlupatazavorka 
			SetConsoleTitle zavorka GAMENAME opacnazavorka  strednik 
			showscore zavorka snake tecka active je LENGHT_MAX carka  snake tecka active  minus  LENGHT_START carka  SLEEP je SLEEP_EASY  otaznik  EASY  dvojtecka   zavorka SLEEP je SLEEP_MEDIUM  otaznik  MEDIUM  dvojtecka   zavorka SLEEP je SLEEP_HARD  otaznik  HARD  dvojtecka  CUSTOM opacnazavorka  opacnazavorka  carka  BORDERS  otaznik  "Normal"  dvojtecka  "Borderless" opacnazavorka  strednik 
			vratitse strednik 
		 opacnachlupatazavorka 
	 opacnachlupatazavorka 
 opacnachlupatazavorka 

prazdnota hotseat zavorka nafurt celecislo SLEEP carka  nafurt anone BORDERS carka  nafurt VISUAL SNAKEVISUAL opacnazavorka 
 chlupatazavorka
 	
 opacnachlupatazavorka 
