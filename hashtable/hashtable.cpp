#include <bits/stdc++.h>

class HashTable {
private:
    int buckets; // Number of buckets
    int size = 0; // Current number of elements in the hash tabe
    std::vector<int> table;

    int hashFunction(int x);
    float loadFactor();

    // Method to check and handle resizing based on load factor
    void expand();
public:
    HashTable(int b);
    ~HashTable();

    // Inserts a key into the hash table
    void insertItem(int key);

    // Deletes a key from the hash table
    void deleteItem(int key);

    // Function to display the hash table
    void displayHash();
};

HashTable::HashTable(int b) : buckets(b) {
    table.resize(buckets, -1);
}

int HashTable::hashFunction(int x) {
    return (x % buckets);
}

HashTable::~HashTable() {
}

void HashTable::insertItem(int key) {
    // Make sure key is positive
    if (key < 0) return;

    int hashNumber = HashTable::hashFunction(key);

    // Linear probing
    while (table[hashNumber] != -1)
    {
        hashNumber = (hashNumber + 1) % buckets;
    }

    table[hashNumber] = key;
    size++;

    // Expand if loadfactor exceeds threshold
    if (loadFactor() > 0.7f) {
        HashTable::expand();
    }
}

void HashTable::deleteItem(int key) {
    // Make sure key is positive
    if (key < 0) return;

    int originalHashNumber = hashFunction(key);
    int hashNumber = originalHashNumber;

    // Linear probing
    while (table[hashNumber] != key) {
        hashNumber = (hashNumber + 1) % buckets;

        // If every value is checked and the key is not found, return
        if (hashNumber == originalHashNumber) {
            return;
        }
    }

    // Delete the key
    table[hashNumber] = -1;
    size--;
}

void HashTable::displayHash() {
    for (int i=0; i < table.size(); i++) {
        std::cout << table[i] << ", ";
    }

    std::cout << "\n";
}

void HashTable::expand() {
    // Create new table with more buckets (double in size)
    buckets *= 2;
    std::vector<int> newTable(buckets, -1);

    // Map values into new table
    for (int i = 0; i < table.size(); i++)
    {
        // Make sure to only hash non-empty values
        if (table[i] != -1)
        {
            int hashNumber = HashTable::hashFunction(table[i]);

            // Linear probing
            while (newTable[hashNumber] != -1)
            {
                hashNumber = (hashNumber + 1) % buckets;
            }

            newTable[hashNumber] = table[i];
        }
    }

    // Update hashtable
    table = newTable;
}

float HashTable::loadFactor() {
    return static_cast<float>(size) / buckets;
}

int main() {
    HashTable ht(5);
    ht.insertItem(2);
    ht.insertItem(1);
    ht.insertItem(4);
    ht.insertItem(3);
    ht.displayHash();
    ht.deleteItem(3);
    ht.insertItem(4);
    ht.displayHash();
    return 0;
}