#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

int thrallAttacks(string name, char rustySword, int lives);
int lichBattle(string name, int lives);
int GoblinBattle(int lives, string name);
void StartGameMessage();
void EnterTheDungeon();
int RedPath(int lives);
void BluePath();
void OnwardThrall();
void OnwardLich();


int main()
{
    int heroHealth = 30;
    int thrallHealth = 15;

    int lives = 3;
    char fight = 'n';
    int attackNum = 0;
    char rustySword = 'n';

    srand(0);
    cout << "       Welcome to Dungeon Odyssey\n\n";
    //INTRO
    StartGameMessage();

    string name;
    cout << "\n" << "Enter name: ";
    cin >> name;
    cout << "Your name is " << name << " Your current health is: "
        << heroHealth << "\n";

    EnterTheDungeon();

    cout << "Choose the RED PATH(1) or the BLUE PATH(2)\n";
    int rbchoice;
    cin >> rbchoice;
    if (rbchoice == 1)
    {
        lives = RedPath(lives);
        cout << "You take the blue path instead";
        BluePath();
    }
    if (rbchoice == 2)
    {
        BluePath();
    }

    lives = GoblinBattle(lives, name);
    cout << "Lives Remaining: " << lives << endl;

    OnwardThrall();

    cout << "Do you want to fight (y) or evade (n)?" << endl;
    cin >> fight;
    cout << fight << endl;
    if (fight == 'n')
    {
        cout << "Please enter a number from 0 - 9";

        cin >> attackNum;
        if (attackNum < 0 || attackNum > 9)
        {
            cout << "Please enter a valid number - 0 - 9";
            cin >> attackNum;
        }
        if (attackNum >= 5)
        {

            cout << "Hero evades successfully" << endl;
            OnwardLich();
            lichBattle(name, lives);
        }
    }
    else
    {
        rustySword = 'y';
        lives = thrallAttacks(name, rustySword, lives);
    }


    OnwardLich();
    lichBattle(name, lives);

}


/*********************************************************
thrallAttacks
Parameters:
Return:
*/

int thrallAttacks(string name, char rustySword, int lives)
{
    srand(time(NULL));
    int heroHealth = 30;
    int thrallHealth = 30;
    int heroAttack = 1;
    int thrallAttack = 3;
    int thrallAttackNum = 0;
    int attackNum = 0;
    int random = 0;
    char win = 'n';
    if (rustySword == 'y')
    {
        heroAttack = heroAttack + 2;
    }
    while (heroHealth > 0 && thrallHealth > 0)
    {
        cout << "Please enter a number (0-9)" << endl;
        cin >> attackNum;
        random = rand() % 10;
        thrallAttackNum = random;
        cout << "Thralls number: " << random << endl;

        if ((attackNum < 5 && thrallAttackNum < 5) || (attackNum >= 5 && thrallAttackNum >= 5))
        {
            if (attackNum > thrallAttackNum)
            {
                cout << "You hit the thrall" << endl;
                thrallHealth = thrallHealth - heroAttack;
                cout << "Thralls Health: " << thrallHealth << endl;
            }
            if (thrallAttackNum > attackNum)
            {
                cout << "the Thrall hit you" << endl;
                heroHealth = heroHealth - thrallAttack;
                cout << name << " Health: " << heroHealth << endl;
            }
            if (thrallAttackNum == attackNum)
            {
                cout << "Your attacks equalled out\n";
            }
        }

        if ((attackNum < 5 && thrallAttackNum >= 5) || (attackNum >= 5 && thrallAttackNum < 5))
        {
            if (attackNum > thrallAttackNum)
            {
                cout << "The Thrall won this attack" << endl;
                heroHealth = heroHealth - thrallAttack;
                cout << name << " Health: " << heroHealth << endl;
            }
            if (thrallAttackNum > attackNum)
            {
                cout << "You won this attack" << endl;
                thrallHealth = thrallHealth - heroAttack;
                cout << "Thralls Health: " << thrallHealth << endl;
            }
            if (thrallAttackNum == attackNum)
            {
                cout << "You tied this attack\n";
            }
        }
    }
    if (heroHealth > 0 && thrallHealth == 0)
    {
        cout << "HERO WINS!!!!" << endl << endl;
        cout <<"As the thrall falls, you hear the rattle of bones as the magic holding it together fails.\n"
            << "On the pile of bones, you reach for the enchanted sword that it brandished against you.\n"
            << "To the winner go the spoils as they say. After taking a moment to catch your breath, you\n"
            << "look for the exit that the thrall guarded and move forward.\n";
    }
    else
    {
        cout << "THRALL WINS :( " << endl;
        lives--;
        cout << "You crumple onto the ground, your legs failing to hold you up anymore.\n"
            << "You look up at the blood-splattered face of the thrall, knowing that all of it belongs to you.\n"
            << "The skeletal thrall stands over you readying its final blow. As it swings down, you clench your eyes close.\n"
            << "You join the many other adventurers who have met a similar fate.\n\n"
            << "You die......\n";
    }

    return lives;
}//end thrallAttacks



