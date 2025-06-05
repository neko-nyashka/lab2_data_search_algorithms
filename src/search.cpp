 #include "search.h"
#include <fstream>
#include "flight.h"
#include "bstree.h"
#include "rbtree.h"
#include <vector>
#include "hash_table.h"
#include <chrono>
#include <map>


int parseCSV(std::string filename, std::vector<Flight> &result) {
    int error = 0;
    std::ifstream in(filename);
    std::string line, flight_number_, airline_, arrival_date_, arrival_time_;
    int i1 = 0, i2 = 0, i3 = 0, i4 = 0, passengers_;

    if (in.is_open()) {
        while (std::getline(in, line)) {
            i1 = i2 = i3 = i4 = 0; 
            for (int i = 0; i < (int)line.size(); i++) {
                if (line[i] == ',') {
                    if (i1 == 0) i1 = i;
                    else if (i2 == 0) i2 = i;
                    else if (i3 == 0) i3 = i;
                    else if (i4 == 0) i4 = i;
                }
            }
            flight_number_ = line.substr(0, i1);
            airline_ = line.substr(i1 + 1, i2 - i1 - 1);
            arrival_date_ = line.substr(i2 + 1, i3 - i2 - 1);
            arrival_time_ = line.substr(i3 + 1, i4 - i3 - 1);
            
            try {
                passengers_ = std::stoi(line.substr(i4 + 1, line.size() - i4 - 1));
            } catch (...) {
                passengers_ = 0; 
            }

            Flight f(flight_number_, airline_, arrival_date_, arrival_time_, passengers_);
            result.push_back(f);
        }
        in.close();
    } else {
        error = 1;
    }
    return error;
}

int linear_search(const std::vector<Flight>& flights, std::vector<Flight>& result) {
    int found = 0;
    for (int i = 0; i < (int)flights.size(); ++i) {
        if (flights[i].Get_airline() == KEY) {
            result.push_back(flights[i]);
            found++;
        }
    }
    return found;
}


BSTree* binary_insert(const std::vector<Flight>& flights) {
    if (flights.empty()) return nullptr;
    
    TreeNode* root = new TreeNode(flights[0]);
    BSTree* tree = new BSTree(root);

    for (int i = 1; i < (int)flights.size(); i++) {
        tree->Insert(flights[i]);
    }

    return tree;
}


RBTree* rb_insert(const std::vector<Flight>& flights) {
    if (flights.empty()) return nullptr;
    
    RBTreeNode* root = new RBTreeNode(flights[0]);
    RBTree* tree = new RBTree(root);

    for (int i = 1; i < (int)flights.size(); i++) {
        tree->Insert(flights[i]);
    }

    return tree;
}


HashTable* hash_table_insert(const std::vector<Flight>& flights, int& collisions) {
    HashTable* table = new HashTable(7);

    for (int i = 0; i < (int)flights.size(); i++) {
        table->insert(flights[i]);
    }
    
    collisions = table->get_collision_count();
    return table;
}

std::multimap<std::string, Flight>* multimap_insert(const std::vector<Flight>& flights) {
    auto* mmap = new std::multimap<std::string, Flight>();
    for (int i = 0; i < (int)flights.size(); i++) {
        mmap->insert({flights[i].Get_airline(), flights[i]});
    }
    return mmap;
}

int main() {
    std::vector<std::string> filenames = {
        "100.csv", "200.csv", "500.csv", "1000.csv", "2000.csv",
        "5000.csv", "10000.csv", "20000.csv", "50000.csv", "75000.csv"
    };

    std::string path = "/Users/anastasiatrufanova/Desktop/lab2_data_search_algorithms/data/";
    std::ofstream out("/Users/anastasiatrufanova/Desktop/lab2_data_search_algorithms/plt/results.csv");
    
    if (!out.is_open()) {
        std::cerr << "Failed to open output file!" << std::endl;
    } else {
    
    out << "Array Size,Linear,Binary,RBTree,HashTable,Collisions,Multimap\n";
    
    for (const auto& filename : filenames) {
        std::string full_path = path + filename;
        std::cout << "Processing: " << full_path << std::endl;
        
        std::vector<Flight> flights;
        if (parseCSV(full_path, flights) != 0) {
            std::cerr << "Error parsing: " << full_path << std::endl;
            continue;
        }
        
        std::vector<Flight> res1, res2, res3, res4, res5;
        int collisions = 0;
        
        auto t1_start = std::chrono::high_resolution_clock::now();
        linear_search(flights, res1);
        auto t1_end = std::chrono::high_resolution_clock::now();
        double time_linear = std::chrono::duration<double, std::milli>(t1_end - t1_start).count();
        

        BSTree* bst_tree = binary_insert(flights);

        auto t2_start = std::chrono::high_resolution_clock::now();
        if (bst_tree) {
            bst_tree->Search(Flight("", KEY, "", "", 0), res2);
        }
        auto t2_end = std::chrono::high_resolution_clock::now();
        double time_binary = std::chrono::duration<double, std::milli>(t2_end - t2_start).count();
        delete bst_tree;
        

        RBTree* rb_tree = rb_insert(flights);

        auto t3_start = std::chrono::high_resolution_clock::now();
        if (rb_tree) {
            rb_tree->Search(Flight("", KEY, "", "", 0), res3);
        }
        auto t3_end = std::chrono::high_resolution_clock::now();
        double time_rbtree = std::chrono::duration<double, std::milli>(t3_end - t3_start).count();
        delete rb_tree;

        HashTable* hash_table = hash_table_insert(flights, collisions);
        auto t4_start = std::chrono::high_resolution_clock::now();
        if (hash_table) {
            hash_table->search(KEY, res4);
        }
        auto t4_end = std::chrono::high_resolution_clock::now();
        double time_hash = std::chrono::duration<double, std::milli>(t4_end - t4_start).count();
        delete hash_table;
        

        auto* mmap = multimap_insert(flights);

        auto t5_start = std::chrono::high_resolution_clock::now();
        if (mmap) {
            auto range = mmap->equal_range(KEY);
            for (auto it = range.first; it != range.second; ++it) {
                res5.push_back(it->second);
            }
        }
        auto t5_end = std::chrono::high_resolution_clock::now();
        double time_multimap = std::chrono::duration<double, std::milli>(t5_end - t5_start).count();
        delete mmap;
        

        out << flights.size() << ","
            << time_linear << "," << time_binary << "," << time_rbtree << ","
            << time_hash << "," << collisions << "," << time_multimap << "\n";
    }
    
    out.close();
    }
   
    return 0;
}