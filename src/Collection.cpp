#include <functional>
#include <any>
#include <string>
#include <algorithm>
#include <vector>
#include "include/Collection.hpp"



#define STRING std::string
#define THIS *this
#define TEMPLATE template<typename TYPE, size_t SIZE>
namespace DiscordPlus
{

    TEMPLATE
    Collection<TYPE, SIZE>::Collection(std::vector<TYPE> VALUES, std::vector<STRING> KEYS)
    {
        if (VALUES.size() != KEYS.size())
        {
            return;
        }

        for (int i = 0; i < VALUES.size(); i++)
        {
            THIS.TYPE_VALUES[i] = VALUES[i];
            THIS.KEYS[i] = KEYS[i];
        };
    };


    // ? Clear function
    TEMPLATE
    void Collection<TYPE, SIZE>::Clear()
    {
        for (long unsigned int i = 0; i < SIZE; i++)
        {
            this->TYPE_COLLECTION[i] = NULL;
        }

        delete this->TYPE_COLLECTION;
    }

    TEMPLATE
    Collection<TYPE, SIZE> Collection<TYPE, SIZE>::Concat(Collection& OTHER)
    {
        if (!(typeid(THIS.TYPE_COLLECTION[0]) == typeid(OTHER.TYPE_COLLECTION[0])))
            return THIS;
        
        Collection<TYPE, THIS.Size() + OTHER.Size()> NEW_COLLECTION();

        // Adds the value of the collection to the new one
        for (int i = 0; i < THIS.Size(); i++)
        {
            NEW_COLLECTION.TYPE_COLLECTION[i] = THIS.TYPE_COLLECTION[i];
            NEW_COLLECTION.KEYS[i] = THIS.KEYS[i];
        };

        // Adds the value of the other Collection to the new one
        for (int i = 0; i < OTHER.Size(); i++)
        {
            NEW_COLLECTION.TYPE_COLLECTION[i] = OTHER.TYPE_COLLECTION[i];
            NEW_COLLECTION.KEYS[i] = OTHER.KEYS[i];
        }

        return NEW_COLLECTION;
    }

    TEMPLATE
    void Collection<TYPE, SIZE>::ForEach(std::function<void (TYPE)>& CALLBACK)
    {
        // Iterates the collection and executes the callback function for each type
        for (int i = 0; i < THIS.Size(); i++)
        {
            CALLBACK(THIS.TYPE_COLLECTION[i]);
        }
    }


    // ? Deletes an entry of the array at specified index
    TEMPLATE
    bool Collection<TYPE, SIZE>::Delete(int index)
    {
        // If segmentation fault
        if (index > SIZE)
            return false;

        //Iterates the array and overrites the array at index by the element at index + 1
        for (index < SIZE; index++;)
        {
            *this[index] = *this[index + 1];
        }

        return true;
    }

    // ? Returns true if the collection is equal to the collection passed as parameter
    TEMPLATE
    bool Collection<TYPE, SIZE>::Equals(Collection& OTHER)
    {

        // Returns false if the Collections don't have the same size
        if(OTHER.Size() < THIS.Size() || THIS.Size() < OTHER.Size())
            return false;

        bool _ = true;

        // Iterates the Collections
        for(int i = 0; i < OTHER.Size(); i++)
        {
            //If one element isn't equal to another returns false and breaks the loop
            if(!(THIS[i] == OTHER[i]))
            {
                _ = false;
                break;
            }
        }

        return _;
    }

    // Returns true if every element of the collection fullifies a condition
    TEMPLATE
    bool Collection<TYPE, SIZE>::Every(std::function<bool (TYPE)>& CALLBACK)
    {

        bool _ = true;

        // Calls the callback function for each element in the array
        for (int i = 0; i < THIS.Size(); i++)
        {
            //If one element doesn't fullify the condition, breaks the loop and returns false
            if(CALLBACK(THIS[i]) == false)
            {
                bool _ = false;
                break;
            }
        }
        // Returns value returned by callback
        return _;
    }

