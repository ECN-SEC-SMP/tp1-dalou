#pragma once

#include <string>
#include <cstdint>

/* Font formatting with ANSI Escape Sequences */
#define ANSI_BLACK              "\033[30m"
#define ANSI_RED                "\033[31m"
#define ANSI_GREEN              "\033[32m"
#define ANSI_YELLOW             "\033[33m"
#define ANSI_BLUE               "\033[34m"
#define ANSI_MAGENTA            "\033[35m"
#define ANSI_CYAN               "\033[36m"
#define ANSI_WHITE              "\033[37m"
#define ANSI_BRIGHT_BLACK       "\033[90m"
#define ANSI_BRIGHT_RED         "\033[91m"
#define ANSI_BRIGHT_GREEN       "\033[92m"
#define ANSI_BRIGHT_YELLOW      "\033[93m"
#define ANSI_BRIGHT_BLUE        "\033[94m"
#define ANSI_BRIGHT_MAGENTA     "\033[95m"
#define ANSI_BRIGHT_CYAN        "\033[96m"
#define ANSI_BRIGHT_WHITE       "\033[97m"
#define ANSI_ORANGE             "\033[38;5;214m"
#define ANSI_LIGHT_GRAY         "\033[38;5;253m"
#define ANSI_DARK_GRAY          "\033[38;5;238m"

#define ANSI_BG_BLACK           "\033[40m"
#define ANSI_BG_RED             "\033[41m"
#define ANSI_BG_GREEN           "\033[42m"
#define ANSI_BG_YELLOW          "\033[43m"
#define ANSI_BG_BLUE            "\033[44m"
#define ANSI_BG_MAGENTA         "\033[45m"
#define ANSI_BG_CYAN            "\033[46m"
#define ANSI_BG_WHITE           "\033[47m"
#define ANSI_BG_BRIGHT_BLACK    "\033[100m"
#define ANSI_BG_BRIGHT_RED      "\033[101m"
#define ANSI_BG_BRIGHT_GREEN    "\033[102m"
#define ANSI_BG_BRIGHT_YELLOW   "\033[103m"
#define ANSI_BG_BRIGHT_BLUE     "\033[104m"
#define ANSI_BG_BRIGHT_MAGENTA  "\033[105m"
#define ANSI_BG_BRIGHT_CYAN     "\033[106m"
#define ANSI_BG_BRIGHT_WHITE    "\033[107m"

#define ANSI_RESET              "\033[0m"
#define ANSI_BOLD               "\033[1m"
#define ANSI_RESET_BOLD         "\033[22m"
#define ANSI_ITALIC             "\033[3m"
#define ANSI_RESET_ITALIC       "\033[23m"
#define ANSI_UNDERLINE          "\033[4m"
#define ANSI_RESET_UNDERLINE    "\033[24m"
#define ANSI_BLINKING           "\033[5m"
#define ANSI_RESET_BLINKING     "\033[25m"
#define ANSI_INVERSE            "\033[7m"
#define ANSI_RESET_INVERSE      "\033[27m"
#define ANSI_HIDDEN             "\033[8m"
#define ANSI_RESET_HIDDEN       "\033[28m"
#define ANSI_STRIKETHROUGH       "\033[9m"
#define ANSI_RESET_STRIKETHROUGH "\033[29m"

#define ANSI_BEL 	            "\007" 
#define ANSI_BS 	            "\010" 
#define ANSI_HT 	            "\011" 
#define ANSI_LF 	            "\012" 
#define ANSI_VT 	            "\013" 
#define ANSI_FF 	            "\014" 
#define ANSI_CR 	            "\015" 
#define ANSI_ESC 	            "\033" 
#define ANSI_DEL                "\177"

#define ANSI_INVISIBLE_CURSOR   "\033[?25l"
#define ANSI_VISIBLE_CURSOR     "\033[?25h"
#define ANSI_RESTOR_SCREEN      "\033[?47l"
#define ANSI_SAVE_SCREEN        "\033[?47h"
#define ANSI_EN_ALT_BUFFER      "\033[?1049l"
#define ANSI_DIS_ALT_BUFFER     "\033[?1049h"

namespace ANSI
{
    inline std::string get256Colors(int id)
    {
        return std::string("\033[38;5;" + std::to_string(id) + "m");
    }
    inline std::string getBG_256Colors(int id)
    {
        return std::string("\033[48;5;" + std::to_string(id) + "m");
    }
    

    inline std::string getRGBColors(uint8_t r, uint8_t g, uint8_t b)
    {
        return std::string("\033[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m");
    }
    inline std::string getBG_RGBColors(uint8_t r, uint8_t g, uint8_t b)
    {
        return std::string("\033[48;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m");
    }
} // namespace ANSI
