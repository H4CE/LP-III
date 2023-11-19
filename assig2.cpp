#include <bits/stdc++.h>
using namespace std;
using intl = long long int;

class Node
{

public:
    Node *left, *right;
    char charac;
    int freq;
    Node(char charac, int freq)
    {
        this->charac = charac;
        this->freq = freq;
        left = NULL;
        right = NULL;
    }
};
class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->freq >= b->freq;
    }
};
Node *createTree(vector<char> &chars, vector<int> &freq)
{
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (int i = 0; i < chars.size(); i++)
    {
        pq.push(new Node(chars[i], freq[i]));
    }

    while (pq.size() != 1)
    {

        auto firstSmall = pq.top();
        pq.pop();
        auto secondSmall = pq.top();
        pq.pop();

        auto newNode = new Node('$', firstSmall->freq + secondSmall->freq);
        newNode->left = firstSmall;
        newNode->right = secondSmall;
        pq.push(newNode);
    }
    auto rootNode = pq.top();
    return rootNode;
}
void printTree(Node *root, string code)
{
    if (root == NULL)
    {
        return;
    }
    if (root->charac != '$')
    {
        cout << root->charac << " : " << code << endl;
    }
    printTree(root->left, code + "0");
    printTree(root->right, code + "1");
}
int main()
{
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> arr = {5, 9, 12, 13, 16, 45};
    auto root = createTree(chars, arr);
    printTree(root, "");
    return 0;
}