#include "UniqueValueChecker.h"

using namespace timestamp;

UniqueValueChecker::UniqueValueChecker() : bucketCount(0) {
    buckets = new char*[HASH_TABLE_SIZE];
    
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        buckets[i] = nullptr;
    }
}

UniqueValueChecker::~UniqueValueChecker() {
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        delete[] buckets[i];
    }
    delete[] buckets;
}

long long UniqueValueChecker::getHash(const char* value) {
    long long hash = 0;
    while (*value) {
        hash = (hash * 31 + *value) % HASH_TABLE_SIZE;
        ++value;
    }
    return hash;
}

bool UniqueValueChecker::insertValue(const char* value) {

    if( bucketCount >= HASH_TABLE_SIZE) {
        std::cerr << "Hash table is full. Will Reallocate." << std::endl;
        return false;
    }

    long long currentHash = getHash(value);
    int index = currentHash % HASH_TABLE_SIZE;

    if( buckets[index] == nullptr) {
        buckets[index] = new char[strlen(value) + 1];
        strncpy(buckets[index], value, strlen(value) + 1);
        bucketCount++;
    } else {
        int originalIndex = index;
        while (buckets[index] != nullptr) {
            if (strcmp(buckets[index], value) == 0) {
                return false;
            }
            index = (index + 1) % HASH_TABLE_SIZE;
            if (index == originalIndex) {
                std::cerr << "Hash table is full. Cannot insert value." << std::endl;
                return false;
            }
        }
        buckets[index] = new char[strlen(value) + 1];
        strncpy(buckets[index], value, strlen(value) + 1);
        bucketCount++;
    }
    return true; 
}





