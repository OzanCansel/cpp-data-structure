#include "hash_map.hpp"
#include <iomanip>
#include <algorithm>
#include <numeric>

template<typename Key, typename Value>
hash_map<Key, Value>::hash_map()
    :   m_buckets(1)
{}

template<typename Key, typename Value>
size_t
hash_map<Key, Value>::bucket_count() const
{
    return m_buckets.size();
}

template<typename Key, typename Value>
void
hash_map<Key, Value>::insert(Key key, Value value)
{
    if (load_factor() > max_load_factor())
    {
        m_buckets.resize(m_buckets.size() * 2);
        rehash();
    }

    auto bucket_idx { std::hash<Key>()(key) % bucket_count() };

    key_value kv { std::move(key), std::move(value) };

    m_buckets[bucket_idx].erase(kv);
    m_buckets[bucket_idx].push_back(kv);
}

template<typename Key, typename Value>
const
Value& hash_map<Key, Value>::value(const Key& key) const
{
    auto bucket_idx = hash(key);
    const auto& bucket { m_buckets[bucket_idx] };

    const auto result = bucket.find_if(
        [&](const key_value& kv){
            return kv.key == key;
        }
    );

    if (!result)
        throw std::out_of_range {
            "Key doesn't exist."
        };

    return result->value; 
}

template<typename Key, typename Value>
float
hash_map<Key, Value>::load_factor() const
{
    return float(size()) / bucket_count();
}

template<typename Key, typename Value>
float
hash_map<Key, Value>::max_load_factor() const
{
    return 10.0f;
}

template<typename Key, typename Value>
size_t
hash_map<Key, Value>::size() const
{
    return accumulate(
        begin(m_buckets),
        end(m_buckets),
        size_t(0),
        [](size_t accumulator, const linked_list<key_value>& y){
            return accumulator + y.size();
        }
    );
}

template<typename Key, typename Value>
void
hash_map<Key, Value>::print()
{
    auto w { std::to_string(m_buckets.size()).size() + 1 };

    for (size_t i = 0; i < m_buckets.size(); ++i)
    {
        std::cout << std::setw(w) << i << '|';

        const linked_list<key_value>& l { m_buckets[i] };

        for (size_t j = 0; j < l.size(); ++j)
        {
            std::cout << std::setw(4) << l.at(j).key << " ";
        }

        std::cout << std::endl;
    }
}

template<typename Key, typename Value>
void
hash_map<Key, Value>::rehash()
{
    for (size_t bucket_idx  = 0; bucket_idx < m_buckets.size(); ++bucket_idx)
    {
        linked_list<key_value>& l { m_buckets[bucket_idx] };

        for (size_t j = 0; j < l.size();)
        {
            auto kv = l.at(j);
            auto new_bucket { hash(kv.key) };

            if (bucket_idx != new_bucket)
            {
                l.erase(kv);

                m_buckets[new_bucket].push_back(kv);
            }
            else
            {
                ++j;
            }
        }
    }
}

template<typename Key, typename Value>
size_t
hash_map<Key, Value>::hash(const Key& key) const
{
    return std::hash<Key>{}(key) % m_buckets.size();
}
