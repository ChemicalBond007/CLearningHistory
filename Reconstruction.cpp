#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream> // Required for file input/output
#include <locale>  // Required for UTF-8 locale setup

// Helper function to escape strings for JSON compatibility.
std::string escape_json(const std::string &s) {
    std::stringstream ss;
    for (auto c : s) {
        switch (c) {
            case '"':  ss << "\\\""; break;
            case '\\': ss << "\\\\"; break;
            default:   ss << c;      break;
        }
    }
    return ss.str();
}

// Structure to hold the parsed data for a single question.
struct Question {
    std::string j_id;
    std::string p_id;
    std::string i_id;
    std::string question_text;
    std::string true_answer;
    std::map<char, std::string> options;

    // Method to convert this structure to a JSON string.
    std::string to_json() const {
        std::stringstream ss;
        ss << "{";
        ss << "\"J_ID\":\"" << escape_json(j_id) << "\",";
        ss << "\"P_ID\":\"" << escape_json(p_id) << "\",";
        ss << "\"I_ID\":\"" << escape_json(i_id) << "\",";
        ss << "\"Question\":\"" << escape_json(question_text) << "\",";
        ss << "\"TrueAnswer\":\"" << escape_json(true_answer) << "\",";
        ss << "\"Options\":{";
        bool first_option = true;
        for (const auto& pair : options) {
            if (!first_option) ss << ",";
            ss << "\"" << pair.first << "\":\"" << escape_json(pair.second) << "\"";
            first_option = false;
        }
        ss << "}"; // Close Options
        ss << "}"; // Close main object
        return ss.str();
    }
};

// Helper function to extract content for a given tag.
std::string extract_field(const std::string& record_str, const std::string& tag) {
    size_t start_pos = record_str.find(tag);
    if (start_pos == std::string::npos) return "";
    start_pos += tag.length();
    size_t end_pos = record_str.find('[', start_pos);
    std::string result = record_str.substr(start_pos, end_pos - start_pos);
    size_t first = result.find_first_not_of(" \t\n\r");
    if (std::string::npos == first) return "";
    size_t last = result.find_last_not_of(" \t\n\r");
    return result.substr(first, (last - first + 1));
}

int main(int argc, char* argv[]) {
    // Set the global locale to support UTF-8 characters correctly.
    std::locale::global(std::locale(""));

    // --- Argument Parsing and File Handling ---
    if (argc < 3) {
        std::cerr << "Error: Please provide input and output filenames." << std::endl;
        std::cerr << "Usage: " << argv[0] << " <input_filename> <output_filename>" << std::endl;
        return 1;
    }

    const std::string input_filename = argv[1];
    const std::string output_filename = argv[2];

    std::ifstream input_file(input_filename);
    if (!input_file.is_open()) {
        std::cerr << "Error: Could not open input file '" << input_filename << "'" << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << input_file.rdbuf();
    std::string input = buffer.str();
    input_file.close();

    // --- Parsing Logic (unchanged) ---
    std::vector<Question> questions;
    size_t current_pos = 0;
    while ((current_pos = input.find("[J]", current_pos)) != std::string::npos) {
        size_t next_pos = input.find("[J]", current_pos + 1);
        std::string record_str = input.substr(current_pos, next_pos - current_pos);
        Question q;
        q.j_id = extract_field(record_str, "[J]");
        q.p_id = extract_field(record_str, "[P]");
        q.i_id = extract_field(record_str, "[I]");
        q.question_text = extract_field(record_str, "[Q]");
        q.true_answer = extract_field(record_str, "[T]");
        q.options['A'] = extract_field(record_str, "[A]");
        q.options['B'] = extract_field(record_str, "[B]");
        q.options['C'] = extract_field(record_str, "[C]");
        q.options['D'] = extract_field(record_str, "[D]");
        questions.push_back(q);
        if (next_pos == std::string::npos) break;
        current_pos = next_pos;
    }

    // --- JSON Generation (unchanged) ---
    std::stringstream json_output_ss;
    json_output_ss << "[" << std::endl;
    for (size_t i = 0; i < questions.size(); ++i) {
        json_output_ss << "  " << questions[i].to_json();
        if (i < questions.size() - 1) {
            json_output_ss << ",";
        }
        json_output_ss << std::endl;
    }
    json_output_ss << "]" << std::endl;

    // --- Write to Output File ---
    std::ofstream output_file(output_filename);
    if (!output_file.is_open()) {
        std::cerr << "Error: Could not create or open output file '" << output_filename << "'" << std::endl;
        return 1;
    }

    output_file << json_output_ss.str();
    output_file.close();

    // --- Success Message ---
    std::cout << "Successfully converted '" << input_filename << "' to '" << output_filename << "'." << std::endl;

    return 0;
}