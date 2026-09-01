#include <iostream>

#define HASH_TABLE_SIZE 100

namespace timestamp {


    class UniqueValueChecker {

       public:
        UniqueValueChecker();
        ~UniqueValueChecker();

        bool insertValue(const char* value);
        bool isValuePresent(const char* value);
        long long getHash(const char* value);


       private:
        char** buckets;
        int bucketCount; 
    };    
}
//Hash Function Implementation for Unique Value Checker