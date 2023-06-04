#include <stdexcept>
#include <sequence/sequence.h>

using namespace SEQUENCE;
using namespace std;

SequenceList::SequenceList(const SequenceList& list) {
    const auto n = list.size();
    _sequences.reserve(n);
    for (int i = 0; i < n; ++i) {
        _sequences.push_back(list[i]->clone());
    }
}

int SequenceList::size() const {
    return static_cast<int>(_sequences.size());
}

void SequenceList::swap(SequenceList& list) noexcept {
    std::swap(this->_sequences, list._sequences);
}

SequenceList& SequenceList::operator=(const SequenceList& list) {
    SequenceList copy(list);
    copy.swap(*this);
    return *this;
}

SequencePtr SequenceList::operator[](const int index) const {
    if (index < 0 || this->size() <= index) {
        throw runtime_error("[SequenceList::operator[]] Index out of range.");
    }

    return _sequences.at(index);
}

void SequenceList::add(SequencePtr item) {
    _sequences.push_back(item);
}

void SequenceList::insert(SequencePtr const item, int index) {
    _sequences.insert(_sequences.begin() + index, item);
}

void SequenceList::erase_index(int index) {
    _sequences.erase(_sequences.begin() + index);
}

int SEQUENCE::search(const SequenceList& sequences, const int n) {
    if (n < 1) {
        throw runtime_error("n < 1");
    }
    int min_i = -1;
    for (int i = 0; i < sequences.size(); i++)
    {
        int min_n;
        if (min_i != -1) {
            min_n = sequences[min_i]->calculate_n(n);
        }
        else min_n = sequences[0]->calculate_n(n);
        int current_n = sequences[i]->calculate_n(n);
        if (min_n >= current_n)
        {
            min_i = i;
        }
    }
    return min_i;
}