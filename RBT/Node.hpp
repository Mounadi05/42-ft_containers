#ifndef NODE_HPP
#define NODE_HPP

template<class Val>
	struct node {
		Val	*		data;
		node *		parent;
		node *		right;
		node *		left;
		bool		isBlack;
		bool		isNil;
		
		explicit node(Val * _val = NULL) : data(_val), parent(NULL), right(NULL), left(NULL), isBlack(false),  isNil(false) {}
		node(const node & other) { *this = other; }
		node & operator=(const node & other) 
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
#endif