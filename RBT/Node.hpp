#ifndef NODE_HPP
#define NODE_HPP
namespace ft {
template<class Val>
	struct Node {
		Val	*		data;
		Node *		parent;
		Node *		right;
		Node *		left;
		bool		isBlack;
		bool		isNil;
		
		explicit Node(Val * _val = NULL) : data(_val), parent(NULL), right(NULL), left(NULL), isBlack(false),  isNil(false) {}
		Node(const Node & other) { *this = other; }
		Node & operator=(const Node & other) 
        {
			if (this != &other) 
            {
				data = other.data;
				parent = other.parent;
				right = other.right;
				left = other.left;
				isBlack = other.isBlack;
				isNil = other.isNil;
			}
			return *this;
		}
	};
}
#endif