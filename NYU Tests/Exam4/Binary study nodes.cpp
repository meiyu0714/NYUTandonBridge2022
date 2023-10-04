typedef int dataType;
struct BinaryNode{
    dataType element;// 和p133 Comparable element是一样的;
    BinaryNode* left;
    BinaryNode* right;
};


class BinarySearchNode{
    public:
      BinarySearchNode():element(0), left(nullptr),right(nullptr){}
      BinarySearchNode(dataType x):element(x), left(nullptr),right(nullptr){}
      BinarySearchNode(dataType x, BinarySearchNode* leftLink, BinarySearchNode* rightLink):
        element(x), left(leftLink), right(rightLink){}
      BinarySearchNode* search(BinarySearchNode* root, dataType target){
        if(root == nullptr || root->element == target)
            return root;
        else if(target < root-> element)
            return search(root->left, target);
        else if(target > root->element) //此行可省略，有了更清晰
            return search(root->right, target);
           //https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
      //比书上的内容更好理解，return nullptr = not exist in this tree 
      }
      BinarySearchNode* findMin(BinarySearchNode* root) const
      {
        if(root == nullptr)
          return nullptr;
        if(root->left == nullptr)
          return root; //在练习的时候这一段忘写了。一定要记得啊  
        else 
          return findMin(root->left);
      }
      //下面这种形式可以吗？
      BinarySearchNode* findMin(BinarySearchNode* root) const
      {
        if(root == nullptr || root->left == nullptr)
          return root; //在练习的时候这一段忘写了。一定要记得啊  
        else 
          return findMin(root->left);
      }
      BinarySearchNode* findMax(BinarySearchNode* root) const
      {
        if(root != nullptr){
            while(root->right != nullptr)
              root = root->right;
        }
        return root;
      }
      void insert(dataType x, BinarySearchNode*& root){
        //insert,remove等要对树本身改变的函数，都要*& root
        //youtube上 root = new node<E>(org); 开头(E obj)
        if(root == nullptr){
            root->element = x;
            root->left = nullptr;
            root->right = nullptr;
            //直接: t = new BinarySearchNode(x,nullptr,nullptr);
        }
        else if(t > root->element){
            insert(x, root->right);
        } 
        else if(t < root->element){
            insert(x, root->left);
        }
        else ;//x = root->element, do nothing
      }
      void remove(BinarySearchNode*& root, int x){
        if(root == nullptr)
          return; //item not found, do nothing
        if(x < root->element)
          return remove(root->left, x);
        else if(x > root->element)
          return remove(root->right, x);
        else if(root->right != nullptr && root->left != nullptr)//two children
        {
           t->element = findMin(t->right)->element;
           remove(t->right, t->element);//只要找到然后删掉即可   
        }
        else
        {
            BinarySearchNode* oldeNode = t;
            t = ( t->left != nullptr)? t->left:t->right;
            delete oldeNode;//I need to know what if the node is the leave. then how the pointer is deleted
        }
        void makeEmpty(BinarySearchNode*& root){
            if(root != nullptr){
                makeEmpty(root->left);
                makeEmpty(root->right);
                delete root;
            }
            root = nullptr;
        }       
        BinarySearchNode* clone(BinaryNode *t) const
        {
            if(t == nullptr)
              return nullptr;
            else 
              return new BinarySearchNode{t->element, clone(t->left),clone(t->right)};  
        }
      }
    private:
      dataType element;
      BinarySearchNode* left;
      BinarySearchNode* right;
};

struct AvlNode
{
    Comparable element;
    AvlNode* left;
    AvlNode* right;
    int height;

    AvlNode(const Comparable& ele, AvlNode* lt, AvlNode*rt, int h = 0)
      :element{ele}, left{lf},right{rt}, height{h}{}
    AvlNode(Comparable&& ele, AvlNode* lt, AvlNode* rt, int h = 0)
      :element{std::move(ele)},left{lt},right{rt},height{h}{}  
}


//Return the height of node t or -1 if t is nullptr
int height(AvlNode*& t){
    if(t == nullptr)
      return -1;
    else 
      return 1 + max(height(t->right),height(t->left));  
}//That is my fuction ; is to compute the height. but not to return the height

//how to return the height
int height(AvlNode* t)const{
    return (t==nullptr)?-1:t->height;
}
//Internal method to insert into a asubtree
void insert(const Comparable &x, AvlNode*& t)
{
    if(t == nullptr)
      t = new AvlNode{x, nullptr, nullptr};
    else if(x < t->left)
      insert(x, t->left);
    else if(x > t->right)
      insert(x, t->right);
    else return;

  balance(t);        
}