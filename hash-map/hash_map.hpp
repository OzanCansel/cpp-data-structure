#pragma once

#include <vector>
#include "linked_list.hpp"

template<typename Key, typename Value>
class hash_map
{
public:

    hash_map();
    void insert(Key k, Value v);
    const Value& value(const Key&) const;
    size_t bucket_count() const;
    float load_factor() const;
    float max_load_factor() const;
    size_t size() const;
    void print();

private:

    void rehash();
    size_t hash(const Key& k) const;

    struct key_value
    {
        Key key;
        Value value;

        friend bool operator==(const key_value& x, const key_value& y)
        {
            return x.key == y.key;
        }
    };

    std::vector<linked_list<key_value>> m_buckets;
};

#include "impl/hash_map_impl.hpp"
