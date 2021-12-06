/**
 * LRU implementation
 */
#include "buffer/lru_replacer.h"
#include "page/page.h"

namespace scudb {

template <typename T> LRUReplacer<T>::LRUReplacer() {}

template <typename T> LRUReplacer<T>::~LRUReplacer() {}

/*
 * Insert value into LRU
 */
template <typename T> void LRUReplacer<T>::Insert(const T &value) {
	if (LRU.empty()){
		LRU.push_back(value);
	}
	else{
		for (typename std::list<T>::iterator iter = LRU.begin(); iter != LRU.end();){
			if (value == *iter){
				LRU.erase(iter++);
			}
			else{
				++iter;
			}
		}
		LRU.push_back(value);
	}
}

/* If LRU is non-empty, pop the head member from LRU to argument "value", and
 * return true. If LRU is empty, return false
 */
template <typename T> bool LRUReplacer<T>::Victim(T &value) {
	if (LRU.empty()) {
		return false;

	}
	else {
		value = LRU.front();
		LRU.pop_front();
		return true;
	}
}

/*
 * Remove value from LRU. If removal is successful, return true, otherwise
 * return false
 */
template <typename T> bool LRUReplacer<T>::Erase(const T &value) {
	for (typename std::list<T>::iterator iter = LRU.begin(); iter != LRU.end();) {
		if (value == *iter){
			LRU.erase(iter);
			return true;
		}
		else{
			++iter;
		}
	}
    return false;
}

template <typename T> size_t LRUReplacer<T>::Size() { return LRU.size(); }

template class LRUReplacer<Page *>;
// test only
template class LRUReplacer<int>;

} // namespace scudb
