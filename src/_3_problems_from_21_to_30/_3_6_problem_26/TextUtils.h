#pragma once

#include <string>
using namespace std;

namespace TextUtils {
    inline string toUppercaseText(
        string text
    ) {
        for (char& character : text)
            character = static_cast<char>(
                toupper(
                    character
                )
            );
        return text;
    }

    inline string toLowercaseText(
        string text
    ) {
        for (char& character : text)
            character = static_cast<char>(
                tolower(
                    character
                )
            );
        return text;
    }
}