#include <iostream>
#include <vector>

template <typename KeyType, typename ValueType>
class Registry {
    std::vector<std::pair<KeyType, ValueType>> data;

public:
    void addElement(const KeyType &key, const ValueType &value) {
        data.push_back(std::make_pair(key, value));
    }

    void removeElementsByKey(const KeyType &key) {
        typename std::vector<std::pair<KeyType, ValueType>>::iterator it = data.begin();
        while (it != data.end()) {
            if (it->first == key) {
                it = data.erase(it);
            } else {
                ++it;
            }
        }
    }

    void printAll() const {
        for (typename std::vector<std::pair<KeyType, ValueType>>::const_iterator it = data.begin();
             it != data.end(); ++it) {
            std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        }
    }

    std::vector<ValueType> findByKey(const KeyType &key) const {
        std::vector<ValueType> result;
        for (typename std::vector<std::pair<KeyType, ValueType>>::const_iterator it = data.begin();
             it != data.end(); ++it) {
            if (it->first == key) {
                result.push_back(it->second);
            }
        }
        return result;
    }
};

int main() {
    Registry<int, std::string> registry;

    while (true) {
        std::cout << "Enter command (add/remove/print/find/exit): ";
        std::string command;
        std::cin >> command;

        if (command == "exit") {
            break;
        } else if (command == "add") {
            int key;
            std::string value;
            std::cout << "Enter key: ";
            std::cin >> key;
            std::cout << "Enter value: ";
            std::cin >> value;
            registry.addElement(key, value);
        } else if (command == "remove") {
            int key;
            std::cout << "Enter key to remove: ";
            std::cin >> key;
            registry.removeElementsByKey(key);
        } else if (command == "print") {
            registry.printAll();
        } else if (command == "find") {
            int key;
            std::cout << "Enter key to find: ";
            std::cin >> key;
            std::vector<std::string> values = registry.findByKey(key);
            if (!values.empty()) {
                std::cout << "Found values:";
                for (typename std::vector<std::string>::const_iterator it = values.begin(); it != values.end(); ++it) {
                    std::cout << " " << *it;
                }
                std::cout << std::endl;
            } else {
                std::cout << "No values found for the specified key." << std::endl;
            }
        } else {
            std::cout << "Invalid command. Try again." << std::endl;
        }
    }

    return 0;
}

