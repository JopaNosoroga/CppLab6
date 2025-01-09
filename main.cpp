#include "Lab6.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  setlocale(LC_ALL, "Russian");
  std::system("chcp 1251");

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

  //
  // третье задание

  UniqueCollection<std::string> compositions;
  compositions.add("Classica");
  compositions.add("Leto");
  compositions.add("Melod");
  compositions.add("Lisa");
  compositions.add("Afrika");

  UniqueCollection<std::string> melomans[3];
  melomans[0].add("Classica");
  melomans[0].add("Leto");
  melomans[0].add("Lisa");
  melomans[0].add("Lol");

  melomans[1].add("Classica");
  melomans[1].add("Leto");
  melomans[1].add("Melod");

  melomans[2].add("Classica");
  melomans[2].add("Leto");
  melomans[2].add("Lisa");

  std::cout << "Кол-во произведений: " << compositions.GetSize() << '\n';
  int *count_compositions = new int[compositions.GetSize()];
  for (int i = 0; i < compositions.GetSize(); i++)
    count_compositions[i] = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < melomans[i].GetSize(); j++) {
      for (int l = 0; l < compositions.GetSize(); l++) {
        if (compositions.GetElement(l) == melomans[i].GetElement(j)) {
          count_compositions[l]++;
          break;
        }
      }
    }
  }

  for (int i = 0; i < compositions.GetSize(); i++) {
    std::cout << "Композиция номер " << i << "  " << count_compositions[i]
              << '\n';
  }
  // четвёртое задание
  //                 0123456789
  std::string rus = "ауоиэыяюеё";
  std::string big_rus = "АУОИЭЫЯЮЕЁ";

  UniqueCollection<std::string> letters[10];

  std::ifstream input("rus_text.txt");
  std::string line;
  while (std::getline(input, line)) {
    std::string temp;
    std::stringstream str_stream(line);
    while (str_stream >> temp) {
      std::cout << temp << '\n';
      for (int i = 0; i < temp.size() / 2; i++) {
        for (int j = 0; j < 10; j++) {
          if (int(temp[i]) == int(rus[j]) || int(temp[i]) == int(big_rus[j])) {
            letters[j].add(temp);
            std::cout << "Буквы " << int(temp[i]) << " " << int(rus[j]) << "  "
                      << int(big_rus[j]) << '\n';
          }
        }
      }
    }
  }
  input.close();

  for (int i = 0; i < 10; i++) {
    letters[i].print();
  }

  return 0;
}
