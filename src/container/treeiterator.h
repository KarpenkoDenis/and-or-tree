#ifndef TREEITERATOR_H
#define TREEITERATOR_H
#include <iterator>
#include <vector>
//#include "tree.h"


class Tree;
class Node;

#include "tree.h"

//template<typename Root, typename CurrElem>
class TreeIterator: public std::iterator<std::input_iterator_tag, Node>
{
    friend class Tree;
private:
    TreeIterator(Tree* r, Node* c);
public:
    TreeIterator(const TreeIterator &it);

    bool operator!=(TreeIterator const& other) const;
    bool operator==(TreeIterator const& other) const;
    typename TreeIterator::reference operator*() const;
    TreeIterator& operator++();
private:
    Tree* r;
    Node* c;

    Node *findNext(Node *curr, Node finding);
    void KLP(Node * curr);
    std::vector<Node *> passed;

};

#endif // TREEITERATOR_H
