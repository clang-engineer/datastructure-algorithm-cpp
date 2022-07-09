#include <iostream>
#include <queue>

struct node {
    std::string position;
    node* first;
    node* second;
};

struct org_tree {
    node* root;

    static org_tree create_org_structure(const std::string& pos) {
        org_tree tree;
        tree.root = new node {pos, NULL, NULL};
        return tree;
    }

    static node* find(node* root, const std::string& value) {
        if (root == NULL)
            return NULL;

        if (root->position == value)
            return root;

        auto firstFound = org_tree::find(root->first, value);

        if (firstFound != NULL)
            return firstFound;

        return org_tree::find(root->second, value);
    }

    bool addSubordinate(const std::string& manager, const std::string& subordinate) {
        auto managerNode = org_tree::find(root, manager);

        if (!managerNode) {
            std::cout << manager << "is couldn't find" << std::endl;
            return false;
        }

        if (managerNode->first && managerNode->second) {
            std::cout << manager << " can't  add " << subordinate << std::endl;
            return false;
       }

        if (!managerNode->first) {
            managerNode->first = new node {subordinate, NULL, NULL};
        } else {
            managerNode->second = new node {subordinate, NULL, NULL};
        }
        
        std::cout << manager << "'s child add " << subordinate << std::endl;
        return true;
    }
};

int main() {
    auto tree = org_tree::create_org_structure("CEO");

    tree.addSubordinate("CEO", "LEV1");
    tree.addSubordinate("LEV1", "LEV1-1");
    tree.addSubordinate("LEV1", "LEV1-2");
    tree.addSubordinate("LEV1-1", "LEV1-1-1");
    tree.addSubordinate("LEV1-1", "LEV1-1-2");
    tree.addSubordinate("LEV1-2", "LEV1-2-1");
    tree.addSubordinate("LEV1-2", "LEV1-2-2");
}
