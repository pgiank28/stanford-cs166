using namespace std;

struct Node {
  Node* leftchild;
  Node* rightchild;
  int value;
};

typedef struct Node* node;

void insert_into(node* root,int value);
void free_tree(node root);
size_t size_of(const node root);
int* contents_of(const node root);
const node second_min_in(const node root);
void printTree(node* root);
int* addNodeToArray(node root,int* array,int nodesInserted);
