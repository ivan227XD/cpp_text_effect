#include <thread>
#include <stdio.h>

// UTF-8

int main() {
    printf("\n\n\n\n\n\n\n");
    std::this_thread::sleep_for(std::chrono::seconds(2));

    const char* text[] = {
        "You_text_1\n\n",
        "@Pause@\n\n",
        "You_text_2\n\n"
    };

    const char* a = "      - (Author)";

    for (int p = 0; p < 3; p++) {
        const char* crnt = text[p];
        for (int i = 0; crnt[i] != '\0'; i++) {

            if (crnt[i] == '@') {
                std::this_thread::sleep_for(std::chrono::milliseconds(600));
                continue;
            }

            printf("%c", crnt[i]);
            fflush(stdout);
            std::this_thread::sleep_for(std::chrono::milliseconds(240));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(360));
    }

    std::this_thread::sleep_for(std::chrono::seconds(3));

    const char* fade[] = { "\033[38;5;235m", "\033[38;5;239m",
                                  "\033[38;5;244m", "\033[38;5;249m", 
                                  "\033[38;5;254m", "\033[0m" };

    for (int i = 0; i < 6; i++) {
        printf("\r%s%s", fade[i], a);
        fflush(stdout);
        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }
    
    printf("\n\n");

    std::this_thread::sleep_for(std::chrono::seconds(3));

    return 0;
}