/*********************************************************
lichBattle
Parameters:
Return:

*/
void lichBattle()
{
    cout << "Move to lich scenario";
}// end lichBattle





int GoblinBattle(int lives, string name) {
    int livesLeft = lives;
    int goblinHealth = 15;
    int heroHealth = 30;
    int punch = 5;
    int goblinAttack;
    srand((int)time(0));

    goblinAttack = rand() % 10 + 1;
    cout << "Goblin battle start \n"
        << "Fight(press 1) or Run(press 2) \n";
    int frchoice;
    cin >> frchoice;

    if (frchoice == 1)
    {
        cout << "You Fight the goblin\n";
    }
    else
    {
        cout << "You cant run away COWARD!!\n";
    }

    cout << "You only have your fists\n"
        << "GOOD LUCK!\n";

    while (heroHealth > 0 && goblinHealth > 0)
    {
        cout << name << " Player health currently: " << heroHealth << "\n";
        cout << "Goblin health currently: " << goblinHealth << " \n";
        cout << "Press 1 to attack\n";
        string attack;
        cin >> attack;

        cout << name << " uses his fists " << " damage is " << punch << endl;
        goblinHealth = goblinHealth - punch;
        goblinAttack = rand() % 7 + 1;
        cout << "Goblin attack for " << goblinAttack << " " << endl;
        heroHealth = heroHealth - goblinAttack;
    }

    if (heroHealth > goblinHealth)
    {
        cout << "YOU WON\n";
        cout << "Victorious at last, you stand above the slain goblin, panting.\n"
            << "You take a moment to catch your breath, before taking the rusty sword \n"
            << "from the goblins dead hands. The sword is covered in your own blood, and \n"
            << "you wipe the blade off on your pants. You now move forward, with a new addition\n"
            << "to your inventory.\n";

    }
    else
    {
        cout << "THE GOBLIN WON\n";
        --livesLeft;
    }
    return livesLeft;
}

void StartGameMessage()
{
    cout << "You have travelled far in search for the fabled Lichs Lair. \n"
        << "Your journey has led you to the small town of Exalar. \n"
        << "Before your journey begins, you rest at the towns inn.\n\n"
        << "Setting off early in the morning, you make your way to the \n"
        << "large stoney cave on the edge of town. Villagers wish you \n"
        << "luck as you march onward to the dungeon.\n\n"
        << "You stand at the entrance to the underground dungeon.\n"
        << "The dark opening emanates a foreboding aura. \n"
        << "You take your first step, enveloping yourself into darkness.\n"
        << "Thus begins your Dungeon Odyssey.\n";
}
void EnterTheDungeon()
{
    cout << "The walls of the cave echo your footfalls as you move forward.\n"
        << "There is no sound except for your walking, breathing, and the occasional \n"
        << "drip of water from the ceiling of the dank cavern. (drip...drip...drip...)\n\n"
        << "A soft glow appears in the distance. You hurry your way forward, growing restless\n"
        << "from being surrounded in darkness.As you approach, you notice two distinct colors: red and blue.\n"
        << "The tunnel you are in abruptly splits into two separate paths, each lit up by what seem to be glowing stones.\n\n"
        << "The blue lit path slopes upward gently, while the red path delves further into the earth. Which path do you choose?\n";
}

