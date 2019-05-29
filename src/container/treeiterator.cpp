#include "treeiterator.h"



TreeIterator::TreeIterator(Tree *r, Node *c) :
    r(r), c(c)
{

}


TreeIterator::TreeIterator(const TreeIterator& it) :
    r(it.r), c(it.c)
{

}


bool TreeIterator::operator!=(TreeIterator const& other) const
{
    return r != other.r && c != other.c;
}


bool TreeIterator::operator==(TreeIterator const& other) const
{
    return r == other.r && c == other.c;
}


typename TreeIterator::reference TreeIterator::operator*() const
{
    return *c;
}

inline Node *  findNext(Node * n, Node finding)
{
    static Node * last = nullptr;
    if(*last == finding)
    {
        return n;
    }

    unsigned i =0;
    for(Node c: n->children)
    {
        if(c == finding)
        {
            if(i+1 < n->children.size())
                return  &n->children.at(i+1);
        }
        auto save = findNext(&c, finding);
        if(save != nullptr)
            return save;
        i++;
    }
    last = n;
    return nullptr;
}

TreeIterator &TreeIterator::operator++()
{
    auto save = c->findKLP_next();
    if(save)
    {
        c = save;
    }
    else {
         c = findNext(&(r->root), *c);
    }

    return *this;
}
