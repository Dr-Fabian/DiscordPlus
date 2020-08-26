#pragma once
#include <vector>
#include <string>
#include <functional>
#include <math.h>

#define STRING std::string

namespace DiscordPlus
{
    template<typename TYPE, size_t SIZE>
    class Collection
    {
        public:
            // ! Constructor / Destructor
            Collection(T, SIZE){};
            Collection(std::array<TYPE> TYPE_ARRAY, SIZE){};
            ~Collection(){};

            // ! Methods
            constexpr size_t Size(){ return SIZE };
            void Clear();
            Collection<Type, SIZE> Clone();
            Collection<Type, Size> Concat(Collection<TYPE, SIZE>& OTHER);
            bool Delete(int index);
            Collection<TYPE, SIZE> ForEach(std::function<void (TYPE)> CALLBACK);
            bool Equals(Collection<TYPE, SIZE>& OTHER);
            bool Every(std::function<void (TYPE)> CALLBACK);
            Collection<TYPE, SIZE> Filter(std::function<void (TYPE)> CALLBACK);
            TYPE Find(std::function<void (TYPE)>);
            STRING FirstKey() { return key[0] };
            TYPE Get(STRING key);
            bool Has(STRING key);
            TYPE Last() { return KEYS[SIZE] };
            Collection<TYPE, SIZE> Map(std::function<void (TYPE)> CALLBACK);
            TYPE Random() { return TYPE_COLLECTION[std::floor(std::rand() % SIZE)] };
            Collection<TYPE, SIZE - 1> Reduce();
            Collection<TYPE, SIZE + 1> Set();
            bool Some(std::function<void (TYPE)> CALLBACK);
            Collection<TYPE, SIZE> Sort();

            // ! OPERATORS

            TYPE operator[](int index) { return TYPE_COLLECTION[index] };

        private:
            // ? DATA CONTAINER
            TYPE TYPE_COLLECTION[SIZE];
            STRING KEYS[SIZE];

    };
};