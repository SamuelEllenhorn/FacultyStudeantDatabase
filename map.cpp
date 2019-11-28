template<typename K, typename V>
class Map {
public
  class Entry;
  class Iterator;

  int size() const;
  bool empty() const;
  Iterator find(const K& k) const;
  void erase(const K& k)
    throw(NonexistentElement);
  void erasee(const Iterator& p);
  Iterator begin();
  Iterator end();

};
