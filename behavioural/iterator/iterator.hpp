template <typename T>

struct BaseNode {
  BaseNode(BaseNode<T> *p = 0, BaseNode<T> *n = 0) : prev(p), next(n) {}
  virtual ~BaseNode() = default;

  BaseNode<T> *prev = 0;
  BaseNode<T> *next = prev;
};

template <typename T> struct Node : public BaseNode<T> {
  Node(const T &v, BaseNode<T> *p = 0, BaseNode<T> *n = 0)
      : BaseNode<T>(p, n), val(v) {}
  T val;
};

template <typename T> class ListIterator {
public:
  ListIterator(BaseNode<T> *n) : node(n) {}

  bool operator==(const ListIterator<T> &rhs) { return node == rhs.node; }
  bool operator!=(const ListIterator<T> &rhs) { return !(node == rhs.node); }
  void operator++(int) { node = node->next; }
  void operator++() { node = node->next; }
  T &operator*() { return reinterpret_cast<Node<T> *>(node)->val; }
  T &operator->() { return this->operator*(); }

protected:
  BaseNode<T> *node;
};

template <typename T> 
class List {
public:
  List(): size(0) {
    end_ = new BaseNode<T>;
    end_->prev = end_;
    end_->next = end_;
  }
  void clear();
  virtual ~List() {
    clear();
    delete end_;
  }
  ListIterator<T> begin() { return end_->next; }
  ListIterator<T> end() { return end_; }
  void push_back(const T &val);
  void push_front(const T &val);

protected:
  BaseNode<T> *end_;
  int size = 0;
};

template <typename T> void List<T>::push_back(const T &val) {
  auto newElem = new Node(val, end_->prev, end_);
  // update links to new element
  end_->prev->next = newElem;
  end_->prev = newElem;
  ++size;
}

template <typename T> void List<T>::push_front(const T &val) {
  auto newElem = new Node(val, end_, end_->next);
  // update links to new element
  end_->next->prev = newElem;
  end_->next = newElem;
  ++size;
}

template<typename T>
void List<T>::clear(){
  while(end_->next != end_){
    Node<T>* nxt = dynamic_cast<Node<T>*>(end_->next);
    end_->next = nxt->next;
    delete nxt;
  }
  size = 0;
}





