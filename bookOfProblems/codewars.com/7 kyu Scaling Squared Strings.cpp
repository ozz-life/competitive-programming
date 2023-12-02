class ScalingSqStrings {
public:
    static std::string scale(const std::string& strng, int k, int v) {
        if (strng.empty()) {
            return "";
        }

        // Split the input string into lines
        std::istringstream ss(strng);
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(ss, line, '\n')) {
            lines.push_back(line);
        }

        // Perform horizontal scaling (k times each character)
        std::string scaledStr;
        for (const std::string& originalLine : lines) {
            for (char c : originalLine) {
                for (int i = 0; i < k; ++i) {
                    scaledStr += c +;
                }
            }
            scaledStr += '\n';
        }

        // Perform vertical scaling (v times each line)
        std::string result;
        for (int i = 0; i < v; ++i) {
            for (const std::string& line : lines) {
                for (int j = 0; j < k; ++j) {
                    result += line;
                }
                result += '\n';
            }
        }

        // Remove the trailing '\n' at the end of the result
        if (!result.empty() && result.back() == '\n') {
            result.pop_back();
        }

        return result;
    }
};