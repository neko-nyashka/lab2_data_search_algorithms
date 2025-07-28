#include "hash_table.h"

Item::Item() {
    key = "";
    values = nullptr; 
    next = nullptr;
}

Item::Item(const std::string& key_, const Flight& value_) {
    key = key_;
    values = new std::vector<Flight>();
    values->push_back(value_);
    next = nullptr;
}

int HashTable::get_collision_count() const {
    return collision_count;
}

HashTable::HashTable(int size_) {
    size = size_;
    items = new Item[size_]; 
    collision_count = 0;
}

HashTable::~HashTable() {
    if (items) {
        for (int i = 0; i < size; i++) {
            Item* current = items[i].next;
            while (current != nullptr) {
                Item* temp = current;
                current = current->next;
                delete temp->values; 
                delete temp;         
            }
        }
        delete[] items;
    }
}

int HashTable::hash_function(const std::string& key) const {
    unsigned long h = 0;
    const unsigned long P = 31;
    for (char c : key) {
        h = h * P + c;
    }
    return h % size;
}

void HashTable::insert(const Flight& value) {
    std::string key = value.Get_airline();
    int h = hash_function(key);
    bool found = false;
    
    Item* current = items[h].next;

    while (current != nullptr) {
        if (current->key == key) {
            current->values->push_back(value); 
            found = true;
            break;
        }

        current = current->next;
    }

    if (!found) {
        Item* new_node = new Item(key, value);
        new_node->next = items[h].next; 
        items[h].next = new_node;

        if (new_node->next != nullptr) {
            collision_count++;
        }
    }
}

int HashTable::search(const std::string& key, std::vector<Flight>& result) const {
    int h = hash_function(key);
    Item* current = items[h].next; 

    while (current != nullptr) {
        if (current->key == key) {
            result.insert(result.end(), current->values->begin(), current->values->end());
            break; 
        }
        current = current->next;
    }
    return result.size();
}