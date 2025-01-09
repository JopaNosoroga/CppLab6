#include <iostream>

template <class T> class Node {
public:
  T data;
  Node *next;
  Node *prev;

  Node(const T &data) : data(data), next(nullptr), prev(nullptr) {}
};

template <class T> class SinglyLinkedList {
private:
  Node<T> *head;
  Node<T> *tail;

public:
  SinglyLinkedList() : head(nullptr), tail(nullptr) {}

  void AppendTop(const T &data) {
    Node<T> *new_node = new Node<T>(data);
    if (head == nullptr) {
      head = new_node;
      tail = new_node;
      return;
    }

    new_node->next = head;
    head = new_node;
  }

  void AppendBack(const T &data) {
    Node<T> *new_node = new Node<T>(data);
    if (tail == nullptr) {
      head = new_node;
      tail = new_node;
      return;
    }
    tail->next = new_node;
    tail = new_node;
  }

  void AppendMiddle(const T &data, int index) {
    Node<T> *new_node = new Node<T>(data);
    Node<T> *temp = head;
    while (temp->next != nullptr && index > 0) {
      temp = temp->next;
      index--;
    }

    new_node->next = temp->next;
    temp->next = new_node->next;
  }

  T PopTop() {
    if (head == nullptr)
      return -1;
    Node<T> *temp = head;
    head = head->next;
    T temp_data = temp->data;
    delete temp;
    return temp_data;
  }

  T PopBack() {
    if (tail == nullptr)
      return nullptr;
    Node<T> *temp = head;
    while (temp->next != tail)
      temp = temp->next;
    temp->next = nullptr;
    T temp_data = tail->data;
    delete tail;
    tail = temp;
    return temp_data;
  }

  bool HasDuplicates() {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }
    Node<T> *current = head;
    while (current != nullptr) {
      Node<T> *runner = current->next;
      while (runner != nullptr) {
        if (current->data == runner->data)
          return true;
        runner = runner->next;
      }
      current = current->next;
    }
    return false;
  }

  void PrintList() {
    Node<T> *temp = head;
    while (temp != nullptr) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << '\n';
  }
};

/*
template <class T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;
    Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
};
*/
template <class T> class DoublyLinkedList {
private:
  Node<T> *head;
  Node<T> *tail;

public:
  DoublyLinkedList() : head(nullptr), tail(nullptr) {}

  void append(const T &data) {
    Node<T> *newNode = new Node<T>(data);
    if (tail == nullptr) {
      head = tail = newNode;
    } else {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    }
  }

  void prepend(const T &data) {
    Node<T> *newNode = new Node<T>(data);
    if (head == nullptr) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }

  bool remove(const T &deleteData) {
    Node<T> *current = head;
    while (current != nullptr) {
      if (current->data == deleteData) {
        if (current == head) {
          head = current->next;
          if (head != nullptr)
            head->prev = nullptr;
        } else if (current == tail) {
          tail = current->prev;
          tail->next = nullptr;
        } else {
          current->prev->next = current->next;
          current->next->prev = current->prev;
        }
        delete current;
        return true;
      }
      current = current->next;
    }
    return false;
  }

  Node<T> *findNode(const T &data) {
    Node<T> *current = head;
    while (current != nullptr) {
      if (current->data == data) {
        return current;
      }
      current = current->next;
    }
    return nullptr;
  }

  void swapNodes(const T &data1, const T &data2) {
    Node<T> *node1 = findNode(data1);
    Node<T> *node2 = findNode(data2);
    if (node1->next == node2 || node1->prev == node2) {
      Node<T> *next = node2->next;
      if (next != nullptr)
        next->prev = node1;
      node2->next = node1;
      node2->prev = node1->prev;
      if (node1->prev != nullptr)
        node1->prev->next = node2;
      node1->prev = node2;
      node1->next = next;
      if (node2->prev == nullptr)
        head = node2;
      if (node1->next == nullptr)
        tail = node1;
    }
  }

  void printList() {
    Node<T> *current = head;
    while (current != nullptr) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }
};

#include <iostream>

template <class T> class UniqueCollection {
private:
  T *elements;  // Массив для хранения элементов
  int size;     // Текущий размер коллекции
  int capacity; // Вместимость коллекции

  // Увеличивает размер массива, если он заполнен
  void resize() {
    capacity *= 2;
    T *newElements = new T[capacity];
    for (int i = 0; i < size; ++i) {
      newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
  }

public:
  // Проверяет, существует ли элемент в коллекции
  bool exists(T element) const {
    for (int i = 0; i < size; ++i) {
      if (elements[i] == element) {
        return true;
      }
    }
    return false;
  }

  T GetElement(int index = 0) {
    if (index >= 0 && index <= size)
      return elements[index];
    return elements[0];
  }

  int GetSize() { return size; }

  UniqueCollection() {
    capacity = 10;
    elements = new T[capacity];
    size = 0;
  }

  ~UniqueCollection() { delete[] elements; }

  // Метод для добавления элемента
  void add(T element) {
    if (!exists(element)) {
      if (size == capacity) {
        resize();
      }
      elements[size++] = element; // Добавляем элемент
    }
  }

  // Метод для удаления элемента
  void remove(T element) {
    for (int i = 0; i < size; ++i) {
      if (elements[i] == element) {
        elements[i] =
            elements[size - 1]; // Заменяем удаляемый элемент последним
        --size; // Уменьшаем размер
        return;
      }
    }
  }

  // Метод для объединения двух коллекций
  UniqueCollection unionWith(const UniqueCollection &other) const {
    UniqueCollection newCollection;
    for (int i = 0; i < size; ++i) {
      newCollection.add(elements[i]);
    }
    for (int i = 0; i < other.size; ++i) {
      newCollection.add(other.elements[i]);
    }
    return newCollection;
  }

  // Метод для исключения элементов другой коллекции
  UniqueCollection except(const UniqueCollection &other) const {
    UniqueCollection newCollection;
    for (int i = 0; i < size; ++i) {
      if (!other.exists(elements[i])) {
        newCollection.add(elements[i]);
      }
    }
    return newCollection;
  }

  // Метод для пересечения двух коллекций
  UniqueCollection intersect(const UniqueCollection &other) const {
    UniqueCollection newCollection;
    for (int i = 0; i < size; ++i) {
      if (other.exists(elements[i])) {
        newCollection.add(elements[i]);
      }
    }
    return newCollection;
  }

  // Метод для вывода коллекции
  void print() const {
    std::cout << "UniqueCollection: { ";
    for (int i = 0; i < size; ++i) {
      std::cout << elements[i] << " ";
    }
    std::cout << "}" << std::endl;
  }
};
