#include "bowling.h"
#include <time.h>

static void init_game(Game *game, const char *player_name);
static void print_scoreboard(const Game *game);
static void calculate_scores(Game *game);
static int get_pins(int max_pins);
static void save_score(const char* player_name, int score);

void play_game() {
    Game game;
    char player_name[MAX_PLAYER_NAME + 1];

    printf("플레이어 이름을 입력하세요 (최대 %d글자): ", MAX_PLAYER_NAME);
    scanf("%9s", player_name);

    init_game(&game, player_name);

    for (int i = 0; i < MAX_FRAMES; i++) {
        game.current_frame = i;
        print_scoreboard(&game);
        printf("%d frame 1 cast : ", i + 1);

        game.frames[i].rolls[0] = get_pins(10);

        if (game.frames[i].rolls[0] == 10) { // Strike
            game.frames[i].is_strike = true;
            if (i == MAX_FRAMES - 1) { // 10th frame
                print_scoreboard(&game);
                printf("%d frame 2 cast : ", i + 1);
                game.frames[i].rolls[1] = get_pins(10);
                print_scoreboard(&game);
                printf("%d frame 3 cast : ", i + 1);
                if (game.frames[i].rolls[1] == 10) {
                    game.frames[i].rolls[2] = get_pins(10);
                } else {
                    game.frames[i].rolls[2] = get_pins(10 - game.frames[i].rolls[1]);
                }
            }
        } else {
            print_scoreboard(&game);
            printf("%d frame 2 cast : ", i + 1);
            game.frames[i].rolls[1] = get_pins(10 - game.frames[i].rolls[0]);

            if (game.frames[i].rolls[0] + game.frames[i].rolls[1] == 10) {
                game.frames[i].is_spare = true;
                if (i == MAX_FRAMES - 1) { // 10th frame
                    print_scoreboard(&game);
                    printf("%d frame 3 cast : ", i + 1);
                    game.frames[i].rolls[2] = get_pins(10);
                }
            }
        }
        calculate_scores(&game);
    }
    game.current_frame = MAX_FRAMES;
    print_scoreboard(&game);
    printf("\n게임이 종료되었습니다!\n");
    int final_score = game.frames[MAX_FRAMES - 1].cumulative_score;
    printf("최종 점수: %d\n", final_score);
    save_score(game.player_name, final_score);
}

static void init_game(Game *game, const char *player_name) {
    strncpy(game->player_name, player_name, MAX_PLAYER_NAME);
    game->player_name[MAX_PLAYER_NAME] = '\0';
    game->current_frame = 0;
    for (int i = 0; i < MAX_FRAMES; i++) {
        game->frames[i].rolls[0] = -1;
        game->frames[i].rolls[1] = -1;
        game->frames[i].rolls[2] = -1;
        game->frames[i].frame_score = 0;
        game->frames[i].cumulative_score = 0;
        game->frames[i].is_strike = false;
        game->frames[i].is_spare = false;
        game->frames[i].bonus = 0;
    }
}

static void print_scoreboard(const Game *game) {
    printf("\nPlayer name: %s\n", game->player_name);
    printf("-------------------------------------------\n");
    printf("| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10  |\n");
    printf("-------------------------------------------\n");
    printf("|");
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (game->frames[i].is_strike) {
            printf("X| |");
        } else if (game->frames[i].is_spare) {
            printf("%d|/|", game->frames[i].rolls[0]);
        } else {
            if (game->frames[i].rolls[0] != -1) {
                printf("%d|", game->frames[i].rolls[0]);
            } else {
                printf(" |");
            }
            if (game->frames[i].rolls[1] != -1) {
                printf("%d|", game->frames[i].rolls[1]);
            } else {
                printf(" |");
            }
        }
    }
    printf("\n-------------------------------------------\n");
    printf("|");
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (game->frames[i].cumulative_score > 0) {
            printf("%3d|", game->frames[i].cumulative_score);
        } else {
            printf("   |");
        }
    }
    printf("\n-------------------------------------------\n");
    printf("Player : %s\n", game->player_name);
}


