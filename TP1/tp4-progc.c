// chmod u+x nccomp
// ./nccomp tp4-progc
// ./tp4-progc

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

void dessiner_chat(int y, int x, int cas_chat) {
    mvprintw(y, x, "*****");
    if (cas_chat == 0)
        mvprintw(y + 1, x, "* * *");
    if (cas_chat == 1)
        mvprintw(y + 1, x, "X * *");
    if (cas_chat == 2)
        mvprintw(y + 1, x, "* * X");
    if (cas_chat == 3)
        mvprintw(y + 1, x, "X * X");
    mvprintw(y + 2, x, "*****");
}

void effacer_chat(int y, int x) {
    mvprintw(y, x, "     ");
    mvprintw(y + 1, x, "     ");
    mvprintw(y + 2, x, "     ");
}

int main() {
    int touche;
    int chat_x, chat_y;
    int souris_x, souris_y;
    int cas_chat;
    MEVENT ev;

    srand(time(NULL));

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    chat_x = rand() % (COLS - 4);
    chat_y = rand() % (LINES - 2);
    cas_chat = 0;
    while (1) {
        touche = getch();
        if (touche == KEY_MOUSE && getmouse(&ev) == OK) {
            souris_x = ev.x;
            souris_y = ev.y;
            if ((chat_x == souris_x) && (chat_y + 1 == souris_y)){
                if (cas_chat == 2)
                    cas_chat = 3;
                if (cas_chat == 0)
                    cas_chat = 1;
            }
            else if ((chat_x + 4 == souris_x) && (chat_y + 1 == souris_y)){
                if (cas_chat == 1)
                    cas_chat = 3;
                if (cas_chat == 0)
                    cas_chat = 2;
            }
            else if ((chat_x <= souris_x) && (souris_x <= chat_x + 4) 
            && (chat_y <= souris_y) && (souris_y <= chat_y + 2)) {
                effacer_chat(chat_y, chat_x);
                chat_x = rand() % (COLS - 4);
                chat_y = rand() % (LINES - 2);
                cas_chat = 0;
                mvprintw(LINES / 2, (COLS / 2) - 9, "Attrape !");
                refresh();
                usleep(500000);
                mvprintw(LINES / 2, (COLS / 2) - 9, "         ");
            }
        }
        dessiner_chat(chat_y, chat_x, cas_chat);
        refresh();

    }

    getch();
    endwin();
    return 0;
}