int RedPath(int lives)
{
    cout << "Choosing the red path, you find yourself journeying further down into the depths. Eventually, you reach an open cavern \n"
        << "that levels out. In the middle of the room, you spot a treasure chest. Moving forward, you hear a metal slammingand see that\n"
        << "the entrance you took is sealed shut by a heavy iron door. From the chest, water sprays out, quickly filling the room.\n"
        << "With no way out, you struggle to swim up. The room continues to fill until there is no dry area. You hold your breath as \n"
        << "long as you can, but eventually succumb to drowning.\n"
        << "You die and lose a life.\n\n"
        << "You walk through the blue path instead.\n\n";


    //int newlives = lives;
    return --lives;
}


int lichBattle(string name, int lives)
{
    srand(time(NULL));
    int heroHealth = 30;
    int lichHealth = 30;
    int heroAttack = 5;
    int lichAttack = 20;
    int lichAttackNum = 0;
    int attackNum = 0;
    int random = 0;
    char win = 'n';
    char enchantedSword = 'y';

    if (enchantedSword == 'y')
    {
        heroAttack = 20;
    }
    while (heroHealth > 0 && lichHealth > 0)
    {
        cout << "Please enter a number (0-9)" << endl;
        cin >> attackNum;
        random = rand() % 10;
        lichAttackNum = random;
        cout << "Lichs number is: " << random << endl;

        if ((attackNum < 5 && lichAttackNum < 5) || (attackNum >= 5 && lichAttackNum >= 5))
        {
            if (attackNum > lichAttackNum)
            {
                cout << "You hit the lich" << endl;
                lichHealth = lichHealth - heroAttack;
                cout << "Lichs health now is: " << lichHealth << endl;
            }
            if (lichAttackNum > attackNum)
            {
                cout << "The Lich hit you this time" << endl;
                heroHealth = heroHealth - lichAttack;
                cout << name << " health is: " << heroHealth << endl;
            }
            if (lichAttackNum = attackNum)
            {
                cout << "Your attacks equaled out" << endl;
            }
        }
        if ((attackNum < 5 && lichAttackNum >= 5) || (attackNum >= 5 && lichAttackNum < 5))
        {
            if (attackNum > lichAttackNum)
            {
                cout << "The Lich hit you this time" << endl;
                heroHealth = heroHealth - lichAttack;
                cout << name << " health is: " << heroHealth << endl;
            }
            if (lichAttackNum > attackNum)
            {
                cout << "You hit the Lich" << endl;
                lichHealth = lichHealth - heroAttack;
                cout << "The Lichs new health is: " << lichHealth << endl;
            }
            if (lichAttackNum = attackNum)
            {
                cout << "Your attacks equaled out" << endl;
            }
        }
    }
    if (heroHealth > 0 && lichHealth == 0)
    {
        cout << "HERO WINS!!!!\n\n";

        cout << "The Lich lets out a great bellow before it rattles to the ground, the fire in its eye quickly extinguishing. You catch your breath while the evil being disintegrates before your eyes, leaving"
            << "nothing but his robes and a single elk skull. Approaching, you hold the skull gingerly in your hands. You have slain the Lich. You have done what countless others have failed to do. You fall to\n"
            << "your knees, fatigue finally setting in. Silent tears stream down your cheeks, making paths through the blood and grime. How ironic that the very being that sought immortality in the end disintegrates\n"
            << "into nothingness, as if it never existed. You stand up, legs still shaking and make your way to the grand staircase that waits for you behind the Lichs accursed throne.\n\n";


        cout << "You take a step upwards, relishing the feeling of finally moving upand out of the lair.You still can’t help the feeling that there is more.That the Lich went down too easily.\n"
            << " Shrugging it off as paranoia, you continue your ascent.Suddenly, the steps lurch beneath youand both the entranceand exit are blocked off.Little did you know, you entered into the belly of the beast. ";


    }
    else
    {
        cout << "LICH WINS :( " << endl;
        lives--;
        cout << "You fall to your feet. You barely feel anything over the burns maring your skin. You know that you have a few broken ribs. Gasping for air, you watch as the Lich\n"
            << "lumber towards you slowly, knowing you cannot get away. Coming to stand before you, the Lich raises a single clawed hand over you. A sob wracks your body at the overwhelming\n"
            << "pain of your soul being ripped from you. The Lichs hand glows a bright blue as it rends your soul for its own. For a moment, you see your lifeless body laying on the ground, like\n"
            << "a bloodied ragdoll. Then, nothing.\n\n";
    }

    return lives;
}//end lichBattle

