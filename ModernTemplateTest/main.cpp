#include <iostream>

struct Node {
	int value;

	Node* left {nullptr};
	Node* right {nullptr};

	Node(int i = 0) : value(i) {}
};

auto left = &Node::left;
auto right = &Node::right;

template<typename T, typename... TP>
Node* traverse(T np, TP... paths)
{
	return (np ->* ...->*paths);
}

int main()
{
	Node* root = new Node();
	
	root->left = new Node { 1 };
	root->right = new Node{ 3 };
	root->left->right = new Node{ 2 };
	root->left->right->left = new Node{ 4 };

	Node* node = traverse(root, left, right, left);

	std::cout << node->value << std::endl;
}
