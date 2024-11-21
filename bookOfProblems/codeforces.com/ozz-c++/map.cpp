#include <iostream>
#include <unordered_map>

int main()
{
    // Declare an unordered_map with string keys and int values
    std::unordered_map<std::string, int> my_map;

    std::unordered_set<char> st;
    for (auto &c : s)
        st.insert(c);

    // Создаем unordered_map из трех строк (которые отображаются на строки)
    std::unordered_map<std::string, std::string> u = {
        {"RED", "#FF0000"},
        {"GREEN", "#00FF00"},
        {"BLUE", "#0000FF"}};

    // Insert elements into the map using emplace
    my_map.emplace("apple", 1);
    my_map.emplace("banana", 2);
    my_map.emplace("cherry", 3);

    // Добавляем две новые записи в unordered_map
    u["BLACK"] = "#000000";
    u["WHITE"] = "#FFFFFF";

    // Iterate over the elements in the map
    for (const auto &[key, value] : my_map)
    {
        std::cout << key << " : " << value << std::endl;
    }

    // Check if the map contains a key
    if (my_map.count("banana"))
    {
        std::cout << "The map contains a banana!" << std::endl;
    }

    // Вспомогательная лямбда-функция для печати пар ключ-значение
    auto print_key_value = [](const auto &key, const auto &value)
    {
        std::cout << "Key:[" << key << "] Value:[" << value << "]\n";
    };

    std::cout << "Iterate and print key-value pairs of unordered_map, being\n"
                 "explicit with their types:\n";
    for (const std::pair<const std::string, std::string> &n : u)
    {
        print_key_value(n.first, n.second);
    }

    std::cout << "\nIterate and print key-value pairs using C++17 structured binding:\n";
    for (const auto &[key, value] : u)
    {
        print_key_value(key, value);
    }

    // Remove an element from the map
    my_map.erase("cherry");

    // Clear all elements from the map
    my_map.clear();

    return 0;
}
https : // codeforces.com/blog/entry/62393

        We always assume hash maps are O(1) per operation(insert, erase, access, etc.)
            .But this depends on a key assumption,
    which is that each item only runs into O(1) collisions on average.If our input data is completely random, this is a reasonable assumption.But this is no longer a safe bet when the input isn't random, especially so if someone is adversarially designing inputs to our code (a.k.a. hacking phase). In particular, if they know our hash function, they can easily generate a large number of different inputs that all collide, thus causing an O(n2) blow-up.
