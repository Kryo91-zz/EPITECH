/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** PackedArray.hpp
*/

#include "stdInclude.hpp"
#include "lib/Lib.hpp"

namespace lib
{

    const id_t MAX_ID = 1000000;

    class IPackedArray
    {
        public:
            virtual ~IPackedArray() = default;
            virtual void idDestroyed(id_t id) = 0;
    };

    template<typename T>
    class PackedArray : public IPackedArray
    {
        private:
            // The packed array of components (of generic type T),
            // set to a specified maximum amount, matching the maximum number
            // of IDs allowed to exist simultaneously, so that each ID
            // has a unique spot.
            std::array<T, MAX_ID> _packedArray;

            // Map from an ID to an array index.
            std::unordered_map<id_t, size_t> _idToIndexMap;

            // Map from an array index to an ID.
            std::unordered_map<size_t, id_t> _indexToIdMap;

            // Total size of valid entries in the array.
            size_t _size;
        public:
            void insertData(id_t id, T component)
            {
                if (_idToIndexMap.find(id) != _idToIndexMap.end())
                    throw lib::Exception("Component already added to id");
                if (_size > MAX_ID)
                    throw lib::Exception("Too many ids in Packed Array");

                size_t newIndex = _size;
                _idToIndexMap[id] = newIndex;
                _indexToIdMap[newIndex] = id;
                _packedArray[newIndex] = component;
                _size++;
            }

            void removeData(id_t id)
            {
                if (_idToIndexMap.find(id) == _idToIndexMap.end())
                    throw lib::Exception("Can't remove: component not found");

                // Copy element at end into deleted element's place to maintain density
                size_t indexOfRemovedId = _idToIndexMap[id];
                size_t indexOfLastElement = _size - 1;
                _packedArray[indexOfRemovedId] = _packedArray[indexOfLastElement];

                // Update map to point to moved spot
                id_t idOfLastElement = _indexToIdMap[indexOfLastElement];
                _idToIndexMap[idOfLastElement] = indexOfRemovedId;
                _indexToIdMap[indexOfRemovedId] = idOfLastElement;

                _idToIndexMap.erase(id);
                _indexToIdMap.erase(indexOfLastElement);

                _size--;
            }

            T& getData(id_t id)
            {
                if (_idToIndexMap.find(id) == _idToIndexMap.end())
                    throw lib::Exception("Can't get: component not found");

                return _packedArray[_idToIndexMap[id]];
            }

            void idDestroyed(id_t id) override
            {
                if (_idToIndexMap.find(id) != _idToIndexMap.end()) {
                    removeData(id);
                }
            }
    };
} // namespace lib