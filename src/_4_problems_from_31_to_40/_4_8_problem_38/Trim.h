#pragma once

#include <iostream>
using namespace std;

namespace Trim {
    inline string trimLeft(
        const string& TEXT
    ) {
        auto start = TEXT.begin();
        const auto END = TEXT.end();

        while (
            start != END &&
            isspace(
                *start
            )
        )
            ++start;

        return {
            start,
            END + 1
        };
    }

    inline string trimRight(
        const string& TEXT
    ) {
        const auto START = TEXT.begin();
        auto end = TEXT.end();

        do {
            --end;
        } while (
            end != START &&
            isspace(
                *end
            )
        );

        return {
            START,
            end + 1
        };
    }

    inline string trim(
        const string& TEXT
    ) {
        auto start = TEXT.begin();
        auto end = TEXT.end();

        while (
            start != end &&
            isspace(
                *start
            )
        )
            ++start;

        do {
            --end;
        } while (
            end != start &&
            isspace(
                *end
            )
        );

        return {
            start,
            end + 1
        };
    }
}