void BluePath()
{
    cout << "Choosing the blue path, you find yourself journeying up for around 20 yards before the path levels out. You take a \n"
        << "moment to appreciate the glowing stones. They are smoothed out from adventurers attempting the same journey you are on \n"
        << "now. You know that countless other adventurers have died before you, and steel yourself for your upcoming fights.\n\n"
        << "You lose track of time, marching forward, until you reach a small room. In the far corner, you spot a small shaking figure. \n"
        << "Whether it is the glow of the stones or the pallid skin of the creature itself, it appears as if it is already dead with a \n"
        << "green hue to its skin. You step forward and the creature immediately turns to you. You see that it is a malnourished goblin.\n"
        << "Readying yourself for battle, the goblin lets out a shrill shriek and lunges for you.\n";
}

void OnwardThrall()
{
    cout << "Moving past the area, you continue down a long hallway. Now, instead of being lit by the soft blue glow of stones, the\n"
        << "path is lit by torches along the wall. The flickering fire illuminates your face as you move forward. You have no option but\n"
        << "to continue and journey further into the Lichs Lair. \n\n"

        << "The tunnel opens again into a well - lit cavern.In the middle of the room, a skeleton thrall turns to face you.It makes no move yet.\n"
        << "Gazing at the skeleton, you spot what appears to be an enchanted blade on its hip.You step towards it and the moment you move, it drops\n"
        << "into a fighting stance.You let out a battle scream as you run headlong into the fray.\n\n";
}

void OnwardLich()
{
    cout << "Moving past the torch-lit arena, you find yourself on a long and winding stairwell. It dives deep into the earth, and the darkness of the path\n"
        << "envelopes you once again, much like the entrance to the dungeon. The cold stagnant air fills your lungs and as you move onward, the temperature continues to drop.\n"
        << "Eventually, you reach a point where your breath comes out in a light fog from your mouth, but further you descend still.\n\n"
        << "As you climb the stairwell downwards, you begin to wonder if there truly is a Lich at the bottom. What if this is just a pit into the bowels of earth that you can never escape.\n"
        << "The stones surrounding you that make up the stairwell hallway feel as if they are closing in on you. For the first time you have entered the dungeon, you are truly scared.\n"
        << "You will yourself to keep moving forward.\n\n"
        << "Finally, you see a flood of light just a few flights down. You eagerly rush towards it, desperate to be out of the choking darkness. Reaching the bottom of the stairs, the hallway\n"
        << "opens up into a grand throne room. Atop a throne of bones in the center of the room sits the fabled Lich you have been searching for. You wonder how many adventurers \n"
        << "Tbones make up the grand throne he sits upon.\n\n"
        << "The Lich raises from its throne. You take in the full magnitude of its size and you feel a menacing aura coming off of it. Suppressing a shiver of fear, your hand goes to rest \n"
        << "on the hilt of your weapon. The Lichs one glowing eye stares at you with a cold indifference, likely encountering many heroes just like you that failed to make a dent in its health.\n"
        << "You know what you must do.\n\n";

}
