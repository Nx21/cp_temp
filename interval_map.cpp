#include <map>
#include <iostream>
template<typename K, typename V>
class interval_map {
    private:
        V m_valBegin;
        std::map<K,V> m_map;
	public:
        interval_map(V const& val)
        : m_valBegin(val)
        {}


        void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
            if(!(keyBegin < keyEnd))
                return;
            K endVal = (*this)[keyEnd];
            auto itb = m_map.upper_bound(keyBegin);
            auto ite = m_map.upper_bound(keyEnd);
            for (; itb != ite; ) {
                auto tmp = itb++;
                m_map.erase(tmp);
            }
            m_map.insert(keyBegin, val);
            m_map.insert(keyEnd, endVal);
        }

        // look-up of the value associated with key
        V const& operator[]( K const& key ) const {
            auto it=m_map.upper_bound(key);
            if(it==m_map.begin()) {
                return m_valBegin;
            } else {
                return (--it)->second;
            }
        }
};