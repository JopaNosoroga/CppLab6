#include "Lab6.h"

int main() {
  setlocale(LC_ALL, "Russian");

  SinglyLinkedList<int> intList;
  intList.AppendTop(1);
  intList.AppendTop(1);
  intList.AppendTop(2);
  intList.AppendTop(3);

  std::cout << "Список целых чисел: ";
  intList.PrintList();
  std::cout << "Есть ли дубликаты? " << (intList.HasDuplicates() ? "Да" : "Нет")
            << std::endl;
  intList.PopTop();
  std::cout << "Список после удаления первого элемента: ";
  intList.PrintList();
  std::cout << "Есть ли дубликаты? " << (intList.HasDuplicates() ? "Да" : "Нет")
            << std::endl;

  SinglyLinkedList<std::string> stringList;
  stringList.AppendTop("hello");
  stringList.AppendTop("world");
  stringList.AppendTop("hello");

  std::cout << "\nСписок строк: ";
  stringList.PrintList();
  std::cout << "Есть ли дубликаты? "
            << (stringList.HasDuplicates() ? "Да" : "Нет") << std::endl;

  // второе задание

  DoublyLinkedList<int> list;
  list.append(1);
  list.append(2);
  list.append(3);
  list.append(2);
  list.append(4);

  std::cout << "Список: ";
  list.printList();

  list.remove(2); // Удаляет первое вхождение 2

  std::cout << "Список после удаления первого 2: ";
  list.printList();

  list.prepend(0);
  std::cout << "Список после добавления 0 в начало: ";
  list.printList();
  list.swapNodes(1, 3);
  std::cout << "Список после обмена соседних элементов 1 и 3: ";
  list.printList();

  DoublyLinkedList<std::string> StringList;
  StringList.append("hello");
  StringList.append("hello");
  StringList.append("chipi");
  StringList.append("chipi");
  StringList.append("chapa");
  StringList.append("chapa");
  std::cout << "Список: ";
  StringList.printList();
  StringList.remove("hello");
  std::cout << "Список после удаления первого hello: ";
  StringList.printList();
  StringList.swapNodes("hello", "chipi");
  std::cout << "Список после перестановки hello and chipi: ";
  StringList.printList();
  return 0;
}
