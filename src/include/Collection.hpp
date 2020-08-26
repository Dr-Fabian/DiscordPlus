#pragma once
#include <vector>
#include <string>
#include <functional>
#include <math.h>
#include <any>

#define STRING std::string

namespace DiscordPlus
{
    template<typename TYPE, size_t SIZE>
    class Collection
    {
        public:
            // ! Constructors / Destructor
            Collection(TYPE){};
            Collection(std::vector<TYPE> VALUE_ARRAYS, std::vector<STRING> KEYS);
            ~Collection(){
                delete TYPE_COLLECTION;
                delete KEYS;
            };

            // ! Methods
            // * Returns the size of the collection
            constexpr size_t Size(){ return SIZE; };

            //TYPE[] Array() { return TYPE_COLLECTION; };

            // * Clears the collection
            void Clear();

            // * Clones the collection
            Collection<TYPE, SIZE> Clone() { return *this; };

            // * Concatenates two Collections
            Collection Concat(Collection& OTHER);

            // * Deletes the collection
            bool Delete(int index);

            // * Iterates through the collection
            void ForEach(std::function<void (TYPE)>& CALLBACK);

            // * Checks if the collection is the same as one another
            bool Equals(Collection& OTHER);

            // * Checks if every element of the collection fullifies a condition
            bool Every(std::function<bool (TYPE)>& CALLBACK);

            // * Filters the Collection and returns another
            Collection Filter(std::function<bool (TYPE)>& CALLBACK);

            // * Finds the first element that fullifies a condition
            TYPE Find(std::function<bool (TYPE)>& CALLBACK);

            // * Returns the first key of the collection
            STRING FirstKey() { return KEYS[0]; };

            // * Gets an element of the collection
            TYPE Get(STRING &key) { return *this[key]; };

            // * Checks if the Collection has a key
            bool Has(STRING &key);

            // * Returns the last element of the Collection 
            TYPE Last() { return KEYS[SIZE]; };

            // * Iterates through the map and returns the new map
            void Map(std::function<void (TYPE)>& CALLBACK);

            // * Returns a random element of the Collection
            TYPE Random() { return TYPE_COLLECTION[std::floor(std::rand() % SIZE)]; };

            // * yeets the last element of the Collection
            void Reduce();

            // * Yeets an element to the end of the Collection
            Collection Set(TYPE& element);

            // * Returns true if one element fullifies a condition
            bool Some(std::function<bool (TYPE)>& CALLBACK);

            // * Sorts the Collection
            Collection<TYPE, SIZE> Sort();

            // ! OPERATORS

            TYPE operator[](STRING KEY);
            TYPE operator[](int& INDEX);

        private:
            // ? DATA CONTAINER
            TYPE TYPE_COLLECTION[SIZE];
            STRING KEYS[SIZE];

    };
};