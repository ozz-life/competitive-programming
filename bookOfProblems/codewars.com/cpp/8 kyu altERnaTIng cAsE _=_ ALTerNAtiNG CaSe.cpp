#include <string>

constexpr bool is_ascii_lowercase(char c) noexcept {
    return c >= 'a' && c <= 'z';
}

std::string to_alternating_case(const std::string& str) {
    std::string result = str;

    for (auto &c : result) {
        if (is_ascii_lowercase(c)) {
            c = std::toupper(c);
        } else {
            c = std::tolower(c);
        }
    }

    return result;
}