    TEMPLATE
    Collection<TYPE, SIZE> Collection<TYPE, SIZE>::Filter(std::function<bool (TYPE)>& CALLBACK)
    {
        std::vector<TYPE> _;
        std::vector<STRING> KEYS;

        // Iterates the Collection and adds it to the arrays
        for (int i = 0; i < THIS.Size(); i++)
        {
            // If value passes filter adds value to vectors
            if (CALLBACK(THIS.TYPE_CONTAINER[i]))
            {
                _[i] = THIS.TYPE_CONTAINER[i];
                KEYS[i] = THIS.KEYS[i];
            }
        }

        // Return new collection with the values of the vectors
        return Collection<TYPE, _.size()> (_, KEYS); 
    }

    // Returns fist element that fullifies a condition
    TEMPLATE
    TYPE Collection<TYPE, SIZE>::Find(std::function<bool (TYPE)>& CALLBACK)
    {
        TYPE _;
        for (int i = 0; i < THIS.Size(); i++)
        {
            if(CALLBACK(THIS[i]))
            {
                _ = THIS[i];
                break;
            }
        }

        return _;
    }

    TEMPLATE
    bool Collection<TYPE, SIZE>::Has(STRING &key)
    {
        bool _;
        // Iterates through the keys
        for (int i = 0; i < THIS.Size(); i++)
        {
            // If one key is equal breaks the loop and returns true
            if(THIS.KEYS[i] == key)
            {
                _ = true;
                break;
            }
        }

        return _;
    }

    TEMPLATE
    void Collection<TYPE, SIZE>::Map(std::function<void (TYPE)>& CALLBACK)
    {
        // Iterates through the map and applies the callback function
        for (int i = 0; i < this; i++)
            CALLBACK(THIS[i]);
    }

    TEMPLATE
    void Collection<TYPE, SIZE>::Reduce()
    {
        // Removes last entries
        THIS.TYPE_COLLECTION[SIZE - 1] = NULL;
        THIS.KEYS[SIZE - 1] = NULL;
    };

    TEMPLATE
    Collection<TYPE, SIZE> Collection<TYPE, SIZE>::Set(TYPE& NEW_ELEMENT)
    {
        // Creates new collection with one extra size
        Collection<TYPE, SIZE + 1> NEW_COLLECTION;

        // Copies data from Collection to the new Collection
        for (int i = 0; i < THIS.Size(); i++)
        {
            NEW_COLLECTION.TYPE_COLLECTION[i] = THIS.TYPE_COLLECTION[i];
            NEW_COLLECTION.KEYS[i] = THIS.KEYS[i];
        }

        // Adds the new data
        NEW_COLLECTION.TYPE_COLLECTION[SIZE] = NEW_ELEMENT;
        NEW_COLLECTION.KEYS[SIZE] = NEW_ELEMENT.id;

        // Destructs old Collection;
        delete this;
        
        // Returns the new Collection
        return NEW_COLLECTION;
    }


    TEMPLATE
    bool Collection<TYPE, SIZE>::Some(std::function<bool (TYPE)>& CALLBACK)
    {

        bool _ = false;

        // Iterates the Collection
        for (int i = 0; i < THIS.Size(); i++)
        {
            // If one value fullifies the condition returns balue and breaks loop
            if(CALLBACK(THIS.TYPE_CONTAINER[i]))
            {
                bool _ = true;
                break;
            }
        }

        return _;
    }

    TEMPLATE
    TYPE Collection<TYPE, SIZE>::operator[](STRING KEY)
    {

        TYPE _;
        //Array iterator
        auto iterator = std::find(std::begin(THIS.KEYS), std::end(THIS.KEYS), THIS.KEYS);

        if(iterator != std::end(THIS.KEYS))
        {
            // Index of the value
            int index = std::distance(std::begin(THIS.KEYS), iterator);
            // Sets the value
            _ = THIS.TYPE_CONTAINER[index];
        }

        // Returns value
        return _;
    }
    
    TEMPLATE
    TYPE Collection<TYPE, SIZE>::operator[](int& INDEX)
    {
        int SIZE_OF_ARRAY = sizeof(THIS.TYPE_COLLECTION) / sizeof(THIS.TYPE_COLLECTION[0]);

        if(INDEX > SIZE_OF_ARRAY)
            return;
        
        THIS.TYPE_CONTAINER[INDEX];
    }

} // namespace DiscordPlus