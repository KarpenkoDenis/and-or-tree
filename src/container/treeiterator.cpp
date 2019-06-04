//#include "treeiterator.h"



//TreeIterator::TreeIterator(Tree<QString> *r, Node<QString> *c) :
//    r(r), c(c)
//{

//}


//TreeIterator::TreeIterator(const TreeIterator& it) :
//    r(it.r), c(it.c)
//{

//}


//bool TreeIterator::operator!=(TreeIterator const& other) const
//{
//    return r != other.r || c != other.c;
//}


//bool TreeIterator::operator==(TreeIterator const& other) const
//{
//    return r == other.r && c == other.c;
//}


//typename TreeIterator::reference TreeIterator::operator*() const
//{
//    return *c;
//}

//TreeIterator &TreeIterator::operator++()
//{
//    auto save = c->findKLP_next();
//    if(save)
//    {
//        c = save;
//    }
//    else {
//         c = findNext(&(r->root), *c);
//    }

//    return *this;
//}

//Node<QString> *TreeIterator::findNext(Node<QString> *curr, Node<QString> finding)
//{
//    KLP(&r->root);
//    for(auto iter = passed.begin(); iter!=passed.end(); ++iter)
//    {
//        if(**iter == finding)
//        {
//            if(*(iter+1))
//                return *(iter+1);
//        }
//    }
//    return nullptr;
//}

//void TreeIterator::KLP(Node<QString> *curr)
//{
//    passed.push_back(curr);
//    for(auto iter = curr->children.begin(); iter!=curr->children.end(); ++iter)
//    {
//        KLP(&*iter);
//    }
//}
