#include "hash_table.h"
int HashTable::get_collision_count() const {
    return collision_count;
}
HashTable::HashTable(int size_) {
    size = size_;
    table.resize(size_);
}

int HashTable::hash_function(const std::string& key) const {
    unsigned long h = 0;
    const unsigned long P = 31;
    for (unsigned char c : key) {
        h = h * P + c;
    }
    return h % size;

}
void HashTable::insert(const Flight& value) {
    std::string key = value.Get_airline();
    int h = hash_function(key);
    bool key_exists = false;
    bool other_key_exists = false;

    for (const Flight& flight : table[h]) {
        if (flight.Get_airline() == key) {
            key_exists = true;
        } else {
            other_key_exists = true;
        }
    }


    if (!key_exists && other_key_exists) {
        collision_count++;
    }
    table[h].push_back(value);

}

int HashTable::search(const std::string& key, std::vector<Flight>& result) const {
    int h = hash_function(key);
    for(int i = 0; i < (int) table[h].size(); ++i) {
        if(table[h][i].Get_airline() == key) result.push_back(table[h][i]);
    }
    return result.size();
    
    
}