static void calculate_scores(Game *game) {
    for (int i = 0; i <= game->current_frame && i < MAX_FRAMES; i++) {
        int frame_score = 0;
        if(game->frames[i].rolls[0] != -1) frame_score += game->frames[i].rolls[0];
        if(game->frames[i].rolls[1] != -1) frame_score += game->frames[i].rolls[1];


        if (game->frames[i].is_strike) {
            frame_score = 10;
            if (i < MAX_FRAMES - 1) {
                if (game->frames[i + 1].is_strike) { // Next frame is a strike
                    frame_score += 10;
                    if (i < MAX_FRAMES - 2) {
                         if (game->frames[i + 2].rolls[0] != -1) {
                            frame_score += game->frames[i + 2].rolls[0];
                        }
                    } else { // 10th frame case
                        if(game->frames[i+1].rolls[1] != -1) {
                             frame_score += game->frames[i+1].rolls[1];
                        }
                    }
                } else if (game->frames[i + 1].rolls[0] != -1 && game->frames[i + 1].rolls[1] != -1) {
                    frame_score += game->frames[i + 1].rolls[0] + game->frames[i + 1].rolls[1];
                }
            } else { // 10th frame
                 if(game->frames[i].rolls[1] != -1) frame_score += game->frames[i].rolls[1];
                 if(game->frames[i].rolls[2] != -1) frame_score += game->frames[i].rolls[2];
            }
        } else if (game->frames[i].is_spare) {
            frame_score = 10;
            if (i < MAX_FRAMES - 1 && game->frames[i + 1].rolls[0] != -1) {
                frame_score += game->frames[i + 1].rolls[0];
            } else { // 10th frame
                 if(game->frames[i].rolls[2] != -1) frame_score += game->frames[i].rolls[2];
            }
        }

        game->frames[i].frame_score = frame_score;

        if (i == 0) {
            game->frames[i].cumulative_score = game->frames[i].frame_score;
        } else {
            if (game->frames[i-1].cumulative_score > 0 && game->frames[i].frame_score > 0)
             game->frames[i].cumulative_score = game->frames[i - 1].cumulative_score + game->frames[i].frame_score;
        }
    }
}


static int get_pins(int max_pins) {
    int pins;
    while (1) {
        if (scanf("%d", &pins) == 1 && pins >= 0 && pins <= max_pins) {
            return pins;
        } else {
            printf("유효한 점수를 입력하세요 (0-%d): ", max_pins);
            while (getchar() != '\n'); // Clear input buffer
        }
    }
}

static void save_score(const char* player_name, int score) {
    FILE* file = fopen("records.csv", "a");
    if (file == NULL) {
        printf("Error opening records file.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    char date_str[20];
    strftime(date_str, sizeof(date_str), "%Y-%m-%d", tm);

    fprintf(file, "%s,%d,%s\n", player_name, score, date_str);
    fclose(file);
}

void view_records() {
    FILE* file = fopen("records.csv", "r");
    if (file == NULL) {
        printf("아직 기록이 없습니다.\n");
        return;
    }

    char player_name_filter[MAX_PLAYER_NAME + 1];
    printf("플레이어 이름 입력하세요 (최대 %d글자): ", MAX_PLAYER_NAME);
    scanf("%9s", player_name_filter);
    printf("\n--- %s 의 기록 보기 ---\n", player_name_filter);
    printf("  Score Date\n");
    printf("-------------------\n");

    char line[100];
    bool found = false;
    while (fgets(line, sizeof(line), file)) {
        char player_name[MAX_PLAYER_NAME + 1];
        int score;
        char date[20];
        if (sscanf(line, "%[^,],%d,%s", player_name, &score, date) == 3 && strcmp(player_name, player_name_filter) == 0) {
            printf("  %-5d %s\n", score, date);
            found = true;
        }
    }
    if (!found) {
        printf("  해당 플레이어의 기록이 없습니다.\n");
    }
    printf("-------------------\n");

    fclose(file);
}
