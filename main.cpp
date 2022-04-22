// Asicosilomu Shell by the all-mighty Asicosilomu.
// Like Asicosilomu Terminal except it's made specifically for Linux-based systems.
// If you're on Windows, use asicosilomu-terminal instead. It won't work there. (see #include <unistd.h>)

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <limits>
#include <sstream>
#include <string>
#include <cstring>
#include <chrono>
#include <thread>
#include <unistd.h>

using namespace std;

string cmd;
string orig;
string tc;

bool hasStarted = false;
bool title_isCustomTitleSet = false;

string promptInputCommand() {
    if (hasStarted == true) {
        cout << endl << endl << "Asicosilomu$ ";
    } else {
        cout << "Asicosilomu Shell version 1.0, by the all-mighty Asicosilomu. Extended from Asicosilomu Terminal 1.0. No rights reserved." << endl << endl << "Asicosilomu$ ";
        hasStarted = true;
    }
    getline(cin, cmd);
    cout << endl;
    return cmd;
}

int main()
{
    if (title_isCustomTitleSet != true) { std::cout << "\033]0;" << "Asicosilomu Shell" << "\007"; };
    while (true) {
        if (title_isCustomTitleSet != true) { std::cout << "\033]0;" << "Asicosilomu Shell" << "\007"; };
        cmd = promptInputCommand();
        tc = cmd;
        stringstream paramParser(cmd);
        paramParser >> cmd;
        orig = cmd;
        transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
        string finalTitleStr = tc + " - Asicosilomu Shell";
        if (title_isCustomTitleSet != true) { std::cout << "\033]0;" << finalTitleStr << "\007";};
        if (cmd == "help") {
            cout << "Basic Asicosilomu Shell commands:" << endl << "help - Displays this message." << endl << "cls - Clears the terminal screen." << endl << "echo <text> - Prints a message to the output." << endl << "exit - Exits Asicosilomu Shell." << endl << "sh - Run the provided code using the unistd.h system function." << endl << "ewwrat - theres a rat amogus" << endl << "title <text> - Sets the window title to the specified text." << endl << "countdown <time> <endMessage> - Counts down <time> seconds, displaying <endMessage> when finished.";
        } else if (cmd == "cls") {
            hasStarted = false;
            system("clear");
        } else if (cmd == "echo") {
            string echo_str;
            bool echo_hasStarted;
            while (paramParser >> echo_str) {
                if (echo_hasStarted == true) {
                    cout << " ";
                } else {
                    echo_hasStarted = true;
                }
                cout << echo_str;
            }
        } else if (cmd == "exit") {
            return 0;
        } else if (cmd == "sh") {
            string sh_str;
             string sh_finalcmd = "";
            bool sh_hasStarted;
            while (paramParser >> sh_str) {
                if (sh_hasStarted == true) {
                    sh_finalcmd = sh_finalcmd + " ";
                } else {
                    sh_hasStarted = true;
                }
                sh_finalcmd = sh_finalcmd + sh_str;
            }
            int sh_cmdLength = sh_finalcmd.length();
            char sh_arr[sh_cmdLength + 1];
            strcpy(sh_arr, sh_finalcmd.c_str());
            system(sh_arr);
        } else if (cmd == "ewwrat") {
            cout << "Mom: eww theres a rat in the house get rid of it, NOW!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "Me: not a big deal" << endl;
            cout << endl;
            cout << "               _     __,..---''''-._                 ';-,";
            cout << endl;
            cout << "        ,    _/_),-''              '-.                `\\";
            cout << endl;
            cout << "       \|.-''`    -_)                 '.                ||";
            cout << endl;
            cout << "       /`   a   ,                      \              .'/";
            cout << endl;
            cout << "       '.___,__/                 .-'    \_        _.-'.'";
            cout << endl;
            cout << "          |\  \      \         /`        _`''''''''''''`_.-'";
            cout << endl;
            cout << "             _/;--._, >        |   --.__/ `''''''''''''`";
            cout << endl;
            cout << "           (((-'  __//`'-......-;\      )";
            cout << endl;
            cout << "                (((-'       __//  '--. /";
            cout << endl;
            cout  << "        jgs               (((-'    __//";
            cout << endl;
            cout << "                                 (((-'";
            cout << endl;
            cout << endl;
            cout << "Me: DAD, THERE'S A RAT IN THE HOUSE!!!!!!!!!!";
        } else if (cmd == "title") {
            string title_t;
            string title_f = "";
            bool title_hasStarted;
            while (paramParser >> title_t) {
                if (title_hasStarted == true) {
                    title_f = title_f + " ";
                } else {
                    title_hasStarted = true;
                }
                title_f = title_f + title_t;
            };
            if (title_f != "") {
                std::cout << "\033]0;" << title_f << "\007";
            } else {
                cout << "No title provided. Console title not changed.";
            }
        } else if (cmd == "countdown") {
            int countdown_countdownTime;
            int countdown_curTime;
            string countdown_timesUpMessage = "";
            if (paramParser >> countdown_countdownTime) {
                bool countdown_tumh = false;
                string countdown_tmg = "";
                while (paramParser >> countdown_tmg) {
                    if (countdown_tumh == true) {
                        countdown_timesUpMessage = countdown_timesUpMessage + " ";
                    } else {
                        countdown_tumh = true;
                    }
                    countdown_timesUpMessage = countdown_timesUpMessage + countdown_tmg;
                }
                if (countdown_timesUpMessage == "") {
                    cout << "WARNING: No countdown ending message specified. Using default: Time's up!" << endl << endl;
                    countdown_timesUpMessage = "Time's up!";
                }
                countdown_curTime = countdown_countdownTime;
                while (countdown_curTime > 0) {
                    sleep(1);
                    cout << countdown_curTime << endl;
                    countdown_curTime = countdown_curTime - 1;
                }
                cout << endl << countdown_timesUpMessage;
            } else {
                cout << "Specify a valid countdown time!";
            }
        } else {
            cout << "'" << orig << "' is not recognized as a valid command. Type 'help' for a list of available commands.";
        }
    }
    return 0;
}
